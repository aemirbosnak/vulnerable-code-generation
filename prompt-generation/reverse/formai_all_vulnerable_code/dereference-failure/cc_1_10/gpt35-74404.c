//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define size of maze
#define ROW 10
#define COL 10

// Define goal position
#define GOAL_ROW 8
#define GOAL_COL 9

// Define position structure
typedef struct {
    int row;
    int col;
} Position;

// Define list node structure
typedef struct node Node;
struct node {
    Position position;
    int distance;
    Node *next;
};

// Define linked list structure
typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

// Create new list node
Node* new_node(Position position, int distance) {
    Node *node = malloc(sizeof(Node));
    node->position = position;
    node->distance = distance;
    node->next = NULL;
    return node;
}

// Create new linked list
LinkedList new_list() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

// Add node to end of list
void add_node(LinkedList *list, Position position, int distance) {
    Node *node = new_node(position, distance);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Remove and return first node from list
Node* remove_first_node(LinkedList *list) {
    Node *node = list->head;
    if (node != NULL) {
        list->head = node->next;
        node->next = NULL;
    }
    return node;
}

// Check if position is within bounds of maze
int is_within_bounds(Position position) {
    return position.row >= 0 && position.row < ROW && position.col >= 0 && position.col < COL;
}

// Check if position is a wall
int is_wall(int maze[][COL], Position position) {
    return maze[position.row][position.col] == 1;
}

// Calculate Manhattan distance between two positions
int manhattan_distance(Position a, Position b) {
    return abs(a.row - b.row) + abs(a.col - b.col);
}

// Find shortest path from start position to goal position using A* algorithm
LinkedList find_shortest_path(int maze[][COL], Position start) {
    LinkedList open_list = new_list();
    LinkedList closed_list = new_list();
    add_node(&open_list, start, 0);
    
    while (open_list.head != NULL) {
        Node *current = remove_first_node(&open_list);
        Position current_position = current->position;
        int distance_from_start = current->distance;
        free(current);
        
        if (current_position.row == GOAL_ROW && current_position.col == GOAL_COL) {
            LinkedList path = new_list();
            add_node(&path, current_position, distance_from_start);
            Node *node = closed_list.tail;
            while (node->position.row != start.row || node->position.col != start.col) {
                add_node(&path, node->position, node->distance);
                node = node->next;
            }
            add_node(&path, node->position, node->distance);
            return path;
        }
        
        for (int d_row = -1; d_row <= 1; d_row++) {
            for (int d_col = -1; d_col <= 1; d_col++) {
                if (d_row == 0 && d_col == 0) {
                    // Skip current position
                    continue;
                }
                
                Position neighbor_position = {current_position.row + d_row, current_position.col + d_col};
                if (!is_within_bounds(neighbor_position) || is_wall(maze, neighbor_position)) {
                    // Skip out-of-bounds or wall positions
                    continue;
                }
                
                int distance_to_neighbor = distance_from_start + 1;
                int estimated_distance_to_goal = manhattan_distance(neighbor_position, (Position){GOAL_ROW, GOAL_COL});
                int total_estimated_distance = distance_to_neighbor + estimated_distance_to_goal;
                
                Node *existing_node = closed_list.head;
                while (existing_node != NULL) {
                    if (existing_node->position.row == neighbor_position.row && existing_node->position.col == neighbor_position.col) {
                        if (existing_node->distance > total_estimated_distance) {
                            existing_node->distance = total_estimated_distance;
                        }
                        break;
                    }
                    existing_node = existing_node->next;
                }
                
                existing_node = open_list.head;
                while (existing_node != NULL) {
                    if (existing_node->position.row == neighbor_position.row && existing_node->position.col == neighbor_position.col) {
                        if (existing_node->distance > total_estimated_distance) {
                            existing_node->distance = total_estimated_distance;
                        }
                        break;
                    }
                    existing_node = existing_node->next;
                }
                
                if (existing_node == NULL) {
                    add_node(&open_list, neighbor_position, total_estimated_distance);
                }
            }
        }
        
        add_node(&closed_list, current_position, distance_from_start);
    }
    
    LinkedList empty_list = new_list();
    return empty_list;
}

int main() {
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    LinkedList path = find_shortest_path(maze, (Position){0, 0});
    Node *node = path.head;
    while (node != NULL) {
        printf("(%d, %d)\n", node->position.row, node->position.col);
        node = node->next;
    }
    
    return 0;
}