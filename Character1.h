#pragma once
#include "Global.h"
#include "main.h"
#include "Objects.h"
class character1  {
public:
	character1();
	~character1();
	enum pick {
		attack, heal, stun, attacked, healed, stunned
	};
	bool loadfile(int h,int dvn, const char* filepath, SDL_Renderer* render);
	void free();
	void rendering( SDL_Renderer* render);
	void animation(int dividenum);
private:
	SDL_Texture* image;
	SDL_Rect divide[10];
	SDL_Rect objectsize;
	int Width, Height, frame,dividenum;
};


