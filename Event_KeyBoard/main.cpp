#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include"def.h"
#include"graphics.h"
using namespace std;
int x = SCREEN_WIDTH/2;
int y = SCREEN_HEIGHT/2;
int w = 250/4;
int h = 175/4;
const int step = 50;

void waitUntilKeyPressed(){
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char* argv[]){
      int numberMove = 0;
    char scoreString[10];
    Graphics graphic;
    graphic.init();
    Mix_Music* gMusic = graphic.loadMusic("spongebob_music.mp3");
    graphic.playMusic(gMusic);
    Mix_Chunk* gSound= graphic.loadSound("jump.wav");


    TTF_Font* font = graphic.loadFont("arial.ttf", 20);
    SDL_Color color = {255, 255, 0, 0};
    SDL_Texture* helloText = graphic.renderText(scoreString, font, color);


    SDL_Texture* background = graphic.loadTexture("bikiniBottom.jpg");
    graphic.prepareScene(background);

    SDL_Texture* spongebob = graphic.loadTexture("Spongebob.png");
    graphic.renderTexture(spongebob,x,y,w,h);

    graphic.presentScene();
    waitUntilKeyPressed();


    SDL_Event event1;
    bool flag=true;
    while(flag){
        while(SDL_PollEvent(&event1)){
        if(event1.type==SDL_QUIT){
                flag=false;
            return 0;
        }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                if(currentKeyStates[SDL_SCANCODE_UP]) {
                        graphic.prepareScene(background);
                        cerr<<"UP"<<endl;y-=step;graphic.renderTexture(spongebob,x,y,w,h);
                        graphic.playSound(gSound);
                        numberMove++;
                        sprintf(scoreString," DIEM SO: %d %s",numberMove,"UP");
                        SDL_Texture* helloText = graphic.renderText(scoreString, font, color);

                        graphic.renderTexture(helloText, 200, 200,800,200);

                }

                if(currentKeyStates[SDL_SCANCODE_DOWN]){
                        graphic.prepareScene(background);
                        cerr<<"DOWN"<<endl;y+=step;graphic.renderTexture(spongebob,x,y,w,h);
                        graphic.playSound(gSound);
                        numberMove++;
                        sprintf(scoreString," DIEM SO: %d %s",numberMove,"DOWN");
                        SDL_Texture* helloText = graphic.renderText(scoreString, font, color);

                        graphic.renderTexture(helloText, 200, 200,800,200);
                }
                if(currentKeyStates[SDL_SCANCODE_LEFT]){
                    graphic.prepareScene(background);
                cerr<<"LEFT"<<endl;x-=step;graphic.renderTexture(spongebob,x,y,w,h);
                graphic.playSound(gSound);
                numberMove++;
                sprintf(scoreString," DIEM SO: %d %s",numberMove,"LEFT");
                SDL_Texture* helloText = graphic.renderText(scoreString, font, color);

                graphic.renderTexture(helloText, 200, 200,800,200);
                }
                if(currentKeyStates[SDL_SCANCODE_RIGHT]){
                    graphic.prepareScene(background);
                    numberMove++;
                    sprintf(scoreString," DIEM SO: %d %s",numberMove,"RIGHT");
                    SDL_Texture* helloText = graphic.renderText(scoreString, font, color);

                 cerr<<"RIGHT"<<endl;x+=step;graphic.renderTexture(spongebob,x,y,w,h);
                 graphic.playSound(gSound);
                 graphic.renderTexture(helloText, 200, 200,800,200);
                }
                graphic.presentScene();
                }

            }


        SDL_DestroyTexture(spongebob);
        spongebob = NULL;
        SDL_DestroyTexture(background);
        background = NULL;

 if (gSound != nullptr) Mix_FreeChunk( gSound);

       SDL_DestroyTexture( helloText );
    TTF_CloseFont( font );
    helloText = NULL;

    graphic.quitSDL();
    return 0;

}


