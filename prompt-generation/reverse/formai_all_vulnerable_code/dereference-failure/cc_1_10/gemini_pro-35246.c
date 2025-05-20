//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point start;
    point end;
    int **map;
    int size;
} maze;

maze *create_maze(int size)
{
    maze *m = malloc(sizeof(maze));
    m->size = size;
    m->map = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        m->map[i] = malloc(sizeof(int) * size);
    }
    return m;
}

void destroy_maze(maze *m)
{
    for (int i = 0; i < m->size; i++) {
        free(m->map[i]);
    }
    free(m->map);
    free(m);
}

void print_maze(maze *m)
{
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf("%d ", m->map[i][j]);
        }
        printf("\n");
    }
}

int is_valid_point(maze *m, point p)
{
    return p.x >= 0 && p.x < m->size && p.y >= 0 && p.y < m->size && m->map[p.x][p.y] == 0;
}

int is_goal_point(maze *m, point p)
{
    return p.x == m->end.x && p.y == m->end.y;
}

point *find_path(maze *m)
{
    point *path = malloc(sizeof(point) * (m->size * m->size));
    int path_size = 0;

    point current = m->start;
    while (!is_goal_point(m, current)) {
        // Try to move in all directions
        point directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            point next = {current.x + directions[i].x, current.y + directions[i].y};
            if (is_valid_point(m, next)) {
                path[path_size++] = next;
                current = next;
                break;
            }
        }
    }

    return path;
}

int main()
{
    // Create a maze
    maze *m = create_maze(10);
    m->start.x = 0;
    m->start.y = 0;
    m->end.x = 9;
    m->end.y = 9;

    // Add some obstacles
    m->map[3][3] = 1;
    m->map[3][4] = 1;
    m->map[3][5] = 1;
    m->map[4][3] = 1;
    m->map[4][5] = 1;
    m->map[5][3] = 1;
    m->map[5][4] = 1;
    m->map[5][5] = 1;

    // Print the maze
    print_maze(m);

    // Find a path through the maze
    point *path = find_path(m);

    // Print the path
    printf("Path:\n");
    for (int i = 0; i < 10; i++) {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }

    // Destroy the maze
    destroy_maze(m);
    free(path);

    return 0;
}