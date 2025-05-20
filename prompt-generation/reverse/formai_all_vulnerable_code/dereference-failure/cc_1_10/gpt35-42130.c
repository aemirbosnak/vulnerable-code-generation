//FormAI DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char email[50];
    struct node *next;
};

struct node *head = NULL;

void addNode(char *name, char *email) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%s (%s)\n", temp->name, temp->email);
        temp = temp->next;
    }
}

struct node *findNode(char *email) {
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void removeNode(char *email) {
    if (head == NULL) {
        return;
    }
    struct node *temp = head;
    if (strcmp(temp->email, email) == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        if (strcmp(temp->next->email, email) == 0) {
            struct node *removeNode = temp->next;
            temp->next = removeNode->next;
            free(removeNode);
            return;
        }
        temp = temp->next;
    }
}

int main() {
    addNode("Alice", "alice@example.com");
    addNode("Bob", "bob@example.com");
    addNode("Charlie", "charlie@example.com");
    addNode("Dave", "dave@example.com");
    displayList();
    struct node *foundNode = findNode("alice@example.com");
    if (foundNode != NULL) {
        printf("Found node: %s (%s)\n", foundNode->name, foundNode->email);
    } else {
        printf("Node not found.\n");
    }
    removeNode("alice@example.com");
    displayList();
    return 0;
}