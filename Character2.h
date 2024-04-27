#pragma once
#include "Global.h"
#include "main.h"
#include "Objects.h"
class character2 {
public:
	character2();
	~character2();
	enum pick {
		attacked, healed, stunned, attack, heal,stun
	};
	bool loadfile(int h,int dvn, const char* filepath, SDL_Renderer* render);
	void free();
	void rendering( SDL_Renderer* render);
	void animation(int dividenum);
private:
	SDL_Texture* image;
	SDL_Rect objectsize;
	SDL_Rect divide[10];
	int Width, Height, frame, dividenum;
};