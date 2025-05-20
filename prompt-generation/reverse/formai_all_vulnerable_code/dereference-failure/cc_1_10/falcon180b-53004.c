//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[50];
    struct node *next;
} node;

node *head = NULL;

void addNode(char data[]) {
    node *newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->data, data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deleteNode(char data[]) {
    node *temp = head;
    node *prev = NULL;

    if (strcmp(temp->data, data) == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void searchNode(char data[]) {
    node *temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Node found.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Node not found.\n");
}

void displayList() {
    node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List:\n");
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    addNode("John");
    addNode("Doe");
    addNode("Jane");

    displayList();

    searchNode("John");
    searchNode("Doe");
    searchNode("Jane");

    deleteNode("John");

    displayList();

    return 0;
}