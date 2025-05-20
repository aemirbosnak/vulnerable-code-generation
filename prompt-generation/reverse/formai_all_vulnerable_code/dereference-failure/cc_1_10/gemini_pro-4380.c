//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Point center;
    double radius;
} Circle;

void draw_line(Line line, FILE *fp) {
    fprintf(fp, "Line(%lf, %lf, %lf, %lf)\n", line.p1.x, line.p1.y, line.p2.x, line.p2.y);
}

void draw_circle(Circle circle, FILE *fp) {
    fprintf(fp, "Circle(%lf, %lf, %lf)\n", circle.center.x, circle.center.y, circle.radius);
}

int main(int argc, char **argv) {
    int width = DEFAULT_WIDTH, height = DEFAULT_HEIGHT;
    if (argc >= 3) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    }

    FILE *fp = fopen("output.svg", "w");
    fprintf(fp, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", width, height);

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        double x1 = (double)rand() / RAND_MAX * width;
        double y1 = (double)rand() / RAND_MAX * height;
        double x2 = (double)rand() / RAND_MAX * width;
        double y2 = (double)rand() / RAND_MAX * height;
        Line line = {{x1, y1}, {x2, y2}};
        draw_line(line, fp);
    }

    for (int i = 0; i < 50; i++) {
        double cx = (double)rand() / RAND_MAX * width;
        double cy = (double)rand() / RAND_MAX * height;
        double radius = (double)rand() / RAND_MAX * 100;
        Circle circle = {{cx, cy}, radius};
        draw_circle(circle, fp);
    }

    fprintf(fp, "</svg>\n");
    fclose(fp);

    return 0;
}