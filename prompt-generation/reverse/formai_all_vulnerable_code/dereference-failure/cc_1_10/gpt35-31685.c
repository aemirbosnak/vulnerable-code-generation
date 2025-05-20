//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
// A Creative Database Indexing System using Hash Table
// Author: [Your Name]

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20 // Size of Hash Table

// Define Structure for Indexing Records
struct Record {
    char name[20];
    int id;
    char email[40];
    char phone[15];
};

// Define Hash Table
struct Table {
    struct Record* hash[SIZE];
};

// Define Function to Create New Record
struct Record* createRecord(char name[], int id, char email[], char phone[]) {
    struct Record* newRecord = (struct Record*) malloc(sizeof(struct Record));
    strcpy(newRecord->name, name);
    newRecord->id = id;
    strcpy(newRecord->email, email);
    strcpy(newRecord->phone, phone);
    return newRecord;
}

// Define Function to Initialize Hash Table
struct Table* createTable() {
    struct Table* newTable = (struct Table*) malloc(sizeof(struct Table));
    for(int i=0; i<SIZE; i++) {
        newTable->hash[i] = NULL;
    }
    return newTable;
}

// Define Hashing Function
int hashCode(int id) {
    return id % SIZE;
}

// Define Function to Insert New Record into Hash Table
void insertRecord(struct Table* table, char name[], int id, char email[], char phone[]) {
    struct Record* newRecord = createRecord(name, id, email, phone);
    int index = hashCode(id);
    while(table->hash[index] != NULL && table->hash[index]->id != id) {
        index = (index + 1) % SIZE;
    }
    table->hash[index] = newRecord;
}

// Define Function to Search Record by ID
struct Record* searchRecord(struct Table* table, int id) {
    int index = hashCode(id);
    while(table->hash[index] != NULL && table->hash[index]->id != id) {
        index = (index + 1) % SIZE;
    }
    return table->hash[index];
}

// Main Function
int main() {
    struct Table* table = createTable();
    insertRecord(table, "John Doe", 101, "jdoe@example.com", "123-456-7890");
    insertRecord(table, "Jane Doe", 102, "jane@example.com", "987-654-3210");
    insertRecord(table, "Bob Smith", 201, "bsmith@example.com", "555-555-5555");
    insertRecord(table, "Alice Johnson", 301, "ajohnson@example.com", "999-999-9999");
    struct Record* record = searchRecord(table, 201);
    printf("Name: %s\nID: %d\nEmail: %s\nPhone: %s\n", record->name, record->id, record->email, record->phone);
    return 0;
}