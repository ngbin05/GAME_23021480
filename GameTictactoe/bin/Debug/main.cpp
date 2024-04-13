#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"logic.h"
#include"defs.h"
#include"graphic.h"


int w=80,h=80;

using namespace std;



void waitUntilKeyPressed(){
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
        return;
        SDL_Delay(100);
    }
}

int main(int argc, char* argv[]){
    int x,y;
    Graphics graphic;
    graphic.init();
    SDL_Texture* background=graphic.loadTexture("img\\bikiniBottom.jpg");
    SDL_Texture* spongebob=graphic.loadTexture("img\\Spongebob.png");
    SDL_Texture* playbutton=graphic.loadTexture("img\\play.png");
    SDL_Texture* returnbutton=graphic.loadTexture("img\\bt.png");
    graphic.prepareScene(background);
    graphic.renderTexture(playbutton,290,450,80,80);
    graphic.presentScene();
    SDL_Event even;
    int n,m;
    while(true){
    SDL_PollEvent(&even);
    if(even.type==SDL_QUIT){
              return 0;
        }else if(even.type==SDL_MOUSEBUTTONDOWN){
            SDL_GetMouseState(&n,&m);
            if((n>=290&&n<=290+80)&&(m>=450&&m<=450+80)){
            graphic.prepareScene(background);
                break;

            }
        }
    }
graphic.renderTexture(returnbutton,0,0,80,80);
    Tictactoe game;
    game.init();
    graphic.renderGame(game);
    SDL_Event event;
    bool flag=true;
    while(flag){
        SDL_PollEvent(&event);
        SDL_GetMouseState(&x,&y);
        if(event.type==SDL_QUIT){
                flag=false;
            break;
        }else if(event.type==SDL_MOUSEBUTTONDOWN){

        SDL_GetMouseState(&x,&y);
        if((x>=0&&x<=80)&&(y>=0&&y<=80)){
            graphic.prepareScene(background);
            game.init();
            graphic.renderTexture(returnbutton,0,0,w,h);
            graphic.renderGame(game);

        }
        //SDL_Delay(100);
        graphic.renderTexture(returnbutton,0,0,w,h);
        int Row=x/CELL_SIZE-4;
        int Col=y/CELL_SIZE-4;
        if((Row>=0&&Row<3)&&(Col>=0&&Col<3)){
            game.move(Row,Col);
            graphic.renderGame(game);
            if(graphic.check(game)==false) {
                 graphic.renderTexture(spongebob,600-495/4,600-350/4,495/4,350/4);
            graphic.presentScene();
            //SDL_Event event2;
            SDL_PollEvent(&event);
            if(event.type==SDL_MOUSEBUTTONDOWN){
            SDL_GetMouseState(&x,&y);
        if((x<80)&&(y<80)) {
                continue;

        }
        else break;
            }
        }
    }
    }
    }

    waitUntilKeyPressed();
    SDL_DestroyTexture(background);
    background=nullptr;
    SDL_DestroyTexture(playbutton);
    playbutton=NULL;
    SDL_DestroyTexture(spongebob);
    spongebob=NULL;
    graphic.quitSDL();
    return 0;

}


