//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef struct Node {
    char name[255];
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head) {
    Node* newNode = malloc(sizeof(Node));
    scanf("Enter name: ", newNode->name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
    return head;
}

void PrintList(Node* head) {
    while (head) {
        printf("%s\n", head->name);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    while (1) {
        printf("Options:\n");
        printf("1. Insert at tail\n");
        printf("2. Print list\n");
        printf("3. Exit\n");

        int choice;
        scanf("Enter choice: ", &choice);

        switch (choice) {
            case 1:
                InsertAtTail(head);
                break;
            case 2:
                PrintList(head);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}