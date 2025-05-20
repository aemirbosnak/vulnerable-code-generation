//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTS 100
#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *verts;
    int num_verts;
} Polygon;

void read_polygon(Polygon *poly, FILE *fp) {
    int i, n;
    Point *verts = (Point *)malloc(MAX_VERTS * sizeof(Point));
    fscanf(fp, "%d", &n);
    poly->num_verts = n;
    poly->verts = verts;
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d %d", &verts[i].x, &verts[i].y);
    }
}

void print_polygon(Polygon *poly) {
    int i;
    for (i = 0; i < poly->num_verts; i++) {
        printf("(%d, %d) ", poly->verts[i].x, poly->verts[i].y);
    }
    printf("\n");
}

void rotate_polygon(Polygon *poly, double angle) {
    int i;
    Point center = {0, 0};
    for (i = 0; i < poly->num_verts; i++) {
        Point *p = &poly->verts[i];
        double dx = p->x - center.x;
        double dy = p->y - center.y;
        double theta = angle * PI / 180.0;
        double new_x = dx * cos(theta) - dy * sin(theta);
        double new_y = dx * sin(theta) + dy * cos(theta);
        p->x = center.x + new_x;
        p->y = center.y + new_y;
    }
}

int main() {
    FILE *fp;
    Polygon poly1, poly2;
    double angle;

    fp = fopen("polygon1.txt", "r");
    read_polygon(&poly1, fp);
    fclose(fp);

    fp = fopen("polygon2.txt", "r");
    read_polygon(&poly2, fp);
    fclose(fp);

    printf("Polygon 1:\n");
    print_polygon(&poly1);

    printf("Polygon 2:\n");
    print_polygon(&poly2);

    printf("Enter rotation angle (in degrees): ");
    scanf("%lf", &angle);

    rotate_polygon(&poly2, angle);

    printf("Rotated polygon:\n");
    print_polygon(&poly2);

    return 0;
}