//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

//Node structure
typedef struct node{
    int id;
    char name[20];
    int degree;
    struct node* edges[MAX_EDGES];
}Node;

//Linked list functions
void add_node(Node* graph, int id, char* name){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->degree = 0;
    for(int i=0; i<MAX_EDGES; i++){
        new_node->edges[i] = NULL;
    }
    graph->degree++;
    graph->edges[graph->degree-1] = new_node;
}

void add_edge(Node* graph, int from_node_id, int to_node_id){
    Node* from_node = graph->edges[from_node_id];
    Node* to_node = graph->edges[to_node_id];
    from_node->degree++;
    to_node->degree++;
    from_node->edges[from_node->degree-1] = to_node;
    to_node->edges[to_node->degree-1] = from_node;
}

//Main function
int main(){
    Node* graph = (Node*)malloc(sizeof(Node));
    graph->degree = 0;
    for(int i=0; i<MAX_EDGES; i++){
        graph->edges[i] = NULL;
    }

    //Add nodes
    add_node(graph, 1, "A");
    add_node(graph, 2, "B");
    add_node(graph, 3, "C");
    add_node(graph, 4, "D");

    //Add edges
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);

    //Print graph
    printf("Graph:\n");
    for(int i=0; i<graph->degree; i++){
        printf("Node %d: %s\n", graph->edges[i]->id, graph->edges[i]->name);
        printf("Edges: ");
        for(int j=0; j<graph->edges[i]->degree; j++){
            printf("%d ", graph->edges[i]->edges[j]->id);
        }
        printf("\n");
    }

    return 0;
}