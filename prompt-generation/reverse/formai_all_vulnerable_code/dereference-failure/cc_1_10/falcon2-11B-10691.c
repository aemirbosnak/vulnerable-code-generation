//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(int data) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

int search(int data) {
    struct Node* current = head;

    while (current!= NULL && current->data!= data) {
        current = current->next;
    }

    if (current!= NULL) {
        return 1;
    } else {
        return 0;
    }
}

void printList() {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    printList(); // Output: 1 2 3 4

    delete(2);

    printList(); // Output: 1 3 4

    int searchVal = 3;
    if (search(searchVal)) {
        printf("Found %d in the list.\n", searchVal);
    } else {
        printf("Not found in the list.\n");
    }

    return 0;
}