//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COORDINATES 100
#define MAX_MOVES 50

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate goal;
    bool is_solved;
    int moves;
    int distance;
} PathfindingProblem;

PathfindingProblem* create_problem(Coordinate start, Coordinate goal) {
    PathfindingProblem* problem = malloc(sizeof(PathfindingProblem));
    problem->start = start;
    problem->goal = goal;
    problem->is_solved = false;
    problem->moves = 0;
    problem->distance = 0;
    return problem;
}

void print_problem(PathfindingProblem* problem) {
    printf("Start: (%d, %d)\n", problem->start.x, problem->start.y);
    printf("Goal: (%d, %d)\n", problem->goal.x, problem->goal.y);
    printf("Moves: %d\n", problem->moves);
    printf("Distance: %d\n", problem->distance);
    printf("Is Solved: %s\n", problem->is_solved? "True" : "False");
}

bool is_valid_move(Coordinate* current_coord, Coordinate* next_coord) {
    return (next_coord->x >= 0 && next_coord->x < MAX_COORDINATES && 
            next_coord->y >= 0 && next_coord->y < MAX_COORDINATES && 
            current_coord->x!= next_coord->x && current_coord->y!= next_coord->y);
}

bool is_path_found(PathfindingProblem* problem) {
    return problem->is_solved;
}

void solve_problem(PathfindingProblem* problem) {
    if (is_path_found(problem)) {
        printf("Path already found!\n");
        return;
    }

    Coordinate* current_coord = &problem->start;
    Coordinate* next_coord;
    int moves = 0;
    int distance = 0;

    while (is_valid_move(current_coord, &next_coord)) {
        current_coord = next_coord;
        distance += 1;
        moves += 1;

        if (current_coord->x == problem->goal.x && current_coord->y == problem->goal.y) {
            problem->is_solved = true;
            printf("Path found: %d moves, %d distance\n", moves, distance);
            return;
        }

        if (current_coord->x == problem->goal.x || current_coord->y == problem->goal.y) {
            problem->is_solved = true;
            printf("Path found: %d moves, %d distance\n", moves, distance);
            return;
        }

        Coordinate* random_coord = malloc(sizeof(Coordinate));
        do {
            random_coord->x = rand() % MAX_COORDINATES;
            random_coord->y = rand() % MAX_COORDINATES;
        } while (is_valid_move(current_coord, random_coord));
        next_coord = random_coord;
    }

    problem->is_solved = false;
    printf("No path found!\n");
}

int main() {
    Coordinate start = {0, 0};
    Coordinate goal = {MAX_COORDINATES - 1, MAX_COORDINATES - 1};
    PathfindingProblem* problem = create_problem(start, goal);
    print_problem(problem);
    solve_problem(problem);
    free(problem);
    return 0;
}