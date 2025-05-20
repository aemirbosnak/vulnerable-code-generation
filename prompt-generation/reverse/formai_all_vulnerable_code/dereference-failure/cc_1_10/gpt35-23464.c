//FormAI DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for Index Record
typedef struct Index_Record {
    int key;
    int offset;
} Index_Record;

// define struct for Index Table
typedef struct Index_Table {
    int size;
    Index_Record* records;
} Index_Table;

// function to create a new Index Table
Index_Table* createIndexTable(int size) {
    Index_Table* table = (Index_Table*)malloc(sizeof(Index_Table));
    table->size = size;
    table->records = (Index_Record*)calloc(size, sizeof(Index_Record));
    return table;
}

// function to insert new record into Index Table
void insertRecord(Index_Table* table, int index, int key, int offset) {
    table->records[index].key = key;
    table->records[index].offset = offset;
}

// function to perform linear search on Index Table
int linearSearch(Index_Table* table, int key) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (table->records[i].key == key) {
            return i;
        }
    }
    return -1;
}

// function to perform binary search on Index Table
int binarySearch(Index_Table* table, int key, int min, int max) {
    if (max < min) {
        return -1;
    } else {
        int mid = (max + min) / 2;
        if (table->records[mid].key > key) {
            return binarySearch(table, key, min, mid-1);
        } else if (table->records[mid].key < key) {
            return binarySearch(table, key, mid+1, max);
        } else {
            return mid;
        }
    }
}

// main function
int main() {
    // create Index Table
    Index_Table* table = createIndexTable(5);

    // insert sample records
    insertRecord(table, 0, 10, 100);
    insertRecord(table, 1, 20, 200);
    insertRecord(table, 2, 30, 300);
    insertRecord(table, 3, 40, 400);
    insertRecord(table, 4, 50, 500);

    // perform linear search
    int linearIndex = linearSearch(table, 30);

    // perform binary search
    int binaryIndex = binarySearch(table, 30, 0, 4);

    // print search results
    printf("Linear search index: %d\n", linearIndex);
    printf("Binary search index: %d\n", binaryIndex);

    return 0;
}