//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Graph data structure
typedef struct Graph {
    int num_nodes;
    int** adj_matrix;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->adj_matrix = (int**)malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = (int*)malloc(sizeof(int) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to a graph
void add_edge(Graph* graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

// Function to print a graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a graph is bipartite
int is_bipartite(Graph* graph) {
    // Create a color vector to store the colors of the nodes
    int* colors = (int*)malloc(sizeof(int) * graph->num_nodes);
    for (int i = 0; i < graph->num_nodes; i++) {
        colors[i] = -1;
    }

    // Color the first node with color 1
    colors[0] = 1;

    // Perform a breadth-first search to color the remaining nodes
    int queue[graph->num_nodes];
    int front = 0;
    int rear = 0;
    queue[rear++] = 0;
    while (front != rear) {
        int node = queue[front++];

        // Get the neighbors of the current node
        for (int i = 0; i < graph->num_nodes; i++) {
            if (graph->adj_matrix[node][i] == 1 && colors[i] == -1) {
                // Color the neighbor with the opposite color of the current node
                colors[i] = 1 - colors[node];
                queue[rear++] = i;
            } else if (graph->adj_matrix[node][i] == 1 && colors[i] == colors[node]) {
                // If the neighbor has the same color as the current node, the graph is not bipartite
                return 0;
            }
        }
    }

    // If all nodes have been colored, the graph is bipartite
    return 1;
}

// Function to play the graph coloring game
void play_graph_coloring_game(Graph* graph) {
    // Get the number of players
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Create an array to store the colors of the players
    int* player_colors = (int*)malloc(sizeof(int) * num_players);
    for (int i = 0; i < num_players; i++) {
        player_colors[i] = -1;
    }

    // Let the players take turns coloring the nodes
    int current_player = 0;
    while (!is_bipartite(graph)) {
        // Get the node that the current player wants to color
        int node;
        printf("Player %d, enter the node you want to color: ", current_player + 1);
        scanf("%d", &node);

        // Get the color that the current player wants to use
        int color;
        printf("Player %d, enter the color you want to use (1 or 2): ", current_player + 1);
        scanf("%d", &color);

        // Color the node with the specified color
        graph->adj_matrix[node][node] = color;

        // Update the player's color
        player_colors[current_player] = color;

        // Switch to the next player
        current_player = (current_player + 1) % num_players;
    }

    // Print the winning player
    printf("Player %d wins!\n", current_player + 1);
}

int main() {
    // Create a graph
    Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    // Play the graph coloring game
    play_graph_coloring_game(graph);

    return 0;
}