//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a graph node
typedef struct node {
    int value;
    struct node *next;
} node;

// Define the structure of a graph
typedef struct graph {
    int num_nodes;
    node *nodes;
} graph;

// Create a new graph
graph *create_graph(int num_nodes) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->nodes = (node *)malloc(num_nodes * sizeof(node));
    return g;
}

// Free the memory allocated for a graph
void free_graph(graph *g) {
    free(g->nodes);
    free(g);
}

// Add a node to a graph
void add_node(graph *g, int value) {
    node *n = (node *)malloc(sizeof(node));
    n->value = value;
    n->next = g->nodes;
    g->nodes = n;
}

// Print the nodes of a graph
void print_graph(graph *g) {
    node *n = g->nodes;
    while (n != NULL) {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

// Generate a random graph
graph *generate_random_graph(int num_nodes, int num_edges) {
    graph *g = create_graph(num_nodes);
    for (int i = 0; i < num_edges; i++) {
        int node1 = rand() % num_nodes;
        int node2 = rand() % num_nodes;
        add_node(g, node1);
        add_node(g, node2);
    }
    return g;
}

// Calculate the mean of the node values in a graph
double calculate_mean(graph *g) {
    double sum = 0;
    node *n = g->nodes;
    while (n != NULL) {
        sum += n->value;
        n = n->next;
    }
    return sum / g->num_nodes;
}

// Calculate the standard deviation of the node values in a graph
double calculate_standard_deviation(graph *g) {
    double mean = calculate_mean(g);
    double sum_of_squares = 0;
    node *n = g->nodes;
    while (n != NULL) {
        sum_of_squares += pow(n->value - mean, 2);
        n = n->next;
    }
    return sqrt(sum_of_squares / (g->num_nodes - 1));
}

// Calculate the skewness of the node values in a graph
double calculate_skewness(graph *g) {
    double mean = calculate_mean(g);
    double standard_deviation = calculate_standard_deviation(g);
    double sum_of_cubes = 0;
    node *n = g->nodes;
    while (n != NULL) {
        sum_of_cubes += pow(n->value - mean, 3);
        n = n->next;
    }
    return sum_of_cubes / (g->num_nodes - 1) / pow(standard_deviation, 3);
}

// Calculate the kurtosis of the node values in a graph
double calculate_kurtosis(graph *g) {
    double mean = calculate_mean(g);
    double standard_deviation = calculate_standard_deviation(g);
    double sum_of_fourth_powers = 0;
    node *n = g->nodes;
    while (n != NULL) {
        sum_of_fourth_powers += pow(n->value - mean, 4);
        n = n->next;
    }
    return sum_of_fourth_powers / (g->num_nodes - 1) / pow(standard_deviation, 4) - 3;
}

// Print the statistical summary of a graph
void print_statistical_summary(graph *g) {
    printf("Mean: %.2f\n", calculate_mean(g));
    printf("Standard deviation: %.2f\n", calculate_standard_deviation(g));
    printf("Skewness: %.2f\n", calculate_skewness(g));
    printf("Kurtosis: %.2f\n", calculate_kurtosis(g));
}

// Main function
int main() {
    // Create a random graph
    graph *g = generate_random_graph(100, 500);

    // Print the graph
    print_graph(g);

    // Print the statistical summary of the graph
    print_statistical_summary(g);

    // Free the memory allocated for the graph
    free_graph(g);

    return 0;
}