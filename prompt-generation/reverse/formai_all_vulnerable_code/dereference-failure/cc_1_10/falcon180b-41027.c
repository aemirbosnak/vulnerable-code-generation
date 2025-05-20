//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node *next;
} Node;

Node *head = NULL;

void push(char data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    display();
    pop();
    pop();
    display();
    return 0;
}