//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char *name;
    int age;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(char *name, int age) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->name = (char *) malloc(strlen(name) + 1);
    if (newNode->name == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(char *name) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s\nAge: %d\n", temp->name, temp->age);
        }
        temp = temp->next;
    }
}

int main() {
    int i, choice;
    char name[50];

    do {
        printf("\n\n");
        printf("1. Add node\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &i);
            addNode(name, i);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search(name);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}