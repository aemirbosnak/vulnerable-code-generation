//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

void addEdge(struct node **head, int value);
void displayGraph(struct node **head, int vertices);

int main(){
    int vertices, edges, source, destination;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct node *adj_list[vertices];
    for(int i=0; i<vertices; i++){
        adj_list[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for(int i=0; i<edges; i++){
        printf("Enter the source and destination for edge %d: ", i+1);
        scanf("%d %d", &source, &destination);
        addEdge(&adj_list[source], destination);
        addEdge(&adj_list[destination], source);
    }

    printf("\nGraph Representation:\n");
    displayGraph(adj_list, vertices);

    return 0;
}

void addEdge(struct node **head, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void displayGraph(struct node **head, int vertices){
    struct node *temp;
    for(int i=0; i<vertices; i++){
        temp = head[i];
        printf("\n%d: ", i);
        while(temp != NULL){
            printf("%d ", temp->value);
            temp = temp->next;
        }
    }
}