//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Graph;

Graph *create_graph(int capacity) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->data = (Person *) malloc(capacity * sizeof(Person));
    graph->size = 0;
    graph->capacity = capacity;
    return graph;
}

void destroy_graph(Graph *graph) {
    free(graph->data);
    free(graph);
}

void add_person(Graph *graph, int id, char *name, int age) {
    if (graph->size >= graph->capacity) {
        printf("Graph is full. Cannot add more people.\n");
        return;
    }
    Person *person = (Person *) malloc(sizeof(Person));
    person->id = id;
    strcpy(person->name, name);
    person->age = age;
    graph->data[graph->size++] = *person;
}

void remove_person(Graph *graph, int id) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->data[i].id == id) {
            for (int j = i; j < graph->size - 1; j++) {
                graph->data[j] = graph->data[j + 1];
            }
            graph->size--;
            break;
        }
    }
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", graph->data[i].id, graph->data[i].name, graph->data[i].age);
    }
}

void main() {
    Graph *graph = create_graph(5);
    add_person(graph, 1, "John", 25);
    add_person(graph, 2, "Jane", 30);
    add_person(graph, 3, "Bob", 40);
    add_person(graph, 4, "Alice", 35);
    add_person(graph, 5, "Charlie", 50);
    print_graph(graph);
    remove_person(graph, 3);
    print_graph(graph);
    destroy_graph(graph);
}