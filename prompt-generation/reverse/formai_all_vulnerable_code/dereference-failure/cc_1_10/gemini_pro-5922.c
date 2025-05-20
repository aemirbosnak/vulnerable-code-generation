//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int year;
    struct Node *next;
} Node;

Node *createNode(int year) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->year = year;
    node->next = NULL;
    return node;
}

void insertNode(Node **head, int year) {
    Node *node = createNode(year);
    if (*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

void printLinkedList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->year);
        head = head->next;
    }
    printf("NULL\n");
}

void timeTravel(Node **head, int year) {
    if (*head == NULL) {
        printf("You have not visited any year yet.\n");
    } else {
        Node *node = *head;
        while (node != NULL) {
            if (node->year == year) {
                printf("You are now in the year %d.\n", year);
                return;
            }
            node = node->next;
        }
        printf("You have not visited the year %d yet.\n", year);
    }
}

int main() {
    Node *head = NULL;

    int choice;
    do {
        printf("1. Visit a year\n");
        printf("2. Print the list of visited years\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int year;
                printf("Enter the year you want to visit: ");
                scanf("%d", &year);
                insertNode(&head, year);
                timeTravel(&head, year);
                break;
            }
            case 2: {
                printLinkedList(head);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please enter a valid choice.\n");
            }
        }
    } while (choice != 3);

    return 0;
}