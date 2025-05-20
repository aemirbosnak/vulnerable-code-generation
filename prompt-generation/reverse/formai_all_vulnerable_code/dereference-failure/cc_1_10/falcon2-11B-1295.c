//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold the path
struct path {
    int x, y;
    struct path* next;
};

struct node {
    int x, y;
    int g;
    int h;
    int f;
    struct node* parent;
};

struct node* create_node(int x, int y) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->x = x;
    n->y = y;
    n->g = 0;
    n->h = 0;
    n->f = 0;
    n->parent = NULL;
    return n;
}

struct node* find_node(struct node* n, int x, int y) {
    if (n->x == x && n->y == y) {
        return n;
    }
    if (n->parent == NULL) {
        return NULL;
    }
    return find_node(n->parent, x, y);
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

struct node* search(struct node* start, struct node* end) {
    struct node* current = start;
    struct node* previous = NULL;
    struct node* parent = NULL;
    struct node* node = NULL;
    int i;
    for (i = 0; i < 100; i++) {
        if (current == end) {
            break;
        }
        node = find_node(current, current->x, current->y);
        if (node == NULL) {
            break;
        }
        if (node->parent == NULL) {
            current->g = current->f = current->h = 0;
            parent = current;
        } else {
            current = parent;
            parent = node;
        }
    }
    struct path* path = NULL;
    if (node!= NULL) {
        struct node* next = node->parent;
        struct node* prev = NULL;
        while (next!= NULL) {
            path = (struct path*)malloc(sizeof(struct path));
            path->x = next->x;
            path->y = next->y;
            prev = path;
            next = next->parent;
        }
    }
    return path;
}

int main() {
    struct node* start = create_node(0, 0);
    struct node* end = create_node(9, 9);
    struct node* node = create_node(2, 2);
    struct node* n = NULL;
    n = find_node(start, 3, 3);
    printf("Node at %d, %d\n", n->x, n->y);
    printf("Path: ");
    struct path* path = search(start, end);
    while (path!= NULL) {
        printf("%d, %d -> ", path->x, path->y);
        path = path->next;
    }
    printf("\n");
    return 0;
}