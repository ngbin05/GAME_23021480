#include<bits/stdc++.h>
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
    ScrollingBackground bgr;
    bgr.setTexture(graphic.loadTexture("origbig.png"));
    SDL_Texture* object2=graphic.loadTexture("helicopter_2.png");
     SDL_Texture* object1=graphic.loadTexture("helicopter_1.png");

    SDL_Event e;
    bool quit = false;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }
        SDL_GetMouseState(&x,&y);
        cerr<<x<<" "<<y<<endl;
        x-=55;
        y-=15;

             graphic.render(bgr);
             if(x<SCREEN_WIDTH/2) graphic.renderTexture(object1,x,y);
             else graphic.renderTexture(object2,x,y);
            graphic.presentScene();
            if(x>SCREEN_WIDTH*0.5){
        int num=abs(x-SCREEN_HEIGHT*0.5);
        bgr.scroll(num/20);
        graphic.render(bgr);
          graphic.renderTexture(object2,x,y);
        graphic.presentScene();
        }
        if(x<SCREEN_WIDTH*0.25){
        int num=abs(x-SCREEN_HEIGHT*0.25);
        bgr.scroll1(-num/15);
        graphic.render(bgr);
          graphic.renderTexture(object1,x,y);
        graphic.presentScene();
        }
    }
SDL_DestroyTexture(object1);
SDL_DestroyTexture(object2);
object1=NULL;
object2=NULL;
SDL_DestroyTexture( bgr.texture );
bgr.texture=NULL;



    graphic.quitSDL();
    return 0;

}


