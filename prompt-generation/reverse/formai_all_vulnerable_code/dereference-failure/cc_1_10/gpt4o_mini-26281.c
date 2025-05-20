//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(LinkedList* list) {
    Node* current = list->head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

void reverse(LinkedList* list) {
    Node *prev = NULL, *current = list->head, *next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    list->head = prev; // Update head to the new first node
}

void search(LinkedList* list, int value) {
    Node* current = list->head;
    int position = 0;
    while (current != NULL) {
        if (current->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

int main() {
    LinkedList* list = createLinkedList();
    
    printf("Appending elements to the linked list...\n");
    for (int i = 1; i <= 5; i++) {
        append(list, i);
    }
    display(list);
    
    printf("Reversing linked list...\n");
    reverse(list);
    display(list);

    int searchValue = 3;
    printf("Searching for value %d in the list...\n", searchValue);
    search(list, searchValue);

    printf("Cleaning up the linked list...\n");
    deleteList(list);
    printf("All resources freed!\n");

    return 0;
}