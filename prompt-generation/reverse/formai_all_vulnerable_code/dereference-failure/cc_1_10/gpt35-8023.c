//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 5
#define MAX_COLOR 3

typedef struct Node {
    int id;
    int color;
    int num_neighbors;
    struct Node* neighbors[MAX_NODES-1];
} Node;

// Helper function to generate random edges between nodes
void generateEdges(Node* nodes[MAX_NODES]);
// Helper function to initialize node colors
void initializeColors(Node* nodes[MAX_NODES]);
// Helper function to print the current state of the graph
void printGraph(Node* nodes[MAX_NODES]);

int main() {
    srand(time(0));
    Node* nodes[MAX_NODES];
    // Initialize nodes
    for (int i = 0; i < MAX_NODES; i++) {
        Node* node = malloc(sizeof(Node));
        node->id = i;
        node->color = 0;
        node->num_neighbors = 0;
        nodes[i] = node;
    }
    // Generate edges between nodes
    generateEdges(nodes);
    // Initialize node colors
    initializeColors(nodes);
    // Print the initial state of the graph
    printf("Initial graph:\n");
    printGraph(nodes);
    printf("\n");
    // Start the game
    int turn = 1;
    while (1) {
        printf("Turn %d: Player %d's turn\n", turn, turn % 2 + 1);
        int i, c;
        printf("Enter node index (0-4): ");
        scanf("%d", &i);
        printf("Enter color (1-3): ");
        scanf("%d", &c);
        // Check if move is valid
        if (nodes[i]->color != 0) {
            printf("Invalid move: Node %d is already colored\n\n", i);
            continue;
        } else {
            for (int j = 0; j < nodes[i]->num_neighbors; j++) {
                if (nodes[i]->neighbors[j]->color == c) {
                    printf("Invalid move: Node %d's neighbor already has color %d\n\n", nodes[i]->neighbors[j]->id, c);
                    continue;
                }
            }
        }
        // Set the node color
        nodes[i]->color = c;
        // Print the updated state of the graph
        printf("\nUpdated graph:\n");
        printGraph(nodes);
        printf("\n");
        // Check if the game is over
        int end_game = 1;
        for (int i = 0; i < MAX_NODES; i++) {
            if (nodes[i]->color == 0) {
                end_game = 0;
                break;
            }
        }
        if (end_game) {
            printf("Game over\n");
            break;
        }
        turn++;
    }
    // Free nodes
    for (int i = 0; i < MAX_NODES; i++) {
        free(nodes[i]);
    }
    return 0;
}

void generateEdges(Node* nodes[MAX_NODES]) {
    // Generate random edges
    for (int i = 0; i < MAX_NODES-1; i++) {
        for (int j = i+1; j < MAX_NODES; j++) {
            if (rand() % 2 == 0) {
                nodes[i]->neighbors[nodes[i]->num_neighbors++] = nodes[j];
                nodes[j]->neighbors[nodes[j]->num_neighbors++] = nodes[i];
            }
        }
    }
}

void initializeColors(Node* nodes[MAX_NODES]) {
    // Randomly initialize node colors
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i]->color = rand() % MAX_COLOR + 1;
    }
}

void printGraph(Node* nodes[MAX_NODES]) {
    // Print the current state of the graph
    printf("node    |color |neighbors\n");
    printf("------------------------\n");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%-8d|%d     |", nodes[i]->id, nodes[i]->color);
        for (int j = 0; j < nodes[i]->num_neighbors; j++) {
            printf("%d ", nodes[i]->neighbors[j]->id);
        }
        printf("\n");
    }
}