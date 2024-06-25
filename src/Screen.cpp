//
// Created by david on 6/25/24.
//

#include <Screen.h>


Screen::Screen() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(400, 400, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
}

void Screen::addPixel(float x, float y) {
    SDL_FPoint point = {x, y};
    points.emplace_back(point);
}

void Screen::clearPixels(){
    points.clear();
}

void Screen::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (auto& point : points){
        SDL_RenderDrawPointF(renderer, point.x, point.y);
    }

    SDL_RenderPresent(renderer);
}

void Screen::handleEvents() {
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            SDL_Quit();
            isPlaying = false;
        }
    }
}
