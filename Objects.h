#pragma once
#include"Global.h"
#include "main.h"
class Objects {
public: 
	Objects();
	~Objects();
	bool loadfile(int w,int h,int dvn,const char* filepath,SDL_Renderer* render, int red, int green, int blue);
	void rect(SDL_Renderer* render, int x, int y, int w, int h, int red, int green, int blue, int transparence);
	void free();
	void rendering(SDL_Renderer* render, int delay,int x, int y);
	int getw(), geth();
	void animation(int dividenum);
private:
	SDL_Texture* image;
	SDL_Rect objectdivide[10];
	SDL_Rect objectsize;
	int Width, Height,frame,dividenum;
};

