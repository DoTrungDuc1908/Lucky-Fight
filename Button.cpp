#include "Button.h"
#include "Global.h"
extern int input, order, turn, a1, a2,stunned1,stunned2,s1,s2,opening;
extern double  h1, h2;
extern int guess ;
extern int computer ;
button::button() { b = 0; };
button:: ~button() {};
int button:: songaunhien(int min, int max) {
    srand(time(0));
    return rand() % max + min;
}
std::string button:: returnchoice(int b) {
    if (b == 1) { changecomputer(1); return "paper"; }
    else if (b == 2) { changecomputer(2); return "rock"; }
    else { changecomputer(3); return "scissors"; }
    return "";
}
int button::oantuti(std::string ng1, std::string ng2) {
    if (ng1 == ng2) { return 3; }
    if (ng1 == "paper") {
        if (ng2 == "rock") { return 1; }
        else  return 0;
    }
    else if (ng1 == "rock") {
        if (ng2 == "paper")return 0;
        else return 1;
    }
    else {
        if (ng2 == "paper")return 1;
        else return 0;
    }
}
void button::handleinput() {
    if (order == 1) {
        if (turn == 0) {
            b = songaunhien(3, 5);
            if (300 - 50 * a1 + h1 * 40 - s1 * 25 <= 50) { b = 5; }
            else if (300 - 50 * a2 + 40 * h2 - s2 * 25 > 260) {
                b = songaunhien(1, 2);
                if (b == 1) { b = 3; }
                else { b = 5; }
            }
            switch (b) {
            case 3:
                changeinput(3); changeorder(2); changea1(a1 + 1); break;
            case 4:
                changeh2(h2 + 1); changeinput(4); changeorder(2); 
                    break;
            case 5:
                changes1(s1 + 1); changeinput(5); changeorder(2); changestun2(songaunhien(1, 2));
                 break;
            default: changeinput(-1); break;
            }
        }
    }
}
void button::handlekey(SDL_Event event) {
    a = "";
    switch (event.key.keysym.sym) {
    case SDLK_1:
        if (order == 0) {
            a = "paper"; changeguess(1); changeorder(4); changeturn(oantuti(a, returnchoice(songaunhien(1, 3))));
        } break;
    case SDLK_2:
        if (order == 0) {
            a = "rock"; changeguess(2); changeorder(4); changeturn(oantuti(a, returnchoice(songaunhien(1, 3))));
        } break;
    case SDLK_3: if (order == 0) {
        a = "scissors"; changeguess(3); changeorder(4); changeturn(oantuti(a, returnchoice(songaunhien(1, 3))));
    } break;
    case SDLK_a:if (order == 1 && turn == 1) {
        changeinput(0);  changeorder(2); changea2(a2 + 1);
    } break;
    case SDLK_s:if (order == 1 && turn == 1) {
        changeinput(2); changeorder(2); changes2(s2 + 1); changestun1(songaunhien(1, 2));
    }  break;
    case SDLK_h:if (order == 1 && turn == 1) {
        changeinput(1);  changeorder(2); changeh1(h1 + 1);
        if (300 - 50 * a1 + h1 * 40 - s1 * 25 > 300) {
            changeh1(h1 - (double)(-50 * a1 + h1 * 40 - s1 * 25) / 40);
        }
    }break;
    case SDLK_SPACE:if (300 - 50 * a1 + h1 * 40 - s1 * 25 <= 0 || 300 - 50 * a2 + 40 * h2 - s2 * 25 <= 0) {
        changeorder(0); changeinput(-1); changeturn(2); changea1(0); changea2(0); changeh1(0); changeh2(0); changeguess(0); changecomputer(0);
        changestun1(0); changestun2(0); changes1(0); changes2(0); changeopening(0);
        Mix_PlayMusic(Mix_LoadMUS("music//background.wav"), -1);
    }
                   break;
    default:
        if (turn == 3) {
            if (order == 4 || order == 5) {
                break;
            }
            else { changeturn(2); }
        }
        break;
    }
}






