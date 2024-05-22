
#ifndef _DINO__H
#define _DINO__H
#include "defs.h"
#include"music.h"
#include "graphics.h"
struct character{
    int posX,posY;
    int canjump;
    Sprite dino;

void render(Graphics&graphics,SDL_Texture*charTexture)
    {
        dino.init(charTexture,6,CHAR_CLIPS);
        graphics.render2(posX,posY,dino);
        dino.tick();
    }
    void renderEx(Graphics&graphics,SDL_Texture*charTexture)
    {
        dino.init(charTexture,6,CHAR_CLIPS);
        dino.tick();
        graphics.renderEx(posX,posY,dino,90);

    }
void move(SDL_Event &e){
   const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if(posY>=470) canjump=20;
    if(currentKeyStates[SDL_SCANCODE_UP]&&canjump>0){
            Mix_Chunk* jumpSound = loadSound("sounds\\jump_audio.wav");

       if(posY>470&&posY<=500) play(jumpSound);

            canjump--;
    if(posY>=300) posY-=15;
    } else if(posY<=470) posY+=15;
}

void dinosour(Graphics&graphics,SDL_Texture*charTexture,SDL_Event &e)
    {
        render(graphics,charTexture);
        move(e);
    }
};

#endif // _GRAPHICS__H
