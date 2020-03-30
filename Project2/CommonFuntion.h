#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<Windows.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gScreen = NULL;
static SDL_Event gEvent;

//SCREEN
const int FRAME_PER_SECOND = 25; //fps
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

#define BLANK_TILE 0
#define TILE_SIZE 64
#define MAX_MAP_X 20
#define MAX_MAP_Y 10

typedef struct Input
{
	int left_;
	int right_;
	int up_;
	int down_;
}; 

typedef struct Map
{
	int start_x_;
	int start_y_;

	int max_x_;
	int max_y_;

	int tile[MAX_MAP_Y][MAX_MAP_X];
    const char* file_name;

};
#endif
