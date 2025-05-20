//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data);
Node* insert_node(Node* head, int data);
Node* delete_node(Node* head, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;

    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);

    print_list(head);

    head = delete_node(head, 3);

    print_list(head);

    return 0;
}

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Node* insert_node(Node* head, int data) {
    Node* new_node = create_node(data);

    if(head == NULL) {
        head = new_node;
        return head;
    }

    Node* temp = head;

    while(temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;

    return head;
}

Node* delete_node(Node* head, int data) {
    Node* temp = head;

    if(temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if(temp == NULL) {
        return head;
    }

    Node* next_node = temp->next;
    free(temp);
    temp = next_node;

    return head;
}

void print_list(Node* head) {
    Node* temp = head;

    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}