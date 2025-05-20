//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtTail(struct Node* head, char data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        head->prev->next = newNode;
        newNode->prev = head;
    }
    head = newNode;
}

int search(struct Node* head, char data) {
    while (head) {
        if (head->data == data) {
            return 1;
        } else if (head->next) {
            head = head->next;
        } else {
            return 0;
        }
    }
    return 0;
}

void findMazeRoute(struct Node* head, char start, char end) {
    struct Node* current = head;
    struct Node* visited = NULL;
    char currentChar = start;

    while (!search(visited, end) && current) {
        if (current->data == start) {
            visited = current;
            currentChar = current->data;
        } else if (!search(visited, current->data)) {
            insertAtTail(visited, currentChar);
            currentChar = current->data;
            current = current->next;
        } else {
            current = current->prev;
        }
    }

    if (search(visited, end)) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }
}

int main() {
    struct Node* head = NULL;
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    findMazeRoute(head, 'a', 'e');

    return 0;
}