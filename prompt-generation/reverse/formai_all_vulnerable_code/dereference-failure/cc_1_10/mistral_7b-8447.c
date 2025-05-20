//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char gratitude[50];
    struct Node* next;
} Node;

Node* head = NULL;
int totalItems = 0;

void addGratitude(char* gratitude) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->gratitude, gratitude);
    newNode->next = head;
    head = newNode;
    totalItems++;
    printf("Added %s to the list of gratitude.\n", gratitude);
}

void displayGratitudeList() {
    Node* currentNode = head;
    printf("\nCurrent list of gratitude:\n");
    while (currentNode != NULL) {
        printf("%s\n", currentNode->gratitude);
        currentNode = currentNode->next;
    }
}

void removeDuplicates() {
    Node* currentNode = head;
    Node* previousNode = NULL;

    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        int isDuplicate = 0;

        while (nextNode != NULL) {
            if (strcmp(currentNode->gratitude, nextNode->gratitude) == 0) {
                isDuplicate = 1;
                break;
            }
            nextNode = nextNode->next;
        }

        if (!isDuplicate) {
            previousNode = currentNode;
            currentNode = nextNode;
        } else {
            previousNode->next = nextNode;
            Node* tempNode = currentNode;
            currentNode = nextNode;
            free(tempNode);
            totalItems--;
        }
    }
}

int main() {
    char input[50];
    int choice;

    while (1) {
        printf("\nLinkedListOfGratitude\n");
        printf("1. Add an item to the list of gratitude\n");
        printf("2. Display the list of gratitude\n");
        printf("3. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter something you are grateful for: ");
                scanf("%s", input);
                addGratitude(input);
                break;
            case 2:
                displayGratitudeList();
                break;
            case 3:
                printf("Thank you for using LinkedListOfGratitude. Goodbye!\n");
                removeDuplicates();
                free(head);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}