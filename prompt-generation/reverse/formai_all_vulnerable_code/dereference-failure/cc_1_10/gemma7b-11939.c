//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
typedef struct Record {
    char name[20];
    int age;
    struct Record* next;
} Record;

// Define the index structure
typedef struct Index {
    char key[20];
    int rec_no;
    struct Index* next;
} Index;

// Create a new record
Record* create_record(char* name, int age) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->next = NULL;
    return new_record;
}

// Insert a new record into the database
void insert_record(Record** head, char* name, int age) {
    Record* new_record = create_record(name, age);
    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

// Create a new index entry
Index* create_index(char* key, int rec_no) {
    Index* new_index = (Index*)malloc(sizeof(Index));
    strcpy(new_index->key, key);
    new_index->rec_no = rec_no;
    new_index->next = NULL;
    return new_index;
}

// Insert a new index entry into the index structure
void insert_index(Index** head, char* key, int rec_no) {
    Index* new_index = create_index(key, rec_no);
    if (*head == NULL) {
        *head = new_index;
    } else {
        (*head)->next = new_index;
    }
}

// Search for a record by name
Record* search_record(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Main function
int main() {
    // Create a linked list of records
    Record* head = NULL;

    // Insert some records into the database
    insert_record(&head, "John Doe", 25);
    insert_record(&head, "Jane Doe", 30);
    insert_record(&head, "Peter Pan", 12);

    // Create an index structure
    Index* index_head = NULL;

    // Insert index entries into the index structure
    insert_index(&index_head, "John Doe", 0);
    insert_index(&index_head, "Jane Doe", 1);
    insert_index(&index_head, "Peter Pan", 2);

    // Search for a record by name
    Record* record = search_record(head, "John Doe");

    // Print the record information
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}