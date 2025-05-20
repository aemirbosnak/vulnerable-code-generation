//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point points[ROWS * COLS];
    int size;
} Path;

typedef struct {
    int g;
    int h;
    int f;
    Point parent;
} NodeInfo;

void print_board(int board[ROWS][COLS], Point start, Point goal) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == start.row && j == start.col)
                printf("S ");
            else if (i == goal.row && j == goal.col)
                printf("G ");
            else if (board[i][j] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int heuristic(Point current, Point goal) {
    return abs(current.row - goal.row) + abs(current.col - goal.col);
}

int is_valid(Point point, int board[ROWS][COLS]) {
    if (point.row < 0 || point.row >= ROWS || point.col < 0 || point.col >= COLS)
        return 0;
    if (board[point.row][point.col] == 1)
        return 0;
    return 1;
}

NodeInfo get_node_info(Point point, int board[ROWS][COLS], Point goal, Point parent) {
    NodeInfo info;
    int g, h;

    g = parent.row == -1 ? 0 : 1 + board[parent.row][parent.col];
    h = heuristic(point, goal);
    info.g = g;
    info.h = h;
    info.f = g + h;
    info.parent = parent;
    return info;
}

Path get_path(Point start, Point goal, int board[ROWS][COLS]) {
    NodeInfo nodes[ROWS][COLS] = { 0 };
    Point open_set[ROWS * COLS];
    Point closed_set[ROWS * COLS];
    int num_open_set = 0, num_closed_set = 0;
    int i, j, k;
    Point current, neighbor;
    NodeInfo current_info, neighbor_info;

    /* initialize start node */
    nodes[start.row][start.col] = get_node_info(start, board, goal, (Point) { -1, -1 });
    open_set[num_open_set++] = start;

    while (num_open_set > 0) {
        /* find the open node with the lowest f value */
        int lowest_f_index = 0;
        for (i = 0; i < num_open_set; i++) {
            if (nodes[open_set[i].row][open_set[i].col].f < nodes[open_set[lowest_f_index].row][open_set[lowest_f_index].col].f)
                lowest_f_index = i;
        }
        current = open_set[lowest_f_index];

        /* if we have reached the goal, construct the path */
        if (current.row == goal.row && current.col == goal.col) {
            Point path[ROWS * COLS];
            int path_index = 0;
            Path result;

            while (current.row != -1 && current.col != -1) {
                path[path_index++] = current;
                current = nodes[current.row][current.col].parent;
            }
            result.size = path_index;
            for (i = 0, j = path_index - 1; i < path_index && j >= 0; i++, j--) {
                result.points[i] = path[j];
            }
            return result;
        }
        /* move current node from open_set to closed_set */
        open_set[lowest_f_index] = open_set[--num_open_set];
        closed_set[num_closed_set++] = current;

        /* for each neighbor of current */
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if ((i == 0 && j == 0) || (i != 0 && j != 0))
                    continue;
                neighbor = (Point) { current.row + i, current.col + j };
                if (!is_valid(neighbor, board))
                    continue;

                /* check if neighbor is in closed_set */
                for (k = 0; k < num_closed_set; k++) {
                    if (neighbor.row == closed_set[k].row && neighbor.col == closed_set[k].col)
                        goto skip;
                }

                /* calculate neighbor info and add it to open_set */
                neighbor_info = get_node_info(neighbor, board, goal, current);
                if (nodes[neighbor.row][neighbor.col].f == 0 || neighbor_info.f < nodes[neighbor.row][neighbor.col].f) {
                    nodes[neighbor.row][neighbor.col] = neighbor_info;
                    open_set[num_open_set++] = neighbor;
                }

            skip:;
            }
        }

    }
    /* no path found */
    Path result;
    result.size = -1;
    return result;
}

int main() {
    int board[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    Point start = { 0, 0 };
    Point goal = { 9, 9 };
    Path path = get_path(start, goal, board);
    printf("Board:\n");
    print_board(board, start, goal);
    if (path.size == -1) {
        printf("No path found\n");
    } else {
        printf("Path:\n");
        for (int i = 0; i < path.size; i++) {
            printf("(%d,%d)\n", path.points[i].row, path.points[i].col);
        }
    }
    return 0;
}