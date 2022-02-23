#ifndef BaseObject_h
#define BaseObject_h

#include"needed.h"

class BaseObject {

public :
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y ){ rect_.x = x; rect_.y=y;}
    SDL_Rect  getRect () const { return rect_;}
    SDL_Texture * getObject () const { return p_object_;}

    bool loadImg ( std ::string path, SDL_Renderer * screen );
    void Render( SDL_Renderer * des);
    void Free();

protected :
    SDL_Texture * p_object_ ;
    SDL_Rect  rect_;

};


#endif