//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
typedef struct Record
{
    char name[50];
    int age;
    struct Record* next;
} Record;

// Create a linked list of records
Record* head = NULL;

// Function to insert a record into the linked list
void insertRecord(char* name, int age)
{
    // Allocate memory for a new record
    Record* newRecord = (Record*)malloc(sizeof(Record));

    // Copy the name and age of the new record
    strcpy(newRecord->name, name);
    newRecord->age = age;

    // If the linked list is empty, make the new record the head
    if (head == NULL)
    {
        head = newRecord;
    }
    // Otherwise, insert the new record at the end
    else
    {
        head->next = newRecord;
        head = newRecord;
    }
}

// Function to search for a record in the linked list
Record* searchRecord(char* name)
{
    // Iterate over the linked list
    for (Record* currentRecord = head; currentRecord != NULL; currentRecord = currentRecord->next)
    {
        // If the name of the record is equal to the search name, return the record
        if (strcmp(currentRecord->name, name) == 0)
        {
            return currentRecord;
        }
    }

    // If the record is not found, return NULL
    return NULL;
}

// Main function
int main()
{
    // Insert some records into the linked list
    insertRecord("John Doe", 25);
    insertRecord("Jane Doe", 30);
    insertRecord("Peter Pan", 12);

    // Search for a record in the linked list
    Record* record = searchRecord("Jane Doe");

    // If the record is found, print its name and age
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
    }
    else
    {
        printf("Record not found.\n");
    }

    return 0;
}