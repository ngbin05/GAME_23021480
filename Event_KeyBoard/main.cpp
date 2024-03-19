#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
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

    Graphics graphic;
    graphic.init();
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
                }

                if(currentKeyStates[SDL_SCANCODE_DOWN]){
                        graphic.prepareScene(background);
                        cerr<<"DOWN"<<endl;y+=step;graphic.renderTexture(spongebob,x,y,w,h);
                }
                if(currentKeyStates[SDL_SCANCODE_LEFT]){
                    graphic.prepareScene(background);
                cerr<<"LEFT"<<endl;x-=step;graphic.renderTexture(spongebob,x,y,w,h);
                }
                if(currentKeyStates[SDL_SCANCODE_RIGHT]){
                    graphic.prepareScene(background);
                 cerr<<"RIGHT"<<endl;x+=step;graphic.renderTexture(spongebob,x,y,w,h);
                }
                graphic.presentScene();
                }

            }


        SDL_DestroyTexture(spongebob);
        spongebob = NULL;
        SDL_DestroyTexture(background);
        background = NULL;




    graphic.quitSDL();
    return 0;

}


