//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
// C program to implement A* search algorithm in a medieval-style map

#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 15

struct node {
    int row, col;
    int g, h, f;
    struct node *parent;
};

int map[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0}
};

struct node *
create_node(int row, int col, int g, int h, int f, struct node *parent)
{
    struct node *n = malloc(sizeof(struct node));
    n->row = row;
    n->col = col;
    n->g = g;
    n->h = h;
    n->f = f;
    n->parent = parent;
    return n;
}

int
heuristic(int r1, int c1, int r2, int c2)
{
    // Manhattan distance
    return abs(r1 - r2) + abs(c1 - c2);
}

struct node *
find_min_f(struct node **list, int size)
{
    int i, min_f = 999999, min_index;
    for (i = 0; i < size; i++) {
        if (list[i] == NULL) continue;
        if (list[i]->f < min_f) {
            min_f = list[i]->f;
            min_index = i;
        }
    }
    if (min_f == 999999) return NULL;
    return list[min_index];
}

int
is_valid(int row, int col)
{
    if (row < 0 || row >= ROW || col < 0 || col >= COL) return 0;
    if (map[row][col] != 0) return 0;
    return 1;
}

struct node **
get_neighbors(struct node *curr, int *size)
{
    int i, j, row = curr->row, col = curr->col;
    int rows[] = {0, -1, 1, 0};
    int cols[] = {-1, 0, 0, 1};
    struct node **neighbors = malloc(4 * sizeof(struct node *));
    *size = 0;
    for (i = 0; i < 4; i++) {
        int nrow = row + rows[i];
        int ncol = col + cols[i];
        if (is_valid(nrow, ncol)) {
            neighbors[*size] = create_node(
                nrow, ncol, curr->g + 1,
                heuristic(nrow, ncol, ROW - 1, COL - 1),
                curr->g + 1 + heuristic(nrow, ncol, ROW - 1, COL - 1),
                curr
            );
            (*size)++;
        }
    }
    return neighbors;
}

void
print_result(struct node *goal)
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (i == 0 && j == 0) printf("S  ");
            else if (i == ROW - 1 && j == COL - 1) printf("E  ");
            else if (map[i][j] == 8) printf("#  ");
            else {
                int in_path = 0;
                struct node *node = goal;
                while (node != NULL) {
                    if (node->row == i && node->col == j) {
                        printf(".  ");
                        in_path = 1;
                        break;
                    }
                    node = node->parent;
                }
                if (!in_path) printf("   ");
            }
        }
        printf("\n");
    }
}

void
a_star_search()
{
    int i, size = 1;
    struct node *start = create_node(0, 0, 0, heuristic(0, 0, ROW - 1, COL - 1), heuristic(0, 0, ROW - 1, COL - 1), NULL);
    struct node *closed_list[ROW * COL] = {NULL};
    struct node **open_list = malloc(ROW * COL * sizeof(struct node *));
    open_list[0] = start;
    while (1) {
        struct node *curr = find_min_f(open_list, size);
        if (curr == NULL) {
            printf("No path found.\n");
            return;
        }
        if (curr->row == ROW - 1 && curr->col == COL - 1) {
            printf("Path found!\n");
            print_result(curr);
            return;
        }
        for (i = 0; i < size; i++) {
            if (open_list[i] == curr) {
                open_list[i] = NULL;
                break;
            }
        }
        closed_list[i] = curr;
        int n_size;
        struct node **neighbors = get_neighbors(curr, &n_size);
        for (i = 0; i < n_size; i++) {
            int in_closed_list = 0, in_open_list = 0;
            struct node *neighbor = neighbors[i];
            if (neighbor->row == ROW - 1 && neighbor->col == COL - 1) {
                printf("Path found!\n");
                print_result(neighbor);
                return;
            }
            for (int j = 0; j < size; j++) {
                if (closed_list[j] != NULL && neighbor->row == closed_list[j]->row && neighbor->col == closed_list[j]->col) {
                    in_closed_list = 1;
                    break;
                }
            }
            if (in_closed_list) {
                free(neighbor);
                continue;
            }
            for (int j = 0; j < size; j++) {
                if (open_list[j] != NULL && neighbor->row == open_list[j]->row && neighbor->col == open_list[j]->col) {
                    in_open_list = 1;
                    if (neighbor->g < open_list[j]->g) {
                        open_list[j]->g = neighbor->g;
                        open_list[j]->f = neighbor->f;
                        open_list[j]->parent = neighbor->parent;
                    }
                    free(neighbor);
                    break;
                }
            }
            if (!in_open_list) {
                open_list[size] = neighbor;
                size++;
            }
        }
    }
}

int
main()
{
    a_star_search();
    return 0;
}