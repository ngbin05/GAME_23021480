#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include"defs.h"
#include"graphic.h"
using namespace std;
int x = SCREEN_WIDTH/2;
int y = SCREEN_HEIGHT/2;

const int step = 20;

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
    graphic.renderTexture(spongebob,x,y);

    graphic.presentScene();


  /*  SDL_Event event1;
    bool flag=true;
    while(flag){
        SDL_PollEvent(&event1);
        if(event1.type==SDL_QUIT){
                flag=false;
            return 0;
        }
        else if(event1.type==SDL_KEYDOWN){
                graphic.prepareScene(background);
            switch(event1.key.keysym.scancode){
                case SDL_SCANCODE_UP: cerr<<"UP"<<endl;y-=step;graphic.renderTexture(spongebob,x,y,w,h);break;
                case SDL_SCANCODE_DOWN: cerr<<"DOWN"<<endl;y+=step;graphic.renderTexture(spongebob,x,y,w,h);break;
                case SDL_SCANCODE_LEFT: cerr<<"LEFT"<<endl;x-=step;graphic.renderTexture(spongebob,x,y,w,h);break;
                case SDL_SCANCODE_RIGHT: cerr<<"RIGHT"<<endl;x+=step;graphic.renderTexture(spongebob,x,y,w,h);break;
                }
                graphic.presentScene();
            }

        }*/


    SDL_Event event;
        int m,n;
    while(true){
        SDL_PollEvent(&event);
        if(event.type==SDL_QUIT){
            break;
            return 0;
        }
        SDL_GetMouseState(&m,&n);
            cerr<<m<<", "<<n<<endl;
            x=m-100;y=n-70;
            graphic.prepareScene(background);
            graphic.renderTexture(spongebob,x,y);
            graphic.presentScene();
   }







     SDL_DestroyTexture( spongebob );
        spongebob = NULL;
        SDL_DestroyTexture( background );
        background = NULL;




    graphic.quitSDL();
    return 0;

}


