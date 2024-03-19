/*#ifndef BULLET_H

#define BULLET_H

#include"graphics.h"
#inlcude<iostream>
#include<vector>
#include<def.h>

struct Bullet::graphics{
SDL_Rect rect;
int speed;
};
vector<int> bullets;
Bullet* createBullet(int x,int y,int speed){
Bullet* bullet= new Bullet();
bullet->rect.x = x;
bullet->rect.y = y;
bullet->rect.w = 20;
bullet->rect.h = 10;
bullet->speed = 10;
}
void drawBullet(Bullet* bullet, SDL_Renderer* renderer){
SDL_SetRenderDrawColor(renderer,255,0,255,255);
SDL_RenderFillRect(renderer,bullet->rect);
}
void mouseButton(SDL_MouseButtonEvent event){
Bullet = createBullet(event.x,event.y,10.0f)
}

void updateBullets() {
  for (Bullet& bullet : bullets) {


    if (bullet.x < 0 || bullet.x > SCREEN_WIDTH || bullet.y < 0 || bullet.y > SCREEN_HEIGHT) {
      bullet.erase(&bullet);
    }
  }
}
#endif*/
