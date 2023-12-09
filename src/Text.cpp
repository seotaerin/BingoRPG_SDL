#include "Text.h"
#include "Window.h"

bool Text::notBlink= false;

//생성자에서 ttf 사용을 위해 초기화
Text::Text()
{
    TTF_Init();
}

//텍스트를 렌더러에 추가하기 위한 함수
void Text::textRender(char* str, int x, int y, int size)
{
    font = TTF_OpenFont("Galmuri9.ttf", size);
    textSurface = TTF_RenderUTF8_Solid(font, str, textColor);
    textTexture = SDL_CreateTextureFromSurface(Window::renderer, textSurface);
    textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(Window::renderer, textTexture, nullptr, &textRect);
    if(notBlink) //글씨가 바뀔때만 새로 렌더링 하도록
    {
        SDL_RenderPresent(Window::renderer);
        SDL_Delay(1000);
    }
}