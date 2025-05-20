//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insert(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int num, choice;
    char option;

    while (1) {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Print the list\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &num);
                head = insert(head, num);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &num);
                head = insert(head, num);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}