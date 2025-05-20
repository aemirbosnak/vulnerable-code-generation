//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a simple database structure
typedef struct Record {
    char name[20];
    int age;
    double salary;
} Record;

// Create a linked list of records
typedef struct Node {
    Record data;
    struct Node* next;
} Node;

// Insert a record into the linked list
void insert(Node** head, Record record) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = record;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Search for a record in the linked list
Record* search(Node* head, char* name) {
    while (head) {
        if (strcmp(head->data.name, name) == 0) {
            return &head->data;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    // Create a linked list of records
    Node* head = NULL;

    // Insert some records
    insert(&head, (Record){.name = "John Doe", .age = 25, .salary = 50000});
    insert(&head, (Record){.name = "Jane Doe", .age = 20, .salary = 60000});
    insert(&head, (Record){.name = "Peter Pan", .age = 12, .salary = 70000});

    // Search for a record
    Record* record = search(head, "John Doe");

    // Print the record
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
        printf("Salary: %f\n", record->salary);
    } else {
        printf("Record not found\n");
    }

    return 0;
}