//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 15
#define COL 20
#define MAX_NODES 100
#define BLOCKED 1
#define FREE 0

int grid[ROW][COL] = {{FREE, FREE, FREE, BLOCKED, FREE, FREE, FREE, FREE, FREE, FREE, BLOCKED, FREE, FREE, FREE, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED},
                        {FREE, BLOCKED, FREE, BLOCKED, FREE, FREE, BLOCKED, FREE, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, FREE, FREE, FREE, FREE},
                        {FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED},
                        {FREE, FREE, FREE, FREE, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, FREE, FREE, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, BLOCKED, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, FREE, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, FREE, BLOCKED, FREE, BLOCKED, BLOCKED, FREE, FREE, BLOCKED, FREE, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, FREE, FREE, FREE, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, FREE, BLOCKED, BLOCKED, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {BLOCKED, BLOCKED, FREE, FREE, BLOCKED, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, FREE, FREE, FREE, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, BLOCKED, FREE, FREE, FREE, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, FREE, FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE},
                        {FREE, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, FREE, FREE, FREE, FREE, BLOCKED, BLOCKED, FREE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED}};

int n = ROW;
int m = COL;

struct node {
    int x, y;
    struct node *parent;
    double f, g, h;
};

typedef struct node Node;

int heuristic(Node *current, Node *goal) {
    int dx = abs(current->x - goal->x);
    int dy = abs(current->y - goal->y);
    int res = (dx + dy);
    return res;
}

int is_valid(int x, int y, int grid[][COL]) {
    if (x < 0 || x >= ROW) return 0;
    if (y < 0 || y >= COL) return 0;
    if (grid[x][y] == BLOCKED) return 0;
    return 1;
}

void print_grid(int grid[][COL], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_goal(Node *current, Node *goal) {
    if (current->x == goal->x && current->y == goal->y) {
        return 1;
    }
    return 0;
}

void reconstruct_path(Node *current) {
    if (current->parent == NULL) {
        printf("(%d, %d)\n", current->x, current->y);
        return;
    }
    reconstruct_path(current->parent);
    printf("(%d, %d)\n", current->x, current->y);
}

Node *get_lowest_f_score_node(Node *open_set[]) {
    int i;
    Node *lowest = open_set[0];

    for (i = 1; i < MAX_NODES; i++) {
        if (open_set[i] == NULL) {
            continue;
        }
        if (open_set[i]->f < lowest->f) {
            lowest = open_set[i];
        }
    }

    return lowest;
}

int main() {
    int start_x, start_y, goal_x, goal_y;

    printf("Enter starting point co-ordinates (row-column): ");
    scanf("%d-%d", &start_x, &start_y);

    printf("Enter goal point co-ordinates (row-column): ");
    scanf("%d-%d", &goal_x, &goal_y);

    Node *start = (Node *) malloc(sizeof(Node));
    start->x = start_x;
    start->y = start_y;
    start->parent = NULL;
    start->f = 0;
    start->g = 0;
    start->h = 0;

    Node *goal = (Node *) malloc(sizeof(Node));
    goal->x = goal_x;
    goal->y = goal_y;

    Node *open_set[MAX_NODES], *closed_set[MAX_NODES];
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        open_set[i] = NULL;
        closed_set[i] = NULL;
    }

    open_set[0] = start;

    int count = 1;

    while (count > 0) {
        Node *current = get_lowest_f_score_node(open_set);
        if (is_goal(current, goal)) {
            reconstruct_path(current);
            break;
        }

        for (i = 0; i < MAX_NODES; i++) {
            if (open_set[i] == current) {
                open_set[i] = NULL;
                break;
            }
        }

        closed_set[count-1] = current;

        // Get neighbors
        Node *neighbors[8];
        int nx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int ny[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (i = 0; i < 8; i++) {
            int nx_pos = current->x + nx[i];
            int ny_pos = current->y + ny[i];
            if (!is_valid(nx_pos, ny_pos, grid)) {
                continue;
            }

            Node *neighbor = (Node *) malloc(sizeof(Node));
            neighbor->x = nx_pos;
            neighbor->y = ny_pos;
            neighbor->parent = current;
            neighbor->g = current->g + 1;
            neighbor->h = heuristic(neighbor, goal);
            neighbor->f = neighbor->g + neighbor->h;

            // Check if neighbor is in closed_set
            int in_closed_set = 0;
            for (j = 0; j < MAX_NODES; j++) {
                if (closed_set[j] == NULL) {
                    continue;
                }
                if (closed_set[j]->x == neighbor->x && closed_set[j]->y == neighbor->y) {
                    in_closed_set = 1;
                    break;
                }
            }

            if (in_closed_set) {
                free(neighbor);
                continue;
            }

            // Check if neighbor is in open_set
            int in_open_set = 0;
            for (j = 0; j < MAX_NODES; j++) {
                if (open_set[j] == NULL) {
                    continue;
                }
                if (open_set[j]->x == neighbor->x && open_set[j]->y == neighbor->y) {
                    in_open_set = 1;
                    break;
                }
            }

            if (!in_open_set) {
                open_set[count] = neighbor;
                count++;
                continue;
            }
            else {
                free(neighbor);
            }
        }
    }

    return 0;
}