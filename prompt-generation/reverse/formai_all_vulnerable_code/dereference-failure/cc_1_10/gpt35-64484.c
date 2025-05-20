//FormAI DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char name[100];
    int age;
    char profession[100];
};

typedef struct node {
    struct person data;
    struct node* next;
} Node;

Node* head = NULL;

void insert(struct person p) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = p;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && strcmp(current->data.name, p.name) < 0) {
            prev = current;
            current = current->next;
        }

        if(prev == NULL) {
            new_node->next = head;
            head = new_node;
        } else {
            prev->next = new_node;
            new_node->next = current;
        }
    }
}

void search(char* name) {
    Node* current = head;
    while (current != NULL) {
        if(strcmp(current->data.name, name) == 0) {
            printf("Name: %s\tAge: %d\tProfession: %s\n", current->data.name, current->data.age, current->data.profession);
            return;
        }
        current = current->next;
    }
    printf("Person not found.\n");
}

void print() {
    Node* current = head;
    while (current != NULL) {
        printf("Name: %s\tAge: %d\tProfession: %s\n", current->data.name, current->data.age, current->data.profession);
        current = current->next;
    }
}

int main() {
    struct person p1 = {"John", 25, "Engineer"};
    struct person p2 = {"Alice", 30, "Teacher"};
    struct person p3 = {"Bob", 28, "Lawyer"};
    struct person p4 = {"Charlie", 20, "Student"};
    struct person p5 = {"David", 35, "Doctor"};

    insert(p1);
    insert(p2);
    insert(p3);
    insert(p4);
    insert(p5);

    printf("Printing all entries:\n");
    print();

    printf("\nSearching for Bob:\n");
    search("Bob");

    printf("\nSearching for Sarah:\n");
    search("Sarah");

    return 0;
}