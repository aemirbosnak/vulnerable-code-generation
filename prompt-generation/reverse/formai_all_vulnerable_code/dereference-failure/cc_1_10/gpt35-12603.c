//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void add_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void print_list() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(int data) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;

    if(head->data == data) {
        head = head->next;
        free(temp);
        return;
    }

    while(temp->next != NULL && temp->next->data != data)
        temp = temp->next;

    if(temp->next == NULL) {
        printf("Data not found!\n");
        return;
    }

    Node *del_node = temp->next;
    temp->next = del_node->next;

    free(del_node);
}

int main() {
    add_node(10);
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);

    printf("List before deletion: ");
    print_list();

    // Deleting node with value 30
    delete_node(30);

    printf("List after deletion: ");
    print_list();

    return 0;
}