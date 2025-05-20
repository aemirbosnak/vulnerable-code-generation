//FormAI DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Person;

typedef struct Node {
    Person data;
    struct Node* next;
} Node;

Node* head = NULL;
int size = 0;

void insert(Person person) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = person;
    node->next = head;
    head = node;
    size++;
}

void delete(int id) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->data.id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Person with id %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    size--;
}

void print() {
    Node* current = head;

    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", current->data.id, current->data.name, current->data.age);
        current = current->next;
    }
}

int main() {
    Person person1 = {1, "John", 25};
    Person person2 = {2, "Alice", 32};
    Person person3 = {3, "Bob", 18};

    insert(person1);
    insert(person2);
    insert(person3);

    printf("Database contents:\n");
    print();

    delete(2);

    printf("\nDatabase contents after deleting record with ID 2:\n");
    print();

    return 0;
}