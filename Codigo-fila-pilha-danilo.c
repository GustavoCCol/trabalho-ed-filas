#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 15
#define TAM_GUICHE 3

typedef struct tagFila {
    char    *buffer;// Buffer para guardar os elementos
    char     *first;// ponteiro para primeiro elemento
    char      *last;// ponteiro para ultimo
    int        size;// tamanho da fila
    char sizeElement;// tamanho do elemento da fila
    int  maxElement;// numero maximo de elementos
    bool preferencial;// determina se a fila e de atendimento preferencial ou não 
} TFila;

TFila fila_normal;
TFila fila_preferencial;
char fila_next; //Determina o tipo de paciente a ser chamado, 1 para preferencial, 2 para normal
char n_filas_normais = 0;//Quantidade de filas normais criadas
char n_filas_preferenciais = 0;//Quantidade de filas preferenciais criadas
char guiche[TAM_GUICHE][20];//guiche onde os pacientes serão atendidos
bool isPreferencial;//determina se o próximo paciente a ser chamado será preferencial

bool Fila_create(TFila *fila, char sizeElement, int max, bool preferencial);
void Fila_destroy(TFila *fila);
bool Fila_put(TFila *fila,char *data);
bool Fila_get(TFila *fila,char *data);
bool Fila_isEmpty(TFila *fila);
bool Fila_isFull(TFila *fila);
int Fila_size(TFila *fila);
void clrscr();
void Iniciar_Guiche();
bool Menu();
bool Escolha_Menu(char escolha);

void clrscr()
{
       printf("\x1b[2J");
}

int main(){
    bool continuar = true;
    
    Iniciar_Guiche();
    while(continuar == true){
        continuar = Menu();
    }
    
    printf("\nSessão encerrada, adeus.\n");
    
    return 0;
}

bool Fila_create(TFila *fila, char sizeElement, int max, bool preferencial){
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
    fila->preferencial = preferencial;
   
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
    printf("*************************\n");
    printf("buffer = %04x\n", fila->buffer);
    printf("SizeElem = %d\n",fila->sizeElement);
    printf("Size     = %d\n",fila->size);
    printf("Max      = %d\n",fila->maxElement);
    printf("first  = %04x\n",fila->first);
    printf("Last   = %04x\n",fila->last);
    printf("-----------------------\n");
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

void Iniciar_Guiche(){
    int i;
    for(i = 0; i < TAM_GUICHE; i++){
        guiche[i][0] = '\0'; // define string vazia
    }
}

bool Menu(){
    char escolha;
    bool continuar;
    
    clrscr();
    printf("\nEscolha uma opção:\n");
    printf("\n1 - Criar fila");
    printf("\n2 - Adicionar paciente");
    printf("\n3 - Chamar paciente");
    printf("\n4 - Liberar paciente");
    printf("\n5 - Encerrar fila");
    printf("\n6 - Exibir guichês");
    printf("\n7 - Encerrar sessão\n");
    printf("\nEscolha: ");
    scanf(" %c", &escolha);
    clrscr();
    
    continuar = Escolha_Menu(escolha);
    
    return continuar;
}

bool Escolha_Menu(char escolha){
    bool result;
    char escolha_fila;
    char data[20];
    int i, contador = 0;
    
    switch(escolha){
        case '1':
            if(n_filas_normais == 1 && n_filas_preferenciais == 1){
                printf("\nNúmero máximo de filas já foi alcançado, não é possível criar mais filas\n");
                break;
            }
            printf("\nEscolha o tipo de fila");
            printf("\n1 - normal\n2 - preferencial\n");
            printf("\nEscolha: ");
            scanf(" %d", &escolha_fila);
            clrscr();
            if(escolha_fila == 1){
                if(n_filas_normais == 1){
                    printf("\nNúmero máximo de filas normais já foi alcançada, não é possível criar mais\n");
                    sleep(2);
                    break;
                }
                result = Fila_create(&fila_normal, sizeof(char) * 20, TAM, false);
                if(result == true){
                    printf("\nFila criada com sucesso!\n");
                    sleep(2);
                    n_filas_normais++;
                }
                else{
                    printf("\nErro ao criar fila, tente novamente\n");
                    sleep(2);
                }  
            }
            else if(escolha_fila == 2){
                if(n_filas_preferenciais == 1){
                    printf("\nNúmero máximo de filas preferenciais já foi alcançado, não é possível criar mais\n");
                    sleep(2);
                }
                result = Fila_create(&fila_preferencial, sizeof(char) * 20, TAM, true);
                if(result == true){
                    printf("\nFila criada com sucesso!\n");
                    sleep(2);
                    n_filas_preferenciais++;
                }
                else{
                    printf("\nErro ao criar fila, tente novamente\n");
                    sleep(2);
                }
            }
            else{
                printf("\nOpção inválida, tente novamente\n");
                sleep(2);
            }
            break;
        case '2':
            if(n_filas_normais == 0 && n_filas_preferenciais == 0){
                printf("\nNão há filas para se adicionar pacientes, crie uma fila para prosseguir.\n");
                sleep(2);
                break;
            }        
            printf("\nEscolha o tipo de fila para adicionar o paciente");
            printf("\n1 - normal\n2 - preferencial\n");
            printf("\nEscolha: ");
            scanf(" %d", &escolha_fila);
            clrscr();
            if(escolha_fila == 1){
                if(n_filas_normais == 0){
                    printf("\nNão há uma fila normal, crie uma fila antes de prosseguir.\n");
                    sleep(2);
                    break;
                }
                if(fila_normal.size == 15){
                    printf("\nA fila está cheia, não é possível adicionar pacientes.\n");
                    sleep(2);
                    break;
                }
                printf("\nDiga o nome do paciente: ");
                scanf(" %19s", data);
                result = Fila_put(&fila_normal, data);
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
            else if(escolha_fila == 2){
                if(n_filas_preferenciais == 0){
                    printf("\nNão há uma fila preferencial, crie uma fila antes de prosseguir.\n");
                    sleep(2);
                    break;
                }
                if(fila_preferencial.size == 15){
                    printf("\nA fila está cheia, não é possível adicionar pacientes.\n");
                    sleep(2);
                    break;
                }
                printf("\nDiga o nome do paciente: ");
                scanf(" %19s", data);
                result = Fila_put(&fila_preferencial, data);
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
            break;
        case '3':
            // Verifica se todos os guichês estão ocupados
            for(i = 0; i < TAM_GUICHE; i++){
                if (guiche[i][0] == '\0') {
                    break;
                }
            }
            if (i == TAM_GUICHE) {
                printf("\nGuichê cheio.\n");
                sleep(2);
                break;
            }

            if(n_filas_normais == 0 && n_filas_preferenciais == 0){
                printf("\nNão há filas para se chamar pacientes, crie uma fila para prosseguir.\n");
                sleep(2);
                break;
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
                break;
            }
            if(isPreferencial == true){
                for(i = 0; i < TAM_GUICHE; i++){
                    if (guiche[i][0] == '\0'){
                        result = Fila_get(&fila_preferencial, guiche[i]);
                        break;
                    }
                }
                if(result == true){
                    printf("\nPaciente chamado com sucesso.\n");
                    sleep(2);
                    isPreferencial = false;
                }
                else{
                    printf("\nGuichê cheio.\n");
                    sleep(2);
                }
            }
            else{
                for(i = 0; i < TAM_GUICHE; i++){
                    if (guiche[i][0] == '\0'){
                        result = Fila_get(&fila_normal, guiche[i]);
                        break;
                    }
                }
                if(result == true){
                    printf("\nPaciente chamado com sucesso\n");
                    sleep(2);
                    isPreferencial = true;
                }
                else{
                    printf("\nGuichê cheio.\n");
                    sleep(2);
                }
            }
            break;
        case '4':
            for(i = 0; i < TAM_GUICHE; i++){
                if (guiche[i][0] == '\0'){
                    contador++;
                }
            }
            if(contador == TAM_GUICHE){
                printf("\nNão há pacientes para serem liberados\n");
                sleep(2);
                break;
            }
            for(i = 0; i < TAM_GUICHE; i++){
                if(strlen(guiche[i]) > 0){
                    printf("\nO paciente %s, do guichê %d foi liberado\n", guiche[i], i + 1);
                    guiche[i][0] = '\0'; // limpa a string
                    sleep(2);
                    break;
                }
            }
            break;
        case '5':
            if(n_filas_normais == 0 && n_filas_preferenciais == 0){
                printf("\nNão há filas para serem encerradas\n");
                sleep(2);
                break;
            }
            printf("\nEscolha a fila a ser encerrada");
            printf("\n1 - fila normal\n2 - fila preferencial");
            printf("\nEscolha: ");
            scanf(" %d", &escolha_fila);
            clrscr();
            if(escolha_fila == 1){
                if(n_filas_normais == 0){
                    printf("\nNão há filas normais para serem encerradas\n");
                    sleep(2);
                    break;
                }
                Fila_destroy(&fila_normal);
                printf("\nFila encerrada com sucesso.\n");
                sleep(2);
                n_filas_normais--;
            }
            else if(escolha_fila == 2){
                if(n_filas_preferenciais == 0){
                    printf("\nNão há filas preferenciais para serem encerradas\n");
                    sleep(2);
                    break;
                }
                Fila_destroy(&fila_preferencial);
                printf("\nFila encerrada com sucesso.\n");
                sleep(2);
                n_filas_preferenciais--;
            }
            else{
                printf("\nOpção inválida, tente novamemte\n");
                sleep(2);
            }
            break;
        case '6':
            for(i = 0; i <= TAM_GUICHE; i++){
                if (strlen(guiche[i]) > 0)
                    printf("\nGuichê %d: %s", i + 1, guiche[i]);
                else
                    printf("\nGuichê %d: [vazio]", i + 1);
            }
            sleep(2);
            break;
        case '7':
            return false;
        default:
            printf("\nOpção inválida, tente novamente\n");
            sleep(2);
    }
    
    return true;
}
