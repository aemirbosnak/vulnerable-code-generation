//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the linked list
typedef struct List {
    struct Node* head;
    int size;
} List;

// Function to insert a new node at the beginning of the list
void insert(List* list, int data) {
    struct Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Function to delete a node from the list
void delete(List* list, int data) {
    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    list->size--;
}

// Function to display the data structure of the linked list
void display(List* list) {
    struct Node* current = list->head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    List list;
    list.head = NULL;
    list.size = 0;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);

    display(&list);

    delete(&list, 2);

    display(&list);

    return 0;
}