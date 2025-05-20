//Falcon-180B DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
} Node;

Node* head = NULL;

void init() {
    head = (Node*) malloc(sizeof(Node));
    if (head == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    head->data[0] = '\0';
    head->size = 0;
    head->next = NULL;
}

void add(char* str) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data, str);
    newNode->size = strlen(str);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(char* str) {
    Node* prev = head;
    Node* curr = head->next;
    while (curr!= NULL) {
        if (strcmp(curr->data, str) == 0) {
            if (curr == head) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Error: String not found.\n");
}

void search(char* str) {
    Node* curr = head->next;
    while (curr!= NULL) {
        if (strcmp(curr->data, str) == 0) {
            printf("Found string: %s\n", curr->data);
            return;
        }
        curr = curr->next;
    }
    printf("Error: String not found.\n");
}

void print() {
    Node* curr = head->next;
    while (curr!= NULL) {
        printf("String: %s\n", curr->data);
        curr = curr->next;
    }
}

int main() {
    init();
    add("Hello");
    add("World");
    print();
    search("Hello");
    delete("Hello");
    print();
    return 0;
}