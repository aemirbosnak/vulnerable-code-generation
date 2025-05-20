//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\n***** MENU *****\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("List: ");
                printList(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}