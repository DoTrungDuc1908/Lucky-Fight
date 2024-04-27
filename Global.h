#pragma once
#include <windows.h>
#include <SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#ifndef GLOBAL_H
#define GLOBAL_H
 static int p1posx = 300,p1posy=410,p2posx=800,p2posy=410;
  void changeorder(int a);
  void changeinput(int a);
  void changeturn(int a);
  void changea1(int a);
  void changea2(int a);
  void changeh1(double a);
  void changeh2(double a);
  void changeguess(int a);
  void changecomputer(int a);
  void changestun1(int a);
  void changestun2(int a);
  void changes1(int a);
  void changes2(int a);
  void changeopening(int a);


#endif 
