#include "raylib.h"
#include <stdio.h>
#include <string.h> 



#define MAX_MOVING_PATIENTS 3
#define MAX_NAME_LENGTH 15 


typedef struct {
    char name[15];
    float x;
    float y;
    int moveType;    
    float moveTimer; 
    float atend;     
} Paciente;


float COMECAR_X = 350.0f;
float COMECAR_Y = 200.0f;
float andar = 5.0f;
float limitey = 100.0f;
float tempo_at1 = 5.0f; 
float tempo_at2 = 7.5f;  
float tempo_at3 = 10.5f;  

int guiches[4] = {0, 0, 0, 0};





bool isMoveTypeActive(Paciente *pacientes, int count, int type) {
    for (int i = 0; i < count; i++) {
        if (pacientes[i].moveType == type) {
            return true;
        }
    }
    return false;
}

bool moverCache2(Paciente *patient) { 
    if (patient->y > limitey) {
        patient->y -= andar;
        if (patient->y < limitey) {
            patient->y = limitey;
        }
        return true; 
    }
    return false; 
}

bool moverCache1(Paciente *patient) { 
    if (patient->y > 200.0f) {
        patient->y -= andar;
        if (patient->y < 200.0f) patient->y = 200.0f;
        return true;
    } else if (patient->x > 100.0f) {
        patient->x -= andar;
        if (patient->x < 100.0f) patient->x = 100.0f;
        return true;
    } else if (patient->y > limitey) {
        patient->y -= andar;
        if (patient->y < limitey) patient->y = limitey;
        return true;
    }
    return false;
}

bool moverCache3(Paciente *patient) { 
    if (patient->y > 200.0f) {
        patient->y -= andar;
        if (patient->y < 200.0f) patient->y = 200.0f;
        return true;
    } else if (patient->x < 600.0f) {
        patient->x += andar;
        if (patient->x > 600.0f) patient->x = 600.0f;
        return true;
    } else if (patient->y > limitey) {
        patient->y -= andar;
        if (patient->y < limitey) patient->y = limitey;
        return true;
    }
    return false;
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Simulação de Clínica");


    guiches[1] = 0; 
    guiches[2] = 0; 
    guiches[3] = 0; 

    int batata = 0; 
    char inputName[MAX_NAME_LENGTH + 1] = "\0"; 
    int letterCount = 0; 

    ///retangulos
    Rectangle buttonRect1 = {5.0f, 35.0f, 95, 30};
    Rectangle buttonRect2 = {255.0f, 35.0f, 100, 30};
    Rectangle buttonRect3 = {505.0f, 35.0f, 100, 30};
    Rectangle buttonRect4 = {505.0f, 262.5f, 150, 30};

    Rectangle ate1 = {0.0f, 0.0f, 225, 90};
    Rectangle ate2 = {250.0f, 0.0f, 225, 90};
    Rectangle ate3 = {500.0f, 0.0f, 225, 90};
        ///menu
    Rectangle menuButtonSimulation = {300.0f, 300.0f, 200, 50};
    Rectangle menuButtonAddPatient = {300.0f, 150.0f, 200, 50};
    Rectangle nameInputBox = {300.0f, 100.0f, 200, 50};
        ///menu
    ///retangulos

    ///botoes
    const char *buttonText1 = "Cache1";
    const char *buttonText2 = "Cache2";
    const char *buttonText3 = "Cache3";
    const char *buttonText4 = "Novo Paciente"; //SIMUAC
    const char *buttonTextAddPatientMenu = "Adicionar Paciente"; //MENU
    ///botoes

    Color buttonColor = LIGHTGRAY;

    float scaleFactor = 0.10f;
    float textureScaleFactor = 0.10f;
    float posya = 30.0f; 

    Texture pessoa = LoadTexture("./pessoa3.png");
  

    SetTargetFPS(60);

    TFila filaPacientes;
    int maxQueueCapacity = 10;
    Fila_create(&filaPacientes, sizeof(Paciente), maxQueueCapacity, TYPE_FILA);

    Paciente pacientesParaMover[MAX_MOVING_PATIENTS];
    int numPacientesParaMover = 0;

  /*
    Paciente novop_init;
    snprintf(novop_init.name, sizeof(novop_init.name), "Dante"); novop_init.x=0; novop_init.y=0; novop_init.moveType=0; novop_init.moveTimer=0; novop_init.atend=0;
    Fila_put(&filaPacientes, (char*)&novop_init);
    snprintf(novop_init.name, sizeof(novop_init.name), "Udson"); novop_init.x=0; novop_init.y=0; novop_init.moveType=0; novop_init.moveTimer=0; novop_init.atend=0;
    Fila_put(&filaPacientes, (char*)&novop_init);
    snprintf(novop_init.name, sizeof(novop_init.name), "Joao"); novop_init.x=0; novop_init.y=0; novop_init.moveType=0; novop_init.moveTimer=0; novop_init.atend=0;
    Fila_put(&filaPacientes, (char*)&novop_init);
    snprintf(novop_init.name, sizeof(novop_init.name), "Pedro"); novop_init.x=0; novop_init.y=0; novop_init.moveType=0; novop_init.moveTimer=0; novop_init.atend=0;
    Fila_put(&filaPacientes, (char*)&novop_init);
    snprintf(novop_init.name, sizeof(novop_init.name), "Manoel"); novop_init.x=0; novop_init.y=0; novop_init.moveType=0; novop_init.moveTimer=0; novop_init.atend=0;
    Fila_put(&filaPacientes, (char*)&novop_init);
    snprintf(novop_init.name, sizeof(novop_init.name), "Gustavo"); novop_init.x=0; novop_init.y=0; novop_init.moveType=0; novop_init.moveTimer=0; novop_init.atend=0;
    Fila_put(&filaPacientes, (char*)&novop_init);*/

    float filay = 300.0f; 
    float espacox = 20.0f; 
    float comecox = 50.0f; 

    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();


        if (batata == 0) { 

            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_NAME_LENGTH)) {
                    inputName[letterCount] = (char)key;
                    letterCount++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE)) {
                if (letterCount > 0) {
                    letterCount--;
                    inputName[letterCount] = '\0';
                }
            }
 
            if (CheckCollisionPointRec(mousePoint, menuButtonSimulation) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                batata= 1; 
            }
            if (CheckCollisionPointRec(mousePoint, menuButtonAddPatient) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (letterCount > 0) { 
                    if (!Fila_isFull(&filaPacientes)) {
                        Paciente novop;
                        strncpy(novop.name, inputName, sizeof(novop.name) - 1);
                        novop.name[sizeof(novop.name) - 1] = '\0'; 
                        novop.x = 0.0f; 
                        novop.y = 0.0f;
                        novop.moveType = 0; 
                        novop.moveTimer = 0.0f;
                        Fila_put(&filaPacientes, (char*)&novop);
                    } 
                }

                letterCount = 0;
                memset(inputName, 0, sizeof(inputName));
            }
        } else if (batata == 1) { 

          
            if (CheckCollisionPointRec(mousePoint, buttonRect4) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (!Fila_isFull(&filaPacientes)) {
                    Paciente novop;
                    snprintf(novop.name, sizeof(novop.name), "P%d", Fila_size(&filaPacientes) + 1);
                    novop.x = 0.0f; 
                    novop.y = 0.0f;
                    novop.moveType = 0; 
                    novop.moveTimer = 0.0f;
                    Fila_put(&filaPacientes, (char*)&novop);

                    
                }     
            }


            if (CheckCollisionPointRec(mousePoint, buttonRect2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (guiches[2] == 1) {

                } else if (numPacientesParaMover < MAX_MOVING_PATIENTS) {
                    Paciente tempPaciente;
                    if (Fila_get(&filaPacientes, (char*)&tempPaciente)) {
                        guiches[2] = 1;
                        pacientesParaMover[numPacientesParaMover] = tempPaciente;
                        pacientesParaMover[numPacientesParaMover].x = COMECAR_X;
                        pacientesParaMover[numPacientesParaMover].y = COMECAR_Y;
                        pacientesParaMover[numPacientesParaMover].moveType = 1; 
                        pacientesParaMover[numPacientesParaMover].moveTimer = 0.0f;
                        pacientesParaMover[numPacientesParaMover].atend = tempo_at2;
                        numPacientesParaMover++;

                    }
                }
            }                

            if (CheckCollisionPointRec(mousePoint, buttonRect1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (guiches[1] == 1) {

                } else if (numPacientesParaMover < MAX_MOVING_PATIENTS) {
                    Paciente tempPaciente;
                    if (Fila_get(&filaPacientes, (char*)&tempPaciente)) {
                        guiches[1] = 1;
                        pacientesParaMover[numPacientesParaMover] = tempPaciente;
                        pacientesParaMover[numPacientesParaMover].x = COMECAR_X;
                        pacientesParaMover[numPacientesParaMover].y = COMECAR_Y;
                        pacientesParaMover[numPacientesParaMover].moveType = 2; 
                        pacientesParaMover[numPacientesParaMover].moveTimer = 0.0f;
                        pacientesParaMover[numPacientesParaMover].atend = tempo_at1;
                        numPacientesParaMover++;

                    } 
                }
            }

            if (CheckCollisionPointRec(mousePoint, buttonRect3) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (guiches[3] == 1) {

                } else if (numPacientesParaMover < MAX_MOVING_PATIENTS) {
                    Paciente tempPaciente;
                    if (Fila_get(&filaPacientes, (char*)&tempPaciente)) {
                        guiches[3] = 1;
                        pacientesParaMover[numPacientesParaMover] = tempPaciente;
                        pacientesParaMover[numPacientesParaMover].x = COMECAR_X;
                        pacientesParaMover[numPacientesParaMover].y = COMECAR_Y;
                        pacientesParaMover[numPacientesParaMover].moveType = 3;
                        pacientesParaMover[numPacientesParaMover].moveTimer = 0.0f;
                        pacientesParaMover[numPacientesParaMover].atend = tempo_at3;
                        numPacientesParaMover++;
                    } 
                }   
            }

               ///desaparece
            for (int i = 0; i < numPacientesParaMover; ) {
                bool aindaMovendo = false;

                if (pacientesParaMover[i].moveType == 1) { 
                    aindaMovendo = moverCache2(&pacientesParaMover[i]);
                } else if (pacientesParaMover[i].moveType == 2) { 
                    aindaMovendo = moverCache1(&pacientesParaMover[i]);
                } else if (pacientesParaMover[i].moveType == 3) { 
                    aindaMovendo = moverCache3(&pacientesParaMover[i]);
                }

                if (aindaMovendo) {
                    pacientesParaMover[i].moveTimer = 0.0f; 
                    i++;
                } else { 
                    if (pacientesParaMover[i].moveType != 0) {
                        pacientesParaMover[i].moveTimer += GetFrameTime();
                    }

                    if (pacientesParaMover[i].moveTimer >= pacientesParaMover[i].atend) {



                        if (pacientesParaMover[i].moveType == 1) { 
                            guiches[2] = 0;
                        } else if (pacientesParaMover[i].moveType == 2) {
                            guiches[1] = 0;
                        } else if (pacientesParaMover[i].moveType == 3) {
                            guiches[3] = 0;
                        }

 
                        if (numPacientesParaMover > 1 && i != numPacientesParaMover - 1) {
                            pacientesParaMover[i] = pacientesParaMover[numPacientesParaMover - 1];
                        }
                        numPacientesParaMover--; 
                    } else {
                        i++; 
                    }
                }
            }
        } 
        ///desaparecer timer



        BeginDrawing();
        ClearBackground((Color){255, 255, 255, 255}); 

        if (batata == 0) {


               ///NOMES
            DrawRectangleRec(menuButtonSimulation, LIGHTGRAY);
            DrawText("Iniciar Simulacao", menuButtonSimulation.x + (menuButtonSimulation.width - MeasureText("Iniciar Simulacao", 20)) / 2,
                     menuButtonSimulation.y + (menuButtonSimulation.height - 20) / 2, 20, BLACK);

    
            DrawText("Nome do Paciente:", screenWidth / 2 - MeasureText("Nome do Paciente:", 20) / 2, nameInputBox.y - 25, 20, BLACK);
            DrawRectangleRec(nameInputBox, LIGHTGRAY);
            DrawRectangleLines((int)nameInputBox.x, (int)nameInputBox.y, (int)nameInputBox.width, (int)nameInputBox.height, BLACK);
            DrawText(inputName, (int)nameInputBox.x + 5, (int)nameInputBox.y + 10, 20, BLACK);

            

        
            DrawRectangleRec(menuButtonAddPatient, LIGHTGRAY);
            DrawText(buttonTextAddPatientMenu, menuButtonAddPatient.x + (menuButtonAddPatient.width - MeasureText(buttonTextAddPatientMenu, 20)) / 2,
                     menuButtonAddPatient.y + (menuButtonAddPatient.height - 20) / 2, 20, BLACK);

            ///NOMES


        } else if (batata == 1) { 
            ///guiches
            DrawRectangleRec(ate1, buttonColor);
            DrawRectangleRec(ate2, buttonColor);
            DrawRectangleRec(ate3, buttonColor);
           
            DrawTextureEx(pessoa, (Vector2){100, posya}, 0.0f, scaleFactor, WHITE);
            DrawText("Atendente 1", 70, posya - 20, 20, BLACK);      
            DrawTextureEx(pessoa, (Vector2){350, posya}, 0.0f, scaleFactor, WHITE);
            DrawText("Atendente 2", 320, posya - 20, 20, BLACK);          
            DrawTextureEx(pessoa, (Vector2){600, posya}, 0.0f, scaleFactor, WHITE);
            DrawText("Atendente 3", 570, posya - 20, 20, BLACK);           
            
            DrawRectangleRec(buttonRect1, YELLOW);
            DrawRectangleRec(buttonRect2, YELLOW);
            DrawRectangleRec(buttonRect3, YELLOW);
            DrawRectangleRec(buttonRect4, buttonColor); 

            int textWidth1 = MeasureText(buttonText1, 20);
            int textWidth4 = MeasureText(buttonText4, 20);

            DrawText(buttonText1, buttonRect1.x + (buttonRect1.width - textWidth1) / 2, buttonRect1.y + (buttonRect1.height - 20) / 2, 20, BLACK);
            DrawText(buttonText2, buttonRect2.x + (buttonRect2.width - textWidth1) / 2, buttonRect2.y + (buttonRect2.height - 20) / 2, 20, BLACK);
            DrawText(buttonText3, buttonRect3.x + (buttonRect3.width - textWidth1) / 2, buttonRect3.y + (buttonRect3.height - 20) / 2, 20, BLACK);
            DrawText(buttonText4, buttonRect4.x + (buttonRect4.width - textWidth4) / 2, filay - 30, 20, BLACK);
            
            ///guiches

            ///filaimg
            DrawText("Fila de Pacientes:", comecox, filay - 30, 20, BLACK);

            Paciente filado;
   
            float currentX = comecox;
            for (int i = 0; i < Fila_size(&filaPacientes); i++) {
                if (Fila_peek_at(&filaPacientes, i, (char*)&filado)) {
                    float patientDrawX = currentX + (i * (espacox + (pessoa.width * textureScaleFactor)));
                    DrawTextureEx(pessoa, (Vector2){patientDrawX, filay}, 0.0f, textureScaleFactor, WHITE);
                    DrawText(filado.name, patientDrawX, filay + (pessoa.height * textureScaleFactor) + 5, 15, BLACK);
                }
            }
            ///fila img

            ///atend++timer
            for (int i = 0; i < numPacientesParaMover; i++) {
                DrawTextureEx(pessoa, (Vector2){pacientesParaMover[i].x, pacientesParaMover[i].y}, 0.0f, textureScaleFactor, WHITE);
                int nameWidth = MeasureText(pacientesParaMover[i].name, 15);
                DrawText(pacientesParaMover[i].name,
                         pacientesParaMover[i].x + (pessoa.width * textureScaleFactor / 2) - (nameWidth / 2),
                         pacientesParaMover[i].y + (pessoa.height * textureScaleFactor) ,
                         15, BLUE);

                if (pacientesParaMover[i].moveType != 0) {
                    DrawText(TextFormat("%.1f / %.1f", pacientesParaMover[i].moveTimer, pacientesParaMover[i].atend),
                             pacientesParaMover[i].x, pacientesParaMover[i].y + 70, 20, BLACK);
                }
            }
            ///atend++timer

 
            DrawText(TextFormat("Guiche 1: %s", guiches[1] == 0 ? "Livre" : "Ocupado"), 0, 90, 5, BLACK);
            DrawText(TextFormat("Guiche 2: %s", guiches[2] == 0 ? "Livre" : "Ocupado"), 250, 90, 5, BLACK);
            DrawText(TextFormat("Guiche 3: %s", guiches[3] == 0 ? "Livre" : "Ocupado"), 500, 90, 5, BLACK);
        }

        EndDrawing();
    }

    UnloadTexture(pessoa);
    CloseWindow();
    return 0;
}