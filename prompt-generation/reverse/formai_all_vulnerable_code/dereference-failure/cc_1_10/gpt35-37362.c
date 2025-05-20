//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct Node {
    int id;
    int x;
    int y;
    struct EdgeList *edges;
} Node;

typedef struct Edge {
    int id;
    struct Node *start;
    struct Node *end;
    int weight;
} Edge;

typedef struct EdgeList {
    struct Edge *edge;
    struct EdgeList *next;
} EdgeList;

int num_nodes = 0;
int num_edges = 0;
struct Node* nodes[MAX_NODES];
struct Edge* edges[MAX_EDGES];
struct EdgeList* edge_lists[MAX_NODES];

int find_node(int x, int y) {
    for(int i = 0; i < num_nodes; i++) {
        if(nodes[i]->x == x && nodes[i]->y == y) {
            return nodes[i]->id;
        }
    }
    return -1;
}

void add_node(int id, int x, int y) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->id = id;
    node->x = x;
    node->y = y;
    node->edges = NULL;
    nodes[num_nodes++] = node;
    edge_lists[node->id] = NULL;
}

void add_edge(int id, int start_x, int start_y, int end_x, int end_y, int weight) {
    int start_id = find_node(start_x, start_y);
    int end_id = find_node(end_x, end_y);

    if(start_id == -1) {
        add_node(num_nodes, start_x, start_y);
        start_id = num_nodes - 1;
    }

    if(end_id == -1) {
        add_node(num_nodes, end_x, end_y);
        end_id = num_nodes - 1;
    }

    struct Edge *edge = (struct Edge*) malloc(sizeof(struct Edge));
    edge->id = id;
    edge->start = nodes[start_id];
    edge->end = nodes[end_id];
    edge->weight = weight;
    edges[num_edges++] = edge;

    struct EdgeList *start_edge = (struct EdgeList*) malloc(sizeof(struct EdgeList));
    start_edge->edge = edge;
    start_edge->next = edge_lists[start_id];
    edge_lists[start_id] = start_edge;

    struct EdgeList *end_edge = (struct EdgeList*) malloc(sizeof(struct EdgeList));
    end_edge->edge = edge;
    end_edge->next = edge_lists[end_id];
    edge_lists[end_id] = end_edge;
}

void print_topology() {
    printf("Nodes:\n");
    for(int i = 0; i < num_nodes; i++) {
        printf("%d: (%d, %d)\n", nodes[i]->id, nodes[i]->x, nodes[i]->y);
    }

    printf("Edges:\n");
    for(int i = 0; i < num_edges; i++) {
        printf("%d: (%d, %d) -> (%d, %d), weight=%d\n", 
            edges[i]->id, 
            edges[i]->start->x,
            edges[i]->start->y,
            edges[i]->end->x,
            edges[i]->end->y,
            edges[i]->weight);
    }

    printf("Edge Lists:\n");
    for(int i = 0; i < num_nodes; i++) {
        printf("%d: ", nodes[i]->id);
        struct EdgeList *edge = edge_lists[i];
        while(edge) {
            printf("%d ", edge->edge->id);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Generating random network topology...\n");

    for(int i = 0; i < 50; i++) {
        int x1 = rand() % 100;
        int y1 = rand() % 100;
        int x2 = rand() % 100;
        int y2 = rand() % 100;
        int weight = rand() % 100;

        add_edge(i, x1, y1, x2, y2, weight);
    }

    printf("\n\n");
    printf("Network Topology:\n\n");
    print_topology();

    return 0;
}