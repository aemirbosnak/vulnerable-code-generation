//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x;
    int y;
} position_t;

typedef struct {
    position_t start;
    position_t end;
} path_t;

path_t* generate_path(int width, int height) {
    path_t* path = malloc(width * height * sizeof(path_t));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            path[i * height + j].start = (position_t) { i, j };
            path[i * height + j].end = (position_t) { i, j + 1 };
        }
    }
    return path;
}

void draw_space(int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void move_cat(position_t* position, int direction) {
    switch (direction) {
        case 1:
            position->y++;
            break;
        case 2:
            position->x++;
            break;
        case 3:
            position->y--;
            break;
        case 4:
            position->x--;
            break;
    }
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    position_t start = (position_t) { 0, 0 };
    position_t end = (position_t) { width - 1, height - 1 };
    path_t* path = generate_path(width, height);

    srand(time(NULL));

    printf("Crazy Cats in Space!\n");
    printf("You are a brave space cat, and you must navigate through the galaxy to reach the secret catnip planet.\n");
    printf("You start at position (%d, %d) and your goal is at position (%d, %d).\n", start.x, start.y, end.x, end.y);

    while (1) {
        draw_space(width, height);
        printf("You are at position (%d, %d).\n", start.x, start.y);

        int direction = rand() % 4;
        move_cat(&start, direction);

        if (start.x == end.x && start.y == end.y) {
            printf("You reached the secret catnip planet! Congratulations, space cat!\n");
            break;
        }

        if (start.x < 0 || start.x >= width || start.y < 0 || start.y >= height) {
            printf("You fell off the edge of the galaxy! Better luck next time, space cat.\n");
            break;
        }
    }

    free(path);
    return 0;
}