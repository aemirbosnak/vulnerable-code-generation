//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char name[50];
    int age;
    float salary;
} Record;

typedef struct Node {
    Record data;
    struct Node* next;
} Node;

Node* head = NULL;

void createRecord(char* name, int age, float salary) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    newNode->data.age = age;
    newNode->data.salary = salary;
    newNode->next = head;
    head = newNode;
}

void displayDatabase() {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("\nName: %s\nAge: %d\nSalary: %.2f", currentNode->data.name, currentNode->data.age, currentNode->data.salary);
        currentNode = currentNode->next;
    }
}

int main() {
    createRecord("John Doe", 25, 3000.5);
    createRecord("Jane Smith", 30, 4000.75);
    createRecord("Mike Johnson", 45, 5000.0);

    printf("\nDatabase before delete:\n");
    displayDatabase();

    Node* nodeToDelete = head;
    if (strcmp(nodeToDelete->data.name, "Jane Smith") == 0) {
        head = head->next;
        free(nodeToDelete);
    }

    printf("\nDatabase after delete:\n");
    displayDatabase();

    return 0;
}