//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct user {
    char name[50];
    int friends[100];
};

struct graph {
    struct user nodes[100];
    int num_nodes;
};

struct graph* create_graph() {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->num_nodes = 0;
    return graph;
}

void add_node(struct graph* graph, char* name) {
    struct user* new_node = (struct user*)malloc(sizeof(struct user));
    strcpy(new_node->name, name);
    for (int i = 0; i < 100; i++) {
        new_node->friends[i] = 0;
    }
    graph->nodes[graph->num_nodes] = *new_node;
    graph->num_nodes++;
}

void add_friendship(struct graph* graph, char* name1, char* name2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i].name, name1) == 0) {
            index1 = i;
        }
        if (strcmp(graph->nodes[i].name, name2) == 0) {
            index2 = i;
        }
    }
    if (index1!= -1 && index2!= -1) {
        graph->nodes[index1].friends[index2] = 1;
        graph->nodes[index2].friends[index1] = 1;
    }
}

void print_graph(struct graph* graph) {
    printf("Nodes in the graph:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%s : ", graph->nodes[i].name);
        for (int j = 0; j < 100; j++) {
            if (graph->nodes[i].friends[j] == 1) {
                printf("%s, ", graph->nodes[i].name);
            }
        }
        printf("\n");
    }
}

int main() {
    struct graph* graph = create_graph();
    add_node(graph, "Alice");
    add_node(graph, "Bob");
    add_node(graph, "Charlie");
    add_node(graph, "Dave");
    add_friendship(graph, "Alice", "Bob");
    add_friendship(graph, "Alice", "Charlie");
    add_friendship(graph, "Bob", "Charlie");
    add_friendship(graph, "Dave", "Charlie");
    add_friendship(graph, "Dave", "Bob");
    add_friendship(graph, "Dave", "Alice");
    print_graph(graph);
    return 0;
}