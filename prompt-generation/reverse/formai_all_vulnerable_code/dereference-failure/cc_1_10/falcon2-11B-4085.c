//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 10000000

struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node *parent;
};

struct node* create_node(int x, int y) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->x = x;
    node->y = y;
    node->f = INF;
    node->g = INF;
    node->h = 0;
    node->parent = NULL;
    return node;
}

void print_node(struct node* node) {
    printf("(%.2f, %.2f) ", node->x / 100.0, node->y / 100.0);
    printf("f: %d, g: %d, h: %d\n", node->f, node->g, node->h);
}

void print_path(struct node* node) {
    while (node!= NULL) {
        print_node(node);
        node = node->parent;
    }
}

int main() {
    struct node* start = create_node(0, 0);
    struct node* end = create_node(10, 10);

    start->g = 0;
    start->h = (end->x - start->x) * (end->x - start->x) + (end->y - start->y) * (end->y - start->y);
    start->f = start->g + start->h;

    struct node* open_list = create_node(0, 0);
    struct node* closed_list = create_node(0, 0);
    open_list->parent = NULL;
    closed_list->parent = NULL;

    open_list->x = start->x;
    open_list->y = start->y;
    open_list->f = start->f;
    open_list->g = start->g;
    open_list->h = start->h;

    closed_list->x = end->x;
    closed_list->y = end->y;
    closed_list->f = end->f;
    closed_list->g = end->g;
    closed_list->h = end->h;

    while (open_list->f!= closed_list->f) {
        struct node* current = open_list;

        if (current->x == end->x && current->y == end->y) {
            printf("Found the shortest path!\n");
            print_path(current);
            break;
        }

        struct node* next = NULL;

        for (struct node* neighbor = current->parent; neighbor!= NULL; neighbor = neighbor->parent) {
            if (neighbor->x == current->x + 1 && neighbor->y == current->y) {
                next = create_node(neighbor->x + 1, neighbor->y);
                break;
            } else if (neighbor->x == current->x - 1 && neighbor->y == current->y) {
                next = create_node(neighbor->x - 1, neighbor->y);
                break;
            } else if (neighbor->x == current->x && neighbor->y == current->y + 1) {
                next = create_node(neighbor->x, neighbor->y + 1);
                break;
            } else if (neighbor->x == current->x && neighbor->y == current->y - 1) {
                next = create_node(neighbor->x, neighbor->y - 1);
                break;
            }
        }

        if (next!= NULL) {
            next->parent = current;

            if (next->f > current->f + 1) {
                next->f = current->f + 1;
                next->g = current->g + 1;
                next->h = (next->x - end->x) * (next->x - end->x) + (next->y - end->y) * (next->y - end->y);
                if (open_list->f > next->f) {
                    open_list->parent = next;
                    open_list->f = next->f;
                    open_list->g = next->g;
                    open_list->h = next->h;
                } else if (open_list->f == next->f && open_list->g > next->g) {
                    open_list->parent = next;
                    open_list->g = next->g;
                    open_list->h = next->h;
                }
            }
        }

        struct node* temp = open_list;
        open_list = open_list->parent;
        free(temp);
    }

    return 0;
}