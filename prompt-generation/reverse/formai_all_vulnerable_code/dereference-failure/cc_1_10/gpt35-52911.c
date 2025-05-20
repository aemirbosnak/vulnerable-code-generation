//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the position of a node in the world
struct position {
    int x;
    int y;
};

// Define a structure to hold a node in the world
struct node {
    struct position pos;
    int f_score;
    int g_score;
    int h_score;
    struct node* parent;
};

// Define an array to hold the open and closed nodes
struct node** open_list;
struct node** closed_list;

// Define the size of the world
#define WORLD_WIDTH 50
#define WORLD_HEIGHT 50

// Define the start and end positions in the world
struct position start_pos = {0, 0};
struct position end_pos = {WORLD_WIDTH - 1, WORLD_HEIGHT - 1};

void init_lists() {
    // Allocate memory for the open and closed lists
    open_list = (struct node**) malloc(sizeof(struct node*) * WORLD_WIDTH * WORLD_HEIGHT);
    closed_list = (struct node**) malloc(sizeof(struct node*) * WORLD_WIDTH * WORLD_HEIGHT);
    
    // Initialize the open and closed lists to NULL
    for (int i = 0; i < WORLD_WIDTH * WORLD_HEIGHT; i++) {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }
}

void destroy_lists() {
    // Free the memory allocated for the open and closed lists
    free(open_list);
    free(closed_list);
}

int is_valid_pos(struct position pos) {
    // Check if the position is inside the world bounds
    return pos.x >= 0 && pos.x < WORLD_WIDTH && pos.y >= 0 && pos.y < WORLD_HEIGHT;
}

int is_walkable_pos(struct position pos) {
    // Check if the position is walkable (in this case, always true)
    return 1;
}

int calculate_h_score(struct position pos) {
    // Calculate the heuristic score (in this case, Manhattan distance to the end position)
    return abs(pos.x - end_pos.x) + abs(pos.y - end_pos.y);
}

int get_node_index(struct node* node) {
    // Get the index of a node in the open or closed list
    return node->pos.y * WORLD_WIDTH + node->pos.x;
}

struct node* get_node_from_list(struct node** list, struct position pos) {
    // Get a node from the open or closed list by position
    return list[get_node_index(&(struct node) {pos})];
}

void insert_node_to_list(struct node** list, struct node* node) {
    // Insert a node to the open or closed list
    list[get_node_index(node)] = node;
}

void remove_node_from_list(struct node** list, struct node* node) {
    // Remove a node from the open or closed list
    list[get_node_index(node)] = NULL;
}

struct node* create_node(struct position pos, int g_score, struct node* parent) {
    // Allocate memory for a new node and initialize its values
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->pos = pos;
    node->f_score = g_score + calculate_h_score(pos);
    node->g_score = g_score;
    node->h_score = calculate_h_score(pos);
    node->parent = parent;
    return node;
}

int get_adjacent_nodes(struct node* parent, struct node** adjacent_nodes) {
    int count = 0;
    
    // Define the possible movement directions (up, down, left, right)
    struct position directions[] = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
    
    // Generate new nodes for each adjacent position and add them to the list
    for (int i = 0; i < sizeof(directions) / sizeof(struct position); i++) {
        struct position adjacent_pos = {parent->pos.x + directions[i].x, parent->pos.y + directions[i].y};
        if (is_valid_pos(adjacent_pos) && is_walkable_pos(adjacent_pos)) {
            struct node* adjacent_node = create_node(adjacent_pos, parent->g_score + 1, parent);
            adjacent_nodes[count++] = adjacent_node;
        }
    }
    
    return count;
}

void insert_adjacent_nodes_to_open_list(struct node** adjacent_nodes, int count) {
    // Insert all adjacent nodes to the open list
    for (int i = 0; i < count; i++) {
        struct node* node = adjacent_nodes[i];
        struct node* existing_node = get_node_from_list(open_list, node->pos);
        if (!existing_node || node->g_score < existing_node->g_score) {
            remove_node_from_list(closed_list, node);
            insert_node_to_list(open_list, node);
        }
    }
}

int get_lowest_f_score_node_index() {
    // Get the index of the node with the lowest f score in the open list
    int lowest_f_score = -1;
    int lowest_f_score_index = -1;
    for (int i = 0; i < WORLD_WIDTH * WORLD_HEIGHT; i++) {
        struct node* node = open_list[i];
        if (node && (lowest_f_score == -1 || node->f_score < lowest_f_score)) {
            lowest_f_score = node->f_score;
            lowest_f_score_index = i;
        }
    }
    return lowest_f_score_index;
}

void print_world(struct node* current_node) {
    // Print the world and the current path
    printf("+");
    for (int x = 0; x < WORLD_WIDTH; x++) {
        printf("-");
    }
    printf("+\n");
    for (int y = 0; y < WORLD_HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WORLD_WIDTH; x++) {
            if (start_pos.x == x && start_pos.y == y) {
                printf("S");
            } else if (end_pos.x == x && end_pos.y == y) {
                printf("E");
            } else if (current_node && current_node->pos.x == x && current_node->pos.y == y) {
                printf("x");
            } else {
                printf(".");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int x = 0; x < WORLD_WIDTH; x++) {
        printf("-");
    }
    printf("+\n");
}

void print_path(struct node* node) {
    // Print the path from the end node to the start node
    printf("Path found!\n");
    while (node) {
        printf("(%d, %d)\n", node->pos.x, node->pos.y);
        node = node->parent;
    }
}

void pathfinding() {
    // Initialize the open and closed lists
    init_lists();
    
    // Add the start position to the open list
    insert_node_to_list(open_list, create_node(start_pos, 0, NULL));
    
    // Loop until the end position is reached
    while (1) {
        // Get the node with the lowest f score from the open list
        int current_node_index = get_lowest_f_score_node_index();
        if (current_node_index == -1) {
            // If the open list is empty, no path was found
            printf("No path found.\n");
            break;
        }
        struct node* current_node = open_list[current_node_index];
        
        // Move the current node from the open to the closed list
        remove_node_from_list(open_list, current_node);
        insert_node_to_list(closed_list, current_node);
        
        // If the current node is the end position, the path is found
        if (current_node->pos.x == end_pos.x && current_node->pos.y == end_pos.y) {
            print_path(current_node);
            break;
        }
        
        // Get the adjacent nodes of the current node
        struct node* adjacent_nodes[4];
        int adjacent_nodes_count = get_adjacent_nodes(current_node, adjacent_nodes);
        
        // Insert the adjacent nodes to the open list
        insert_adjacent_nodes_to_open_list(adjacent_nodes, adjacent_nodes_count);
        
        // Print the world and the current path
        print_world(current_node);
    }
    
    // Destroy the open and closed lists
    destroy_lists();
}

int main() {
    pathfinding();
    return 0;
}