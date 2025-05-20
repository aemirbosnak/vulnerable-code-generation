//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point {
    int x;
    int y;
};

struct line {
    int x1;
    int y1;
    int x2;
    int y2;
};

struct polygon {
    struct point points[4];
};

struct polygon *generate_polygon(int num_points) {
    struct polygon *polygon = malloc(sizeof(struct polygon));
    for (int i = 0; i < num_points; i++) {
        struct point point;
        point.x = rand() % 20 + 1;
        point.y = rand() % 20 + 1;
        polygon->points[i] = point;
    }
    return polygon;
}

int is_point_inside_polygon(struct polygon *polygon, struct point point) {
    int n = 0;
    for (int i = 0; i < 4; i++) {
        int x = polygon->points[i].x;
        int y = polygon->points[i].y;
        int x_test = point.x;
        int y_test = point.y;
        if (y_test < y) {
            while (x_test <= x) {
                if (y_test > y)
                    return 0;
                n++;
                x_test++;
            }
            if (n % 2 == 1)
                return 0;
        } else {
            while (y_test >= y) {
                if (x_test > x)
                    return 0;
                n++;
                y_test--;
            }
            if (n % 2 == 1)
                return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    struct polygon *polygon = generate_polygon(4);
    struct point point;
    point.x = 10;
    point.y = 10;
    if (is_point_inside_polygon(polygon, point))
        printf("The point is inside the polygon.\n");
    else
        printf("The point is not inside the polygon.\n");
    return 0;
}