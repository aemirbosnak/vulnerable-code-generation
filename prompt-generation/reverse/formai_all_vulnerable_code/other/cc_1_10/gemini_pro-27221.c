//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t start;
    point_t end;
    int **map;
} pathfinding_t;

int **create_map(void) {
    int i, j;
    int **map = (int **) malloc(sizeof(int *) * MAP_HEIGHT);
    assert(map);

    for (i = 0; i < MAP_HEIGHT; i++) {
        map[i] = (int *) malloc(sizeof(int) * MAP_WIDTH);
        assert(map[i]);

        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = rand() % 100;
        }
    }

    return map;
}

void free_map(int **map) {
    int i;

    for (i = 0; i < MAP_HEIGHT; i++) {
        free(map[i]);
    }

    free(map);
}

pathfinding_t *create_pathfinding(point_t start, point_t end, int **map) {
    pathfinding_t *pathfinding = (pathfinding_t *) malloc(sizeof(pathfinding_t));
    assert(pathfinding);

    pathfinding->start = start;
    pathfinding->end = end;
    pathfinding->map = map;

    return pathfinding;
}

void free_pathfinding(pathfinding_t *pathfinding) {
    free(pathfinding);
}

int is_valid_point(pathfinding_t *pathfinding, point_t point) {
    return (point.x >= 0 && point.x < MAP_WIDTH && point.y >= 0 && point.y < MAP_HEIGHT && pathfinding->map[point.y][point.x] != 0);
}

int is_end_point(pathfinding_t *pathfinding, point_t point) {
    return (point.x == pathfinding->end.x && point.y == pathfinding->end.y);
}

int **create_visited_map(void) {
    int i, j;
    int **visited_map = (int **) malloc(sizeof(int *) * MAP_HEIGHT);
    assert(visited_map);

    for (i = 0; i < MAP_HEIGHT; i++) {
        visited_map[i] = (int *) malloc(sizeof(int) * MAP_WIDTH);
        assert(visited_map[i]);

        for (j = 0; j < MAP_WIDTH; j++) {
            visited_map[i][j] = 0;
        }
    }

    return visited_map;
}

void free_visited_map(int **visited_map) {
    int i;

    for (i = 0; i < MAP_HEIGHT; i++) {
        free(visited_map[i]);
    }

    free(visited_map);
}

int **create_path_map(void) {
    int i, j;
    int **path_map = (int **) malloc(sizeof(int *) * MAP_HEIGHT);
    assert(path_map);

    for (i = 0; i < MAP_HEIGHT; i++) {
        path_map[i] = (int *) malloc(sizeof(int) * MAP_WIDTH);
        assert(path_map[i]);

        for (j = 0; j < MAP_WIDTH; j++) {
            path_map[i][j] = 0;
        }
    }

    return path_map;
}

void free_path_map(int **path_map) {
    int i;

    for (i = 0; i < MAP_HEIGHT; i++) {
        free(path_map[i]);
    }

    free(path_map);
}

int find_path(pathfinding_t *pathfinding, int **visited_map, int **path_map) {
    int i, j;
    point_t current_point;
    point_t next_point;

    current_point.x = pathfinding->start.x;
    current_point.y = pathfinding->start.y;

    while (!is_end_point(pathfinding, current_point)) {
        visited_map[current_point.y][current_point.x] = 1;

        // Check all 8 possible next points
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                next_point.x = current_point.x + i;
                next_point.y = current_point.y + j;

                if (is_valid_point(pathfinding, next_point) && !visited_map[next_point.y][next_point.x]) {
                    path_map[next_point.y][next_point.x] = path_map[current_point.y][current_point.x] + 1;
                    current_point = next_point;
                    break;
                }
            }
        }
    }

    return path_map[pathfinding->end.y][pathfinding->end.x];
}

void print_map(int **map) {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%d ", map[i][j]);
        }

        printf("\n");
    }
}

void print_path(int **path_map) {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (path_map[i][j] == 0) {
                printf(" ");
            } else {
                printf("%d", path_map[i][j]);
            }
        }

        printf("\n");
    }
}

int main(void) {
    int **map = create_map();
    pathfinding_t *pathfinding = create_pathfinding((point_t) { 0, 0 }, (point_t) { 99, 99 }, map);
    int **visited_map = create_visited_map();
    int **path_map = create_path_map();
    int path_length;

    path_length = find_path(pathfinding, visited_map, path_map);

    printf("Map:\n");
    print_map(map);

    printf("Path:\n");
    print_path(path_map);

    printf("Path length: %d\n", path_length);

    free_pathfinding(pathfinding);
    free_map(map);
    free_visited_map(visited_map);
    free_path_map(path_map);

    return 0;
}