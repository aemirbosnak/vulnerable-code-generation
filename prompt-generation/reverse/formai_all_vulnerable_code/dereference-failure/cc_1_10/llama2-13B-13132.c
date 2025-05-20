//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Point p1, p2, p3;
} Triangle;

typedef struct {
    Point *points;
    int count;
} Polyline;

void initImage(double *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i] = (i % 2 == 0) ? 0.5 : 0.0;
    }
}

void drawPoint(double *image, Point point) {
    int x = (int)point.x;
    int y = (int)point.y;
    image[x + y * WIDTH] = 1.0;
}

void drawLine(double *image, Line line) {
    drawPoint(image, line.p1);
    drawPoint(image, line.p2);
}

void drawTriangle(double *image, Triangle triangle) {
    drawPoint(image, triangle.p1);
    drawPoint(image, triangle.p2);
    drawPoint(image, triangle.p3);
}

void drawPolyline(double *image, Polyline polyline) {
    for (int i = 0; i < polyline.count; i++) {
        drawPoint(image, polyline.points[i]);
    }
}

void main() {
    double *image = (double*)malloc(WIDTH * HEIGHT * sizeof(double));
    initImage(image, WIDTH, HEIGHT);

    Point p1 = {0.5, 0.5};
    Point p2 = {0.5, 1.5};
    Point p3 = {1.5, 1.5};
    Line line1 = {p1, p2};
    Line line2 = {p2, p3};
    Triangle triangle = {p1, p2, p3};
    Polyline polyline = {&p1, 3};

    drawPoint(image, p1);
    drawPoint(image, p2);
    drawPoint(image, p3);
    drawLine(image, line1);
    drawLine(image, line2);
    drawTriangle(image, triangle);
    drawPolyline(image, polyline);

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%.2f ", image[i]);
    }
    printf("\n");

    free(image);
}