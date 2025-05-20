//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

typedef struct {
    Polygon *polygons;
    int num_polygons;
} Scene;

void draw_pixel(Color *buffer, int x, int y, Color color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    buffer[y * WIDTH + x] = color;
}

void draw_line(Color *buffer, Point p1, Point p2, Color color) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = p1.x;
    float y = p1.y;
    for (int i = 0; i <= steps; i++) {
        draw_pixel(buffer, round(x), round(y), color);
        x += x_inc;
        y += y_inc;
    }
}

void draw_polygon(Color *buffer, Polygon polygon, Color color) {
    for (int i = 0; i < polygon.num_points; i++) {
        Point p1 = polygon.points[i];
        Point p2 = polygon.points[(i + 1) % polygon.num_points];
        draw_line(buffer, p1, p2, color);
    }
}

void draw_scene(Color *buffer, Scene scene) {
    for (int i = 0; i < scene.num_polygons; i++) {
        draw_polygon(buffer, scene.polygons[i], (Color){255, 255, 255, 255});
    }
}

int main() {
    Color *buffer = malloc(WIDTH * HEIGHT * sizeof(Color));
    memset(buffer, 0, WIDTH * HEIGHT * sizeof(Color));

    Point points[] = {
        {100, 100},
        {200, 100},
        {200, 200},
        {100, 200},
    };
    Polygon polygon = {points, 4};

    Scene scene = {&polygon, 1};

    draw_scene(buffer, scene);

    FILE *fp = fopen("pixel_art.bmp", "wb");
    fprintf(fp, "BM");
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c", 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
    fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);

    fwrite(buffer, WIDTH * HEIGHT * sizeof(Color), 1, fp);

    fclose(fp);

    return 0;
}