//FormAI DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

void addNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = start;
    start = newNode;
    printf("Successfully added a node with data value %d to the front of the list!\n", data);
}

void deleteNode() {
    if (start == NULL) {
        printf("Error: Cannot delete node from an empty list!\n");
        return;
    }
    struct Node* tempNode = start;
    start = start->next;
    free(tempNode);
    printf("Successfully deleted the first node in the list! Goodbye, node!\n");
}

int main() {
    printf("Welcome to the Linked List of Fun!\n");
    printf("It's a magical list that can do all sorts of things!\n");
    
    int choice, data;
    while (1) {
        printf("What would you like to do with the list today?\n");
        printf("1. Add a node to the front of the list.\n");
        printf("2. Delete a node from the front of the list.\n");
        printf("3. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("What data value would you like to add to the list? ");
                scanf("%d", &data);
                addNode(data);
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                printf("Goodbye! May the Linked List of Fun bring you joy and happiness always!\n");
                exit(0);
            default:
                printf("Oops, that's not a valid choice. Please try again.\n");
        }
    }
    return 0;
}