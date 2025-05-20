//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[100];
    struct node *next;
} Node;

void append(Node **head, char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void prepend(Node **head, char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = *head;
    *head = new_node;
}

void delete(Node **head, char *data) {
    Node *temp = *head;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data not found\n");
        return;
    }
    Node *prev = temp->next;
    free(temp);
    prev->next = temp->next;
}

void display(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    append(&head, "apple");
    append(&head, "banana");
    append(&head, "cherry");
    display(head);
    prepend(&head, "date");
    display(head);
    delete(&head, "banana");
    display(head);
    return 0;
}