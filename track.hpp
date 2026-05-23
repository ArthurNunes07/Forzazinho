#ifndef TRACK_HPP
#define TRACK_HPP

#include "raylib.h"

class Pista{
  private:
    int x;
    int y;
    int width;
    int height;

  public:
    Pista();

    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;
    void Draw();

};












#endif