//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_MAX 177
#define QR_MAX_LEN (QR_MAX * 4)

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int count;
} Path;

void init_path(Path *path) {
    path->points = (Point *)malloc(sizeof(Point) * QR_MAX_LEN);
    path->count = 0;
}

void add_point(Path *path, int x, int y) {
    if (path->count >= QR_MAX_LEN - 1) {
        printf("Path too long!\n");
        exit(1);
    }
    path->points[path->count].x = x;
    path->points[path->count].y = y;
    path->count++;
}

void draw_path(Path *path) {
    for (int i = 0; i < path->count; i++) {
        printf("(%d,%d) ", path->points[i].x, path->points[i].y);
    }
    printf("\n");
}

void random_qr(int size, Path *path) {
    int x, y;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        x = rand() % (size - 2) + 1;
        y = rand() % (size - 2) + 1;
        add_point(path, x, y);
    }
}

int main() {
    int size;
    printf("Enter QR code size (1-40): ");
    scanf("%d", &size);
    if (size < 1 || size > 40) {
        printf("Invalid size!\n");
        return 1;
    }
    Path path;
    init_path(&path);
    random_qr(size, &path);
    draw_path(&path);
    return 0;
}