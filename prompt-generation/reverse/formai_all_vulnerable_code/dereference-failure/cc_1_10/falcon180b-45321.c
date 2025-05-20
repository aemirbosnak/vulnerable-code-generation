//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_maze(char maze[ROWS][COLS]);
void generate_maze(char maze[ROWS][COLS]);
int check_win(char maze[ROWS][COLS]);
void move(char maze[ROWS][COLS], int *row, int *col, char dir);

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];
    int player_row = 0, player_col = 0;
    generate_maze(maze);
    while (!check_win(maze)) {
        system("clear");
        print_maze(maze);
        char input;
        scanf("%c", &input);
        move(maze, &player_row, &player_col, input);
    }
    printf("Congratulations! You won!\n");
    return 0;
}

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
    maze[0][0] = '.';
    maze[ROWS - 1][COLS - 1] = 'E';
}

int check_win(char maze[ROWS][COLS]) {
    return maze[ROWS - 1][COLS - 1] == '.';
}

void move(char maze[ROWS][COLS], int *row, int *col, char dir) {
    int new_row = *row, new_col = *col;
    switch (dir) {
        case 'w': --new_row; break;
        case 'a': --new_col; break;
        case's': ++new_row; break;
        case 'd': ++new_col; break;
    }
    if (maze[new_row][new_col] == '.') {
        *row = new_row;
        *col = new_col;
    }
}