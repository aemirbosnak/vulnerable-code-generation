//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 1
#define PATH 0
#define START 2
#define END 3

int** init_maze(int n) {
    int** maze = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        maze[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            maze[i][j] = WALL;
        }
    }
    return maze;
}

void print_maze(int** maze, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            switch (maze[i][j]) {
                case WALL: printf("# "); break;
                case PATH: printf("  "); break;
                case START: printf("S "); break;
                case END: printf("E "); break;
            }
        }
        printf("\n");
    }
}

void create_maze(int** maze, int n, int x, int y) {
    maze[x][y] = PATH;
    while (1) {
        int rx = rand() % n;
        int ry = rand() % n;
        if ((rx == x && abs(ry - y) == 1) || (ry == y && abs(rx - x) == 1)) {
            if (maze[rx][ry] == WALL) {
                int count = 0;
                if (rx > 0 && maze[rx-1][ry] == PATH) count++;
                if (rx < n-1 && maze[rx+1][ry] == PATH) count++;
                if (ry > 0 && maze[rx][ry-1] == PATH) count++;
                if (ry < n-1 && maze[rx][ry+1] == PATH) count++;
                if (count == 1) {
                    create_maze(maze, n, rx, ry);
                    maze[rx][ry] = PATH;
                }
            }
        }
        int check = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == WALL) {
                    check = 1;
                    break;
                }
            }
        }
        if (check == 0) break;
    }
}

void set_start_end(int** maze, int n) {
    while (1) {
        int rsx = rand() % n;
        int rsy = rand() % n;
        int rex = rand() % n;
        int rey = rand() % n;
        if (maze[rsx][rsy] == PATH && maze[rex][rey] == PATH && (rsx != rex || rsy != rey)) {
            maze[rsx][rsy] = START;
            maze[rex][rey] = END;
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the size of the maze: ");
    scanf("%d", &n);
    int** maze = init_maze(n);
    create_maze(maze, n, 0, 0);
    set_start_end(maze, n);
    print_maze(maze, n);
    return 0;
}