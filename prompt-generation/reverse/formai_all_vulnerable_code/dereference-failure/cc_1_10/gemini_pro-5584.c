//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int r, g, b;
} Color;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
    Color c;
} Line;

typedef struct {
    Point p1, p2, p3;
    Color c;
} Triangle;

typedef struct {
    Point p;
    Color c;
    int r;
} Circle;

typedef struct {
    Line *lines;
    int num_lines;
    Triangle *triangles;
    int num_triangles;
    Circle *circles;
    int num_circles;
} Image;

Image *new_image() {
    Image *image = malloc(sizeof(Image));
    image->lines = malloc(0);
    image->num_lines = 0;
    image->triangles = malloc(0);
    image->num_triangles = 0;
    image->circles = malloc(0);
    image->num_circles = 0;
    return image;
}

void free_image(Image *image) {
    free(image->lines);
    free(image->triangles);
    free(image->circles);
    free(image);
}

void add_line(Image *image, Line line) {
    image->lines = realloc(image->lines, (image->num_lines + 1) * sizeof(Line));
    image->lines[image->num_lines] = line;
    image->num_lines++;
}

void add_triangle(Image *image, Triangle triangle) {
    image->triangles = realloc(image->triangles, (image->num_triangles + 1) * sizeof(Triangle));
    image->triangles[image->num_triangles] = triangle;
    image->num_triangles++;
}

void add_circle(Image *image, Circle circle) {
    image->circles = realloc(image->circles, (image->num_circles + 1) * sizeof(Circle));
    image->circles[image->num_circles] = circle;
    image->num_circles++;
}

void render(Image *image) {
    int x, y;
    Color c;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            c = (Color){0, 0, 0};
            for (int i = 0; i < image->num_lines; i++) {
                Line line = image->lines[i];
                if (x >= line.p1.x && x <= line.p2.x && y >= line.p1.y && y <= line.p2.y) {
                    c.r = line.c.r;
                    c.g = line.c.g;
                    c.b = line.c.b;
                }
            }
            for (int i = 0; i < image->num_triangles; i++) {
                Triangle triangle = image->triangles[i];
                if (x >= triangle.p1.x && x <= triangle.p2.x && y >= triangle.p1.y && y <= triangle.p3.y) {
                    c.r = triangle.c.r;
                    c.g = triangle.c.g;
                    c.b = triangle.c.b;
                }
            }
            for (int i = 0; i < image->num_circles; i++) {
                Circle circle = image->circles[i];
                int dx = x - circle.p.x;
                int dy = y - circle.p.y;
                if (dx * dx + dy * dy <= circle.r * circle.r) {
                    c.r = circle.c.r;
                    c.g = circle.c.g;
                    c.b = circle.c.b;
                }
            }
            printf("#%02x%02x%02x ", c.r, c.g, c.b);
        }
        printf("\n");
    }
}

int main() {
    Image *image = new_image();

    // Add a line
    Line line1 = {{10, 10}, {90, 90}, {255, 0, 0}};
    add_line(image, line1);

    // Add a triangle
    Triangle triangle1 = {{20, 20}, {80, 20}, {50, 80}, {0, 255, 0}};
    add_triangle(image, triangle1);

    // Add a circle
    Circle circle1 = {{50, 50}, {0, 0, 255}, 20};
    add_circle(image, circle1);

    render(image);

    free_image(image);

    return 0;
}