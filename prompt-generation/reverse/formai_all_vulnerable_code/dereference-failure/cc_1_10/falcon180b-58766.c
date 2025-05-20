//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList() {
    struct Node* head = NULL;
    int choice, data;

    printf("Enter the size of the linked list: ");
    scanf("%d", &choice);

    if (choice <= 0 || choice > MAX_SIZE) {
        printf("Invalid size.\n");
        exit(1);
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory error.\n");
        exit(1);
    }

    head->data = 0;
    head->next = NULL;

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < choice; i++) {
        scanf("%d", &data);
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("Memory error.\n");
            exit(1);
        }
        temp->data = data;
        temp->next = NULL;
        head->next = temp;
        head = temp;
    }

    return head;
}

void printLinkedList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createLinkedList();
    printLinkedList(head);

    return 0;
}