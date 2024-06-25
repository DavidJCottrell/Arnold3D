//
// Created by david on 6/25/24.
//

#include <Cube.h>

Cube::Cube() {
    points = {
            {50, 50, 50},
            {150, 50, 50},
            {150, 150, 50},
            {50, 150, 50},

            {50, 50, 150},
            {150, 50, 150},
            {150, 150, 150},
            {50, 150, 150},
    };

    connections = {
            {0, 4},
            {1, 5},
            {2, 6},
            {3, 7},

            {0, 1},
            {1, 2},
            {2, 3},
            {3, 0},

            {4, 5},
            {5, 6},
            {6, 7},
            {7, 4},
    };

    for(auto& p : points){
        centroid.x += p.x;
        centroid.y += p.y;
        centroid.z += p.z;
    }

    centroid.x /= points.size();
    centroid.y /= points.size();
    centroid.z /= points.size();
}

void Cube::rotate(vec3 &point, float x, float y, float z) {
    float rad;

    rad = x;
    point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

    rad = y;
    point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
    point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

    rad = z;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
    point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;
}

void Cube::drawLine(Screen &screen, float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float length = std::sqrt(dx * dx + dy * dy);
    float angle = std::atan2(dy, dx);

    for(float i = 0; i < length; i++){
        screen.addPixel(x1 + std::cos(angle) * i, y1 + std::sin(angle) * i);
    }
}

void Cube::render(Screen& screen) {
    for (auto& p : points){
        p.x -= centroid.x;
        p.y -= centroid.y;
        p.z -= centroid.z;
        rotate(p, 0.002, 0.001, 0.004);
        p.x += centroid.x;
        p.y += centroid.y;
        p.z += centroid.z;
        screen.addPixel(p.x, p.y);
    }

    for(auto& conn : connections){
        drawLine(screen, points[conn.a].x, points[conn.a].y, points[conn.b].x, points[conn.b].y);
    }
}



