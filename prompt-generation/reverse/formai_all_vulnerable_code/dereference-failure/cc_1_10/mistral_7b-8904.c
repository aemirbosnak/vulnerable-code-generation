//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[50];
    int age;
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;
Node* temp = NULL;
Node* newNode = NULL;

void insert(char* name, int age) {
    if (head == NULL) {
        newNode = (Node*) malloc(sizeof(Node));
        strcpy(newNode->name, name);
        newNode->age = age;
        newNode->next = NULL;
        head = newNode;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        newNode = (Node*) malloc(sizeof(Node));
        strcpy(newNode->name, name);
        newNode->age = age;
        newNode->next = NULL;
        current->next = newNode;
    }
}

void delete(char* name) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (strcmp(head->name, name) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found!\n");
        return;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

bool search(char* name) {
    current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void display() {
    current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d\n", current->name, current->age);
        current = current->next;
    }
}

int main() {
    char name[50];
    int age;
    char searchName[50];

    insert("John Doe", 25);
    insert("Jane Smith", 30);
    insert("Mike Johnson", 35);

    display();

    printf("Enter name to search: ");
    scanf("%s", searchName);

    if (search(searchName)) {
        printf("%s found!\n", searchName);
    } else {
        printf("%s not found!\n", searchName);
    }

    delete("John Doe");

    display();

    return 0;
}