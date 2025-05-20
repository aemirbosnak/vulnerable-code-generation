//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;

void push(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int pop() {
    if (head == NULL) return -1;
    node* temp = head;
    int data = temp->data;
    head = head->next;
    free(temp);
    return data;
}

int peek() {
    if (head == NULL) return -1;
    return head->data;
}

void display() {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    printf("Popped %d\n", pop());
    printf("Peeked %d\n", peek());
    display();
    return 0;
}