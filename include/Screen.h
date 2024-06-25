//
// Created by david on 6/25/24.
//

#ifndef ARNOLD3D_SCREEN_H
#define ARNOLD3D_SCREEN_H

#include <SDL2/SDL.h>
#include <vector>

class Screen {
public:

    Screen();

    void addPixel(float x, float y);
    void clearPixels();
    void render();
    void handleEvents();
    [[nodiscard]] bool getIsPlaying() const { return isPlaying; };

private:
    SDL_Event e{};
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    std::vector<SDL_FPoint> points;
    bool isPlaying = true;
};

#endif //ARNOLD3D_SCREEN_H
