//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

typedef struct Node {
    int id;
    char name[30];
    struct Node *next; // Pointer to the next node
} Node;

typedef struct Edge {
    int from;
    int to;
    struct Edge *next; // Pointer to the next edge
} Edge;

Node *nodes[MAX_NODES]; // Node list
Edge *edges[MAX_NODES]; // Edge list
int node_count = 0;
int edge_count = 0;

Node* create_node(int id, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->next = NULL;
    return new_node;
}

Edge* create_edge(int from, int to) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->next = NULL;
    return new_edge;
}

void add_node(const char *name) {
    if (node_count >= MAX_NODES) {
        printf("Error: Maximum node limit reached.\n");
        return;
    }
    nodes[node_count] = create_node(node_count, name);
    node_count++;
}

void add_edge(int from, int to) {
    if (edge_count >= MAX_NODES) {
        printf("Error: Maximum edge limit reached.\n");
        return;
    }
    edges[edge_count] = create_edge(from, to);
    edge_count++;
}

void display_nodes() {
    printf("Network Nodes:\n");
    for (int i = 0; i < node_count; i++) {
        printf("ID: %d, Name: %s\n", nodes[i]->id, nodes[i]->name);
    }
    printf("\n");
}

void display_edges() {
    printf("Network Edges:\n");
    for (int i = 0; i < edge_count; i++) {
        printf("From Node %d to Node %d\n", edges[i]->from, edges[i]->to);
    }
    printf("\n");
}

void free_resources() {
    for (int i = 0; i < node_count; i++) {
        free(nodes[i]);
    }
    for (int i = 0; i < edge_count; i++) {
        free(edges[i]);
    }
}

int main() {
    int choice, from, to;
    char node_name[30];
    
    while(1) {
        printf("Network Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Edge\n");
        printf("3. Display Nodes\n");
        printf("4. Display Edges\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", node_name);
                add_node(node_name);
                break;
            case 2:
                printf("Enter from Node ID and to Node ID: ");
                scanf("%d %d", &from, &to);
                add_edge(from, to);
                break;
            case 3:
                display_nodes();
                break;
            case 4:
                display_edges();
                break;
            case 5:
                free_resources();
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
    
    return 0;
}