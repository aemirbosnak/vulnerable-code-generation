//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: funny
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

int map[ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

struct node {
    int x, y;
    int f, g, h;
    struct node *parent;
};

struct list {
    struct node *data;
    struct list *next;
};

int abs(int a) {
    return a < 0 ? -a : a;
}

int heuristic(struct node *a, struct node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

int in_closed_list(struct node *q, struct list *closed_list) {
    while (closed_list != NULL) {
        if (closed_list->data->x == q->x && closed_list->data->y == q->y)
            return 1;
        closed_list = closed_list->next;
    }
    return 0;
}

int in_open_list(struct node *q, struct list *open_list) {
    while (open_list != NULL) {
        if (open_list->data->x == q->x && open_list->data->y == q->y)
            return 1;
        open_list = open_list->next;
    }
    return 0;
}

struct node* lowest_f(struct list* open_list) {
    struct list *ptr = open_list;
    struct node *min_f_node = open_list->data;
    while (ptr != NULL) {
        if (ptr->data->f < min_f_node->f)
            min_f_node = ptr->data;
        ptr = ptr->next;
    }
    return min_f_node;
}

void append(struct list **l, struct node *data) {
    struct list *new_node = (struct list*)malloc(sizeof(struct list));
    new_node->data = data;
    new_node->next = NULL;
    if (*l == NULL)
        *l = new_node;
    else {
        struct list *ptr = *l;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
}

void print_path(struct node *node) {
    if (node->parent != NULL)
        print_path(node->parent);
    printf("(%d,%d) -> ", node->x, node->y);
}

void a_star(struct node *start, struct node *end) {
    struct list *open_list = NULL;
    struct list *closed_list = NULL;
    append(&open_list, start);
    while (open_list != NULL) {
        struct node *cur = lowest_f(open_list);
        if (cur->x == end->x && cur->y == end->y) {
            printf("Found a path!\n");
            print_path(end);
            printf("\b\b  \n");
            return;
        }
        struct list *succ_list = NULL;
        if (cur->x - 1 >= 0 && map[cur->x-1][cur->y] == 0) {
            struct node *up = (struct node*)malloc(sizeof(struct node));
            up->x = cur->x - 1;
            up->y = cur->y;
            up->g = cur->g + 1;
            up->h = heuristic(up, end);
            up->f = up->g + up->h;
            up->parent = cur;
            if (!in_closed_list(up, closed_list) && !in_open_list(up, open_list))
                append(&succ_list, up);
        }
        if (cur->x + 1 < ROW && map[cur->x+1][cur->y] == 0) {
            struct node *down = (struct node*)malloc(sizeof(struct node));
            down->x = cur->x + 1;
            down->y = cur->y;
            down->g = cur->g + 1;
            down->h = heuristic(down, end);
            down->f = down->g + down->h;
            down->parent = cur;
            if (!in_closed_list(down, closed_list) && !in_open_list(down, open_list))
                append(&succ_list, down);
        }
        if (cur->y - 1 >= 0 && map[cur->x][cur->y-1] == 0) {
            struct node *left = (struct node*)malloc(sizeof(struct node));
            left->x = cur->x;
            left->y = cur->y - 1;
            left->g = cur->g + 1;
            left->h = heuristic(left, end);
            left->f = left->g + left->h;
            left->parent = cur;
            if (!in_closed_list(left, closed_list) && !in_open_list(left, open_list))
                append(&succ_list, left);
        }
        if (cur->y + 1 < COL && map[cur->x][cur->y+1] == 0) {
            struct node *right = (struct node*)malloc(sizeof(struct node));
            right->x = cur->x;
            right->y = cur->y + 1;
            right->g = cur->g + 1;
            right->h = heuristic(right, end);
            right->f = right->g + right->h;
            right->parent = cur;
            if (!in_closed_list(right, closed_list) && !in_open_list(right, open_list))
                append(&succ_list, right);
        }
        struct list *ptr = succ_list;
        while (ptr != NULL) {
            if (!in_open_list(ptr->data, open_list))
                append(&open_list, ptr->data);
            else {
                struct list *optr = open_list;
                while (optr != NULL) {
                    if (optr->data->x == ptr->data->x && optr->data->y == ptr->data->y) {
                        if (ptr->data->f < optr->data->f) {
                            optr->data->f = ptr->data->f;
                            optr->data->g = ptr->data->g;
                            optr->data->h = ptr->data->h;
                            optr->data->parent = cur;
                        }
                        break;
                    }
                    optr = optr->next;
                }
            }
            ptr = ptr->next;
        }
        struct list *q = open_list;
        open_list = open_list->next;
        q->next = closed_list;
        closed_list = q;
    }
    printf("Cannot find a path.\n");
}

int main() {
    struct node *start = (struct node*)malloc(sizeof(struct node));
    start->x = 1;
    start->y = 2;
    start->f = 0;
    start->g = 0;
    start->h = 0;
    start->parent = NULL;

    struct node *end = (struct node*)malloc(sizeof(struct node));
    end->x = 7;
    end->y = 8;
    end->f = 0;
    end->g = 0;
    end->h = 0;
    end->parent = NULL;

    a_star(start, end);

    return 0;
}