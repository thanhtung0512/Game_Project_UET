#include"needed.h"
#include"BaseObject.h"

BaseObject :: BaseObject (){
    p_object_= NULL;
    rect_.x=0;
    rect_.y=0;
    rect_.w=0;
    rect_.h=0;
}

BaseObject :: ~BaseObject(){
    Free();
}

bool BaseObject :: loadImg( std ::string path, SDL_Renderer * screen ){
    SDL_Texture * new_texture=NULL;
    SDL_Surface * tmp_surface = IMG_Load(path.c_str());
    if ( tmp_surface !=NULL){
        SDL_SetColorKey (  tmp_surface,SDL_TRUE,SDL_MapRGB ( tmp_surface->format ,COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen,tmp_surface);
        if ( new_texture !=NULL){
            // 
            rect_.w= tmp_surface->w;
            rect_.h= tmp_surface->h;
        }
        SDL_FreeSurface ( tmp_surface);    
    }
    p_object_ = new_texture;   
    if ( p_object_ ==NULL) return 0;
    else return 1;   
}

void BaseObject :: Render (SDL_Renderer * des  ){
    SDL_Rect renderquad = { rect_.x , rect_.y , rect_.w, rect_.h};
    SDL_RenderCopy (des,p_object_,NULL,&renderquad);
}

void BaseObject::Free(){
    if ( p_object_!=NULL){
        SDL_DestroyTexture(p_object_);
        p_object_=NULL;
        rect_.w=0;
        rect_.h=0;
    }
}