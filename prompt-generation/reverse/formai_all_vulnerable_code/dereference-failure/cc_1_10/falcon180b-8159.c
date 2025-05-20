//Falcon-180B DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    struct Node *next;
} Node;

void appendNode(Node **head, char *name, int age) {
    Node *newNode = malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->age = age;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    while (head!= NULL) {
        printf("%s is %d years old.\n", head->name, head->age);
        head = head->next;
    }
}

void deleteList(Node **head) {
    Node *curr = *head;
    while (curr!= NULL) {
        Node *next = curr->next;
        free(curr->name);
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void searchList(Node *head, char *name) {
    while (head!= NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("%s is %d years old.\n", name, head->age);
            return;
        }
        head = head->next;
    }
    printf("%s not found.\n", name);
}

int main() {
    Node *head = NULL;
    appendNode(&head, "Alice", 25);
    appendNode(&head, "Bob", 30);
    appendNode(&head, "Charlie", 20);
    appendNode(&head, "Dave", 40);
    appendNode(&head, "Eve", 35);
    printList(head);
    searchList(head, "Bob");
    deleteList(&head);
    return 0;
}