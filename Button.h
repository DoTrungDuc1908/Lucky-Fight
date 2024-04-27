#pragma once
#include "Global.h"
#include "main.h"
class button {
public:
	button();
	~button();
	void handlekey(SDL_Event event);
	int oantuti(std::string ng1, std::string ng2);
	std::string returnchoice(int b);
	int songaunhien(int min, int max);
	void handleinput();
private:
	std::string a;
	int b;
};

