//Falcon-180B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
};

struct node* head = NULL;

void addNode(void) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the data for the new node: ");
    scanf("%s", newNode->data);
    newNode->size = strlen(newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(void) {
    char key[MAX_SIZE];

    printf("Enter the key to delete the node: ");
    scanf("%s", key);

    struct node* temp = head;

    if (strcmp(temp->data, key) == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp->next!= NULL && strcmp(temp->next->data, key)!= 0) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node not found!\n");
        return;
    }

    struct node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void displayList(void) {
    struct node* temp = head;
    printf("Linked List: ");

    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    do {
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            displayList();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}