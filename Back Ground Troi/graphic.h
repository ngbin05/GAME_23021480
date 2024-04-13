
#ifndef GRAPHICS_H

#define GRAPHICS_H

#include<SDL.h>
#include<SDL_image.h>
#include"defs.h"
struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick() {
        currentFrame = (currentFrame + 1) % clips.size();
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
};


struct ScrollingBackground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;
      void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }

    void scroll1(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset > width ) { scrollingOffset = 0; }
    }
};



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
void renderTexture(SDL_Texture* texture, int x, int y){

    SDL_Rect dest;
        dest.x=x;
        dest.y=y;
        SDL_QueryTexture(texture,NULL,NULL,&dest.w,&dest.h);
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
void render(const ScrollingBackground& bgr) {
        renderTexture(bgr.texture, bgr.scrollingOffset, 0);
        renderTexture(bgr.texture, bgr.scrollingOffset - bgr.width, 0);
    }
void render1(const ScrollingBackground& bgr) {
        renderTexture(bgr.texture, bgr.scrollingOffset, 0);
        renderTexture(bgr.texture, bgr.scrollingOffset + bgr.width, 0);
    }
 void render(int x, int y, const Sprite& sprite) {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }

};


#endif
