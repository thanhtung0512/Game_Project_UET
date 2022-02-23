#include"needed.h"
#include"BaseObject.h"
BaseObject gBackground;

bool initData(){
    bool success =1;
    if (SDL_Init(SDL_INIT_EVERYTHING )<0){
        return false;
    }
    else {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
    }
    gWindow = SDL_CreateWindow ("Tung Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if (gWindow!=NULL){
        gRenderer=SDL_CreateRenderer ( gWindow,-1,SDL_RENDERER_ACCELERATED);
        if ( gRenderer == NULL){
            success=0;
        }else {
            SDL_SetRenderDrawColor(gRenderer,Render_Draw_Color,Render_Draw_Color,Render_Draw_Color,Render_Draw_Color);
            int imgFlags = IMG_INIT_PNG;
            if ( !(IMG_Init(imgFlags) && imgFlags)){
                success =0;
            }
        }
    }
    else success = 0;
    return success;
}

bool loadBackground (){
    bool ret = gBackground.loadImg("Test.png",gRenderer);
    if (ret==false) return false;
    else {
      return true;  
    }
}

void close (){
    gBackground.Free();
    SDL_DestroyRenderer(gRenderer);
    gRenderer=NULL;
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;
    SDL_Quit();
}

int main(int argc, char * agrv[]){
    // variable declare 
   if(initData()==false){
       return -1;
   }
   if (loadBackground()==false){
       return -1;
   }
   bool stop = false;
   while (stop == false ){
       SDL_RenderClear(gRenderer);
       while ( SDL_PollEvent(&gEvent)){
           if(gEvent.type==SDL_QUIT){
               stop=1;
           }
       }
       SDL_SetRenderDrawColor(gRenderer,Render_Draw_Color,Render_Draw_Color,Render_Draw_Color,Render_Draw_Color);
       gBackground.Render(gRenderer);
       SDL_RenderPresent(gRenderer);
   }
    close();
    return 0;
}