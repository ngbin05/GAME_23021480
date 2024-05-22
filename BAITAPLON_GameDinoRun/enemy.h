
#ifndef _ENEMY_H
#define _ENEMY_H

struct enemy{
    int posX,posY;
    int type,speed;
    void move()
    {
        posX-=speed;
        if(type==FLY&&posX<=-100)
        {
            posX=SCREEN_WIDTH+rand()%400;
            posY=SCREEN_HEIGHT/2+rand()%150;
        }
        else if(type==RUN&&posX<=-100)
        {
            posX=SCREEN_WIDTH+rand()%400;
        }
    }

};

#endif // _ENEMY_H
