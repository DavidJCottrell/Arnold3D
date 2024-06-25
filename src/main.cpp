#include <Screen.h>
#include <Cube.h>

int main() {

    Screen screen;

    std::vector<Cube> cubes {
            {Cube({0, 0, 0}, 1)},
            {Cube({10, 10, 0}, 1)},
            {Cube({20, 20, 0}, 1)},
            {Cube({30, 30, 0}, 1)},
    };
    
    while(screen.getIsPlaying()){
        for(auto& cube : cubes){
            cube.render(screen);
        }
        screen.render();
        screen.clearPixels();
        screen.handleEvents();
        SDL_Delay(10);
    }

    return 0;
}
