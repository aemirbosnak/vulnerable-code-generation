//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char item[20];
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    int size;
};

void insert(struct Warehouse* w, char item) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->item, item);
    newNode->next = NULL;

    if (w->head == NULL) {
        w->head = newNode;
    } else {
        insert(w, item);
    }
}

void search(struct Warehouse* w, char item) {
    struct Node* current = w->head;

    while (current) {
        if (strcmp(current->item, item) == 0) {
            printf("%s found!\n", item);
            return;
        }
        current = current->next;
    }

    printf("%s not found.\n", item);
}

int main() {
    struct Warehouse* w = malloc(sizeof(struct Warehouse));
    w->head = NULL;
    w->size = 0;

    insert(w, "Apple");
    insert(w, "Banana");
    insert(w, "Orange");

    search(w, "Apple");
    search(w, "Banana");
    search(w, "Kiwi");

    return 0;
}