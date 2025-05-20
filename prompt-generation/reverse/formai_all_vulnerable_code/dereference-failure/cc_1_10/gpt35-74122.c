//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
// A* Pathfinding Algorithm - Irregular Style
#include <stdio.h>
#include <stdlib.h>

// Define the playing field dimensions
#define ROWS 10
#define COLS 15

// Define the starting and ending positions
#define START_ROW 2
#define START_COL 2
#define END_ROW 8
#define END_COL 13

// Define the heuristic coefficient
#define HEURISTIC_COEF 1.5

// Define the node structure
typedef struct node {
    int row;
    int col;
    int g_score;
    int h_score;
    int f_score;
    int parent_row;
    int parent_col;
    struct node* parent;
    struct node* neighbors[8];
    struct node* next;
} node_t;

// Define the open and closed lists
node_t* open_list = NULL;
node_t* closed_list = NULL;

// Define the playing field
int playing_field[ROWS][COLS] = {
    // 0 = empty space, 1 = obstacle
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// Function prototypes
node_t* create_node(int row, int col, node_t* parent);
void add_to_open_list(node_t* node);
void add_to_closed_list(node_t* node);
void remove_node_from_open_list(node_t* node);
void remove_node_from_closed_list(node_t* node);
void remove_node_from_list(node_t** list, node_t* node);
void calculate_scores(node_t* node);
int is_node_in_list(node_t* list, node_t* node);
int is_valid_position(int row, int col);
void generate_neighbors(node_t* node);
void print_playing_field();
void print_node(node_t* node);

int main() {
    // Create the starting node
    node_t* current_node = create_node(START_ROW, START_COL, NULL);
    current_node->g_score = 0;
    calculate_scores(current_node);
    add_to_open_list(current_node);

    // Loop until the end node is found or the open list is empty
    while (open_list != NULL) {
        // Find the node in the open list with the lowest f score
        node_t* min_f_score_node = open_list;
        node_t* temp_node = open_list;
        while (temp_node != NULL) {
            if (temp_node->f_score < min_f_score_node->f_score) {
                min_f_score_node = temp_node;
            }
            temp_node = temp_node->next;
        }
        current_node = min_f_score_node;

        // If the end node is found, quit the loop
        if (current_node->row == END_ROW && current_node->col == END_COL) {
            break;
        }

        // Move the current node from the open list to the closed list
        remove_node_from_open_list(current_node);
        add_to_closed_list(current_node);

        // Generate the neighbors of the current node
        generate_neighbors(current_node);

        for (int i = 0; i < 8; i++) {
            node_t* neighbor = current_node->neighbors[i];
            if (neighbor == NULL) {
                continue;
            }

            // If the neighbor is already in the closed list, skip it
            if (is_node_in_list(closed_list, neighbor)) {
                continue;
            }

            // Calculate the tentative g score
            int tentative_g_score = current_node->g_score + 1;

            // If the neighbor is not in the open list, add it
            if (!is_node_in_list(open_list, neighbor)) {
                add_to_open_list(neighbor);
            }
            // If the tentative g score is greater than or equal to the current g score, skip the neighbor
            else if (tentative_g_score >= neighbor->g_score) {
                continue;
            }

            // The neighbor is a better path
            neighbor->parent = current_node;
            neighbor->g_score = tentative_g_score;
            calculate_scores(neighbor);
        }
    }

    // If the end node was not found, print an error message
    if (current_node->row != END_ROW || current_node->col != END_COL) {
        printf("Error: could not find path from (%d, %d) to (%d, %d)\n", START_ROW, START_COL, END_ROW, END_COL);
        return 1;
    }

    // Backtrack to find the path
    node_t* path = current_node;
    while (path != NULL) {
        playing_field[path->row][path->col] = 2;
        path = path->parent;
    }

    // Print the playing field with the path
    print_playing_field();

    return 0;
}

node_t* create_node(int row, int col, node_t* parent) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->row = row;
    node->col = col;
    node->g_score = -1;
    node->h_score = -1;
    node->f_score = -1;
    node->parent_row = -1;
    node->parent_col = -1;
    node->parent = parent;
    for (int i = 0; i < 8; i++) {
        node->neighbors[i] = NULL;
    }
    node->next = NULL;
    return node;
}

void add_to_open_list(node_t* node) {
    node->next = open_list;
    open_list = node;
}

void add_to_closed_list(node_t* node) {
    node->next = closed_list;
    closed_list = node;
}

void remove_node_from_open_list(node_t* node) {
    remove_node_from_list(&open_list, node);
}

void remove_node_from_closed_list(node_t* node) {
    remove_node_from_list(&closed_list, node);
}

void remove_node_from_list(node_t** list, node_t* node) {
    if (*list == NULL) {
        return;
    }
    if (*list == node) {
        *list = node->next;
        node->next = NULL;
        return;
    }
    node_t* temp_node = *list;
    while (temp_node->next != NULL) {
        if (temp_node->next == node) {
            temp_node->next = node->next;
            node->next = NULL;
            return;
        }
        temp_node = temp_node->next;
    }
}

void calculate_scores(node_t* node) {
    int dx = END_COL - node->col;
    int dy = END_ROW - node->row;
    node->h_score = (int)(HEURISTIC_COEF * sqrt(dx*dx + dy*dy));
    node->f_score = node->g_score + node->h_score;
}

int is_node_in_list(node_t* list, node_t* node) {
    node_t* temp_node = list;
    while (temp_node != NULL) {
        if (temp_node == node) {
            return 1;
        }
        temp_node = temp_node->next;
    }
    return 0;
}

int is_valid_position(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    return !playing_field[row][col];
}

void generate_neighbors(node_t* node) {
    int row = node->row;
    int col = node->col;
    int index = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if (is_valid_position(neighbor_row, neighbor_col)) {
                node_t* neighbor = create_node(neighbor_row, neighbor_col, node);
                node->neighbors[index++] = neighbor;
            }
        }
    }
}

void print_playing_field() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (playing_field[i][j] == 0) {
                printf(". ");
            }
            else if (playing_field[i][j] == 1) {
                printf("# ");
            }
            else if (playing_field[i][j] == 2) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void print_node(node_t* node) {
    printf("(%d, %d) - g=%d, h=%d, f=%d\n", node->col, node->row, node->g_score, node->h_score, node->f_score);
}