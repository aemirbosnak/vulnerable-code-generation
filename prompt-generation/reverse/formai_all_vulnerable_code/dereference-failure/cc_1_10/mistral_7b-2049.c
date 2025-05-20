//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* head = NULL;

void insert(int data, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(int data) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* current = head;
    if (current->data == data) {
        head = current->next;
        free(current);
        return;
    }

    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Data not found!\n");
        return;
    }

    Node* toDelete = current->next;
    current->next = current->next->next;
    free(toDelete);
}

int search(int data) {
    Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

void print() {
    Node* current = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while (current != NULL) {
        printf("(%s, %d) -> ", current->name, current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insert(1, "One");
    insert(2, "Two");
    insert(3, "Three");
    insert(4, "Four");

    print();

    delete(2);
    print();

    int position = search(3);
    if (position != -1) {
        printf("Found at position %d\n", position);
    } else {
        printf("Not found!\n");
    }

    return 0;
}