#include "Global.h"
 int order = 0, input = -1, turn = 2;
 int a1 = 0, a2 = 0,s1=0,s2=0,stunned1=0,stunned2=0,opening=0;
 double h1 = 0, h2 = 0;
 int guess = 0;
int computer = 0;
void changea1(int a) { a1 = a; }
void changea2(int a) { a2 = a; }
void changeh1(double a) { h1 = a; }
void changeh2(double a) { h2 = a; }
void changes1(int a) { s1 = a; }
 void changes2(int a) {s2 = a; }
 void changestun1(int a) {stunned1 = a; }
 void changestun2(int a) { stunned2 = a; }
 void changeorder(int a) { order = a; }
 void changeinput(int a) { input = a; }
 void changeturn(int a) { turn = a; }
 void changeguess(int a) { guess = a; }
 void changecomputer(int a) { computer = a; }
 void changeopening(int a) { opening = a; }

