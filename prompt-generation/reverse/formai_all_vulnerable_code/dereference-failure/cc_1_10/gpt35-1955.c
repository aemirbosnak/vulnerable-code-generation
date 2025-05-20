//FormAI DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define RADIUS 30

typedef struct {
    float red, green, blue;
} color_t;

typedef struct {
    float x, y;
} point_t;

typedef struct {
    point_t center;
    color_t color;
} circle_t;

color_t random_color() {
    color_t c = {rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX};
    return c;
}

void draw_circle(circle_t circle, color_t *image) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            float dx = x - circle.center.x;
            float dy = y - circle.center.y;
            float d = sqrt(dx*dx + dy*dy);
            if (d < RADIUS) {
                int index = x*HEIGHT + y;
                image[index].red = circle.color.red;
                image[index].green = circle.color.green;
                image[index].blue = circle.color.blue;
            }
        }
    }
}

int main() {
    int i;
    color_t *image = malloc(WIDTH*HEIGHT*sizeof(color_t));
    for (i = 0; i < WIDTH*HEIGHT; i++) {
        image[i] = random_color();
    }
    circle_t circle1 = {{200, 200}, {1, 0, 0}};
    circle_t circle2 = {{400, 300}, {0, 1, 0}};
    draw_circle(circle1, image);
    draw_circle(circle2, image);
    FILE *fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (i = 0; i < WIDTH*HEIGHT; i++) {
        fputc((unsigned char)(image[i].red*255), fp);
        fputc((unsigned char)(image[i].green*255), fp);
        fputc((unsigned char)(image[i].blue*255), fp);
    }
    fclose(fp);
    free(image);
    return 0;
}