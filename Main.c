#include <raylib.h>


int main(void){
    InitWindow(800 ,400, "basic window"); // for initializing the window
    Vector2 position; 
    position.x = 400;
    position.y = 380;
    float playerspeed = 300;
    Vector2 enemypositon;
    enemypositon.x = 0;
    enemypositon.y = 0;
    float enemyspeed = 150;
    Vector2 ballspeed;
    ballspeed.x = 200;
    ballspeed.y =200;
    bool bricksexist[10];


    for (int i = 0; i < 10; i++){
        bricksexist[i]= true;
    }
    while (!WindowShouldClose()){
     float currentspeed =playerspeed;
    if (IsKeyDown(KEY_RIGHT)){
        position.x = position.x +(currentspeed *GetFrameTime());
    } 
    if (IsKeyDown(KEY_LEFT)){
        position.x = position.x -(currentspeed * GetFrameTime());
    }
    
     if (IsKeyDown(KEY_LEFT_SHIFT)){
        currentspeed = playerspeed * 2.0f;
    }

    if (IsKeyDown(KEY_A)){
        position.x = position.x - (currentspeed * GetFrameTime());
    }
    if (IsKeyDown(KEY_LEFT_SHIFT)){
        currentspeed = playerspeed * 2.0f;
    }
    if (IsKeyDown(KEY_D)){
        position.x = position.x + (currentspeed * GetFrameTime());
    }
    if (position.x < 50){
        position.x = 50;
    }
    if (position.x > 750){
        position.x = 750;
    }
    if (position.y < 20){
        position.y = 20;
    }
    if (position.y > 380){
        position.y = 380;
    }

    enemypositon.x += ballspeed.x * GetFrameTime();
    enemypositon.y += ballspeed.y * GetFrameTime();

    if (enemypositon.x > 800){
        ballspeed.x *= -1;
    }
    if (enemypositon.x < 0){
        ballspeed.x *= -1;
    }

    if (enemypositon.y < 0){
        ballspeed.y *= -1;
    }
    if (enemypositon.y > 400 ){
        enemypositon.y = 200;
        enemypositon.x = 400; 
    }
    Rectangle paddle = {
        position.x -50 , 370 , 100 ,20
    };


    if (CheckCollisionCircleRec(enemypositon ,15 , paddle)){
        ballspeed.y = -200;
    }
    for (int i = 0; i<10; i++){
        if(bricksexist[i]){
            Rectangle brickrect = {20 + i*80,40,70,20};
        
        if (CheckCollisionCircleRec(enemypositon,15,brickrect)){
            bricksexist[i] =false;
            ballspeed.y*= -1;
        }

        }
    }
    

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        for ( int i = 0 ; i <10; i++){
            if (bricksexist[i]){
                DrawRectangle(20 +i*80 , 40 , 70 , 20 ,ORANGE);
            }
        }
        
        DrawRectangle(position.x -50 , 370 , 100 ,20 , BLUE);
        DrawCircleV(enemypositon , 15, MAROON);
        EndDrawing();

    }
    CloseWindow();
    


    return 0; 
}