#include "Global.h"
#include "Objects.h"
extern int turn,order;
Objects::Objects() {
	image = NULL;
	*objectdivide = { NULL };
	objectsize = { NULL };
	Width = 0; Height = 0; frame = 0; dividenum = 0; 
}
Objects::~Objects() {
	free();
}

bool Objects::loadfile(int w, int h,int dvn, const char* filepath, SDL_Renderer* render, int red, int green, int blue) {
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(filepath);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, red,green,blue));
	if (surface != NULL) {
		texture = SDL_CreateTextureFromSurface(render, surface);
		Width = w; Height = h;
		image = texture;
		dividenum = dvn;
		animation(dividenum); 
		SDL_FreeSurface(surface);
	}
	return texture != NULL;
}
void Objects::animation( int dividenum) {
	for (int j = 0; j < dividenum; j++) {
		objectdivide[j].x = Width * j / dividenum;
		objectdivide[j].y = 0;
		objectdivide[j].w = Width / dividenum;
		objectdivide[j].h = Height;
	}
}
void Objects:: rect(SDL_Renderer* render, int x,int y, int w, int h,int red,int green,int blue,int transparence ) {
	 objectsize = { x,y,w,h };
	SDL_SetRenderDrawColor (render, red,green, blue,transparence);
	SDL_RenderFillRect(render, &objectsize);
}
int Objects::getw() { return Width; }
int Objects::geth() { return Height; }
void Objects::rendering(SDL_Renderer* render, int delay, int x, int y) {
	objectsize = { x,y,Width / dividenum ,Height };
	if (delay == 0) { SDL_RenderCopy(render, image, NULL, &objectsize); }
	else {
		if (frame / delay < dividenum) {
			if (dividenum == 1) {
				SDL_RenderCopy(render, image, NULL, &objectsize);
				frame++;
			}
			else{
				SDL_RenderCopy(render, image, &objectdivide[frame/delay], &objectsize);
				frame++;
			}
		}
		else {
			frame = 0; if (delay == 50) {
				if (order == 4) {
					changeorder(5);
				}
				else if ((turn == 1 || turn == 0) && order == 5) {
					changeorder(1);
				}
				else if (order == 5 && turn == 3) {
					changeorder(0);
				}
			}
			else if (turn == 3 && order == 0 && delay==75) { changeturn(2); }
		}
		}
	}

void Objects::free() {
	SDL_DestroyTexture(image);
	 *objectdivide = { NULL };
	 objectsize = { NULL };
	 Width = 0; Height = 0; dividenum = 0;
}