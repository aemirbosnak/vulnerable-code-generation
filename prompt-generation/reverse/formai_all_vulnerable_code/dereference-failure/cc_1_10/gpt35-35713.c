//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertAtBeginning(Node** head, int data) {
    Node* new_node = createNode(data);
    new_node->next = *head;
    *head = new_node;
}

void insertAtEnd(Node** head, int data) {
    Node* new_node = createNode(data);
    Node* temp = *head;
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtPosition(Node** head, int data, int pos) {
    if(pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    Node* new_node = createNode(data);
    if(pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    Node* temp = *head;
    int i;
    for(i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteFromBeginning(Node** head) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp1 = *head, *temp2 = *head;
    while(temp1->next) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if(*head == temp1) {
        *head = NULL;
    } else {
        temp2->next = NULL;
    }
    free(temp1);
}

void deleteFromPosition(Node** head, int pos) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if(pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    Node* temp1 = *head, *temp2 = NULL;
    if(pos == 1) {
        *head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 1; i < pos && temp1 != NULL; i++) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if(temp1 == NULL) {
        printf("Invalid position!\n");
        return;
    }
    temp2->next = temp1->next;
    free(temp1);
}

void printList(Node* head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List elements: ");
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    insertAtPosition(&head, 6, 2);
    insertAtPosition(&head, 8, 4);
    printList(head);
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 2);
    printList(head);
    return 0;
}