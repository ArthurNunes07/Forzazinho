#include "track.hpp"

Pista::Pista(){
    x = 250;
    y = 0;
    width = 300;
    height = 600;
}

int Pista::GetX() const{
    return x;
}

int Pista::GetY() const{
    return y;
}

int Pista::GetWidth() const{
    return width;
}

int Pista::GetHeight() const{
    return height;
}

void Pista::Draw(){
    DrawRectangle(0, 0, 800, 600, GREEN);
    DrawRectangle(x, y, width, height, GRAY);       
}