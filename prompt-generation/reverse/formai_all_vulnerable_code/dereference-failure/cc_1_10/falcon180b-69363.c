//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    char data[MAX_SIZE];
    int size;
    struct Node* next;
};

struct Node* createNode(char* data, int size) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;

    return newNode;
}

struct Node* addNode(struct Node* head, char* data, int size) {
    struct Node* newNode = createNode(data, size);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;

        while (temp->next!= NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

int search(struct Node* head, char* data) {
    struct Node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Data found\n");
            return temp->size;
        }

        temp = temp->next;
    }

    printf("Data not found\n");
    return -1;
}

void main() {
    struct Node* head = NULL;

    head = addNode(head, "apple", 5);
    head = addNode(head, "banana", 6);
    head = addNode(head, "cherry", 7);

    char searchData[MAX_SIZE];

    printf("Enter the data to search: ");
    scanf("%s", searchData);

    int result = search(head, searchData);

    if (result!= -1) {
        printf("Size of the data: %d\n", result);
    }
}