//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: innovative
// A maze-solving program.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef enum {NORTH, SOUTH, EAST, WEST} direction;
void init_map(int** map);
void print_map(int** map);
bool valid_move(int** map, int x, int y, direction dir);
void find_route(int** map, int* track, int n);
bool solved(int* track, int n);
int main()
{
    int i, j;
    int** map = NULL;
    int track[1024];
    // Create a 10x10 maze
    map = malloc(sizeof(int*)*10);
    for (i=0; i<10; i++) {
        map[i] = calloc(sizeof(int), 10);
    }
    // Initialize the maze
    init_map(map);
    // Print the maze
    print_map(map);
    // Find the exit
    find_route(map, track, 0);
    // Print the solution
    if (solved(track, 0)) {
        for (j=0; ; j++) {
            if (track[j] == -1) break;
            printf("%d ", track[j]);
        }
        printf("\n");
    } else {
        printf("No solution found.\n");
    }
    // Free the maze
    for (i=0; i<10; i++) {
        free(map[i]);
    }
    free(map);
    return EXIT_SUCCESS;
}
void init_map(int** map) {
    // Define the walls of the maze
    map[0][0] = 1;
    map[0][1] = 1;
    map[0][2] = 1;
    map[0][3] = 1;
    map[0][4] = 1;
    map[0][5] = 1;
    map[0][6] = 1;
    map[0][7] = 1;
    map[0][8] = 1;
    map[0][9] = 1;
    map[9][0] = 1;
    map[9][1] = 1;
    map[9][2] = 1;
    map[9][3] = 1;
    map[9][4] = 1;
    map[9][5] = 1;
    map[9][6] = 1;
    map[9][7] = 1;
    map[9][8] = 1;
    map[9][9] = 1;
    map[2][2] = 1;
    map[2][3] = 1;
    map[2][4] = 1;
    map[2][5] = 1;
    map[2][6] = 1;
    map[2][7] = 1;
    map[2][8] = 1;
    map[3][2] = 1;
    map[4][2] = 1;
    map[5][2] = 1;
    map[6][2] = 1;
    map[7][2] = 1;
    map[8][2] = 1;
    map[6][3] = 1;
    map[6][4] = 1;
    map[6][5] = 1;
    map[6][6] = 1;
    map[6][7] = 1;
}
void print_map(int** map) {
    int i, j;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            if (map[i][j]) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
bool valid_move(int** map, int x, int y, direction dir) {
    switch (dir) {
        case NORTH:
            return y > 0 && !map[y-1][x];
        case SOUTH:
            return y < 9 && !map[y+1][x];
        case EAST:
            return x < 9 && !map[y][x+1];
        case WEST:
            return x > 0 && !map[y][x-1];
    }
    return false;
}
void find_route(int** map, int* track, int n) {
    if (track[n] == -1) {
        return;
    }
    int x = track[n] % 10;
    int y = track[n] / 10;
    if (x == 9 && y == 9) {
        return;
    }
    if (valid_move(map, x, y, NORTH)) {
        track[n+1] = (y-1)*10 + x;
        find_route(map, track, n+1);
    }
    if (valid_move(map, x, y, SOUTH)) {
        track[n+1] = (y+1)*10 + x;
        find_route(map, track, n+1);
    }
    if (valid_move(map, x, y, EAST)) {
        track[n+1] = y*10 + x+1;
        find_route(map, track, n+1);
    }
    if (valid_move(map, x, y, WEST)) {
        track[n+1] = y*10 + x-1;
        find_route(map, track, n+1);
    }
    track[n] = -1;
}
bool solved(int* track, int n) {
    return track[n] == 99;
}