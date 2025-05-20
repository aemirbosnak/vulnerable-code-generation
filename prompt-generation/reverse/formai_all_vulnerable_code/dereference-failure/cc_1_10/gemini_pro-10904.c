//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point start;
    point end;
} maze;

typedef struct node {
    point pos;
    struct node *next;
} node;

node *path[1000];
int path_length;
int path_found;

int is_in_bounds(maze *m, point *p) {
    return (p->x >= m->start.x && p->x <= m->end.x &&
            p->y >= m->start.y && p->y <= m->end.y);
}

int is_wall(char **map, point *p) {
    return map[p->y][p->x] == '#';
}

void add_to_path(point *p) {
    node *new = malloc(sizeof(node));
    new->pos = *p;
    new->next = NULL;
    path[path_length++] = new;
}

void print_path() {
    int i;
    printf("Path: ");
    for (i = 0; i < path_length; i++) {
        printf("(%d, %d) ", path[i]->pos.x, path[i]->pos.y);
    }
    printf("\n");
}

void free_path() {
    int i;
    for (i = 0; i < path_length; i++) {
        free(path[i]);
    }
    path_length = 0;
}

int find_path(char **map, maze *m, point *p) {
    if (!is_in_bounds(m, p) || is_wall(map, p)) {
        return 0;
    }

    if (p->x == m->end.x && p->y == m->end.y) {
        add_to_path(p);
        path_found = 1;
        return 1;
    }

    add_to_path(p);

    if (find_path(map, m, (point *) {p->x + 1, p->y})) return 1;
    if (find_path(map, m, (point *) {p->x - 1, p->y})) return 1;
    if (find_path(map, m, (point *) {p->x, p->y + 1})) return 1;
    if (find_path(map, m, (point *) {p->x, p->y - 1})) return 1;

    free_path();
    return 0;
}

int main() {
    char *map[] = {
        "########",
        "#......#",
        "##.###.#",
        "#..#.###",
        "#..#..##",
        "#.####.#",
        "##.###.#",
        "#......#",
        "########",
    };

    maze m = {{1, 1}, {7, 7}};

    if (find_path(map, &m, &m.start)) {
        print_path();
    } else {
        printf("No path found.\n");
    }

    return 0;
}