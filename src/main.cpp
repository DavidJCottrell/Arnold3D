#include <Screen.h>
#include <Cube.h>

int main() {

    Screen screen;
    Cube cube;

    while(screen.getIsPlaying()){
        cube.render(screen);
        screen.render();
        screen.clearPixels();
        screen.handleEvents();
        SDL_Delay(10);
    }

    return 0;
}
