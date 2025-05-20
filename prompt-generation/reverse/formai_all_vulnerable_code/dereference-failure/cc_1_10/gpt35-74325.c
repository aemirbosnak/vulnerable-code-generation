//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    int visited;
    struct node* next;
} Node;

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define START_X 0
#define START_Y 0

#define END_X 9
#define END_Y 9

Node *head = NULL;
Node *tail = NULL;

// Adds a node with the specified coordinates to the end of the list
void add_node(int x, int y) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->visited = 0;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

// Removes the first node in the list and returns its coordinates
int *remove_node() {
    int *coords = (int*)malloc(sizeof(int) * 2);
    
    coords[0] = head->x;
    coords[1] = head->y;
    
    Node *temp = head;
    head = head->next;
    
    free(temp);
    
    return coords;
}

// Returns a pointer to the node at the specified coordinates, or NULL if there is no such node
Node *get_node(int x, int y) {
    Node *node = head;
    
    while (node != NULL) {
        if (node->x == x && node->y == y) {
            return node;
        }
        
        node = node->next;
    }
    
    return NULL;
}

int main() {
    int map[MAP_WIDTH][MAP_HEIGHT] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 0}
    };
    
    add_node(START_X, START_Y);
    
    while (head != NULL) {
        int *coords = remove_node();
        int x = coords[0];
        int y = coords[1];
        free(coords);
        
        if (x == END_X && y == END_Y) {
            printf("Path found!\n");
            return 0;
        }
        
        // Mark node as visited
        Node *node = get_node(x, y);
        node->visited = 1;
        
        // Check neighbors
        if (x > 0 && map[x - 1][y] == 0) {
            Node *neighbor = get_node(x - 1, y);
            
            if (neighbor == NULL) {
                add_node(x - 1, y);
            }
        }
        
        if (x < MAP_WIDTH - 1 && map[x + 1][y] == 0) {
            Node *neighbor = get_node(x + 1, y);
            
            if (neighbor == NULL) {
                add_node(x + 1, y);
            }
        }
        
        if (y > 0 && map[x][y - 1] == 0) {
            Node *neighbor = get_node(x, y - 1);
            
            if (neighbor == NULL) {
                add_node(x, y - 1);
            }
        }
        
        if (y < MAP_HEIGHT - 1 && map[x][y + 1] == 0) {
            Node *neighbor = get_node(x, y + 1);
            
            if (neighbor == NULL) {
                add_node(x, y + 1);
            }
        }
    }
    
    printf("No path found...\n");
    
    return 0;
}