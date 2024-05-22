
#ifndef _COLLISION__H
#define _COLLISION__H
  bool isCollision (SDL_Rect rect1,SDL_Rect rect2)
{
    return SDL_HasIntersection(&rect1, &rect2);
}

bool isCollisionwithmonster(int x1,int y1,int manwidth,int manheight,int x2,int y2,int monsterwidth,int monsterheight)
{

    SDL_Rect manRect = {x1,y1,manwidth,manheight };
    SDL_Rect monsterRect = { x2,y2,monsterwidth,monsterheight };
    if(isCollision(manRect,monsterRect))
    {
        return true;
    }
    return false;
}

#endif // _COLLISION__H
