//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Graph structure
typedef struct graph {
    Node* head;
    int size;
} Graph;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the graph
void add_node(Graph* graph, int data) {
    Node* new_node = create_node(data);
    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        Node* temp = graph->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    graph->size++;
}

// Function to add an edge between two nodes
void add_edge(Graph* graph, int node1, int node2) {
    Node* temp1 = graph->head;
    Node* temp2 = graph->head;
    while (temp1!= NULL) {
        if (temp1->data == node1) {
            break;
        }
        temp1 = temp1->next;
    }
    while (temp2!= NULL) {
        if (temp2->data == node2) {
            break;
        }
        temp2 = temp2->next;
    }
    if (temp1!= NULL && temp2!= NULL) {
        temp1->next = temp2;
    }
}

// Function to print the graph
void print_graph(Graph* graph) {
    Node* temp = graph->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Graph graph;
    graph.head = NULL;
    graph.size = 0;

    // Add nodes to the graph
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);

    // Add edges between nodes
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);

    // Print the graph
    printf("Graph:\n");
    print_graph(&graph);

    return 0;
}