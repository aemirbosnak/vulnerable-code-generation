//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** create_maze(int width, int height) {
    char** maze = (char**) malloc(height * sizeof(char*));
    for(int i=0; i<height; ++i) {
        maze[i] = (char*) malloc(width * sizeof(char));
        memset(maze[i], '#', width);
    }
    return maze;
}

void print_maze(char** maze, int width, int height) {
    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

typedef struct Point {
    int x;
    int y;
} Point;

int can_move(char** maze, int width, int height, Point pos) {
    if(pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height) {
        return 0;
    }
    return maze[pos.y][pos.x] == ' ';
}

void mark_maze(char** maze, int width, int height, Point pos, char mark) {
    maze[pos.y][pos.x] = mark;
}

Point find_start(char** maze, int width, int height) {
    Point pos = {0, 0};
    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            if(maze[i][j] == 'S') {
                pos.x = j;
                pos.y = i;
                return pos;
            }
        }
    }
    return pos;
}

int dfs(char** maze, int width, int height, Point pos, Point dest) {
    if(!can_move(maze, width, height, pos) || maze[pos.y][pos.x] == '#') {
        return 0;
    }
    if(pos.x == dest.x && pos.y == dest.y) {
        return 1;
    }

    int found = 0;
    mark_maze(maze, width, height, pos, '#');

    Point next_pos = {pos.x-1, pos.y};
    found |= dfs(maze, width, height, next_pos, dest);

    next_pos.x = pos.x + 1;
    next_pos.y = pos.y;
    found |= dfs(maze, width, height, next_pos, dest);

    next_pos.x = pos.x;
    next_pos.y = pos.y - 1;
    found |= dfs(maze, width, height, next_pos, dest);

    next_pos.x = pos.x;
    next_pos.y = pos.y + 1;
    found |= dfs(maze, width, height, next_pos, dest);

    mark_maze(maze, width, height, pos, ' ');
    return found;
}

int main() {
    int maze_width = 20;
    int maze_height = 10;

    char** maze = create_maze(maze_width, maze_height);

    // Put some walls in the maze
    for(int i=2; i<maze_width-2; ++i) {
        maze[3][i] = '#';
    }

    for(int i=2; i<maze_height-2; ++i) {
        maze[i][7] = '#';
    }

    // Put the start and end points
    maze[0][0] = 'S';
    maze[maze_height-1][maze_width-1] = 'E';

    // Print the maze
    printf("Original maze:\n");
    print_maze(maze, maze_width, maze_height);

    // Find the route using DFS
    Point start_pos = find_start(maze, maze_width, maze_height);
    Point dest_pos = {maze_width-1, maze_height-1};
    int found_route = dfs(maze, maze_width, maze_height, start_pos, dest_pos);

    // Print the maze with the route found
    if(found_route) {
        printf("\n\nRoute found:\n");
    } else {
        printf("\n\nNo route found!\n");
    }
    print_maze(maze, maze_width, maze_height);

    // Free the memory
    for(int i=0; i<maze_height; ++i) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}