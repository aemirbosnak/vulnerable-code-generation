//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point *points;
    int size;
} path;

typedef struct {
    char **grid;
    int width;
    int height;
} maze;

maze *maze_create(int width, int height) {
    int i;
    maze *m = malloc(sizeof(maze));
    m->grid = malloc(sizeof(char *) * height);
    for (i = 0; i < height; i++) {
        m->grid[i] = malloc(sizeof(char) * width);
    }
    m->width = width;
    m->height = height;
    return m;
}

void maze_free(maze *m) {
    int i;
    for (i = 0; i < m->height; i++) {
        free(m->grid[i]);
    }
    free(m->grid);
    free(m);
}

void maze_print(maze *m) {
    int i, j;
    for (i = 0; i < m->height; i++) {
        for (j = 0; j < m->width; j++) {
            printf("%c", m->grid[i][j]);
        }
        printf("\n");
    }
}

int maze_is_valid(maze *m, point p) {
    return p.x >= 0 && p.x < m->width && p.y >= 0 && p.y < m->height && m->grid[p.y][p.x] != '#';
}

path *path_create(int size) {
    path *p = malloc(sizeof(path));
    p->points = malloc(sizeof(point) * size);
    p->size = 0;
    return p;
}

void path_free(path *p) {
    free(p->points);
    free(p);
}

void path_add(path *p, point point) {
    if (p->size == p->size) {
        p->points = realloc(p->points, sizeof(point) * (p->size + 1));
    }
    p->points[p->size] = point;
    p->size++;
}

int path_is_valid(maze *m, path *p) {
    int i;
    for (i = 0; i < p->size; i++) {
        if (!maze_is_valid(m, p->points[i])) {
            return 0;
        }
    }
    return 1;
}

path *maze_solve(maze *m, point start, point end) {
    int i;
    path *p = path_create(m->width * m->height);
    path_add(p, start);
    while (p->size > 0) {
        point current = p->points[p->size - 1];
        if (current.x == end.x && current.y == end.y) {
            return p;
        }
        for (i = 0; i < 4; i++) {
            point next;
            switch (i) {
                case 0:
                    next.x = current.x + 1;
                    next.y = current.y;
                    break;
                case 1:
                    next.x = current.x - 1;
                    next.y = current.y;
                    break;
                case 2:
                    next.x = current.x;
                    next.y = current.y + 1;
                    break;
                case 3:
                    next.x = current.x;
                    next.y = current.y - 1;
                    break;
            }
            if (maze_is_valid(m, next) && !path_is_valid(m, p)) {
                path_add(p, next);
            }
        }
        p->size--;
    }
    return NULL;
}

int main() {
    int i, j;
    maze *m = maze_create(10, 10);
    for (i = 0; i < m->height; i++) {
        for (j = 0; j < m->width; j++) {
            m->grid[i][j] = '.';
        }
    }
    m->grid[0][0] = '#';
    m->grid[0][1] = '#';
    m->grid[0][2] = '#';
    m->grid[0][3] = '#';
    m->grid[0][4] = '#';
    m->grid[1][0] = '#';
    m->grid[1][1] = '#';
    m->grid[1][2] = '#';
    m->grid[1][3] = '#';
    m->grid[1][4] = '#';
    m->grid[2][0] = '#';
    m->grid[2][1] = '#';
    m->grid[2][2] = '#';
    m->grid[2][3] = '#';
    m->grid[2][4] = '#';
    m->grid[3][0] = '#';
    m->grid[3][1] = '#';
    m->grid[3][2] = '#';
    m->grid[3][3] = '#';
    m->grid[3][4] = '#';
    m->grid[4][0] = '#';
    m->grid[4][1] = '#';
    m->grid[4][2] = '#';
    m->grid[4][3] = '#';
    m->grid[4][4] = '#';
    m->grid[5][0] = '#';
    m->grid[5][1] = '#';
    m->grid[5][2] = '#';
    m->grid[5][3] = '#';
    m->grid[5][4] = '#';
    m->grid[6][0] = '#';
    m->grid[6][1] = '#';
    m->grid[6][2] = '#';
    m->grid[6][3] = '#';
    m->grid[6][4] = '#';
    m->grid[7][0] = '#';
    m->grid[7][1] = '#';
    m->grid[7][2] = '#';
    m->grid[7][3] = '#';
    m->grid[7][4] = '#';
    m->grid[8][0] = '#';
    m->grid[8][1] = '#';
    m->grid[8][2] = '#';
    m->grid[8][3] = '#';
    m->grid[8][4] = '#';
    m->grid[9][0] = '#';
    m->grid[9][1] = '#';
    m->grid[9][2] = '#';
    m->grid[9][3] = '#';
    m->grid[9][4] = '#';
    maze_print(m);
    path *p = maze_solve(m, (point) { 0, 0 }, (point) { 9, 9 });
    if (p != NULL) {
        printf("Path found:\n");
        for (i = 0; i < p->size; i++) {
            printf("(%d, %d)\n", p->points[i].x, p->points[i].y);
        }
    } else {
        printf("No path found.\n");
    }
    path_free(p);
    maze_free(m);
    return 0;
}