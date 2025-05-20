//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the number of nodes in the graph
#define NUM_NODES 4

// Define the colors used to color the nodes
#define NUM_COLORS 3

// Graph coloring problem data structure
typedef struct {
    int num_nodes;  // Number of nodes in the graph
    int num_colors; // Number of colors available
    int** adjacency_matrix;  // Adjacency matrix representing the graph
    int* colors;  // Array of colors assigned to each node
} GraphColoringProblem;

// Function to create a new graph coloring problem instance
GraphColoringProblem* create_graph_coloring_problem(int num_nodes, int num_colors, int** adjacency_matrix) {
    GraphColoringProblem* problem = malloc(sizeof(GraphColoringProblem));
    problem->num_nodes = num_nodes;
    problem->num_colors = num_colors;
    problem->adjacency_matrix = adjacency_matrix;
    problem->colors = malloc(sizeof(int) * num_nodes);
    return problem;
}

// Function to free the memory allocated for a graph coloring problem instance
void free_graph_coloring_problem(GraphColoringProblem* problem) {
    free(problem->adjacency_matrix);
    free(problem->colors);
    free(problem);
}

// Function to check if a given coloring is valid
bool is_valid_coloring(GraphColoringProblem* problem) {
    for (int i = 0; i < problem->num_nodes; i++) {
        for (int j = i + 1; j < problem->num_nodes; j++) {
            if (problem->adjacency_matrix[i][j] == 1 && problem->colors[i] == problem->colors[j]) {
                return false;
            }
        }
    }
    return true;
}

// Function to print the coloring of the graph
void print_coloring(GraphColoringProblem* problem) {
    printf("Coloring: ");
    for (int i = 0; i < problem->num_nodes; i++) {
        printf("%d ", problem->colors[i]);
    }
    printf("\n");
}

// Function to solve the graph coloring problem using backtracking
bool solve_graph_coloring_problem(GraphColoringProblem* problem, int node) {
    // If we have colored all the nodes, then the problem is solved
    if (node == problem->num_nodes) {
        return is_valid_coloring(problem);
    }

    // Try all possible colors for the current node
    for (int color = 0; color < problem->num_colors; color++) {
        problem->colors[node] = color;

        // If the coloring is valid, then recursively solve the problem for the next node
        if (is_valid_coloring(problem)) {
            if (solve_graph_coloring_problem(problem, node + 1)) {
                return true;
            }
        }
    }

    // If no valid coloring was found for the current node, then backtrack and try a different color
    return false;
}

// Main function
int main() {
    // Define the adjacency matrix for the graph
    int adjacency_matrix[NUM_NODES][NUM_NODES] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    // Create a graph coloring problem instance
    GraphColoringProblem* problem = create_graph_coloring_problem(NUM_NODES, NUM_COLORS, adjacency_matrix);

    // Solve the graph coloring problem
    if (solve_graph_coloring_problem(problem, 0)) {
        printf("Graph coloring problem solved!\n");
        print_coloring(problem);
    } else {
        printf("Graph coloring problem could not be solved.\n");
    }

    // Free the memory allocated for the graph coloring problem instance
    free_graph_coloring_problem(problem);

    return 0;
}