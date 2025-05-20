//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

Node *head = NULL;

void addPerson(Person p) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = head;
    head = newNode;
}

void displayDatabase() {
    Node *temp = head;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Height: %.2f\n", temp->data.name, temp->data.age, temp->data.height);
        temp = temp->next;
    }
}

int main() {
    Person p1 = {"John Doe", 30, 1.85};
    Person p2 = {"Jane Doe", 25, 1.68};

    addPerson(p1);
    addPerson(p2);

    printf("Database before sorting:\n");
    displayDatabase();

    // Implement your sorting algorithm here

    printf("\nDatabase after sorting:\n");
    displayDatabase();

    return 0;
}