//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct person {
    int id;
    char name[MAX_SIZE];
    int age;
} Person;

typedef struct node {
    Person data;
    struct node* next;
} Node;

Node* head = NULL;

void insert(Person p) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = p;
    new_node->next = head;
    head = new_node;
}

void display() {
    printf("ID\tName\tAge\n");
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d\t%s\t%d\n", current_node->data.id, current_node->data.name, current_node->data.age);
        current_node = current_node->next;
    }
}

int main() {
    // add some persons
    Person p1, p2, p3;
    p1.id = 1;
    strcpy(p1.name, "John");
    p1.age = 23;
    p2.id = 2;
    strcpy(p2.name, "Alice");
    p2.age = 27;
    p3.id = 3;
    strcpy(p3.name, "Bob");
    p3.age = 31;

    // insert persons and display list
    insert(p1);
    insert(p2);
    insert(p3);
    display();

    // cleanup
    Node* current_node = head;
    while (current_node != NULL) {
        Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    head = NULL;

    return 0;
}