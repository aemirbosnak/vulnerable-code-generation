//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char *name;
    int value;
    struct _node *next;
} node;

typedef struct _circuit {
    char *name;
    int size;
    node *nodes;
} circuit;

circuit *create_circuit(char *name) {
    circuit *c = malloc(sizeof(circuit));
    c->name = strdup(name);
    c->size = 0;
    c->nodes = NULL;
    return c;
}

void destroy_circuit(circuit *c) {
    node *n = c->nodes;
    while (n) {
        node *next = n->next;
        free(n->name);
        free(n);
        n = next;
    }
    free(c->name);
    free(c);
}

node *create_node(char *name, int value) {
    node *n = malloc(sizeof(node));
    n->name = strdup(name);
    n->value = value;
    n->next = NULL;
    return n;
}

void destroy_node(node *n) {
    free(n->name);
    free(n);
}

void add_node(circuit *c, node *n) {
    if (!c->nodes) {
        c->nodes = n;
    } else {
        node *p = c->nodes;
        while (p->next) {
            p = p->next;
        }
        p->next = n;
    }
    c->size++;
}

void remove_node(circuit *c, node *n) {
    if (c->nodes == n) {
        c->nodes = n->next;
    } else {
        node *p = c->nodes;
        while (p->next != n) {
            p = p->next;
        }
        p->next = n->next;
    }
    c->size--;
}

void print_circuit(circuit *c) {
    printf("Circuit: %s\n", c->name);
    printf("Size: %d\n", c->size);
    node *n = c->nodes;
    while (n) {
        printf("  Node: %s, Value: %d\n", n->name, n->value);
        n = n->next;
    }
}

int main() {
    circuit *c = create_circuit("MyCircuit");
    node *n1 = create_node("Node1", 1);
    node *n2 = create_node("Node2", 2);
    node *n3 = create_node("Node3", 3);
    add_node(c, n1);
    add_node(c, n2);
    add_node(c, n3);
    print_circuit(c);
    remove_node(c, n2);
    print_circuit(c);
    destroy_node(n1);
    destroy_node(n3);
    destroy_circuit(c);
    return 0;
}