//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

bool should_draw(Line line) {
    return fabs(line.start.x - line.end.x) > 1 || fabs(line.start.y - line.end.y) > 1;
}

void draw_line(float *buffer, Line line) {
    if (!should_draw(line)) {
        return;
    }

    double angle = atan2(line.end.y - line.start.y, line.end.x - line.start.x);
    double length = hypot(line.end.y - line.start.y, line.end.x - line.start.x);

    Point midpoint = {
        (line.start.x + line.end.x) / 2,
        (line.start.y + line.end.y) / 2
    };

    Point left_point = {
        midpoint.x + length / 3 * cos(angle + M_PI / 3),
        midpoint.y + length / 3 * sin(angle + M_PI / 3)
    };

    Point right_point = {
        midpoint.x + length / 3 * cos(angle - M_PI / 3),
        midpoint.y + length / 3 * sin(angle - M_PI / 3)
    };

    Line left_line = {line.start, left_point};
    Line right_line = {right_point, line.end};

    draw_line(buffer, left_line);
    draw_line(buffer, right_line);
}

void generate_fractal(float *buffer) {
    Line root = {
        {500, 900},
        {500, 100}
    };

    draw_line(buffer, root);
}

int main() {
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    float *buffer = malloc(sizeof(float) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        buffer[i] = 0;
    }

    generate_fractal(buffer);

    unsigned char *pixels = malloc(sizeof(unsigned char) * WIDTH * HEIGHT * 3);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        float value = buffer[i];
        pixels[i * 3 + 0] = value * 255;
        pixels[i * 3 + 1] = value * 255;
        pixels[i * 3 + 2] = value * 255;
    }

    fwrite(pixels, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    free(buffer);
    free(pixels);
}