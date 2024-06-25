//
// Created by david on 6/25/24.
//

#ifndef ARNOLD3D_CUBE_H
#define ARNOLD3D_CUBE_H

#include <vector>
#include <cmath>

#include <Screen.h>

struct vec3 {
    float x, y, z;
};

struct connection {
    int a, b;
};

class Cube {
public:
    Cube(vec3 position, float size);
    void render(Screen& screen);
private:
    std::vector<vec3> points;
    std::vector<connection> connections;
    vec3 centroid{0, 0, 0};
    static void rotate(vec3& point, float x = 1, float y = 1, float z = 1);
    static void drawLine(Screen& screen, float x1, float y1, float x2, float y2);
};

#endif //ARNOLD3D_CUBE_H
