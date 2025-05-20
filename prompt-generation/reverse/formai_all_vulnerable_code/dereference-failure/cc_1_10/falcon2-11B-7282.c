//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int size) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = i;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current!= NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }
    *head = NULL;
}

int main() {
    int size = 10;
    struct Node* list = createList(size);
    printList(list);
    printf("Size: %d\n", size);
    deleteList(&list);
    return 0;
}