//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
// C Program to Implement a Database Indexing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a database item
typedef struct DatabaseItem {
    int id;
    char name[50];
    char address[50];
    double salary;
} DatabaseItem;

// Structure to hold information about an index entry
typedef struct IndexEntry {
    int id;
    long offset;
    struct IndexEntry *next;
} IndexEntry;

// Structure to hold information about an index
typedef struct Index {
    IndexEntry *head;
    IndexEntry *tail;
} Index;

// Function to create a new index
Index *createIndex() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->head = NULL;
    index->tail = NULL;
    return index;
}

// Function to create a new index entry
IndexEntry *createIndexEntry(int id, long offset) {
    IndexEntry *entry = (IndexEntry *)malloc(sizeof(IndexEntry));
    entry->id = id;
    entry->offset = offset;
    entry->next = NULL;
    return entry;
}

// Function to insert an index entry into an index
void insertIndexEntry(Index *index, int id, long offset) {
    IndexEntry *entry = createIndexEntry(id, offset);
    if(index->head == NULL) {
        index->head = entry;
        index->tail = entry;
    }
    else {
        index->tail->next = entry;
        index->tail = entry;
    }
}

// Function to write a database item to a binary file
void writeItemToFile(FILE *fp, DatabaseItem *item) {
    fwrite(&item->id, sizeof(int), 1, fp);
    fwrite(item->name, sizeof(char), 50, fp);
    fwrite(item->address, sizeof(char), 50, fp);
    fwrite(&item->salary, sizeof(double), 1, fp);
}

// Function to read a database item from a binary file
DatabaseItem *readItemFromFile(FILE *fp) {
    DatabaseItem *item = (DatabaseItem *)malloc(sizeof(DatabaseItem));
    fread(&item->id, sizeof(int), 1, fp);
    fread(item->name, sizeof(char), 50, fp);
    fread(item->address, sizeof(char), 50, fp);
    fread(&item->salary, sizeof(double), 1, fp);
    return item;
}

// Function to print a database item
void printItem(DatabaseItem *item) {
    printf("ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Address: %s\n", item->address);
    printf("Salary: %.2f\n", item->salary);
    printf("-----------------------------\n");
}

int main() {
    // Create an index
    Index *index = createIndex();

    // Open a binary file for writing
    FILE *fp = fopen("database.dat", "wb");

    // Generate some database items and write them to the file
    DatabaseItem item1 = {1, "John Smith", "123 Main St", 50000.00};
    DatabaseItem item2 = {2, "Jane Doe", "456 Oak St", 60000.00};
    DatabaseItem item3 = {3, "Bob Johnson", "789 Pine St", 70000.00};
    writeItemToFile(fp, &item1);
    writeItemToFile(fp, &item2);
    writeItemToFile(fp, &item3);

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen("database.dat", "rb");

    // Read the items from the file and insert them into the index
    long offset = 0;
    DatabaseItem *item;
    while((item = readItemFromFile(fp)) != NULL) {
        insertIndexEntry(index, item->id, offset);
        offset = ftell(fp);
    }

    // Close the file
    fclose(fp);

    // Print out the items in the index
    IndexEntry *entry = index->head;
    while(entry != NULL) {
        // Open the file for reading
        fp = fopen("database.dat", "rb");
        fseek(fp, entry->offset, SEEK_SET);

        // Read the item from the file and print it
        item = readItemFromFile(fp);
        printItem(item);

        // Close the file
        fclose(fp);

        // Move to the next index entry
        entry = entry->next;
    }

    return 0;
}