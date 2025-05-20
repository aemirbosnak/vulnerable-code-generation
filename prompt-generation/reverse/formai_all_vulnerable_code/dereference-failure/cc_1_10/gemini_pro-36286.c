//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

typedef struct {
    Point **grid;
    int width, height;
} Grid;

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->grid = malloc(sizeof(Point *) * height);
    for (int i = 0; i < height; i++) {
        grid->grid[i] = malloc(sizeof(Point) * width);
    }
    return grid;
}

void destroy_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

Path *find_path(Grid *grid, Point start, Point end) {
    // Initialize the open and closed sets.
    Path *open_set = malloc(sizeof(Path));
    open_set->size = 0;
    open_set->points = malloc(sizeof(Point));
    open_set->points[open_set->size++] = start;

    Path *closed_set = malloc(sizeof(Path));
    closed_set->size = 0;
    closed_set->points = malloc(sizeof(Point));

    // While the open set is not empty.
    while (open_set->size > 0) {
        // Find the point in the open set with the lowest f-score.
        int lowest_f_score_index = 0;
        for (int i = 1; i < open_set->size; i++) {
            if (open_set->points[i].x + open_set->points[i].y < open_set->points[lowest_f_score_index].x + open_set->points[lowest_f_score_index].y) {
                lowest_f_score_index = i;
            }
        }

        // Current point is the point with the lowest f-score.
        Point current = open_set->points[lowest_f_score_index];

        // If the current point is the end point, then we have found the path.
        if (current.x == end.x && current.y == end.y) {
            return open_set;
        }

        // Move the current point from the open set to the closed set.
        closed_set->points[closed_set->size++] = current;
        open_set->points[lowest_f_score_index] = open_set->points[open_set->size - 1];
        open_set->size--;

        // For each neighbor of the current point.
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighbor is not the current point.
                if (i != 0 || j != 0) {
                    // If the neighbor is within the grid.
                    if (current.x + i >= 0 && current.x + i < grid->width && current.y + j >= 0 && current.y + j < grid->height) {
                        // If the neighbor is not in the closed set.
                        int in_closed_set = 0;
                        for (int k = 0; k < closed_set->size; k++) {
                            if (closed_set->points[k].x == current.x + i && closed_set->points[k].y == current.y + j) {
                                in_closed_set = 1;
                                break;
                            }
                        }
                        if (!in_closed_set) {
                            // If the neighbor is not in the open set.
                            int in_open_set = 0;
                            for (int k = 0; k < open_set->size; k++) {
                                if (open_set->points[k].x == current.x + i && open_set->points[k].y == current.y + j) {
                                    in_open_set = 1;
                                    break;
                                }
                            }
                            if (!in_open_set) {
                                // Add the neighbor to the open set.
                                open_set->points[open_set->size++] = (Point) {current.x + i, current.y + j};
                            }
                        }
                    }
                }
            }
        }
    }

    // If the open set is empty, then there is no path.
    return NULL;
}

void print_path(Path *path) {
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
    }
}

int main() {
    // Create a grid.
    Grid *grid = create_grid(10, 10);

    // Set the start and end points.
    Point start = {0, 0};
    Point end = {9, 9};

    // Find the path.
    Path *path = find_path(grid, start, end);

    // Print the path.
    if (path != NULL) {
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    // Destroy the grid.
    destroy_grid(grid);

    return 0;
}