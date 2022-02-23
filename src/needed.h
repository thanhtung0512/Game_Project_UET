#ifndef needed_h
#define needed_h
#include <SDL.h>
#include <stdio.h>
#include<iostream>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<windows.h>
#include<string>
#include<string.h>
#include<SDL_image.h>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720


#define SCREEN_BPP 32

#define COLOR_KEY_R 167
#define COLOR_KEY_G 175
#define COLOR_KEY_B 180

#define Render_Draw_Color  255

static SDL_Window * gWindow=NULL;
static SDL_Renderer * gRenderer=NULL;
static SDL_Event  gEvent ;

# endif