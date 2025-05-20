//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 1000
#define KEY_LENGTH 20
#define TABLE_NAME_LENGTH 20
#define DATA_SIZE 100

typedef struct {
    char tableName[TABLE_NAME_LENGTH];
    char key[KEY_LENGTH];
    int recordCount;
    int *index;
} Table;

void createTable(Table *table, char *name) {
    strcpy(table->tableName, name);
    table->recordCount = 0;
    table->index = (int *) malloc(DATA_SIZE * sizeof(int));
}

void insertRecord(Table *table, char *record) {
    table->index[table->recordCount] = strlen(record) + 1; // index is length of record + 1
    strcpy((char *) &((char *) table->index)[table->index[table->recordCount]], record);
    table->recordCount++;
}

int *createIndex(Table *table) {
    int i, j, k;
    int *index = (int *) malloc(table->recordCount * sizeof(int));

    for (i = 0; i < table->recordCount; i++) {
        for (j = i + 1; j < table->recordCount; j++) {
            if (strcmp((char *) &((char *) table->index)[table->index[i]], (char *) &((char *) table->index)[table->index[j]]) > 0) {
                k = table->index[i];
                table->index[i] = table->index[j];
                table->index[j] = k;
            }
        }
    }

    for (i = 0; i < table->recordCount; i++) {
        index[i] = table->index[i];
    }

    return index;
}

void printTable(Table *table) {
    int i;
    printf("%s:\n", table->tableName);
    for (i = 0; i < table->recordCount; i++) {
        printf("%s\n", (char *) &((char *) table->index)[table->index[i]]);
    }
}

int main() {
    Table myTable;
    createTable(&myTable, "Fruits");

    insertRecord(&myTable, "Apple");
    insertRecord(&myTable, "Banana");
    insertRecord(&myTable, "Cherry");
    insertRecord(&myTable, "Durian");
    insertRecord(&myTable, "Elderberry");

    printf("Unsorted Table:\n");
    printTable(&myTable);

    int *index = createIndex(&myTable);

    printf("Index:\n");
    for (int i = 0; i < myTable.recordCount; i++) {
        printf("%d ", index[i]);
    }

    printf("\nSorted Table:\n");
    printTable(&myTable);

    return 0;
}