//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node * next;
}node;

typedef struct circuit {
    int size;
    node * head;
    node * tail;
}circuit;

circuit * create_circuit();
void add_node(circuit * c, int data);
void remove_node(circuit * c, int data);
void print_circuit(circuit * c);

int main() {
    circuit * myCircuit = create_circuit();
    add_node(myCircuit, 100);
    add_node(myCircuit, 200);
    add_node(myCircuit, 300);
    print_circuit(myCircuit);
    remove_node(myCircuit, 200);
    print_circuit(myCircuit);

    return 0;
}

circuit * create_circuit() {
    circuit * c = (circuit*) malloc(sizeof(circuit));
    c->size = 0;
    c->head = NULL;
    c->tail = NULL;

    return c;
}

void add_node(circuit * c, int data) {
    node * n = (node*) malloc(sizeof(node));
    n->data = data;
    if (c->size == 0) {
        c->head = n;
        c->tail = n;
        n->next = c->head;
        c->size++;
        return;
    }
    else {
        c->tail->next = n;
        n->next = c->head;
        c->tail = n;
        c->size++;
    }
}

void remove_node(circuit * c, int data) {
    node * temp = c->head;
    node * prev = c->tail;
    while (temp->data!=data && temp!=c->tail) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == c->tail && temp->data == data) {
        prev->next = c->head;
        c->tail = prev;
        free(temp);
        c->size--;
    }
    else if (temp->data == data) {
        prev->next = temp->next;
        free(temp);
        c->size--;
    }
    else {
        printf("%d not found in the circuit\n",data);
    }
}

void print_circuit(circuit * c) {
    node * temp = c->head;
    for (int i=0; i<c->size; i++) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}