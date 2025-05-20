//MISTRAL-7B DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    int x, y;
} Point;

bool **maze;
bool visited[WIDTH][HEIGHT];
Point stack[WIDTH * HEIGHT];
int top;

void print_maze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j])
                printf(maze[i][j] ? "  ##" : "  .  ");
            else
                printf(visited[j][i] ? "  @@ " : "   . ");
        }
        printf("\n");
    }
}

void dfs(int x, int y) {
    visited[x][y] = true;
    maze[y][x] = true;

    stack[top++] = (Point){x, y};

    for (int dx = -2; dx <= 2; dx += 4) {
        int nx = x + dx / 2, ny = y + dx / 2;

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT &&
            !maze[ny][nx] && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }

    if (--top < 0) {
        if (x > 0 && !maze[y][x - 1])
            dfs(x - 1, y);
        if (x < WIDTH - 1 && !maze[y][x + 1])
            dfs(x + 1, y);
        if (y > 0 && !maze[y - 1][x])
            dfs(x, y - 1);
        if (y < HEIGHT - 1 && !maze[y + 1][x])
            dfs(x, y + 1);
    }
}

int main() {
    srand(time(NULL));

    maze = malloc(HEIGHT * sizeof(bool *));
    for (int i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(bool));

    top = 0;
    dfs(rand() % WIDTH, rand() % HEIGHT);

    print_maze();

    for (int i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);

    return 0;
}