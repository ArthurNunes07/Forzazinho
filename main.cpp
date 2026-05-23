#include "player.hpp"
//compilacao: g++ main.cpp player.cpp track.cpp -o jogo -lraylib -lopengl32 -lgdi32 -lwinmm
//./jogo

int main(){

    InitWindow(800, 600, "Forzazinho");

    Car player(400,300);
    Pista p;
    
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        player.Update(dt, p);
        
        BeginDrawing();
        ClearBackground(DARKGRAY);
        p.Draw();
        player.DrawPlayer();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
