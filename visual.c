#include "raylib.h"
#define MAX_MOVING_PATIENTS 3 


typedef struct {
    char name[10]; 
    float x;       
    float y;       
    int moveType;  
    float moveTimer; 
    float atend;
} Paciente;



float COMECAR_X = 350.0f;     
float COMECAR_Y = 200.0f;     
float andar=5.0f;
float limitey =100.0f;
float tempo_at=5.0f;
float tempo_at1=10.0f;
float tempo_at2=5.0f;
float tempo_at3=7.5f;

bool moverCache2(float *Y) {
    if (*Y > limitey) {
        *Y -= andar; 
        if (*Y < limitey) {
            *Y = limitey; 
        }
        return true; 
    }
    return false;
}
bool moverCache1(float *X, float *Y) {

    if (*Y > 200.0f) {
        *Y -= andar;
        if (*Y < 200.0f) *Y = 200.0f; 
        return true;
    }

    else if (*X > 100.0f) {
        *X -= andar; 
        if (*X < 100.0f) *X = 100.0f;
        return true;
    }
    else if (*Y > limitey) {
        *Y -= andar; 
        if (*Y < limitey) *Y = limitey; 
        return true; 
    }
    //tempo_at+=5.0f;
    return false;
}

bool moverCache3(float *X, float *Y) {
    if (*Y > 200.0f) {
        *Y -= andar; 
        if (*Y < 200.0f) *Y = 200.0f; 
        return true; 
    }
    else if (*X < 600.0f) {
        *X += andar; 
        if (*X > 600.0f) *X = 600.0f; 
        return true; 
    }
    else if (*Y > limitey) {
        *Y -= andar;
        if (*Y < limitey) *Y = limitey;
        return true; 
    }
    return false;
}


bool isMoveTypeActive(Paciente *pacientes, int count, int type) {
    for (int i = 0; i < count; i++) {

        if (pacientes[i].moveType == type) {
            return true;
        }
    }
    return false;
}
int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Botão em raylib");
    ///retangulos
    Rectangle buttonRect1 = { 5.0f, 35.0f, 95, 30 };
    Rectangle buttonRect2 = { 255.0f,35.0f, 100, 30 };
    Rectangle buttonRect3 = { 505.0f,35.0f, 100, 30 };
    Rectangle buttonRect4 = { 505.0f,262.5f, 150, 30 };
    Rectangle ate1 = { 0.0f,0.0f, 225, 90};
    Rectangle ate2 = { 250.0f,0.0f, 225, 90};
    Rectangle ate3 = { 500.0f,0.0f, 225, 90};
    
    
    ///retangulos
    const char* buttonText1 = "cache1";
    const char* buttonText2 = "cache2";
    const char* buttonText3 = "cache3";
    const char* buttonText4 = "novo paciente";
    Color buttonColor = LIGHTGRAY;


    float scaleFactor = 0.10f;
    float textureScaleFactor = 0.10f;
    float posya, posxa;
    Texture pessoa;
    pessoa = LoadTexture("./pessoa3.png"); 
    SetTargetFPS(60);

    TFila filaPacientes;
    int maxQueueCapacity = 10;

    Paciente pacientesParaMover[MAX_MOVING_PATIENTS]; 
    int numPacientesParaMover = 0; 

    Fila_create(&filaPacientes, sizeof(Paciente), maxQueueCapacity, TYPE_FILA);

    posxa = 0.0f;
    posya = 30.0f;




    float filay = 300.0f;  
    float espacox = 20.0f;  
    float comecox = 50.0f;  

    
    Paciente novop;
    snprintf(novop.name, sizeof(novop.name), "dante", Fila_size(&filaPacientes) + 1);
    novop.x = 0.0f; 
    novop.y = 0.0f;
    novop.moveType = 0; 
    novop.moveTimer = 0.0f;
    Fila_put(&filaPacientes, (char*)&novop);
    snprintf(novop.name, sizeof(novop.name), "udson", Fila_size(&filaPacientes) + 1);
    Fila_put(&filaPacientes, (char*)&novop);
    snprintf(novop.name, sizeof(novop.name), "joao", Fila_size(&filaPacientes) + 1);
    Fila_put(&filaPacientes, (char*)&novop);
    snprintf(novop.name, sizeof(novop.name), "pedro", Fila_size(&filaPacientes) + 1);
    Fila_put(&filaPacientes, (char*)&novop);
    snprintf(novop.name, sizeof(novop.name), "manoel", Fila_size(&filaPacientes) + 1);
    Fila_put(&filaPacientes, (char*)&novop);
    snprintf(novop.name, sizeof(novop.name), "gustavo", Fila_size(&filaPacientes) + 1);
    Fila_put(&filaPacientes, (char*)&novop);

    
    
    
    
    SetTargetFPS(60);
    
    
    while (!WindowShouldClose()) {

        Vector2 mousePoint = GetMousePosition();
        
        
///adicionar

        bool isMouseOverEnqueueButton = CheckCollisionPointRec(mousePoint, buttonRect4);
        if (isMouseOverEnqueueButton) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                TraceLog(LOG_INFO, "Botão 'Adicionar à Fila' clicado!");
                if (!Fila_isFull(&filaPacientes)) {
                    Paciente novop;
                    snprintf(novop.name, sizeof(novop.name), "P%d", Fila_size(&filaPacientes) + 1);
                    novop.x = 0.0f; 
                    novop.y = 0.0f;
                    novop.moveType = 0; 
                    novop.moveTimer = 0.0f;
                    if (Fila_put(&filaPacientes, (char*)&novop)) {
                        TraceLog(LOG_INFO, TextFormat("Adicionado '%s' à fila.", novop.name));
                    }
                } else {
                    TraceLog(LOG_WARNING, "Fila de pacientes cheia! Não é possível adicionar mais.");
                }
            }
        }
///adicionar


   ///ações mover
   
   ///cache 2
        bool isMouseOverMoveCollectedButton = CheckCollisionPointRec(mousePoint, buttonRect2);
        if (isMouseOverMoveCollectedButton) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (isMoveTypeActive(pacientesParaMover, numPacientesParaMover, 1)) {
                } else if (numPacientesParaMover < MAX_MOVING_PATIENTS) {
                    Paciente tempPaciente;
                    if (Fila_get(&filaPacientes, (char*)&tempPaciente)) {
                        pacientesParaMover[numPacientesParaMover] = tempPaciente;
                        pacientesParaMover[numPacientesParaMover].x = COMECAR_X; 
                        pacientesParaMover[numPacientesParaMover].y = COMECAR_Y; 
                        pacientesParaMover[numPacientesParaMover].moveType = 1;
                        pacientesParaMover[numPacientesParaMover].moveTimer = 0.0f;
                        pacientesParaMover[numPacientesParaMover].atend = tempo_at2;
                        numPacientesParaMover++;
                    } 
                } 
                Fila_dump(&filaPacientes);
            }
        }

       ///cache 1
        bool isMouseOverMainPessoaMoveButton = CheckCollisionPointRec(mousePoint, buttonRect1);
        if (isMouseOverMainPessoaMoveButton) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (isMoveTypeActive(pacientesParaMover, numPacientesParaMover, 2)) {
                } else if (numPacientesParaMover < MAX_MOVING_PATIENTS) {
                    Paciente tempPaciente;
                    if (Fila_get(&filaPacientes, (char*)&tempPaciente)) {
                        pacientesParaMover[numPacientesParaMover] = tempPaciente;
                        pacientesParaMover[numPacientesParaMover].x = COMECAR_X; 
                        pacientesParaMover[numPacientesParaMover].y = COMECAR_Y; 
                        pacientesParaMover[numPacientesParaMover].moveType = 2;
                        pacientesParaMover[numPacientesParaMover].moveTimer = -10.0f;
                        pacientesParaMover[numPacientesParaMover].atend = tempo_at1;
                        numPacientesParaMover++;
                    } 
                } 
                Fila_dump(&filaPacientes);
            }
        }

        ///cache 3
        bool isMouseOverMainPessoaCache3Button = CheckCollisionPointRec(mousePoint, buttonRect3);
        if (isMouseOverMainPessoaCache3Button) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (isMoveTypeActive(pacientesParaMover, numPacientesParaMover, 3)) {
                } else if (numPacientesParaMover < MAX_MOVING_PATIENTS) {
                    Paciente tempPaciente;
                    if (Fila_get(&filaPacientes, (char*)&tempPaciente)) {
                        pacientesParaMover[numPacientesParaMover] = tempPaciente;
                        pacientesParaMover[numPacientesParaMover].x = COMECAR_X; 
                        pacientesParaMover[numPacientesParaMover].y = COMECAR_Y;   
                        pacientesParaMover[numPacientesParaMover].moveType = 3; 
                        pacientesParaMover[numPacientesParaMover].moveTimer = 0.0f;
                        pacientesParaMover[numPacientesParaMover].atend = tempo_at3;                        
                        numPacientesParaMover++;
                    } 
                } 
                Fila_dump(&filaPacientes);
            }
        } 
        ///açoes mover


    ///limitar movimentos
        for (int i = 0; i < numPacientesParaMover; ) { 
            bool aindaMovendo = false;
         
            if (pacientesParaMover[i].moveType == 1) { 
                aindaMovendo = moverCache2(&pacientesParaMover[i].y); 
            } else if (pacientesParaMover[i].moveType == 2) { 
                aindaMovendo = moverCache1(&pacientesParaMover[i].x, &pacientesParaMover[i].y);
            } else if (pacientesParaMover[i].moveType == 3) { 
                aindaMovendo = moverCache3(&pacientesParaMover[i].x, &pacientesParaMover[i].y); 
            }
            if (aindaMovendo) { 
                pacientesParaMover[i].moveTimer = 0.0f; 
                i++; 
            } else { 
                if (pacientesParaMover[i].moveType != 0) {                   
                    pacientesParaMover[i].moveTimer += GetFrameTime();
                }
                if (pacientesParaMover[i].moveTimer >= pacientesParaMover[i].atend) {
                    pacientesParaMover[i].moveType = 0; 
                    if (i != numPacientesParaMover - 1) {
                        pacientesParaMover[i] = pacientesParaMover[numPacientesParaMover - 1];
                    }
                    numPacientesParaMover--; 
                } else {
                    i++; 
                }
            }
        }
        ///limitar move
        BeginDrawing();
        DrawRectangleRec(ate1, buttonColor);
        DrawRectangleRec(ate2, buttonColor);
        DrawRectangleRec(ate3, buttonColor);
        ClearBackground((Color){ 255, 255, 255, 100 });

        /// Atendentes
        DrawTextureEx(pessoa, (Vector2){ posxa + 100, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente1", posxa + 70, posya - 20, 20, BLACK);

        DrawTextureEx(pessoa, (Vector2){ posxa + 350, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente2", posxa + 320, posya - 20, 20, BLACK);

        DrawTextureEx(pessoa, (Vector2){ posxa + 600, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente3", posxa + 570, posya - 20, 20, BLACK);
        /// Atendentes

        ///retagulos dos botoes
        DrawRectangleRec(buttonRect1, YELLOW);
        DrawRectangleRec(buttonRect2, YELLOW);
        DrawRectangleRec(buttonRect3, YELLOW);
        DrawRectangleRec(buttonRect4, buttonColor);

        /// rentangulos botoes
        ///botoes
        int textWidth = MeasureText(buttonText1, 20);
        int textWidth2 = MeasureText(buttonText4, 20);
        DrawText("Fila de Pacientes:", comecox, filay - 30, 20, BLACK);
        DrawText(buttonText1, buttonRect1.x + (buttonRect1.width - textWidth) / 2, buttonRect1.y + (buttonRect1.height - 20) / 2, 20, BLACK);
        DrawText(buttonText2, buttonRect2.x + (buttonRect2.width - textWidth) / 2, buttonRect2.y + (buttonRect2.height - 20) / 2, 20, BLACK);
        DrawText(buttonText3, buttonRect3.x + (buttonRect3.width - textWidth) / 2, buttonRect3.y + (buttonRect3.height - 20) / 2, 20, BLACK);
        DrawText(buttonText4, buttonRect4.x + (buttonRect4.width - textWidth2) / 2, filay-30 , 20, BLACK);
        ///botoes
        Paciente filado;
        ///fila nomes
        float currentX = comecox;
            for (int i = 0; i < Fila_size(&filaPacientes); i++) {
                if (Fila_peek_at(&filaPacientes, i, (char*)&filado)) {
                    float comecox = currentX + (i * (espacox + (pessoa.width * textureScaleFactor)));
                    DrawTextureEx(pessoa, (Vector2){ comecox, filay }, 0.0f, textureScaleFactor, WHITE);
                    DrawText(filado.name, comecox, filay+ (pessoa.height * textureScaleFactor) + 5, 15, DARKGRAY);
            }
        }
        ///fila nomes
        
        ///fila img
        for (int i = 0; i < numPacientesParaMover; i++) {
                DrawTextureEx(pessoa, (Vector2){ pacientesParaMover[i].x, pacientesParaMover[i].y }, 0.0f, textureScaleFactor, WHITE);
                int nameWidth = MeasureText(pacientesParaMover[i].name, 15);
                DrawText(pacientesParaMover[i].name, pacientesParaMover[i].x + (pessoa.width * textureScaleFactor / 2) - (nameWidth / 2),
                         pacientesParaMover[i].y + (pessoa.height * textureScaleFactor) + 5, 15, BLUE);
            }

        ///fila img
        
        EndDrawing();
    }
    UnloadTexture(pessoa);
    CloseWindow();
    return 0;
}