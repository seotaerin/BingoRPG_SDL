#include "Window.h"
#include "Pointer.h"

SDL_Renderer *Window::renderer= nullptr;
SDL_Window *Window::window= nullptr;
int Window::frame=0;

//윈도우 생성자에서 창을 만들고 렌더러를 정의한다.
Window::Window()
{
    window = SDL_CreateWindow("BingoRPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 960, SDL_WINDOW_POPUP_MENU);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

//이미지를 불러올때 쓸 함수
SDL_Texture* Window::LoadTexture(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex= SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

//프레임을 계산할 함수
void Window::frameCal(int& frame)
{
    frameCount++;
    if (frameCount >= 2) {
        frameCount = 0;
        frame++;
        if (frame >= 4) frame = 0;
    }
}

//빙고판에서 HP, MP, 아이템 상황 등 UI를 표시할 함수
void Window::UI()
{
    std::string ch = "HP " +bar(Player::Playerhp)+"    "+"MP "+bar(Player::Playermp*5)+"   "+"Gold "+std::to_string(Player::gold);
    char* ui = &ch[0];
    Pointer::text->textRender(ui, 45, 50, 28);//텍스트 불러옴

    ch = "HP포션  "+std::to_string(Player::hpPotion)+"개";
    char* hpCount = &ch[0];
    Pointer::text->textRender(hpCount, 775, 100, 28);//텍스트 불러옴
    ch = "MP포션  "+std::to_string(Player::mpPotion)+"개";
    char* mpCount = &ch[0];
    Pointer::text->textRender(mpCount, 775, 150, 28);//텍스트 불러옴

    ch = std::to_string(Map::bingocount)+"bingo!";
    char* bingo = &ch[0];
    Pointer::text->textRender(bingo, 775, 200, 28);//텍스트 불러옴

    if(Monster::gameClear) Pointer::text->textRender((char*)"문이 열렸습니다.", 350, 400, 36);
}

//HP, MP를 숫자가 아니라 네모모양으로 표시하려고 만든 함수
string Window::bar(int n)
{
    if(n>=100)
    {
        return "▮▮▮▮▮▮▮▮▮▮";
    }
    else if(n>=90)
    {
        return "▮▮▮▮▮▮▮▮▮▯";
    }
    else if(n>=80)
    {
        return "▮▮▮▮▮▮▮▮▯▯";
    }
    else if(n>=70)
    {
        return "▮▮▮▮▮▮▮▯▯▯";
    }
    else if(n>=60)
    {
        return "▮▮▮▮▮▮▯▯▯▯";
    }
    else if(n>=50)
    {
        return "▮▮▮▮▮▯▯▯▯▯";
    }
    else if(n>=40)
    {
        return "▮▮▮▮▯▯▯▯▯▯";
    }
    else if(n>=30)
    {
        return "▮▮▮▯▯▯▯▯▯▯";
    }
    else if(n>=20)
    {
        return "▮▮▯▯▯▯▯▯▯▯";
    }
    else if(n>=10)
    {
        return "▮▯▯▯▯▯▯▯▯▯";
    }
    else
    {
        return "▯▯▯▯▯▯▯▯▯▯";
    }

}
