//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAZE_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Maze;

typedef struct {
    Maze maze;
    int size;
    char **data;
} MazeProblem;

int is_valid_point(MazeProblem *problem, Point point) {
    return point.x >= 0 && point.x < problem->size &&
           point.y >= 0 && point.y < problem->size &&
           problem->data[point.x][point.y] != '#';
}

int is_end_point(MazeProblem *problem, Point point) {
    return point.x == problem->maze.end.x &&
           point.y == problem->maze.end.y;
}

void print_maze(MazeProblem *problem) {
    for (int i = 0; i < problem->size; i++) {
        for (int j = 0; j < problem->size; j++) {
            printf("%c", problem->data[i][j]);
        }
        printf("\n");
    }
}

int solve_maze(MazeProblem *problem, Point current) {
    if (!is_valid_point(problem, current)) {
        return 0;
    }
    if (is_end_point(problem, current)) {
        return 1;
    }
    problem->data[current.x][current.y] = '#';
    if (solve_maze(problem, (Point){current.x + 1, current.y})) {
        return 1;
    }
    if (solve_maze(problem, (Point){current.x - 1, current.y})) {
        return 1;
    }
    if (solve_maze(problem, (Point){current.x, current.y + 1})) {
        return 1;
    }
    if (solve_maze(problem, (Point){current.x, current.y - 1})) {
        return 1;
    }
    problem->data[current.x][current.y] = ' ';
    return 0;
}

MazeProblem *create_maze_problem(Maze maze, int size, char **data) {
    MazeProblem *problem = malloc(sizeof(MazeProblem));
    problem->maze = maze;
    problem->size = size;
    problem->data = data;
    return problem;
}

void free_maze_problem(MazeProblem *problem) {
    for (int i = 0; i < problem->size; i++) {
        free(problem->data[i]);
    }
    free(problem->data);
    free(problem);
}

int main() {
    Maze maze = {{0, 0}, {9, 9}};
    int size = 10;
    char *data[] = {
        "########",
        "#......#",
        "#.##...#",
        "#..##..#",
        "#..##..#",
        "#......#",
        "########",
    };
    MazeProblem *problem = create_maze_problem(maze, size, data);
    if (solve_maze(problem, problem->maze.start)) {
        printf("Solution found:\n");
        print_maze(problem);
    } else {
        printf("No solution found.\n");
    }
    free_maze_problem(problem);
    return 0;
}