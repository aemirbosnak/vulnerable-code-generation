//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 5
#define COLS 5

/* Define the Node structure */
typedef struct {
    int row, col;
    bool walkable;
} Node;

/* Define the Graph structure */
typedef struct {
    Node nodes[ROWS][COLS];
    Node *start_node;
    Node *end_node;
} Graph;

/* Define the open and closed lists used by the algorithm */
typedef struct {
    Node *node;
    int f_score;
} AStarNode;

AStarNode *open_list[ROWS * COLS];
int open_list_len = 0;
AStarNode *closed_list[ROWS * COLS];
int closed_list_len = 0;

/* Auxiliary function to compute the Manhattan distance between two nodes */
int manhattan(Node *n1, Node *n2) {
    return abs(n1->row - n2->row) + abs(n1->col - n2->col);
}

/* Auxiliary function to check if a node is already in a list */
bool in_list(Node *node, AStarNode **list, int list_len) {
    for (int i = 0; i < list_len; i++) {
        if (node == list[i]->node) {
            return true;
        }
    }
    return false;
}

/* Auxiliary function to remove a node from a list */
void remove_node(Node *node, AStarNode **list, int *list_len) {
    for (int i = 0; i < *list_len; i++) {
        if (node == list[i]->node) {
            (*list_len)--;
            for (int j = i; j < *list_len; j++) {
                list[j] = list[j+1];
            }
            break;
        }
    }
}

/* Auxiliary function to get the node with the lowest f-score */
AStarNode *get_lowest_fscore() {
    AStarNode *lowest = open_list[0];
    for (int i = 1; i < open_list_len; i++) {
        if (open_list[i]->f_score < lowest->f_score) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

/* Function that implements the A* algorithm */
bool a_star(Graph *graph) {
    /* Initialize the open and closed lists */
    open_list[0] = (AStarNode *)malloc(sizeof(AStarNode));
    open_list[0]->node = graph->start_node;
    open_list[0]->f_score = manhattan(graph->start_node, graph->end_node);
    open_list_len = 1;
    closed_list_len = 0;

    /* Loop until the open list is empty */
    while (open_list_len > 0) {
        /* Get the node with the lowest f-score */
        AStarNode *current = get_lowest_fscore();

        /* If the current node is the end node, we have found a path */
        if (current->node == graph->end_node) {
            return true;
        }

        /* Move the current node from the open to the closed list */
        remove_node(current->node, open_list, &open_list_len);
        closed_list[closed_list_len++] = current;

        /* Loop over the neighbors of the current node */
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (current->node->row + i < 0 || current->node->row + i >= ROWS) {
                    continue;
                }
                if (current->node->col + j < 0 || current->node->col + j >= COLS) {
                    continue;
                }
                Node *neighbor = &graph->nodes[current->node->row+i][current->node->col+j];
                if (!neighbor->walkable || in_list(neighbor, closed_list, closed_list_len)) {
                    continue;
                }

                /* Compute the tentative g-score for the neighbor */
                int tentative_gscore = current->f_score + 1;

                /* If the neighbor is not in the open list, add it */
                AStarNode *astar_neighbor = NULL;
                if (!in_list(neighbor, open_list, open_list_len)) {
                    astar_neighbor = (AStarNode *)malloc(sizeof(AStarNode));
                    astar_neighbor->node = neighbor;
                    astar_neighbor->f_score = tentative_gscore + manhattan(neighbor, graph->end_node);
                    open_list[open_list_len++] = astar_neighbor;
                }
                /* If the tentative g-score is not better than the current one, skip */
                else {
                    for (int i = 0; i < open_list_len; i++) {
                        if (astar_neighbor->node == open_list[i]->node) {
                            astar_neighbor = open_list[i];
                            break;
                        }
                    }
                    if (tentative_gscore >= astar_neighbor->f_score) {
                        continue;
                    }
                }

                /* Update the neighbor's f-score and parent */
                astar_neighbor->f_score = tentative_gscore + manhattan(neighbor, graph->end_node);
            }
        }
    }
    return false;
}

int main() {
    /* Define the graph */
    Graph graph = {{
        { {0, 0, true}, {0, 1, true}, {0, 2, true}, {0, 3, true}, {0, 4, true} },
        { {1, 0, true}, {1, 1, true}, {1, 2, false}, {1, 3, true}, {1, 4, true} },
        { {2, 0, true}, {2, 1, true}, {2, 2, false}, {2, 3, true}, {2, 4, true} },
        { {3, 0, true}, {3, 1, true}, {3, 2, true}, {3, 3, true}, {3, 4, true} },
        { {4, 0, true}, {4, 1, true}, {4, 2, true}, {4, 3, true}, {4, 4, true} }
    }};
    graph.start_node = &graph.nodes[0][0];
    graph.end_node = &graph.nodes[4][4];

    /* Run the algorithm */
    if (a_star(&graph)) {
        printf("A path was found!\n");
    } else {
        printf("No path was found.\n");
    }

    return 0;
}