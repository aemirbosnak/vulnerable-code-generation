//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* Node;

Node create_node(int data) {
    Node new_node = (Node) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed");
        exit(0);
    }
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void insert(Node head, int data) {
    Node new_node = create_node(data);
    
    while(head -> next != NULL) {
        head = head -> next;
    }
    head -> next = new_node;
}

void display(Node head) {
    printf("Current state of the data structure: ");
    
    while(head -> next != NULL) {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    
    printf("%d\n", head -> data);
}

int main() {
    Node head = create_node(1);
    insert(head, 2);
    insert(head, 3);
    
    display(head);
    
    return 0;
}