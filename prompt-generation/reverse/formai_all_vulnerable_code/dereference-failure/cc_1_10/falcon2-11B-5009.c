//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct Graph {
    Node* head;
    int size;
} Graph;

void add_node(Graph* g, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (g->head == NULL) {
        g->head = new_node;
    } else {
        Node* temp = g->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    g->size++;
}

void print_graph(Graph* g) {
    Node* temp = g->head;
    printf("Graph representation:\n");
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_node(Graph* g, int data) {
    Node* temp = g->head;
    Node* prev = NULL;
    while (temp!= NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                g->head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            g->size--;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void delete_graph(Graph* g) {
    Node* temp = g->head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    g->head = NULL;
    g->size = 0;
}

int main() {
    srand(time(NULL));
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->head = NULL;
    graph->size = 0;

    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        add_node(graph, data);
    }

    print_graph(graph);

    int node_to_delete = rand() % 10;
    delete_node(graph, node_to_delete);

    print_graph(graph);

    delete_graph(graph);

    return 0;
}