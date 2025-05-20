//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    printf("List:\n");
    while (current != NULL) {
        printf("| %s | %d |\n", current->name, current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    addNode(&head, 1, "Apple");
    addNode(&head, 2, "Banana");
    addNode(&head, 3, "Cherry");
    addNode(&head, 4, "Durian");
    addNode(&head, 5, "Elderberry");
    displayList(head);

    int choice, data, i;
    char name[20];

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter name: ");
                scanf("%s", name);
                addNode(&head, data, name);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                Node* current = head;
                for (int j = 0; j < i - 1 && current != NULL; j++) {
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Invalid position\n");
                } else {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    free(temp);
                }
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}