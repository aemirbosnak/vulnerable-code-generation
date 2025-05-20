//Gemma-7B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

Node* head = NULL;

void insert(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

void traverse() {
    Node* current = head;
    while (current) {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
}

void remove(void* data) {
    Node* previous = NULL;
    Node* current = head;

    while (current) {
        if (current->data == data) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Data not found.\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    traverse();

    remove(20);

    traverse();

    return 0;
}