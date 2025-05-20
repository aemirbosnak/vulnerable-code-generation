//LLAMA2-13B DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define VISIONARY_WORLD 1

typedef struct {
    int x;
    int y;
    int z;
} visionary_point;

typedef struct {
    visionary_point *points;
    int count;
} visionary_array;

visionary_array *generate_random_points(int count) {
    visionary_array *array = malloc(count * sizeof(visionary_point));
    for (int i = 0; i < count; i++) {
        array->points[i].x = rand() % 100 - 50;
        array->points[i].y = rand() % 100 - 50;
        array->points[i].z = rand() % 100 - 50;
    }
    return array;
}

void draw_points(visionary_array *array) {
    for (int i = 0; i < array->count; i++) {
        printf("(%d, %d, %d) ", array->points[i].x, array->points[i].y, array->points[i].z);
    }
    printf("\n");
}

void move_points(visionary_array *array, int dx, int dy, int dz) {
    for (int i = 0; i < array->count; i++) {
        array->points[i].x += dx;
        array->points[i].y += dy;
        array->points[i].z += dz;
    }
}

int main() {
    srand(time(NULL));

    visionary_array *array = generate_random_points(10);
    draw_points(array);

    move_points(array, 5, 10, 15);
    draw_points(array);

    free(array);

    return 0;
}