//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[10];
    int visited;
    struct Node* next;
};

struct Graph{
    struct Node* nodes[10];
    int size;
};

void topoSort(struct Graph* graph, struct Node* node){
    if(node->visited == 1){
        return;
    }
    else{
        struct Node* current = node->next;
        while(current != NULL){
            topoSort(graph, current);
            current = current->next;
        }
        node->visited = 1;
        printf("%s ", node->name);
    }
}

int main(){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->size = 0;
    int i;
    for(i = 0; i < 10; i++){
        graph->nodes[i] = NULL;
    }

    // Add nodes to graph
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node1->name, "A");
    node1->visited = 0;
    node1->next = NULL;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node2->name, "B");
    node2->visited = 0;
    node2->next = node1;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node3->name, "C");
    node3->visited = 0;
    node3->next = node1;

    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node4->name, "D");
    node4->visited = 0;
    node4->next = node2;

    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node5->name, "E");
    node5->visited = 0;
    node5->next = node3;
    
    graph->nodes[0] = node1;
    graph->nodes[1] = node2;
    graph->nodes[2] = node3;
    graph->nodes[3] = node4;
    graph->nodes[4] = node5;
    graph->size = 5;

    printf("Topological Sort: ");
    for(i = 0; i < graph->size; i++){
        topoSort(graph, graph->nodes[i]);
    }
    printf("\n");

    return 0;
}