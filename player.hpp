#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "track.hpp"

class Car{
  private:
    float x;
    float y;
    float speed;
    float max_speed;
    float angle;
    float height;
    float width; 
    bool offroad;
  public:
    Car(float startX, float startY);

    void DrawPlayer();
    void PlayerInput(float dt);
    void MovePlayer(float dt);
    void Update(float dt, const Pista &p);
    void KeepThisInsideScreen();
    void CheckCollision(const Pista &p);

    float GetX();
    float GetY();

    void SetX(float newX);
    void SetY(float newY);

    float GetHeight();
    float GetWidth();

};

#endif
