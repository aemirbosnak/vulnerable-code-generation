//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
// Linus Torvalds-style C Graph representation example

// What the hell, this is a graph?
#include <stdio.h>
#include <stdlib.h>

// A node in the graph
struct node {
	int data;
	struct node *next;
};

// A graph is a collection of nodes
struct graph {
	int num_nodes;
	struct node **nodes;
};

// Create a new graph
struct graph *create_graph(int num_nodes)
{
	struct graph *graph = malloc(sizeof(struct graph));
	if (!graph) {
		fprintf(stderr, "Error: Could not allocate memory for graph\n");
		return NULL;
	}

	graph->num_nodes = num_nodes;
	graph->nodes = malloc(sizeof(struct node *) * num_nodes);
	if (!graph->nodes) {
		fprintf(stderr, "Error: Could not allocate memory for nodes\n");
		free(graph);
		return NULL;
	}

	for (int i = 0; i < num_nodes; i++) {
		graph->nodes[i] = NULL;
	}

	return graph;
}

// Add an edge to the graph
void add_edge(struct graph *graph, int from, int to)
{
	if (from < 0 || from >= graph->num_nodes || to < 0 || to >= graph->num_nodes) {
		fprintf(stderr, "Error: Invalid edge (%d, %d)\n", from, to);
		return;
	}

	struct node *new_node = malloc(sizeof(struct node));
	if (!new_node) {
		fprintf(stderr, "Error: Could not allocate memory for new node\n");
		return;
	}

	new_node->data = to;
	new_node->next = graph->nodes[from];
	graph->nodes[from] = new_node;
}

// Print the graph
void print_graph(struct graph *graph)
{
	for (int i = 0; i < graph->num_nodes; i++) {
		printf("Node %d: ", i);
		struct node *current_node = graph->nodes[i];
		while (current_node) {
			printf("%d ", current_node->data);
			current_node = current_node->next;
		}
		printf("\n");
	}
}

// Free the graph
void free_graph(struct graph *graph)
{
	for (int i = 0; i < graph->num_nodes; i++) {
		struct node *current_node = graph->nodes[i];
		while (current_node) {
			struct node *next_node = current_node->next;
			free(current_node);
			current_node = next_node;
		}
	}

	free(graph->nodes);
	free(graph);
}

int main()
{
	// Create a new graph with 5 nodes
	struct graph *graph = create_graph(5);

	// Add some edges to the graph
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 2, 4);
	add_edge(graph, 3, 4);

	// Print the graph
	print_graph(graph);

	// Free the graph
	free_graph(graph);

	return 0;
}