#ifndef GRAPHICS_H

#define GRAPHICS_H

#include<SDL.h>
#include<SDL_image.h>
#include"def.h"



struct Graphics{

SDL_Window* window;
SDL_Renderer* renderer;

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"%s %s", msg, error);
    IMG_Quit();
    SDL_Quit();

}

void init(){

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    logErrorAndExit("SDL_Init", SDL_GetError());
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());
    if(!IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG))
    logErrorAndExit("SDL_image error:", IMG_GetError());
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr ) logErrorAndExit("CreateRenderer",SDL_GetError());


    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

SDL_Texture* loadTexture(const char* filename){

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO," Dang tai len anh %s ", filename);

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
        dest.h=h;
        //SDL_QueryTexture(texture,NULL,NULL,&dest.w,&dest.h);
        SDL_RenderCopy(renderer, texture, NULL,&dest);
}
void prepareScene(SDL_Texture* background){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
}
void clearRender(){
SDL_RenderClear(renderer);
}

void presentScene(){
    SDL_RenderPresent(renderer);
}
void quitSDL(){
    IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void veHCN(int a,int b){
SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_Rect hcnday1;
    hcnday1.x=a;
    hcnday1.y=b;
    hcnday1.w=50;
    hcnday1.h=50;
    SDL_RenderDrawRect(renderer,&hcnday1);
    //SDL_RenderPresent(renderer);
}

};

#endif
