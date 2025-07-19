#include "raylib.h"







int main(void){
    const int screenWidth = 800;
    const int screenHeight = 400;
    float scaleFactor = 0.10f;
    float posya,posxa;
    int a,b,c;
    a=10;
    b=20;
    char numberAsString[32];
    c=somar(a,b);
    
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Texture pessoa;
    pessoa= LoadTexture("./pessoa3.png");
    SetTargetFPS(60);
    float posx[15];
    float posy[15];
    posx[1]=700.0f;
    posy[1]=300.0f;
    
    posxa=0.0f;
    posya=30.0f;
    
    //posxt=700.0f;
    //posyt=350.0f;
    
    
    TFila fila;
    int d,i,j;
    char aux1;
    bool result;
    i=0;
    Fila_create(&fila, sizeof(char), 5, TYPE_PILHA);
    d='1';
    Fila_put(&fila,&d);
    Fila_get(&fila,&aux1);
    const char* longText = "This is a very long sentence that needs to be truncated because it might not fit.";
    const char* shortText = "Short text.";
    
    int fontSize = 30;
    int boxWidth = 300;
    
    while(!WindowShouldClose()){
         if(posx[1]>350.0f){
            posx[1]-=10.0f;
            sleep(0.5);
         }

         if(i==1){
            if(posx[1]>100.0f){
                posx[1]-=10.0f;
            }
            if(posy[1]>100.0f){
                posy[1]-=10.0f;
            }
            sleep(0.5); 
        }
  
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            i+=1;
        }
        BeginDrawing();
        /// atendentes
        DrawTextureEx(pessoa, (Vector2){ posxa+100, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente1",posxa+70,posya-20,20,BLACK);
        
        DrawTextureEx(pessoa, (Vector2){ posxa+350, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente2",posxa+320,posya-20,20,BLACK);
        
        DrawTextureEx(pessoa, (Vector2){ posxa+600, posya }, 0.0f, scaleFactor, WHITE);
        DrawText("atendente3",posxa+570,posya-20,20,BLACK);
        ///atendentes
        
        
        
        
            ClearBackground((Color){ 255, 255, 255, 100 });
            //sprintf(numberAsString, "%d", c);
            ///DrawText(numberAsString, 80, 80, 40, DARKBLUE);
            //DrawText(TextFormat("%c",aux1), 90, 90, 90, BLACK);
            
            DrawTextureEx(pessoa, (Vector2){ posx[1], posy[1]}, 0.0f, scaleFactor, WHITE);
            //DrawText("masssaaaaaaaaaaaaa",posx,posy+50,20,BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}