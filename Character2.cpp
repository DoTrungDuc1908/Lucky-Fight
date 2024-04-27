#include "Character2.h"
#include "Global.h"
extern int input, order, turn, stunned1, stunned2;
extern int guess ;
extern int computer ;
character2::character2() {
	image = NULL;
	*divide = { NULL };
	objectsize = { NULL };
	Width = 0; Height = 0; frame = 0; dividenum = 0;
}
character2::~character2() {
	free();
}
void character2::free() {
	SDL_DestroyTexture(image);
	*divide = { NULL };
	image = NULL;
	objectsize = { NULL };
	Width = 0; Height = 0; dividenum = 0;
}
void character2::animation(int dividenum) {
	for (int j = 0; j < dividenum; j++) {
		divide[j].x = Width * j / dividenum;
		divide[j].y = 0;
		divide[j].w = Width / dividenum;
		divide[j].h = Height;
	}
}
bool character2::loadfile(int h, int dvn,const char* filepath, SDL_Renderer* render) {
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

void character2::rendering(SDL_Renderer* render) {
	if (input == 3) {
		objectsize = { p1posx + 50,p2posy - 125,Width / dividenum,Height };
	}
	else if (input == 5) {
		objectsize = { p1posx + 50,p2posy - 55,Width / dividenum,Height };
	}
	else if (input == 4) {
		objectsize = { p2posx,p2posy - 20,Width / dividenum,Height };
	}
	else if (input == 0) {
		objectsize = { p2posx,p2posy - 150,Width / dividenum,Height };
	}
	else if (input == 2) {
		objectsize = { p2posx,p2posy - 150,Width / dividenum,Height };
	}
	else {
		objectsize = { p2posx - 55,p2posy - 145,(Width + 500) / dividenum,Height };
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
				if (stunned2 == 1 ) {
					changeturn(0);
					changeorder(1);
				}
				else {
					changeorder(0);
					changeturn(2);
				}
				changestun2(0);
				changeinput(-1);
				changeguess(0);
				changecomputer(0);
			}
		}
	}
}
