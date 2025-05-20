//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position start;
    Position end;
    Position current;
} Path;

Path* create_path(int start_x, int start_y, int end_x, int end_y) {
    Path* path = malloc(sizeof(Path));
    path->start.x = start_x;
    path->start.y = start_y;
    path->end.x = end_x;
    path->end.y = end_y;
    path->current.x = start_x;
    path->current.y = start_y;
    return path;
}

void move(Path* path) {
    int direction = (rand() % 2) - 1;
    if (direction == 0) {
        path->current.x += 1;
    } else {
        path->current.x -= 1;
    }
    if (direction == 0) {
        path->current.y += 1;
    } else {
        path->current.y -= 1;
    }
}

void draw(Path* path) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", path->current.x);
        printf("%d ", path->current.y);
        printf("\n");
        move(path);
    }
}

int main() {
    srand(time(NULL));
    int start_x = 100;
    int start_y = 100;
    int end_x = 600;
    int end_y = 400;
    Path* path = create_path(start_x, start_y, end_x, end_y);
    draw(path);
    return 0;
}