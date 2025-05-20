//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node {
    int x, y;
    char value;
    int g, f;
    bool closed;
    struct node* parent;
} node;

typedef struct list {
    node* data;
    struct list* next;
} list;

list* open_list = NULL;
list* closed_list = NULL;
node* map[5][5] = { NULL };

int calculate_heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

node* get_lowest_score_node() {
    list* cur = open_list;
    node* lowest = cur->data;
    while (cur != NULL) {
        if (cur->data->f < lowest->f) {
            lowest = cur->data;
        }
        cur = cur->next;
    }
    return lowest;
}

void add_to_list(list** head, node* data) {
    if (*head == NULL) {
        *head = malloc(sizeof(list));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    add_to_list(&(*head)->next, data);
}

void remove_from_list(list** head, node* data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        list* next = (*head)->next;
        free(*head);
        *head = next;
        return;
    }
    remove_from_list(&(*head)->next, data);
}

list* get_neighbors(node* n) {
    list* neighbors = NULL;
    int x = n->x;
    int y = n->y;
    if (x > 0 && map[x-1][y] != NULL) {
        add_to_list(&neighbors, map[x-1][y]);
    }
    if (x < 4 && map[x+1][y] != NULL) {
        add_to_list(&neighbors, map[x+1][y]);
    }
    if (y > 0 && map[x][y-1] != NULL) {
        add_to_list(&neighbors, map[x][y-1]);
    }
    if (y < 4 && map[x][y+1] != NULL) {
        add_to_list(&neighbors, map[x][y+1]);
    }
    return neighbors;
}

void print_path(node* n) {
    if (n == NULL) {
        printf("\n");
        return;
    }
    print_path(n->parent);
    printf("(%d, %d) ", n->x, n->y);
}

void a_star(int start_x, int start_y, int end_x, int end_y) {
    node* start = map[start_x][start_y];
    node* end = map[end_x][end_y];
    start->g = 0;
    start->f = calculate_heuristic(start_x, start_y, end_x, end_y);
    add_to_list(&open_list, start);
    while (open_list != NULL) {
        node* cur = get_lowest_score_node();
        if (cur == end) {
            printf("Path found: ");
            print_path(cur);
            return;
        }
        remove_from_list(&open_list, cur);
        cur->closed = true;
        add_to_list(&closed_list, cur);
        list* neighbors = get_neighbors(cur);
        list* cur_neighbor = neighbors;
        while (cur_neighbor != NULL) {
            node* n = cur_neighbor->data;
            if (!n->closed) {
                int new_g = cur->g + 1;
                if (new_g < n->g) {
                    n->parent = cur;
                    n->g = new_g;
                    n->f = new_g + calculate_heuristic(n->x, n->y, end_x, end_y);
                    if (!open_list) {
                        add_to_list(&open_list, n);
                    } else {
                        bool added = false;
                        list* cur_open = open_list;
                        while (cur_open != NULL) {
                            if (cur_open->data == n) {
                                added = true;
                                break;
                            }
                            cur_open = cur_open->next;
                        }
                        if (!added) {
                            add_to_list(&open_list, n);
                        }
                    }
                }
            }
            cur_neighbor = cur_neighbor->next;
        }
    }
    printf("No path found!\n");
}

int main() {
    node* start = malloc(sizeof(node));
    start->x = 0;
    start->y = 0;
    start->value = '.';
    start->g = 0;
    start->f = 0;
    start->closed = false;
    start->parent = NULL;
    map[start->x][start->y] = start;

    node* end = malloc(sizeof(node));
    end->x = 4;
    end->y = 4;
    end->value = '.';
    end->g = 0;
    end->f = 0;
    end->closed = false;
    end->parent = NULL;
    map[end->x][end->y] = end;

    node* wall1 = malloc(sizeof(node));
    wall1->x = 1;
    wall1->y = 2;
    wall1->value = '#';
    wall1->g = 0;
    wall1->f = 0;
    wall1->closed = false;
    wall1->parent = NULL;
    map[wall1->x][wall1->y] = NULL;

    node* wall2 = malloc(sizeof(node));
    wall2->x = 2;
    wall2->y = 2;
    wall2->value = '#';
    wall2->g = 0;
    wall2->f = 0;
    wall2->closed = false;
    wall2->parent = NULL;
    map[wall2->x][wall2->y] = NULL;

    a_star(0, 0, 4, 4);
    return 0;
}