
#ifndef _BACKGROUND_H
#define _BACKGROUND_H
#include "graphics.h"
#include "defs.h"

struct Background {
    ScrollingBackground layer2;
    ScrollingBackground layer3;
    ScrollingBackground layer4;
    ScrollingBackground layer5;
    ScrollingBackground layer6;

    int speed;

    void loadTextures(Graphics &graphics) {
        layer2.setTexture(graphics.loadTexture("images\\1.png"));
        layer3.setTexture(graphics.loadTexture("images\\2.png"));
        layer4.setTexture(graphics.loadTexture("images\\3.png"));
        layer5.setTexture(graphics.loadTexture("images\\4.png"));
        layer6.setTexture(graphics.loadTexture("images\\5.png"));
    }
    void renderBackgrounds(Graphics &graphics)
    {


        layer6.scroll(speed+2);
        graphics.render(layer6);
        layer5.scroll(speed+3);
        graphics.render(layer5);
        layer4.scroll(speed+4);
        graphics.render(layer4);
        layer3.scroll(speed+5);
        graphics.render(layer3);
        layer2.scroll(speed+5);
        graphics.render(layer2);


    }

    void destroyTextures() {

        SDL_DestroyTexture(layer2.texture);
        SDL_DestroyTexture(layer3.texture);
        SDL_DestroyTexture(layer4.texture);
        SDL_DestroyTexture(layer5.texture);
        SDL_DestroyTexture(layer6.texture);
    }
};
#endif // _BACKGROUND__H

