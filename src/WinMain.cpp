#include "Keyboard.h"
#include "Pointer.h"

int WinMain() {
    
    SDL_Event e; //키입력
    bool quit = false; //창 닫히는지?
    int currentSituation; //캐릭터가 현재 서있는곳

    while (!quit) {

        SDL_RenderClear(Window::renderer); //화면 지우고

        //탈출
        if(Pointer::player->level1Access[Player::yPos][Player::xPos]==4) {
            if(Monster::gameClear) Pointer::gameClearScene();
            quit= true;
        }

        //상점
        else if(Pointer::player->level1Access[Player::yPos][Player::xPos]==3) {
            currentSituation=3;
            while (SDL_PollEvent(&e) != 0) {
                Pointer::renderingScene();
                Keyboard::keyboardInput(e,currentSituation);
                if (e.type == SDL_QUIT) quit = true;
                else if (e.type == SDL_KEYDOWN) Keyboard::keyPressed = true;
                else if (e.type == SDL_KEYUP) Keyboard::keyPressed = false;
            }
            Pointer::renderingScene();
            Shop::printStore();
        }

        //몬스터와 싸울때
        else if(Pointer::player->level1Access[Player::yPos][Player::xPos]==2||Pointer::player->level1Access[Player::yPos][Player::xPos]==5) {
            currentSituation=2;
            Pointer::fightStartCall();
            while (SDL_PollEvent(&e) != 0) {
                Keyboard::keyboardInput(e, currentSituation);
                if (e.type == SDL_QUIT) quit = true;
                else if (e.type == SDL_KEYDOWN) Keyboard::keyPressed = true;
                else if (e.type == SDL_KEYUP) Keyboard::keyPressed = false;
            }
            Pointer::renderingFightScene(1);
            SDL_Delay(50);
        }

        //이동
        else if(Pointer::player->level1Access[Player::yPos][Player::xPos]!=0)
        {
            currentSituation=1;
            while (SDL_PollEvent(&e) != 0) {
                Keyboard::keyboardInput(e,currentSituation);
                if (e.type == SDL_QUIT) quit = true;
                else if (e.type == SDL_KEYDOWN) Keyboard::keyPressed = true;
                else if (e.type == SDL_KEYUP) Keyboard::keyPressed = false;
            }
            Pointer::renderingScene();
        }

        //게임클리어
        if(Monster::gameClear)
        {
            Pointer::map->GameClear();
            Pointer::player->GameClear();
        }

        if(Player::Playerhp<=0) Pointer::gameOverScene(); //게임오버시 초기화

        Pointer::window->frameCal(Window::frame); //프레임 계산
        SDL_RenderPresent(Window::renderer); //화면 렌더링
        SDL_Delay(100); //잠시 멈춤
    }
    return 0;
}
