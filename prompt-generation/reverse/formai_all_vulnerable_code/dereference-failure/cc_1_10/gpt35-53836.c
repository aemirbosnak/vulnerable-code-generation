//FormAI DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;       // key is an integer value
    char value[50];  // value is a string
} Record;

int hash(int key) {
    // a simple hash function to calculate an index for the given key
    return key % 10;
}

void insert(Record** table, Record record) {
    int index = hash(record.key);
    if (table[index] == NULL) {
        // create a new array of Records of size 10 to store the records
        table[index] = (Record*) malloc(10 * sizeof(Record));
        for (int i = 0; i < 10; i++) {
            // initialize all the Records in the array
            table[index][i].key = -1;  // -1 indicates an empty slot
            strcpy(table[index][i].value, "");
        }
    }
    // find an empty slot to insert the new record
    for (int i = 0; i < 10; i++) {
        if (table[index][i].key == -1) {
            table[index][i] = record;
            return;
        }
    }
}

void display(Record** table) {
    printf("Index   Key   Value\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", i);
        for (int j = 0; j < 10; j++) {
            if (table[i][j].key != -1) {
                printf("%d\t%s\n", table[i][j].key, table[i][j].value);
            }
        }
    }
}

int main() {
    Record** table = (Record**) calloc(10, sizeof(Record*));
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
    Record r1 = {1, "Apple"};
    Record r2 = {11, "Orange"};
    Record r3 = {21, "Banana"};
    insert(table, r1);
    insert(table, r2);
    insert(table, r3);
    display(table);
    return 0;
}