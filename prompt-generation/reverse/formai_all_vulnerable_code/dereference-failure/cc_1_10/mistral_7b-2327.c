//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

Node *head = NULL;

void create(Person p) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = head;
    head = newNode;
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Height: %.2f\n", temp->data.name, temp->data.age, temp->data.height);
        temp = temp->next;
    }
}

void search(char *name) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Name: %s, Age: %d, Height: %.2f\n", temp->data.name, temp->data.age, temp->data.height);
            return;
        }
        temp = temp->next;
    }
    printf("No record found for %s\n", name);
}

int main() {
    Person p1 = {"John Doe", 30, 1.80};
    Person p2 = {"Jane Doe", 25, 1.65};
    create(p1);
    create(p2);

    printf("Database:\n");
    display();

    printf("\nSearch for John Doe:\n");
    search("John Doe");

    printf("\nSearch for Jane Smith:\n");
    search("Jane Smith");

    return 0;
}