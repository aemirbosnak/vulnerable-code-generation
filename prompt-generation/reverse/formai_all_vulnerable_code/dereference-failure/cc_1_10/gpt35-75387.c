//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 1
#define ROAD 0

typedef struct {
    int x;
    int y;
} Position;

void print_maze(int *maze, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", maze[i * width + j] == WALL ? 'X' : ' ');
        }
        printf("\n");
    }
}

void recursive_division(int *maze, int x1, int y1, int x2, int y2, int width, int height) {
    if (x1 + 1 >= x2 || y1 + 1 >= y2) {
        return;
    }
    int vertical = rand() % 2;
    int x_wall = vertical ? rand() % (x2 - x1 - 1) + x1 + 1 : rand() % (x2 - x1) + x1;
    int y_wall = !vertical ? rand() % (y2 - y1 - 1) + y1 + 1 : rand() % (y2 - y1) + y1;
    int x_pass = vertical ? rand() % (y2 - y1 - 1) + y1 + 1 : rand() % (x2 - x1) + x1;
    int y_pass = !vertical ? rand() % (x2 - x1 - 1) + x1 + 1 : rand() % (y2 - y1) + y1;

    int i, j;
    for (i = x1; i < x2; i++) {
        if (i == x_wall) {
            continue;
        }
        maze[y_wall * width + i] = WALL;
    }

    for (j = y1; j < y2; j++) {
        if (j == y_wall) {
            continue;
        }
        maze[j * width + x_wall] = WALL;
    }

    maze[y_pass * width + x_pass] = ROAD;

    recursive_division(maze, x1, y1, x_wall, y_wall, width, height);
    recursive_division(maze, x_wall + 1, y_wall + 1, x2, y2, width, height);
    recursive_division(maze, x1, y_wall + 1, x_wall, y2, width, height);
    recursive_division(maze, x_wall + 1, y1, x2, y_wall, width, height);
}

Position find_start_point(int *maze, int width, int height) {
    int x = 0, y = 0;
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (maze[i * width + j] == ROAD && (i == 0 || j == 0 || i == height - 1 || j == width - 1)) {
                return (Position) {j, i};
            }
        }
    }
    return (Position) {-1, -1};
}

int find_direction(int *maze, int width, int height, Position p) {
    int flag = rand() % 2;
    if (p.y == 0 || maze[(p.y - 1) * width + p.x] == WALL) {
        flag = 1;
    }
    if (p.x == 0 || maze[p.y * width + p.x - 1] == WALL) {
        flag = 0;
    }
    if (p.y == height - 1 || maze[(p.y + 1) * width + p.x] == WALL) {
        flag = 1;
    }
    if (p.x == width - 1 || maze[p.y * width + p.x + 1] == WALL) {
        flag = 0;
    }
    return flag ? (rand() % 2 ? 1 : 3) : (rand() % 2 ? 0 : 2); 
}

void move(Position *p, int direction) {
    switch (direction) {
        case 0:
            p->y--;
            break;
        case 1:
            p->x++;
            break;
        case 2:
            p->y++;
            break;
        case 3:
            p->x--;
            break;  
        default:
            break;
    }
}

void generate_maze(int width, int height) {
    int *maze = (int *) malloc(sizeof(int) * width * height);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            maze[i * width + j] = WALL;
        }
    }
    srand(time(NULL));
    recursive_division(maze, 0, 0, width, height, width, height);
    Position start = find_start_point(maze, width, height);
    Position curr = start;
    while (curr.x != -1) {
        maze[curr.y * width + curr.x] = ROAD;
        int direction = find_direction(maze, width, height, curr);
        move(&curr, direction);
    }
    print_maze(maze, width, height);
    free(maze);
}

int main() {
    generate_maze(21, 21);
    return 0;
}