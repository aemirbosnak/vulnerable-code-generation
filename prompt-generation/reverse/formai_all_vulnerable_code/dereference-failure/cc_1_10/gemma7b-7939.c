//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct Database {
    char name[255];
    int age;
    char occupation[255];
    struct Database* next;
} Database;

// Function to insert a new record into the database
void insertRecord(Database* head, char* name, int age, char* occupation) {
    Database* newRecord = (Database*)malloc(sizeof(Database));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    strcpy(newRecord->occupation, occupation);
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }
}

// Function to search for a record in the database
Database* searchRecord(Database* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    Database* head = NULL;
    insertRecord(head, "John Doe", 25, "Software Engineer");
    insertRecord(head, "Jane Doe", 22, "Teacher");
    insertRecord(head, "Peter Pan", 12, "Boy Who Never Grew Up");

    Database* foundRecord = searchRecord(head, "Jane Doe");

    if (foundRecord) {
        printf("Name: %s\n", foundRecord->name);
        printf("Age: %d\n", foundRecord->age);
        printf("Occupation: %s\n", foundRecord->occupation);
    } else {
        printf("Record not found\n");
    }

    return 0;
}