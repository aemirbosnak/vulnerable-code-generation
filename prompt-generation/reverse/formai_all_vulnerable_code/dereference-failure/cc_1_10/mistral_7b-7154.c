//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node** create2DLinkedList() {
    Node** arr = (Node**)calloc(MAX_ROWS, sizeof(Node*));
    for (int i = 0; i < MAX_ROWS; i++) {
        arr[i] = NULL;
    }
    return arr;
}

void insertAtEnd2D(Node** arr, int row, int col, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (arr[row] == NULL) {
        arr[row] = newNode;
    } else {
        Node* lastNode = arr[row];
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void display2DLinkedList(Node** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\nRow %d: ", i);
        Node* temp = arr[i];
        while (temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL");
    }
}

Node* searchLinkedList2D(Node** arr, int row, int col, int data) {
    Node* temp = arr[row];
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteNode2D(Node** arr, int row, int col, int data) {
    Node* current = arr[row];
    Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (previous == NULL) {
        arr[row] = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

int main() {
    Node** arr = create2DLinkedList();

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            insertAtEnd2D(arr, i, j, j * 10);
        }
    }

    display2DLinkedList(arr, MAX_ROWS, MAX_COLS);

    Node* foundNode = searchLinkedList2D(arr, 3, 2, 21);
    if (foundNode != NULL) {
        printf("\nFound node with data %d at row %d and column %d.", foundNode->data, (foundNode->next == NULL) ? foundNode->data / 10 : foundNode->data / 10 + 1, foundNode->data % 10);
    } else {
        printf("\nNode not found.");
    }

    deleteNode2D(arr, 4, 1, 15);
    display2DLinkedList(arr, MAX_ROWS, MAX_COLS);

    return 0;
}