#include "Character1.h"
#include "Global.h"
extern int input, order, turn,stunned1,stunned2;
extern int guess ;
extern int computer ;
character1::character1() {
	image = NULL;
	*divide = { NULL };
	objectsize = { NULL };
	Width = 0; Height = 0; frame = 0; dividenum = 0;
}
character1::~character1() {
	free();
}
void character1::free() {
	SDL_DestroyTexture(image);
	*divide = { NULL };
	image = NULL;
	objectsize = { NULL };
	Width = 0; Height = 0; dividenum = 0;
}
void character1::animation(int dividenum) {
	for (int j = 0; j < dividenum; j++) {
		divide[j].x = Width * j / dividenum;
		divide[j].y = 0;
		divide[j].w = Width / dividenum;
		divide[j].h = Height;
	}
}
bool character1::loadfile(int h,int dvn, const char* filepath, SDL_Renderer* render) {
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(filepath);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 61, 63, 65));
	if (surface != NULL) {
		texture = SDL_CreateTextureFromSurface(render, surface);
		Width = surface->w; Height = h;
		image = texture;
		dividenum = dvn;
		animation(dividenum);
		SDL_FreeSurface(surface);

	}
	return texture != NULL;
}

void character1::rendering(SDL_Renderer* render) {
	if (input == attack) {
		objectsize = { p2posx - 50,p1posy - 125,Width / dividenum,Height };
	}
	else if (input == stun) {
		objectsize = { p2posx - 50,p1posy - 55,Width / dividenum,Height };
	}
	else if (input == heal) {
		objectsize = { p1posx,p1posy,Width / dividenum,Height };
	}
	else if (input == attacked) {
		objectsize = { p1posx,p1posy - 150,Width / dividenum,Height };
	}
	else if (input == stunned) {
		objectsize = { p1posx,p1posy - 150,Width / dividenum,Height };
	}
	else {
		objectsize = { p1posx,p1posy - 145,(Width + 500) / dividenum,Height };
	}
	if (input == -1) {
		if (frame / 3 < dividenum) {
			SDL_RenderCopy(render, image, &divide[frame / 3], &objectsize);
			frame++;
		}
		else {
			frame = 0; SDL_RenderCopy(render, image, &divide[frame / 3], &objectsize);
		}
	}
	else {
		if (dividenum == 1) {
			if (frame / 30 < dividenum) {
				SDL_RenderCopy(render, image, &divide[frame / 30], &objectsize); frame++;
			}
			else {
				frame = 0;
			}
		}
		else {
			if (frame / 5 < dividenum) {
				SDL_RenderCopy(render, image, &divide[frame / 5], &objectsize);
				frame++;
			}
			else {
				frame = 0;
				if (stunned1 == 2) {
					changeinput(-1);
					changeorder(1);
					changeturn(1);
					changestun1(1);
				}
				else {
					changeinput(-1);
					changeorder(0);
					changeturn(2);
				}
				changeguess(0);
				changecomputer(0);
			}
		}
	}
}
