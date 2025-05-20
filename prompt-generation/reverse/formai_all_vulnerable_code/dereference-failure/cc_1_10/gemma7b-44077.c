//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node* head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }
}

void display(node* head) {
    node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    display(head);

    // CPU Scheduling Algorithm - Round Robin
    int quantum = 3;
    node* current = head;
    while (current) {
        printf("Process: %d, Time Slice: %d\n", current->data, quantum);
        current = current->next;
    }

    return 0;
}