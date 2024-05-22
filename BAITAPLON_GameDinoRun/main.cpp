#include "graphics.h"
#include "background.h"
#include "dino.h"
#include "enemy.h"
#include "collision.h"
#include "music.h"
#include"text.h"
#include"highScore.h"
using namespace std;
int main(int argc, char* argv[])
{
    Graphics graphics;
    graphics.init();
    SDL_Texture* muteButton = graphics.loadTexture("images\\mute.png");
    SDL_Texture* unmuteButton = graphics.loadTexture("images\\unmute.png");
    SDL_Texture* muteButton1 = graphics.loadTexture("images\\mute1.png");
    SDL_Texture* unmuteButton1 = graphics.loadTexture("images\\unmute1.png");
    SDL_Texture* playButton = graphics.loadTexture("images\\play.png");
    SDL_Texture* playButton1 = graphics.loadTexture("images\\play1.png");
    SDL_Texture* exitButton = graphics.loadTexture("images\\exit.png");
    SDL_Texture* exitButton1 = graphics.loadTexture("images\\exit1.png");
    SDL_Texture* menu = graphics.loadTexture("images\\menu.png");
    SDL_Texture* dino2 = graphics.loadTexture("images\\dino_right.png");
    SDL_Texture* dino1 = graphics.loadTexture("images\\dino_left.png");
    graphics.prepareScene(menu);
    graphics.renderTexture(playButton,SCREEN_WIDTH/2-58,SCREEN_HEIGHT/2-58);
    graphics.renderTexture(exitButton,0,0);
    graphics.renderTexture(muteButton,SCREEN_WIDTH-110,0);


    TTF_Font* font = graphics.loadFont("RAVIE.ttf", size2);
    SDL_Color color = {255, 100, 150, 255};
    SDL_Texture* menuText = graphics.renderText("DINO_RUN",font,color);
    graphics.renderTexture(menuText,160,50);
     int x,y,i=10;
    bool isRunning=true;

    while(isRunning){
        Mix_Music* gMenu=graphics.loadMusic("sounds\\menu_audio.wav");
         Mix_Chunk* gButton=loadSound("sounds\\button_audio.ogg");
            SDL_Event e0;
            bool isMusic = true;
            graphics.play(gMenu);
        while(true ) {
            graphics.renderTexture(menuText,160,50);
            graphics.renderTexture(dino1,SCREEN_WIDTH/2-340-100,SCREEN_HEIGHT-282);
            graphics.renderTexture(dino2,SCREEN_WIDTH/2+100,SCREEN_HEIGHT-282);
            graphics.presentScene();
            SDL_PollEvent(&e0);
            if( e0.type == SDL_QUIT ){
                return 0;
            }
            if(isMusic==false) Mix_PauseMusic();
            else Mix_ResumeMusic();
            SDL_GetMouseState(&x,&y);
            if(x>=SCREEN_WIDTH/2-58&&x<=SCREEN_WIDTH/2+58&&y>=SCREEN_HEIGHT/2-58&&y<=SCREEN_HEIGHT/2+58)
            {
                graphics.prepareScene(menu);
                graphics.renderTexture(playButton1,SCREEN_WIDTH/2-51,SCREEN_HEIGHT/2-51);
                graphics.renderTexture(exitButton,5,5);
                graphics.renderTexture(muteButton,SCREEN_WIDTH-110,0);
            }
            else if(x>=0&&x<=100&&y>=0&&y<=100){
                  graphics.prepareScene(menu);
                graphics.renderTexture(exitButton1,5,5);
                graphics.renderTexture(playButton,SCREEN_WIDTH/2-58,SCREEN_HEIGHT/2-58);
                if(isMusic == true) graphics.renderTexture(muteButton,SCREEN_WIDTH-110,0);
                else graphics.renderTexture(unmuteButton,SCREEN_WIDTH-110,0);
            }else if(x>=SCREEN_WIDTH-110&&x<=SCREEN_WIDTH&&y>=0&&y<=110){
                 graphics.prepareScene(menu);
                graphics.renderTexture(exitButton,5,5);
                graphics.renderTexture(playButton,SCREEN_WIDTH/2-58,SCREEN_HEIGHT/2-58);
                if(isMusic == true) graphics.renderTexture(muteButton1,SCREEN_WIDTH-110,0);
                else graphics.renderTexture(unmuteButton1,SCREEN_WIDTH-110,0);

            } else{
                graphics.prepareScene(menu);
                graphics.renderTexture(exitButton,5,5);
                graphics.renderTexture(playButton,SCREEN_WIDTH/2-58,SCREEN_HEIGHT/2-58);
                if(isMusic == true) graphics.renderTexture(muteButton,SCREEN_WIDTH-110,0);
                else graphics.renderTexture(unmuteButton,SCREEN_WIDTH-110,0);
            }

            if(e0.type==SDL_MOUSEBUTTONDOWN){
            if(x>=SCREEN_WIDTH/2-58&&x<=SCREEN_WIDTH/2+58&&y>=SCREEN_HEIGHT/2-58&&y<=SCREEN_HEIGHT/2+58){
                    play(gButton);
                Mix_FreeMusic(gMenu);
                break;
            }
            if(x>=0&&x<=100&&y>=0&&y<=100){
                 return 0;
            }
            if(x>=SCREEN_WIDTH-110&&x<=SCREEN_WIDTH&&y>=0&&y<=110){
                 isMusic = !isMusic;

            }

            }
    }

      bool quit=false;



    int frame(0);
    int speed=5;
    character dino;
    dino.posX=400;
    dino.posY=470;
    SDL_Texture*charTexture=graphics.loadTexture("images\\char.png");
    SDL_Texture*cactusTexture=graphics.loadTexture("images\\Cactus.png");
    SDL_Texture*batTexture=graphics.loadTexture("images\\Flying (46x30).png");
    SDL_Texture*loseTexture=graphics.loadTexture("images\\lose.png");
    SDL_Texture*tombTexture=graphics.loadTexture("images\\tomb.png");
    Mix_Music* gMusic = graphics.loadMusic("sounds\\bkgr_audio.wav");
    Mix_Chunk* gdeath=loadSound("sounds\\lose_sound.wav");
    TTF_Font* font = graphics.loadFont("arial.ttf", size1);
    SDL_Color color = {255, 0, 0, 255};
    renderScore(graphics,frame,font,color,0,0);
    enemy bat;
    bat.posX=900;
    bat.posY=SCREEN_HEIGHT/2;
    bat.type=FLY;

    Sprite bats;
    bats.init(batTexture,7,BAT_CLIPS);
    enemy cactus1;
    cactus1.posX=1100;
    cactus1.posY=468;

    cactus1.type=RUN;
    enemy cactus;
    cactus.posX=700;
    cactus.posY=468;

    cactus.type=RUN;
    enemy cactus2;
    cactus2.posX=1500;
    cactus2.posY=468;

    cactus2.type=RUN;

    Background background;
    background.speed=0;
    background.loadTextures(graphics);
    SDL_Event e;

    while(!quit){
        graphics.play(gMusic);
    background.speed=speed-5;
    bat.speed=speed;
    cactus1.speed=speed;
    cactus.speed=speed;
    cactus2.speed=speed;
             while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT )
            {
                quit = true;
                isRunning=false;
            }

    }
    frame++;
    if(frame%100==0) speed++;

    SDL_Texture* scoreText = graphics.renderText("SCORE: "+std::to_string(frame),font,color);
    graphics.renderTexture(scoreText,0,0);
    background.renderBackgrounds(graphics);
    dino.dinosour(graphics,charTexture,e);
    graphics.renderTexture(cactusTexture,cactus.posX,cactus.posY);
    graphics.renderTexture(cactusTexture,cactus1.posX,cactus1.posY);
    graphics.renderTexture(cactusTexture,cactus2.posX,cactus2.posY);
    cactus.move();
    cactus1.move();
    cactus2.move();
    graphics.render2(bat.posX,bat.posY,bats);
    bats.tick();
    bat.move();
    graphics.drawRect(dino.posX+8,dino.posY+8,35,41);
    graphics.drawRect(cactus1.posX+5,cactus1.posY,50,58);
    graphics.drawRect(bat.posX+15,bat.posY,55,40);
    renderScore(graphics,frame,font,color,0,0);
    if(isCollisionwithmonster(dino.posX+8,dino.posY+8,35,41,cactus.posX+5,cactus.posY,50,58)||isCollisionwithmonster(dino.posX+8,dino.posY+8,35,41,cactus1.posX+5,cactus1.posY,50,58)||isCollisionwithmonster(dino.posX+8,dino.posY+8,35,41,cactus2.posX+5,cactus2.posY,50,58)||isCollisionwithmonster(dino.posX+8,dino.posY+8,35,41,bat.posX+15,bat.posY,55,40))
            {
                play(gdeath);
                Mix_FreeMusic(gMusic);
                graphics.prepareScene(menu);
                background.loadTextures(graphics);
                graphics.renderTexture(tombTexture,dino.posX-200,dino.posY-350);
                dino.renderEx(graphics,charTexture);
                 renderScore(graphics,frame,font,color,dino.posX-50,dino.posY-70);
                 graphics.renderTexture(loseTexture,40,0);
                graphics.presentScene();
                quit=true;
                isRunning=false;

                isRunning=waitUntilKeyPressed();
                play(gButton);


            }
    graphics.presentScene();
    SDL_Delay(24);

    }
    background.destroyTextures();
    }
    graphics.quit();




}
