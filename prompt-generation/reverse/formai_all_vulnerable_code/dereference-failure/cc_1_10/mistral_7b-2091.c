//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

typedef struct _Node {
    int data;
    size_t size;
    struct _Node* next;
} Node;

Node* createNode(int data, size_t size) {
    Node* newNode = (Node*) mmap(NULL, sizeof(Node) + size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (newNode == MAP_FAILED) {
        perror("Error creating new node");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->size = size;
    newNode->next = NULL;

    return newNode;
}

void addToList(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node* findNode(Node* head, int data) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            munmap((void*) current, current->size + sizeof(Node));
            break;
        }
        previous = current;
        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("Data: %d, Size: %ld, Address: %p\n", current->data, current->size, current);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    int i;
    clock_t start, end;

    start = clock();

    for (i = 0; i < 10; i++) {
        Node* newNode = createNode(i, sizeof(int) + i * sizeof(int));
        addToList(&head, newNode);
    }

    printf("List created:\n");
    printList(head);

    Node* nodeToFind = findNode(head, 5);
    if (nodeToFind != NULL) {
        printf("\nNode with data 5 found:\n");
        printList(head);

        deleteNode(&head, 5);
        printf("\nNode with data 5 deleted:\n");
        printList(head);
    }

    end = clock();

    printf("\nExecution time: %f seconds\n", (float) (end - start) / CLOCKS_PER_SEC);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        munmap((void*) temp, temp->size + sizeof(Node));
    }

    return 0;
}