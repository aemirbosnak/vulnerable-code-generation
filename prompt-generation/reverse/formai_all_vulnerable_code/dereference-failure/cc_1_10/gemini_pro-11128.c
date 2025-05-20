//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 768

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Path;

typedef struct {
    RGB *pixels;
    Path *paths;
    int num_paths;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(width * height * sizeof(RGB));
    image->paths = malloc(sizeof(Path));
    image->num_paths = 0;
    return image;
}

void image_free(Image *image) {
    free(image->pixels);
    for (int i = 0; i < image->num_paths; i++) {
        free(image->paths[i].lines);
    }
    free(image->paths);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, RGB color) {
    image->pixels[y * WIDTH + x] = color;
}

void image_draw_line(Image *image, Line line, RGB color) {
    int dx = line.p2.x - line.p1.x;
    int dy = line.p2.y - line.p1.y;
    float length = sqrt(dx * dx + dy * dy);
    for (float i = 0; i <= length; i++) {
        float t = i / length;
        int x = (1 - t) * line.p1.x + t * line.p2.x;
        int y = (1 - t) * line.p1.y + t * line.p2.y;
        image_set_pixel(image, x, y, color);
    }
}

void image_draw_path(Image *image, Path path, RGB color) {
    for (int i = 0; i < path.num_lines; i++) {
        image_draw_line(image, path.lines[i], color);
    }
}

int main() {
    Image *image = image_new(WIDTH, HEIGHT);

    // Draw a circle
    Line circle_lines[360];
    for (int i = 0; i < 360; i++) {
        float angle = i * M_PI / 180;
        circle_lines[i].p1.x = WIDTH / 2 + 200 * cos(angle);
        circle_lines[i].p1.y = HEIGHT / 2 + 200 * sin(angle);
        circle_lines[i].p2.x = WIDTH / 2 + 200 * cos(angle + M_PI / 180);
        circle_lines[i].p2.y = HEIGHT / 2 + 200 * sin(angle + M_PI / 180);
    }
    Path circle_path = {circle_lines, 360};
    image_draw_path(image, circle_path, (RGB){255, 0, 0});

    // Draw a star
    Line star_lines[10];
    for (int i = 0; i < 10; i++) {
        float angle = i * M_PI / 5;
        star_lines[i].p1.x = WIDTH / 2 + 100 * cos(angle);
        star_lines[i].p1.y = HEIGHT / 2 + 100 * sin(angle);
        star_lines[i].p2.x = WIDTH / 2 + 50 * cos(angle + M_PI / 10);
        star_lines[i].p2.y = HEIGHT / 2 + 50 * sin(angle + M_PI / 10);
    }
    Path star_path = {star_lines, 10};
    image_draw_path(image, star_path, (RGB){0, 255, 0});

    // Draw a triangle
    Line triangle_lines[3];
    triangle_lines[0].p1.x = WIDTH / 2 - 100;
    triangle_lines[0].p1.y = HEIGHT / 2 + 100;
    triangle_lines[0].p2.x = WIDTH / 2 + 100;
    triangle_lines[0].p2.y = HEIGHT / 2 + 100;
    triangle_lines[1].p1.x = WIDTH / 2 + 100;
    triangle_lines[1].p1.y = HEIGHT / 2 + 100;
    triangle_lines[1].p2.x = WIDTH / 2;
    triangle_lines[1].p2.y = HEIGHT / 2 - 100;
    triangle_lines[2].p1.x = WIDTH / 2;
    triangle_lines[2].p1.y = HEIGHT / 2 - 100;
    triangle_lines[2].p2.x = WIDTH / 2 - 100;
    triangle_lines[2].p2.y = HEIGHT / 2 + 100;
    Path triangle_path = {triangle_lines, 3};
    image_draw_path(image, triangle_path, (RGB){0, 0, 255});

    // Write the image to a file
    FILE *file = fopen("image.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image->pixels, WIDTH * HEIGHT * sizeof(RGB), 1, file);
    fclose(file);

    image_free(image);
    return 0;
}