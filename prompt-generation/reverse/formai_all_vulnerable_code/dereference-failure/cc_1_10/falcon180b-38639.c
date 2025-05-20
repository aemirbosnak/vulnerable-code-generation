//Falcon-180B DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    struct node* next;
};

struct node* head = NULL;

void push(char* str) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->next = head;
    head = new_node;
}

void print_stack() {
    struct node* curr = head;
    while (curr!= NULL) {
        printf("%s ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void pop() {
    if (head == NULL) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    head = head->next;
}

void delete_stack() {
    struct node* curr = head;
    while (curr!= NULL) {
        free(curr);
        curr = curr->next;
    }
    head = NULL;
}

int main() {
    push("Hello");
    push("World");
    print_stack();
    pop();
    print_stack();
    delete_stack();
    return 0;
}