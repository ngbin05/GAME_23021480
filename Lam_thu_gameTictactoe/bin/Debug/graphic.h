#ifndef GRAPHICS_H
#define GRAPHICS_H
#include"logic.h"
#include<SDL.h>
#include<SDL_image.h>
#include"defs.h"
#include<bits/stdc++.h>



struct Graphics{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* cell_empty,*cell_x,*cell_o;


void logErrorAndExit(const char* msg, const char* error){
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"%s %s", msg, error);
    IMG_Quit();
    SDL_Quit();
}


void init(){
    if(SDL_Init(SDL_INIT_EVERYTHING)!= 0) logErrorAndExit( "SDL_Init" , SDL_GetError());
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());
    if(!IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)) logErrorAndExit("SDL_image error:", IMG_GetError());
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr ) logErrorAndExit("CreateRenderer",SDL_GetError());
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    cell_x=loadTexture("img\\cell_x.png");
    cell_o=loadTexture("img\\cell_o.png");
    cell_empty=loadTexture("img\\cell_empty.png");

}

SDL_Texture* loadTexture(const char* filename){
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO," Initializing %s ", filename);

	SDL_Texture *texture = IMG_LoadTexture(renderer,filename);
	if (texture == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"%s", IMG_GetError());
    return texture;
    }
}
void renderTexture(SDL_Texture* texture, int x, int y,int w,int h){

    SDL_Rect dest;
        dest.x=x;
        dest.y=y;
        dest.w=w;
        dest.h=w;
        //SDL_QueryTexture(texture,NULL,NULL,&dest.w,&dest.h);
        SDL_RenderCopy(renderer, texture, NULL,&dest);
}

void renderGame(const Tictactoe &game){
for(int i=4;i<7;i++){
    for(int j=4;j<7;j++){
int x= i*CELL_SIZE;
int y=j*CELL_SIZE;
switch (game.board[i-4][j-4]){
case 0: renderTexture(cell_empty,x,y,CELL_SIZE,CELL_SIZE);break;
case -1: renderTexture(cell_o,x,y,CELL_SIZE,CELL_SIZE);break;
case 1: renderTexture(cell_x,x,y,CELL_SIZE,CELL_SIZE);break;
}
}

}
presentScene();
}
bool check(const Tictactoe &game){
for(int i=0;i<3;i++){
        int counnt=0;
        int coutt=0;
    for(int j=0;j<3;j++){
        if(game.board[i][j]==1) counnt++;
        if(game.board[i][j]==-1) counnt--;
        if(game.board[j][i]==1) coutt++;
        if(game.board[j][i]==-1) coutt--;
    }

    if(abs(counnt)==3) {
            SDL_SetRenderDrawColor(renderer,255,0,0,0);
        SDL_RenderDrawLine(renderer,(i+4)*CELL_SIZE+30,4*CELL_SIZE+30,(i+4)*CELL_SIZE+30,7*CELL_SIZE-30);
        presentScene();
        return false;
    }
     if(abs(coutt)==3) {
            SDL_SetRenderDrawColor(renderer,255,0,0,0);
        SDL_RenderDrawLine(renderer,4*CELL_SIZE+30,(i+4)*CELL_SIZE+30,7*CELL_SIZE-30,(i+4)*CELL_SIZE+30);
        presentScene();
        return false;
    }
}
int couut=0;
for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
                if(i==j){
        if(game.board[i][j]==1) couut++;
        if(game.board[i][j]==-1) couut--;
                }
        }
         if(abs(couut)==3) {
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderDrawLine(renderer,4*CELL_SIZE+30,4*CELL_SIZE+30,7*CELL_SIZE-30,7*CELL_SIZE-30);
        presentScene();
        return false;
    }
}
int coout=0;
for(int i=0;i<3;i++){
          if(game.board[i][2-i]==1) coout++;
          if(game.board[i][2-i]==-1) coout--;
        }
         if(abs(coout)==3) {
            SDL_SetRenderDrawColor(renderer,255,0,0,0);
        SDL_RenderDrawLine(renderer,7*CELL_SIZE-30,4*CELL_SIZE+30,4*CELL_SIZE+30,7*CELL_SIZE-30);
        presentScene();
        return false;
    }
    return true;


}
void prepareScene(SDL_Texture* background){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    }
void presentScene(){
    SDL_RenderPresent(renderer);
    }

void quitSDL(){
    SDL_DestroyTexture(cell_empty);
    cell_empty=nullptr;
    SDL_DestroyTexture(cell_o);
    cell_o= nullptr;
    SDL_DestroyTexture(cell_x);
    cell_x=nullptr;
    IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
    }
};

#endif GRAPHICS_H
