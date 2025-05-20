//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node *next;
} Node;

Node *head = NULL;

void createList(char str[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = newNode;
    }
}

void displayList() {
    Node *temp = head;
    printf("List : ");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(char str[]) {
    Node *temp = head, *prev;

    if (temp != NULL && strcmp(temp->data, str) == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->data, str) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    createList("Hello");
    createList("World");
    createList("Linked");
    createList("List");

    displayList();

    deleteNode("World");

    displayList();

    return 0;
}