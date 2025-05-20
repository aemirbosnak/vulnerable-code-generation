//FormAI DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char value[100];
} Record;

typedef struct {
    Record** records;
    int size;
} IndexTable;

void addRecordToIndexTable(IndexTable* indexTable, Record* record) {
    int i = indexTable->size;
    while (i > 0 && indexTable->records[i-1]->key > record->key) {
        indexTable->records[i] = indexTable->records[i-1];
        i--;
    }
    indexTable->records[i] = record;
    indexTable->size++;
}

IndexTable* createIndexTable(int size) {
    IndexTable* indexTable = (IndexTable*) malloc(sizeof(IndexTable));
    indexTable->records = (Record**) malloc(sizeof(Record*) * size);
    indexTable->size = 0;
    return indexTable;
}

void printRecords(Record** records, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d - %s\n", records[i]->key, records[i]->value);
    }
}

void queryRecordsInIndexTable(IndexTable* indexTable, int start, int end) {
    if (start < 0 || start >= indexTable->size || end < 0 || end >= indexTable->size) {
        printf("Invalid range\n");
        return;
    }
    Record** records = indexTable->records;
    if (start == end) {
        printf("%d - %s\n", records[start]->key, records[start]->value);
        return;
    }
    int mid = (start + end) / 2;
    printf("%d - %s\n", records[mid]->key, records[mid]->value);
    if (start < mid) {
        queryRecordsInIndexTable(indexTable, start, mid-1);
    }
    if (mid < end) {
        queryRecordsInIndexTable(indexTable, mid+1, end);
    }
}

int main() {
    IndexTable* indexTable = createIndexTable(5);
    addRecordToIndexTable(indexTable, &(Record){4, "Record 4"});
    addRecordToIndexTable(indexTable, &(Record){2, "Record 2"});
    addRecordToIndexTable(indexTable, &(Record){5, "Record 5"});
    addRecordToIndexTable(indexTable, &(Record){1, "Record 1"});
    addRecordToIndexTable(indexTable, &(Record){3, "Record 3"});
    queryRecordsInIndexTable(indexTable, 0, indexTable->size-1);
    free(indexTable->records);
    free(indexTable);
    return 0;
}