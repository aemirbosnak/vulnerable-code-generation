//FormAI DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define Structs
typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int size;
} LinkedList;

// Function Prototypes
void initializeList(LinkedList* list);
void insertAtBeginning(LinkedList* list, int data);
void insertAtEnd(LinkedList* list, int data);
void insertAt(LinkedList* list, int data, int position);
void deleteFromBeginning(LinkedList* list);
void deleteFromEnd(LinkedList* list);
void deleteAt(LinkedList* list, int position);
void displayList(LinkedList* list);
void clearList(LinkedList* list);

int main() {
    // Initialize List
    LinkedList list;
    initializeList(&list);

    // Insert Initial Values
    insertAtEnd(&list, 5);
    insertAtBeginning(&list, 3);
    insertAtEnd(&list, 7);
    insertAt(&list, 4, 2);

    // Display Initial List
    displayList(&list);

    // Delete Nodes
    deleteFromBeginning(&list);
    deleteFromEnd(&list);
    deleteAt(&list, 1);

    // Display Updated List
    displayList(&list);

    // Clear Memory
    clearList(&list);

    return 0;
}

// Function Definitions
void initializeList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void insertAtBeginning(LinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void insertAtEnd(LinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->size == 0) {
        list->head = node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    list->size++;
}

void insertAt(LinkedList* list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(list, data);
    } else if (position == list->size) {
        insertAtEnd(list, data);
    } else {
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = data;

        Node* current = list->head;
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        list->size++;
    }
}

void deleteFromBeginning(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->head;
    list->head = current->next;
    free(current);
    list->size--;
}

void deleteFromEnd(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }

    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->size--;
}

void deleteAt(LinkedList* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        deleteFromBeginning(list);
    } else if (position == list->size-1) {
        deleteFromEnd(list);
    } else {
        Node* current = list->head;
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        free(nodeToDelete);
        list->size--;
    }
}

void displayList(LinkedList* list) {
    Node* current = list->head;

    printf("List Size: %d\n", list->size);
    printf("List Contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clearList(LinkedList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}