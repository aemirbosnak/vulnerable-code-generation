//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 10
#define MAX_DEPTH 15

typedef struct {
    int x, y;
} position;

typedef struct {
    char sym;
    int value;
} cell;

void generate_map(cell **map, int width, int height, int max_depth) {
    position stack[MAX_DEPTH];
    int top = -1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    cell *current = map[0];

    srand(time(NULL));

    current->sym = '.', current->value = 0;
    stack[++top] = (position){0, 0};

    while (top >= 0) {
        position cur = stack[top--];
        int x = cur.x, y = cur.y;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < width && ny >= 0 && ny < height &&
                map[ny][nx].sym == '.') {
                map[ny][nx].sym = '*';
                map[ny][nx].value = rand() % 10 + 1;
                stack[++top] = (position){nx, ny};
            }
        }

        current++;
        current->sym = '.', current->value = 0;
    }
}

void print_map(cell *map, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x)
            printf("%c", map[y * width + x].sym);
        printf("\n");
    }
}

int main() {
    cell *map;
    int width = WIDTH, height = HEIGHT;

    map = malloc(sizeof(cell) * width * height);

    generate_map(map, width, height, MAX_DEPTH);
    print_map(map, width, height);

    free(map);
    return 0;
}