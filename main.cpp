#include "main.h"
#include "Global.h"
extern int input, order, turn,a1,a2,s1,s2,stunned1,stunned2,opening;
extern double  h1, h2;
extern int guess ;
extern int computer ;
int main(int argc, char* argv[]) {
    SDL_Window* window = SDL_CreateWindow("Lucky Fight", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Objects background, hp, in, a, s, h, fight, paper1, paper2, rock1, rock2, scissors1, scissors2, press, youwin, arrow, gameover, draw, countdown, stunned, replay;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* backgroundmusic = Mix_LoadMUS("music//background.wav");
    Mix_Chunk* drum = Mix_LoadWAV("music//drum.wav");
    Mix_Chunk* gameoversound = Mix_LoadWAV("music//gameover.wav");
    Mix_Chunk* hurt = Mix_LoadWAV("music//hurt.wav");
    Mix_Chunk* sword = Mix_LoadWAV("music//sword.wav");
    Mix_Chunk* win = Mix_LoadWAV("music//win.wav");
    Mix_Chunk* heal = Mix_LoadWAV("music//heal.wav");
    background.loadfile(1200, 600, 1, "image//hinhnen.png", render, 255, 255, 255);
    fight.loadfile(150, 60, 1, "image//fight.jpg", render, 255, 255, 255);
    in.loadfile(120, 60, 1, "image//123.png", render, 255, 255, 255);
    a.loadfile(50, 30, 1, "image//a.png", render, 255, 255, 255);
    s.loadfile(50, 30, 1, "image//s.png", render, 255, 255, 255);
    h.loadfile(50, 30, 1, "image//h.png", render, 255, 255, 255);
    paper1.loadfile(50, 30, 1, "image//paper1.png", render, 140, 63, 93);
    paper2.loadfile(50, 30, 1, "image//paper2.png", render, 140, 63, 93);
    rock1.loadfile(50, 30, 1, "image//rock1.png", render, 140, 63, 93);
    rock2.loadfile(50, 30, 1, "image//rock2.png", render, 140, 63, 93);
    scissors1.loadfile(50, 30, 1, "image//scissors1.png", render, 140, 63, 93);
    scissors2.loadfile(50, 30, 1, "image//scissors2.png", render, 140, 63, 93);
    press.loadfile(150, 60, 1, "image//press.png", render, 255, 255, 255);
    youwin.loadfile(600, 300, 1, "image//win.png", render, 245, 245, 245);
    arrow.loadfile(50, 30, 1, "image//arrow.png", render, 255, 255, 255);
    gameover.loadfile(600, 300, 1, "image//gameover.png", render, 1, 196, 254);
    draw.loadfile(200, 100, 1, "image//draw.png", render, 255, 255, 255);
    countdown.loadfile(269, 57, 3, "image//countdown.png", render, 255, 255, 255);
    stunned.loadfile(100, 66, 1, "image//stunned.jpg", render, 255, 255, 255);
    replay.loadfile(450, 30, 1, "image//replay.png", render, 255, 255, 255);
    button button;
    character1 idle1, attack1, stun1, heal1, hit1;
    idle1.loadfile(290, 10, "image//Player1//_Idle.png", render);
    attack1.loadfile(270, 6, "image//Player1//_Attack2.png", render);
    stun1.loadfile(200, 4, "image//Player1//_Attack.png", render);
    heal1.loadfile(150, 3, "image//Player1//_CrouchAll.png", render);
    hit1.loadfile(300, 1, "image//Player1//_Hit.png", render);
    character2 idle2, attack2, stun2, heal2, hit2;
    idle2.loadfile(290, 10, "image//Player2//_Idle.png", render);
    attack2.loadfile(270, 6, "image//Player2//_Attack2.png", render);
    stun2.loadfile(200, 4, "image//Player2//_Attack.png", render);
    heal2.loadfile(170, 3, "image//Player2//_CrouchAll.png", render);
    hit2.loadfile(300, 1, "image//Player2//_Hit.png", render);
    SDL_Event event;
    bool is_quit = false;
    Mix_PlayMusic(backgroundmusic, -1);
    while (!is_quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                is_quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                button.handlekey(event);
            }
            else { break; }
        }
        button.handleinput();
        background.rendering(render, 0, 0, 0);
        hp.rect(render, 45, 45, 310, 40, 0, 0, 0, 255);
        hp.rect(render, 845, 45, 310, 40, 0, 0, 0, 255);
        if (300 - 50 * a1 + h1 * 40 - s1 * 25 > 0 && 300 - 50 * a2 + 40 * h2 - s2 * 25 > 0) {
            if (order == 0 && turn == 2) {
                in.rendering(render, 0, 200, 200);
                paper1.rendering(render, 0, 180, 260);
                rock1.rendering(render, 0, 230, 260);
                scissors1.rendering(render, 0, 280, 260);
                press.rendering(render, 0, 45, 200);
            }
            if (order == 1 && turn == 1) {
                a.rendering(render, 0, 200, 200);
                s.rendering(render, 0, 250, 200);
                h.rendering(render, 0, 300, 200);
            }
            if (order == 4) {
                countdown.rendering(render, 50, 570, 200);
            }
            if (order == 5) {
                switch (computer) {
                case 1: paper2.rendering(render, 50, p2posx - 50, p2posy + 30); break;
                case 2: rock2.rendering(render, 50, p2posx - 50, p2posy + 30); break;
                case 3: scissors2.rendering(render, 50, p2posx - 50, p2posy + 30); break;
                default:break;
                }
                switch (guess) {
                case 1:paper1.rendering(render, 50, p1posx + 100, p1posy + 30); break;
                case 2:rock1.rendering(render, 50, p1posx + 100, p1posy + 30); break;
                case 3:scissors1.rendering(render, 50, p1posx + 100, p1posy + 30); break;
                default: break;
                }
            }
            if (turn == 3 && order == 0) { draw.rendering(render, 75, 500, 170); }
            else if (turn == 1 && order == 1) { arrow.rendering(render, 0, 355, 340); }
            else if (turn == 0 && order == 1) { arrow.rendering(render, 0, 810, 340); }
            if (input == 0) {
                Mix_PlayChannel(-1, sword, 0);
                hit2.rendering(render);
                attack1.rendering(render);
            }
            else if (input == 1) {
                heal1.rendering(render);
                idle2.rendering(render);
                Mix_PlayChannel(-1, heal, 0);
            }
            else if (input == 2) {
                Mix_PlayChannel(-1, sword, 0);
                hit2.rendering(render);
                stun1.rendering(render);
            }
            else if (input == 3) {
                Mix_PlayChannel(-1, hurt, 0);
                hit1.rendering(render);
                attack2.rendering(render);
            }
            else if (input == 4) {
                idle1.rendering(render);
                heal2.rendering(render);
                Mix_PlayChannel(-1, heal, 0);
            }
            else if (input == 5) {
                Mix_PlayChannel(-1, hurt, 0);
                hit1.rendering(render);
                stun2.rendering(render);
            }
            else {
                idle1.rendering(render);
                idle2.rendering(render);
            }
            hp.rect(render, 50, 50, 300 - 50 * a1 + h1 * 40 - s1 * 25, 30, 255, 0, 0, 255);
            hp.rect(render, 850, 50, 300 - 50 * a2 + 40 * h2 - s2 * 25, 30, 255, 0, 0, 255);
            if (stunned1 == 2) { stunned.rendering(render, 0, p2posx, p2posy - 60); }
            if (stunned2 == 1) { stunned.rendering(render, 0, p1posx, p1posy - 60); }
        }
        else {
                Mix_HaltMusic();
                if (300 - 50 * a1 + h1 * 40 - s1 * 25 <= 0) {
                    gameover.rendering(render, 0, 300, 100);
                    hp.rect(render, 50, 50, 0, 30, 255, 0, 0, 255);
                    hp.rect(render, 850, 50, 300 - 50 * a2 + 40 * h2 - s2 * 25, 30, 255, 0, 0, 255);
                    if(order==1 || order==2){
                        Mix_FadeOutChannel(Mix_FadeInChannel(-1, gameoversound, 0, 0), 1500);
                        changeorder(0);
                    } 
                }
                else if (300 - 50 * a2 + 40 * h2 - s2 * 25 <= 0) {
                    youwin.rendering(render, 0, 300, 100);
                    hp.rect(render, 50, 50, 300 - 50 * a1 + h1 * 40 - s1 * 25, 30, 255, 0, 0, 255);
                    hp.rect(render, 850, 50, 0, 30, 255, 0, 0, 255);
                    if (order == 1 || order == 2) {
                        Mix_FadeOutChannel(Mix_FadeInChannel(-1, win, 0, 0), 2000);
                        changeorder(0);
                    } 
                }
                replay.rendering(render, 0, 365, 350);
        }
        hp.rect(render, 0, 0, 1200, 300 - opening * 5, 0, 0, 0, 255);
        hp.rect(render, 0, 300 + opening * 5, 1200, 300, 0, 0, 0, 255);
        if (opening < 60) { opening++; }
        SDL_RenderPresent(render);
    }
    return 0;
}