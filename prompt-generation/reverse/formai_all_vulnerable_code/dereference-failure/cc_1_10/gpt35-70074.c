//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL 1
#define PATH 0
#define VISITED 2

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 1, 1, 0}
};

typedef struct Node {
    int row;
    int col;
    int g_score;
    int h_score;
    int f_score;
    bool is_closed;
    struct Node* parent;
} Node;

Node* start_node;
Node* goal_node;

Node* create_node(int row, int col) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g_score = 0;
    node->h_score = 0;
    node->f_score = 0;
    node->is_closed = false;
    node->parent = NULL;
    return node;
}

void print_maze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == WALL) {
                printf("%c ", '#');
            }
            else if(maze[i][j] == PATH) {
                printf("%c ", '.');
            }
            else if(maze[i][j] == VISITED) {
                printf("%c ", '+');
            }
        }
        printf("\n");
    }
}

bool is_valid_move(int row, int col) {
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == PATH) {
        return true;
    }
    return false;
}

int heuristic_cost(int curr_row, int curr_col, int goal_row, int goal_col) {
    return abs(curr_row - goal_row) + abs(curr_col - goal_col);
}

void calculate_scores(Node* curr_node) {
    curr_node->g_score = abs(curr_node->row - start_node->row) + abs(curr_node->col - start_node->col);
    curr_node->h_score = heuristic_cost(curr_node->row, curr_node->col, goal_node->row, goal_node->col);
    curr_node->f_score = curr_node->g_score + curr_node->h_score;
}

void update_scores(Node* curr_node, Node* neighbor) {
    int new_g_score = abs(neighbor->row - start_node->row) + abs(neighbor->col - start_node->col);
    int new_f_score = new_g_score + neighbor->h_score;

    if(new_f_score < neighbor->f_score) {
        neighbor->g_score = new_g_score;
        neighbor->f_score = new_f_score;
        neighbor->parent = curr_node;
    }
}

Node* get_lowest_fscore_node(Node** open_list, int open_list_size) {
    Node* lowest_fscore_node = open_list[0];

    for(int i=1; i<open_list_size; i++) {
        if(open_list[i]->f_score < lowest_fscore_node->f_score) {
            lowest_fscore_node = open_list[i];
        }
    }
    return lowest_fscore_node;
}

void find_path() {
    Node* curr_node;
    Node* neighbor_nodes[4];
    int neighbor_count = 0;
    bool goal_reached = false;

    Node* open_list[ROWS*COLS];
    int open_list_size = 1;
    open_list[0] = start_node;

    Node* closed_list[ROWS*COLS];
    int closed_list_size = 0;

    while(open_list_size > 0) {
        curr_node = get_lowest_fscore_node(open_list, open_list_size);

        if(curr_node == goal_node) {
            goal_reached = true;
            break;
        }

        // remove curr_node from open list
        for(int i=0; i<open_list_size; i++) {
            if(open_list[i] == curr_node) {
                open_list[i]->is_closed = true;
                for(int j=i; j<open_list_size-1; j++) {
                    open_list[j] = open_list[j+1];
                }
                open_list_size--;
                break;
            }
        }

        // add curr_node to closed list
        closed_list[closed_list_size] = curr_node;
        closed_list_size++;

        // get neighbor nodes and update their scores
        neighbor_count = 0;
        if(is_valid_move(curr_node->row-1, curr_node->col)) {
            neighbor_nodes[neighbor_count] = create_node(curr_node->row-1, curr_node->col);
            if(curr_node->parent == NULL || curr_node->parent->row != curr_node->row-1 || curr_node->parent->col != curr_node->col) {
                calculate_scores(neighbor_nodes[neighbor_count]);
            }
            else {
                // if this neighbor is the parent of the current node, don't calculate the scores again
                neighbor_nodes[neighbor_count]->g_score = curr_node->parent->g_score + 1;
                neighbor_nodes[neighbor_count]->f_score = curr_node->parent->f_score + 1;
                neighbor_nodes[neighbor_count]->parent = curr_node->parent;
            }
            neighbor_count++;
        }
        if(is_valid_move(curr_node->row+1, curr_node->col)) {
            neighbor_nodes[neighbor_count] = create_node(curr_node->row+1, curr_node->col);
            if(curr_node->parent == NULL || curr_node->parent->row != curr_node->row+1 || curr_node->parent->col != curr_node->col) {
                calculate_scores(neighbor_nodes[neighbor_count]);
            }
            else {
                neighbor_nodes[neighbor_count]->g_score = curr_node->parent->g_score + 1;
                neighbor_nodes[neighbor_count]->f_score = curr_node->parent->f_score + 1;
                neighbor_nodes[neighbor_count]->parent = curr_node->parent;
            }
            neighbor_count++;
        }
        if(is_valid_move(curr_node->row, curr_node->col-1)) {
            neighbor_nodes[neighbor_count] = create_node(curr_node->row, curr_node->col-1);
            if(curr_node->parent == NULL || curr_node->parent->row != curr_node->row || curr_node->parent->col != curr_node->col-1) {
                calculate_scores(neighbor_nodes[neighbor_count]);
            }
            else {
                neighbor_nodes[neighbor_count]->g_score = curr_node->parent->g_score + 1;
                neighbor_nodes[neighbor_count]->f_score = curr_node->parent->f_score + 1;
                neighbor_nodes[neighbor_count]->parent = curr_node->parent;
            }
            neighbor_count++;
        }
        if(is_valid_move(curr_node->row, curr_node->col+1)) {
            neighbor_nodes[neighbor_count] = create_node(curr_node->row, curr_node->col+1);
            if(curr_node->parent == NULL || curr_node->parent->row != curr_node->row || curr_node->parent->col != curr_node->col+1) {
                calculate_scores(neighbor_nodes[neighbor_count]);
            }
            else {
                neighbor_nodes[neighbor_count]->g_score = curr_node->parent->g_score + 1;
                neighbor_nodes[neighbor_count]->f_score = curr_node->parent->f_score + 1;
                neighbor_nodes[neighbor_count]->parent = curr_node->parent;
            }
            neighbor_count++;
        }

        // add neighbors to open list
        for(int i=0; i<neighbor_count; i++) {
            bool neighbor_in_closed_list = false;

            // check if neighbor is in closed list
            for(int j=0; j<closed_list_size; j++) {
                if(neighbor_nodes[i]->row == closed_list[j]->row && neighbor_nodes[i]->col == closed_list[j]->col) {
                    neighbor_in_closed_list = true;
                    break;
                }
            }

            if(!neighbor_in_closed_list) {
                bool neighbor_in_open_list = false;

                // check if neighbor is in open list
                for(int j=0; j<open_list_size; j++) {
                    if(neighbor_nodes[i]->row == open_list[j]->row && neighbor_nodes[i]->col == open_list[j]->col) {
                        neighbor_in_open_list = true;
                        update_scores(curr_node, open_list[j]);
                        break;
                    }
                }

                if(!neighbor_in_open_list) {
                    update_scores(curr_node, neighbor_nodes[i]);
                    open_list[open_list_size] = neighbor_nodes[i];
                    open_list_size++;
                }
            }
        }
    }

    // print path if goal is reached
    if(goal_reached) {
        Node* path[ROWS*COLS];
        int path_size = 0;
        Node* path_node = goal_node;

        while(path_node != start_node) {
            path[path_size] = path_node;
            path_size++;
            path_node = path_node->parent;
        }

        printf("Path from (%d, %d) to (%d, %d):\n", start_node->row, start_node->col, goal_node->row, goal_node->col);
        printf("(%d, %d)", start_node->row, start_node->col);
        for(int i=path_size-1; i>=0; i--) {
            printf(" -> (%d, %d)", path[i]->row, path[i]->col);
            maze[path[i]->row][path[i]->col] = VISITED;
        }
        printf("\n");
        print_maze();
    }
    else {
        printf("Could not find path from (%d, %d) to (%d, %d)\n", start_node->row, start_node->col, goal_node->row, goal_node->col);
    }
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // set start and goal nodes
    start_node = create_node(0, 0);
    goal_node = create_node(ROWS-1, COLS-1);

    // print initial maze
    printf("Initial maze:\n");
    print_maze();

    // find path
    find_path();

    return 0;
}