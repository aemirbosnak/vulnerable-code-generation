//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

#define PATH_SIZE 100

Path path;

void path_init() {
    path.points = malloc(sizeof(Point) * PATH_SIZE);
    path.size = 0;
}

void path_free() {
    free(path.points);
}

void path_add_point(int x, int y) {
    if (path.size == PATH_SIZE) {
        path.points = realloc(path.points, sizeof(Point) * (path.size + PATH_SIZE));
    }
    path.points[path.size].x = x;
    path.points[path.size].y = y;
    path.size++;
}

void print_qr_code(int size) {
    int i, j, k;
    char *bitmap = malloc(size * size);
    memset(bitmap, ' ', size * size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < path.size; k++) {
                if (i == path.points[k].x && j == path.points[k].y) {
                    bitmap[i * size + j] = '*';
                    break;
                }
            }
        }
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c", bitmap[i * size + j]);
        }
        printf("\n");
    }
    free(bitmap);
}

int main(int argc, char **argv) {
    int size, i, j, k;
    if (argc != 3) {
        printf("Usage: %s <size> <message>\n", argv[0]);
        return 1;
    }
    size = atoi(argv[1]);
    path_init();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int dist = sqrt(pow(i - size / 2, 2) + pow(j - size / 2, 2));
            if (dist <= size / 2) {
                path_add_point(i, j);
            }
        }
    }
    k = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (path.points[k].x == i && path.points[k].y == j) {
                printf("%c", argv[2][k % strlen(argv[2])]);
                k++;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    path_free();
    return 0;
}