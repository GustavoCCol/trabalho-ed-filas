#include "raylib.h"


int main(void){
    const int screenWidth = 800;
    const int screenHeight = 400;
    float scaleFactor = 0.10f;
    float posx,posy;
    int a,b,c;
    a=10;
    b=20;
    char numberAsString[32];
    c=somar(a,b);
    
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Texture pessoa;
    pessoa= LoadTexture("./pessoa3.png");
    SetTargetFPS(60); 
   
    posx=20.0f;
    posy=0.0f;
    
    
    TFila fila;
    int d,i;
    char aux1;
    bool result;
    
    Fila_create(&fila, sizeof(char), 5, TYPE_PILHA);
    d='1';
    Fila_put(&fila,&d);
    Fila_get(&fila,&aux1);

    
    
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground((Color){ 255, 255, 255, 100 });
            //sprintf(numberAsString, "%d", c);
 
            ///DrawText(numberAsString, 80, 80, 40, DARKBLUE);
            DrawText(TextFormat("%c",aux1), 90, 90, 90, BLACK);
            
            DrawTextureEx(pessoa, (Vector2){ posx, posy }, 0.0f, scaleFactor, WHITE);
            DrawText("masssaaaaaaaaaaaaa",posx,posy+50,20,BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}