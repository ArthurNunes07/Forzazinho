#include "player.hpp"
#include "track.hpp"
#include <cmath>


Car::Car(float startX, float startY): x(startX), y(startY) {

    speed = 0;
    max_speed = 500;
    angle = 0;
    width = 60;
    height = 30;
    offroad = false;
}

void Car::PlayerInput(float dt){

    float acceleration = 300;

    if(offroad == true){
        acceleration = 110;
    }
    if(fabs(speed) > 5){
        if(IsKeyDown(KEY_D)){
            angle += 100 * dt;
        }

        if(IsKeyDown(KEY_A)){
            angle -=100 * dt;
        }
    }
    if(IsKeyDown(KEY_W)){
        speed += acceleration * dt;
        if(speed > max_speed){
            speed = max_speed;
        }

    }else if(IsKeyDown(KEY_S)){
        speed -= 400 * dt;
        if(speed < 0){
            speed = 0;
        }
    }else{
        speed *= 0.99f;
        if(fabs(speed) < 1){
            speed = 0;
        }
    }
}

void Car::MovePlayer(float dt){
    float rad = angle * DEG2RAD;
    x += cos(rad) * speed * dt;
    y += sin(rad) * speed * dt;
}

void Car::DrawPlayer(){
    Rectangle carRect = {x, y, (float)width, (float)height};
    Vector2 origin = {width/2.0f, height/2.0f};
    DrawRectanglePro(carRect, origin, angle, BLUE);
}

void Car::Update(float dt, const Pista &p){
    PlayerInput(dt);
    MovePlayer(dt);
    CheckCollision(p);
    KeepThisInsideScreen();
}
float Car::GetX(){
    return x;
}

float Car::GetY(){
    return y;
}

void Car::SetX(float newX){
    x = newX;
}

void Car::SetY(float newY){
    y = newY;
}

float Car::GetHeight(){
    return height;
}
float Car::GetWidth(){
    return width;
}

void Car::CheckCollision(const Pista &p){
    float margem = 15;
    float car_left = x - width/2 + margem;
    float car_right = x + width/2 - margem;

    offroad = false;
    if((car_left < p.GetX()) || (car_right > p.GetX()+ p.GetWidth())){
        offroad = true;
        speed *= 0.95f;
    }    
}

void Car::KeepThisInsideScreen(){

    if(x > 800 - width/2)
        x = 800 - width/2;

    if(x < width/2)
        x = width/2;

    if(y >= 600 - height/2)
        y = 600 - height/2;

    if(y < height/2)
        y = height/2;
}
