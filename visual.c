#include "raylib.h"

void mover2(Texture pessoa, float x, float y) {
    y -= 5.0f;
    DrawTextureEx(pessoa, (Vector2){ x, y}, 0.1f, 0.1f, BLACK);
}

typedef struct {
    char name[10]; // Nome do paciente (máx. 9 chars + '\0')
    float x;        // Coordenada X (pode ser usada para lógica interna, não apenas exibição)
    float y;        // Coordenada Y (pode ser usada para lógica interna, não apenas exibição)
} Paciente;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Botão em raylib");

    // Posição e tamanho do botão
    Rectangle buttonRect1 = { 0.0f, 35.0f, 100, 30 };
    // buttonRect2 and buttonRect3 are declared but not used, kept for completeness
    Rectangle buttonRect2 = { 250.0f,35.0f, 100, 30 };
    Rectangle buttonRect3 = { 500.0f,35.0f, 100, 30 };
    Rectangle buttonRect4 = { 500.0f,262.5f, 150, 30 };
    const char* buttonText1 = "cache1";
    const char* buttonText2 = "cache2";
    const char* buttonText3 = "cache3";
    const char* buttonText4 = "novo paciente";
    Color buttonColor = LIGHTGRAY;

    bool statusAtivo = false;
    float scaleFactor = 0.10f;
    float textureScaleFactor = 0.10f;

    float posya, posxa;
   
 

    // Removed the redundant InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Texture pessoa;
    pessoa = LoadTexture("./pessoa3.png"); // Ensure 'pessoa3.png' is in the same directory as your executable
    SetTargetFPS(60);

    float posx[15];
    float posy[15];
    float posxb[3];
    float posyb[3];
    int cache[3];
    cache[0] = 0; // Corrected index from 1 to 0
    cache[1] = 0; // Corrected index from 2 to 1
    cache[2] = 0; // Corrected index from 3 to 2 (original was out of bounds)
    int cache2[3];
    cache2[0] = 0; // Corrected index from 1 to 0
    cache2[1] = 0; // Corrected index from 2 to 1
    cache2[2] = 0; // Corrected index from 3 to 2 (original was out of bounds)

    posx[1] = 1000.0f;
    posy[1] = 300.0f;
    posx[2] = 1000.0f;
    posy[2] = 300.0f;

    posxa = 0.0f;
    posya = 30.0f;

    //posxt=700.0f;
    //posyt=350.0f;

    // TFila fila; // TFila struct definition is missing, so these lines are commented out
    // int d, i, j;
    float x = 1000.0f, y = 300.0f;
    // char aux1;
    // bool result;
    int i = 0; // Initialized 'i' here, as it was used uninitialized in movement logic

    // Fila_create(&fila, sizeof(char), 5, TYPE_PILHA); // Queue functions not defined
    // d = '1';
    // Fila_put(&fila, &d);
    // Fila_get(&fila, &aux1);

    int fontSize = 30;
    int boxWidth = 300;
    float filay = 300.0f;  
    float espacox = 20.0f;  
    float comecox = 50.0f;  

    while (!WindowShouldClose()) {
        // --- Atualização ---

        Vector2 mousePoint = GetMousePosition();
        bool isMouseOverButton = CheckCollisionPointRec(mousePoint, buttonRect1);

        // Mudar a cor do botão ao passar o mouse
        if (isMouseOverButton) {
            buttonColor = GRAY;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                TraceLog(LOG_INFO, "Botão clicado!"); // Ação ao clicar no botão
                statusAtivo = !statusAtivo;
            }
        } else {
            buttonColor = LIGHTGRAY;
        }

        if (x > 350.0f && i != 1 && statusAtivo == false) {
            x -= 25.0f;
        }
        if (i != 2 && statusAtivo == true && cache[1] == 0) {
            cache2[1] = 1;
            if (y > 100.0f && y > 200.0f) { // Note: y > 100.0f && y > 200.0f simplifies to y > 200.0f
                y -= 5.0f;
            }
            if (x > 100.0f && y <= 200.0f) {
                x -= 5.0f;
            }
            if (x == 100.0f && y >= 125.0f) {
                y -= 5.0f;
            }
        }

        /*
        // Commented out old movement logic, as it was unused or for different states
        if(i==2){
            if(posy[1]>100.0f&&posy[1]>200.0f){
                posy[1]-=5.0f;
            }
            if(posx[1]>100.0f&&posy[1]<=200.0f){
                posx[1]-=5.0f;
            }
            if(posx[1]==100.0f&&posy[1]>=125.0f){
                posy[1]-=5.0f;
            }
        }

        if(i==3){
            if(posy[1]>100.0f&&posy[1]>200.0f){
                posy[1]-=5.0f;
            }
            if(posx[1]<600.0f&&posy[1]<=200.0f){
                posx[1]+=5.0f;
            }
            if(posx[1]==600.0f&&posy[1]>=125.0f){
                posy[1]-=5.0f;
            }
        }
        if(i==1){
            if(posy[1]>100.0f){
                posy[1]-=5.0f;
            }
        }*/

        BeginDrawing();

        ClearBackground((Color){ 255, 255, 255, 100 }); // Clear background with a light, semi-transparent white

        /// Atendentes
        DrawTextureEx(pessoa, (Vector2){ posxa + 100, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente1", posxa + 70, posya - 20, 20, BLACK);

        DrawTextureEx(pessoa, (Vector2){ posxa + 350, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente2", posxa + 320, posya - 20, 20, BLACK);

        DrawTextureEx(pessoa, (Vector2){ posxa + 600, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente3", posxa + 570, posya - 20, 20, BLACK);
        /// Atendentes

        // Draw Button
        DrawRectangleRec(buttonRect1, buttonColor);
        DrawRectangleRec(buttonRect2, buttonColor);
        DrawRectangleRec(buttonRect3, buttonColor);
        DrawRectangleRec(buttonRect4, buttonColor);
        // Centraliza o texto no botão (aproximadamente)
        int textWidth = MeasureText(buttonText1, 20);
        int textWidth2 = MeasureText(buttonText4, 20);
        DrawText("Fila de Clientes:", comecox, filay - 30, 20, BLACK);
        DrawText(buttonText1, buttonRect1.x + (buttonRect1.width - textWidth) / 2, buttonRect1.y + (buttonRect1.height - 20) / 2, 20, BLACK);
        DrawText(buttonText2, buttonRect2.x + (buttonRect2.width - textWidth) / 2, buttonRect2.y + (buttonRect2.height - 20) / 2, 20, BLACK);
        DrawText(buttonText3, buttonRect3.x + (buttonRect3.width - textWidth) / 2, buttonRect3.y + (buttonRect3.height - 20) / 2, 20, BLACK);
        DrawText(buttonText4, buttonRect4.x + (buttonRect4.width - textWidth2) / 2, filay-30 , 20, BLACK);
        // Desenha os Pacientes na Fila (requires TFila and queue functions to be defined and linked)
        DrawText("Fila de Clientes:", comecox, filay - 30, 20, BLACK);
        Paciente currentQueuedPaciente;
        float currentX = comecox;

        // The loop below will cause a compilation error if TFila and its functions are not defined.
        // It's commented out here to ensure the rest of the graphics work.
        /*
        for (int q_idx = 0; q_idx < Fila_size(&filaPacientes); q_idx++) {
            if (Fila_peek_at(&filaPacientes, q_idx, (char*)&currentQueuedPaciente)) {
                float displayX = currentX + (q_idx * (espacox + (pessoa.width * textureScaleFactor)));
                DrawTextureEx(pessoa, (Vector2){ displayX, filay }, 0.0f, textureScaleFactor, WHITE);
                DrawText(currentQueuedPaciente.name, displayX, filay + (pessoa.height * textureScaleFactor) + 5, 15, DARKGRAY);
            }
        }
        */

        // Draw the main moving 'pessoa' texture
        DrawTextureEx(pessoa, (Vector2){ x, y}, 0.0f, scaleFactor, WHITE);

        EndDrawing();
    }
    UnloadTexture(pessoa); // Unload the texture when the window closes
    CloseWindow();
    return 0;
}