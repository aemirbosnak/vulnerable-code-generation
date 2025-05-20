//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 8
#define OPEN_FLAG '@'
#define OBSTACLE_FLAG '*'
#define START_FLAG 'S'
#define DESTINATION_FLAG 'D'
#define PATH_FLAG '+'

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

struct Node {
    int row, col;
    int f_score, h_score, g_score;
    struct Node* parent;
};

struct PriorityQueue {
    int size;
    struct Node* nodes[ROW * COL];
};

struct PriorityQueue pq;

struct Node* create_node(int row, int col, int h_score, int g_score, struct Node* parent) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->h_score = h_score;
    node->g_score = g_score;
    node->f_score = h_score + g_score;
    node->parent = parent;
    return node;
}

void pq_init() {
    pq.size = 0;
}

void pq_add(struct Node* node) {
    int i = pq.size;
    pq.nodes[i] = node;
    pq.size++;
    while (i > 0 && pq.nodes[(i-1)/2]->f_score > pq.nodes[i]->f_score) {
        struct Node* temp = pq.nodes[i];
        pq.nodes[i] = pq.nodes[(i-1)/2];
        pq.nodes[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

struct Node* pq_poll() {
    struct Node* result = pq.nodes[0];
    pq.nodes[0] = pq.nodes[pq.size-1];
    pq.size--;
    int i = 0;
    while (i*2+1 < pq.size) {
        int left = i*2 + 1;
        int right = i*2 + 2;
        int j = left;
        if (right < pq.size && pq.nodes[right]->f_score < pq.nodes[left]->f_score) {
            j = right;
        }
        if (pq.nodes[i]->f_score < pq.nodes[j]->f_score) {
            break;
        }
        struct Node* temp = pq.nodes[i];
        pq.nodes[i] = pq.nodes[j];
        pq.nodes[j] = temp;
        i = j;
    }
    return result;
}

void pq_clear() {
    while (pq.size > 0) {
        free(pq_poll());
    }
}

void print_maze_with_path(struct Node* node) {
    char maze_with_path[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                maze_with_path[i][j] = OBSTACLE_FLAG;
            } else {
                maze_with_path[i][j] = OPEN_FLAG;
            }
        }
    }
    while (node) {
        maze_with_path[node->row][node->col] = PATH_FLAG;
        node = node->parent;
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", maze_with_path[i][j]);
        }
        printf("\n");
    }
}

int calculate_h_score(int row, int col, int dest_row, int dest_col) {
    return abs(dest_row - row) + abs(dest_col - col);
}

int main() {
    int start_row = 1, start_col = 1;
    int dest_row = 3, dest_col = 6;

    // Initialize the priority queue
    pq_init();

    // Add the starting node to the priority queue
    struct Node* start_node = create_node(start_row, start_col, 0,
                                          calculate_h_score(start_row, start_col, dest_row, dest_col),
                                          NULL);
    pq_add(start_node);

    // Create a boolean array to keep track of open nodes
    int open_nodes[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            open_nodes[i][j] = 1;
        }
    }

    // Run the A* search algorithm
    while (pq.size > 0) {
        // Get the node with the lowest f_score
        struct Node* current_node = pq_poll();
        int row = current_node->row;
        int col = current_node->col;

        // If this is the destination node, we have found the shortest path
        if (row == dest_row && col == dest_col) {
            print_maze_with_path(current_node);
            pq_clear();
            break;
        }

        // Mark this node as closed (i.e. already evaluated)
        open_nodes[row][col] = 0;

        // Check the neighbor nodes
        int neighbors[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int neighbor_row = row + neighbors[i][0];
            int neighbor_col = col + neighbors[i][1];

            // Skip this neighbor if it is outside the maze boundaries
            if (neighbor_row < 0 || neighbor_row >= ROW || neighbor_col < 0 || neighbor_col >= COL) {
                continue;
            }

            // Skip this neighbor if it is an obstacle or already closed
            if (maze[neighbor_row][neighbor_col] == 1 || !open_nodes[neighbor_row][neighbor_col]) {
                continue;
            }

            // Calculate the tentative g_score for this neighbor
            int tentative_g_score = current_node->g_score + 1;

            // Check if this neighbor has already been added to the priority queue
            struct Node* neighbor_node = NULL;
            int j;
            for (j = 0; j < pq.size; j++) {
                if (pq.nodes[j]->row == neighbor_row && pq.nodes[j]->col == neighbor_col) {
                    neighbor_node = pq.nodes[j];
                    break;
                }
            }

            // If this neighbor has not been added to the priority queue, add it
            if (neighbor_node == NULL) {
                neighbor_node = create_node(neighbor_row, neighbor_col, 0,
                                            calculate_h_score(neighbor_row, neighbor_col, dest_row, dest_col),
                                            current_node);
                pq_add(neighbor_node);
            }
            // Otherwise, if the tentative g_score is lower than its current g_score, update it
            else if (tentative_g_score < neighbor_node->g_score) {
                neighbor_node->g_score = tentative_g_score;
                neighbor_node->f_score = neighbor_node->h_score + neighbor_node->g_score;
                neighbor_node->parent = current_node;
                // Bubble up the updated node in the priority queue
                while (j > 0 && pq.nodes[(j-1)/2]->f_score > pq.nodes[j]->f_score) {
                    struct Node* temp = pq.nodes[j];
                    pq.nodes[j] = pq.nodes[(j-1)/2];
                    pq.nodes[(j-1)/2] = temp;
                    j = (j-1)/2;
                }
            }
        }
    }
    return 0;
}