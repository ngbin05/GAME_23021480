#ifndef _TEXT__H
#define _TEXT__H

#include<SDL_ttf.h>
#include"graphics.h"
#include"defs.h"
#include<bits/stdc++.h>
#include"highScore.h"


void renderScore(Graphics &graphics,int frame,TTF_Font* font,SDL_Color color,int x,int y){
    SDL_Texture* scoreText = graphics.renderText("SCORE: "+std::to_string(frame),font,color);
    graphics.renderTexture(scoreText,x,y);
    int highScore = readHighScore(FILE_TEXT);
    if(highScore > frame){
        SDL_Texture* highScoreText = graphics.renderText("HIGH SCORE: "+std::to_string(highScore),font,color);
        graphics.renderTexture(highScoreText,x,y+30);
    }
    else{
        SDL_Texture* highScoreText = graphics.renderText("HIGH SCORE: "+std::to_string(frame),font,color);
        graphics.renderTexture(highScoreText,x,y+30);
        highScore = frame;
        saveHighScore(FILE_TEXT,frame);
    }
    graphics.presentScene();
}

#endif // _TEXT__H
