//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct vertex {
    int id;
    int degree;
    int visited;
    struct vertex *next;
} vertex;

typedef struct edge {
    int src;
    int dest;
} edge;

void print_graph(vertex *head) {
    vertex *current = head;
    while (current!= NULL) {
        printf("%d -> ", current->id);
        current = current->next;
    }
    printf("NULL\n");
}

void add_vertex(vertex **head, int id) {
    vertex *new_vertex = (vertex *)malloc(sizeof(vertex));
    new_vertex->id = id;
    new_vertex->degree = 0;
    new_vertex->visited = 0;
    new_vertex->next = *head;
    *head = new_vertex;
}

void add_edge(vertex *head, int src, int dest) {
    vertex *current = head;
    while (current!= NULL) {
        if (current->id == src) {
            vertex *new_vertex = (vertex *)malloc(sizeof(vertex));
            new_vertex->id = dest;
            new_vertex->degree = 1;
            new_vertex->visited = 0;
            new_vertex->next = current->next;
            current->next = new_vertex;
            return;
        }
        current = current->next;
    }
    printf("Vertex not found!\n");
}

void dfs(vertex *head) {
    vertex *current = head;
    while (current!= NULL) {
        current->visited = 1;
        current = current->next;
    }
    current = head;
    while (current!= NULL) {
        if (!current->visited) {
            printf("%d -> ", current->id);
            current = current->next;
        } else {
            printf("NULL\n");
            current = current->next;
        }
    }
}

int main() {
    vertex *head = NULL;
    add_vertex(&head, 1);
    add_vertex(&head, 2);
    add_vertex(&head, 3);
    add_edge(&head, 1, 2);
    add_edge(&head, 2, 3);
    add_edge(&head, 3, 1);
    print_graph(head);
    dfs(head);
    return 0;
}