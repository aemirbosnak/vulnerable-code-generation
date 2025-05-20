//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define our Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define our Linked List structure
typedef struct linked_list {
    Node* head;
} LinkedList;

// Initialize our LinkedList
void init(LinkedList* list) {
    list->head = NULL;
}

// Check if Linked List is Empty
bool is_empty(LinkedList* list) {
    return list->head == NULL;
}

// Get the size of Linked List
int size(LinkedList* list) {
    int size = 0;
    Node* current = list->head;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

// Add node to Linked List at the beginning
void add_first(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if (is_empty(list)) {
        list->head = newNode;
        return;
    }

    newNode->next = list->head;
    list->head = newNode;
}

// Add node to Linked List at the end
void add_last(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (is_empty(list)) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Remove the first Node from Linked List
void remove_first(LinkedList* list) {
    if (is_empty(list)) return;

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

// Remove the last Node from Linked List
void remove_last(LinkedList* list) {
    if (is_empty(list)) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* current = list->head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Print the Linked List
void print_list(LinkedList* list) {
    if (is_empty(list)) {
        printf("Linked List is Empty\n");
        return;
    }

    printf("List: ");
    Node* current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    init(&list);
    int choice, value;

    while (1) {
        printf("1. Add First\n2. Add Last\n3. Remove First\n4. Remove Last\n5. Print List\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add_first(&list, value);
                break;
            case 2:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add_last(&list, value);
                break;
            case 3:
                remove_first(&list);
                break;
            case 4:
                remove_last(&list);
                break;
            case 5:
                print_list(&list);
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;
}