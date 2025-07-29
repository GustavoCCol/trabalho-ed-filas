#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 15
#define TAM_GUICHE 3

typedef struct tagFila {
    char    *buffer;// Buffer para guardar os elementos
    char     *first;// ponteiro para primeiro elemento
    char      *last;// ponteiro para ultimo
    int        size;// tamanho da fila
    char sizeElement;// tamanho do elemento da fila
    int  maxElement;// numero maximo de elementos
} TFila;

TFila fila_normal;
TFila fila_preferencial;
char fila_next; //Determina o tipo de paciente a ser chamado, 1 para preferencial, 2 para normal
TFila guiche;//guiche onde os pacientes serão atendidos
bool isPreferencial;//determina se o próximo paciente a ser chamado será preferencial

bool Fila_create(TFila *fila, char sizeElement, int max);
void Fila_destroy(TFila *fila);
bool Fila_put(TFila *fila,char *data);
bool Fila_get(TFila *fila,char *data);
bool Fila_isEmpty(TFila *fila);
bool Fila_isFull(TFila *fila);
int Fila_size(TFila *fila);
void Fila_dump(TFila *fila);
//void clrscr();
void Iniciar_filas();
bool Menu();
bool Escolha_Menu(char escolha);
void Adicionar_paciente();
void Chamar_paciente();
void Liberar_paciente();
void Encerrar_fila();

/*void clrscr()
{
       printf("\x1b[2J");
}*/

int main(){
    bool continuar = true;
    
    Iniciar_filas();
    while(continuar == true){
        continuar = Menu();
    }
    
    printf("\nSessão encerrada, adeus.\n");
    
    return 0;
}

bool Fila_create(TFila *fila, char sizeElement, int max){
    // verifica se paramentros da funçao sao validos
    if(fila == NULL){
        return false;
    }
    if((sizeElement==0)||(max==0)){
        return false;
    }
    // aloca area para a fila
    if( (fila->buffer = malloc(sizeElement *max))==NULL){
        return false;
    }
    // inicializa propriedades da fila
    fila->size = 0;
    fila->sizeElement = sizeElement;
    fila->maxElement = max;
    fila->first = fila->buffer;
    fila->last  = fila->buffer;
   
    return true;
}

void Fila_destroy(TFila *fila){
    // libera a area da fila
    free(fila->buffer);
    // zera propriedades
    fila->size = 0;
    fila->sizeElement = 0;
    fila->maxElement = 0;
    fila->first = NULL;
    fila->last  = NULL;
    fila->size = 0;
}

bool Fila_put(TFila *fila,char *data){
    if(data == NULL){
        return false;
    }
    if(Fila_isFull(fila)==false){
        // copia o dado para a Fila
        memcpy(fila->last,data,fila->sizeElement);
        // incremento o ponteiro do ultimo
        if (fila->size < fila->maxElement){
            // Incrementa ponteiro
            fila->last += fila->sizeElement;
            if(fila->last >= fila->buffer + fila->maxElement*fila->sizeElement){
                fila->last = fila->buffer;
            }
            // increnta o numero de elementos na fila
            fila->size++;
            return true;
        }
    }
    return false;
   
}
bool Fila_get(TFila *fila,char *data){

    if(data == NULL){
        return false;
    }
    
    if(Fila_isEmpty(fila)==false){
        // copia o dado para a Fila
        memcpy(data,fila->first, fila->sizeElement);
        // incremento o ponteiro do ultimo
        if (fila->size > 0){
            // Incrementa ponteiro
            fila->first += fila->sizeElement;
            // checa se nao deve circular o ponteiro
            if(fila->first>= fila->buffer + fila->maxElement*fila->sizeElement)
            fila->first = fila->buffer;
               
            // increnta o numero de elementos na fila
            fila->size--;
            return true;
        }
        else{
            return false;
        }
    }
        return false;
}

bool Fila_isEmpty(TFila *fila){
    if(fila->size == 0)
        return true;
    return false;
}
bool Fila_isFull(TFila *fila){
    if(fila->size == fila->maxElement){
        return true;
    }
    return false;
}

int Fila_size(TFila *fila){
    return fila->size;
}

void Fila_dump(TFila *fila){
    char *current,*j;
    int i;
    
    current = fila->first;
    for( i =0; i< fila->size;i++){
        printf("Elemento [%d]\n",i);
        for(j=current; j < current + fila->sizeElement;j++){
            printf("%04x : %02x\n",j,(*j));
        }
        current += fila->sizeElement;
        if(current>= fila->buffer + fila->maxElement*fila->sizeElement)
           current = fila->buffer;
        printf("-----------------------\n");
    }
}

void Iniciar_filas(){
    Fila_create(&fila_normal, sizeof(char)*20, TAM);
    Fila_create(&fila_preferencial, sizeof(char)*20, TAM);
    Fila_create(&guiche, sizeof(char)*20, TAM_GUICHE);
}

bool Menu(){
    char escolha;
    bool continuar;
    
    clrscr();
    printf("\nEscolha uma opção:\n");
    printf("\n1 - Adicionar paciente");
    printf("\n2 - Chamar paciente");
    printf("\n3 - Liberar paciente");
    printf("\n4 - Encerrar fila");
    printf("\n5 - Exibir guichês");
    printf("\n6 - Encerrar sessão\n");
    printf("\nEscolha: ");
    escolha = getch();
    clrscr();
    
    continuar = Escolha_Menu(escolha);
    
    return continuar;
}

bool Escolha_Menu(char escolha){
    switch(escolha){
        case '1':
            Adicionar_paciente();
            break;
        case '2':
            Chamar_paciente();
            break;
        case '3':
            Liberar_paciente();
            break;
        case '4':
            Encerrar_fila();
            break;
        case '5':
            Fila_dump(&guiche);
            sleep(2);
            break;
        case '6':
            return false;
        default:
            printf("\nOpção inválida, tente novamente\n");
            sleep(2);
    }
    
    return true;
}
void Adicionar_paciente(){
    bool result;
    char escolha_fila;
    char data[50];
    
    printf("\nEscolha o tipo de fila para adicionar o paciente");
    printf("\n1 - normal\n2 - preferencial\n");
    printf("\nEscolha: ");
    escolha_fila = getch();
    clrscr();
    if(escolha_fila == '1'){
        if(fila_normal.size == 15){
            printf("\nA fila está cheia, não é possível adicionar pacientes.\n");
            sleep(2);
            return;
        }
        printf("\nDiga o nome do paciente: ");
        gets(data);
        result = Fila_put(&fila_normal, &data);
        clrscr();
        if(result == true){
            printf("\nPaciente adicionado com sucesso.\n");
            sleep(2);
        }
        else{
            printf("\nErro ao adicionar paciente, tente novamente\n");
            sleep(2);
        }
    }
    else if(escolha_fila == '2'){
        if(fila_preferencial.size == 15){
            printf("\nA fila está cheia, não é possível adicionar pacientes.\n");
            sleep(2);
            return;
        }
        printf("\nDiga o nome do paciente: ");
        gets(data);
        result = Fila_put(&fila_preferencial, &data);
        clrscr();
        if(result == true){
            //Aqui tem q colocar o nome do paciente
            printf("\nPaciente adicionado com sucesso.\n");
            sleep(2);
            if(fila_preferencial.size == 1){
                isPreferencial = true;
            }
        }
        else{
            printf("\nErro ao adicionar paciente, tente novamente\n");
            sleep(2);
        }
    }
    else{
        printf("\nOpção inválida, tente novamente\n");
        sleep(2);
    }
}

void Chamar_paciente(){
    bool result;
    char escolha_fila;
    char data[50];
            // Verifica se todos os guichês estão ocupados
            if(guiche.size == TAM_GUICHE){
                printf("\nTodos os guichês estão ocupados.\n");
                return;
            }
            if(fila_preferencial.size == 0 && fila_normal.size != 0){
                isPreferencial = false;
            }
            if(fila_preferencial.size != 0 && fila_normal.size == 0){
                isPreferencial = true;
            }
            if(fila_preferencial.size == 0 && fila_normal.size == 0){
                printf("\nNão há pacientes para serem chamados.\n");
                sleep(2);
                return;
            }
            if(isPreferencial == true){
                result = Fila_get(&fila_preferencial, &data);
                if(result == true){
                    result = Fila_put(&guiche, &data);
                    if(result == true){
                        printf("\nPaciente chamado com sucesso.\n");
                        sleep(2);
                        isPreferencial = false;
                    }
                    else{
                        printf("\nNão foi possível chamar o paciente, tente novamente.\n");
                        sleep(2);
                    }
                }
                else{
                    printf("\nNão foi possível chamar o paciente, tente novamente.\n");
                    sleep(2);
                }
            }
            else{
                result = Fila_get(&fila_normal, &data);
                if(result == true){
                    result = Fila_put(&guiche, &data);
                    if(result == true){
                        printf("\nPaciente chamado com sucesso.\n");
                        sleep(2);
                        isPreferencial = false;
                    }
                    else{
                        printf("\nNão foi possível chamar o paciente, tente novamente.\n");
                        sleep(2);
                    }
                }
                else{
                    printf("\nNão foi possível chamar o paciente, tente novamente.\n");
                    sleep(2);
                }
            }
}

void Liberar_paciente(){
    bool result;
    char data[50];
    
    if(guiche.size == 0){
        printf("\nNão há pacientes para serem liberados\n");
        sleep(2);
        return;
    }
    result = Fila_get(&guiche, &data);
    if(result == true){
        printf("\nPaciente liberado: ");
        puts(data);
        sleep(2);
    }
}

void Encerrar_fila(){
    bool result;
    char escolha_fila;
    char data[50];
            printf("\nEscolha a fila a ser encerrada");
            printf("\n1 - fila normal\n2 - fila preferencial");
            printf("\nEscolha: ");
            escolha_fila = getch();
            clrscr();
            if(escolha_fila == '1'){
                Fila_destroy(&fila_normal);
                printf("\nFila encerrada com sucesso.\n");
                sleep(2);
            }
            else if(escolha_fila == '2'){
                Fila_destroy(&fila_preferencial);
                printf("\nFila encerrada com sucesso.\n");
                sleep(2);
            }
            else{
                printf("\nOpção inválida, tente novamemte\n");
                sleep(2);
            }
}
