//FormAI DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 30
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int id;
    float score;
} Record;

typedef struct {
    int index;
    char* key;
} Index;

void insertIndex(Index indexes[], int* size, char* key, int index) {
    Index newIndex;
    newIndex.index = index;
    newIndex.key = calloc(MAX_STRING_LENGTH, sizeof(char));
    strcpy(newIndex.key, key);
    indexes[*size] = newIndex;
    (*size)++;
}

int* searchIndex(Index indexes[], int size, char* key) {
    int* results = calloc(size, sizeof(int));
    int counter = 0;
    for(int i = 0; i < size; i++) {
        if(strcmp(indexes[i].key, key) == 0) {
            results[counter] = indexes[i].index;
            counter++;
        }
    }
    if(counter == 0) {
        results = NULL;
    }
    return results;
}

void addRecord(Record records[], int* count, Index nameIndex[], Index idIndex[], Index scoreIndex[]) {
    if(*count < MAX_RECORDS) {
        Record newRecord;
        printf("Enter name: ");
        scanf("%s", newRecord.name);
        printf("Enter id: ");
        scanf("%d", &newRecord.id);
        printf("Enter score: ");
        scanf("%f", &newRecord.score);
        records[*count] = newRecord;
        insertIndex(nameIndex, &nameIndex[0].index, newRecord.name, *count);
        insertIndex(idIndex, &idIndex[0].index, (char*)&newRecord.id, *count);
        insertIndex(scoreIndex, &scoreIndex[0].index, (char*)&newRecord.score, *count);
        *count = *count + 1;
    }
}

void printRecords(Record records[], int* count) {
    if(*count == 0) {
        printf("No records found\n");
    } else {
        printf("Name\tID\tScore\n");
        for(int i = 0; i < *count; i++) {
            printf("%s\t%d\t%.2f\n", records[i].name, records[i].id, records[i].score);
        }
    }
}

void printIndex(Index indexes[], int* size) {
    printf("Index\tKey\n");
    for(int i = 0; i < *size; i++) {
        printf("%d\t%s\n", indexes[i].index, indexes[i].key);
    }
}

int main() {
    Record records[MAX_RECORDS];
    int recordCount = 0;
    Index nameIndex[MAX_RECORDS], idIndex[MAX_RECORDS], scoreIndex[MAX_RECORDS];
    nameIndex[0].index = 0;
    idIndex[0].index = 0;
    scoreIndex[0].index = 0;

    while(1) {
        printf("1. Add Record\n2. Print Records\n3. Print Name Index\n4. Print ID Index\n5. Print Score Index\n6. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(records, &recordCount, nameIndex, idIndex, scoreIndex);
                break;
            case 2:
                printRecords(records, &recordCount);
                break;
            case 3:
                printIndex(nameIndex, &nameIndex[0].index);
                break;
            case 4:
                printIndex(idIndex, &idIndex[0].index);
                break;
            case 5:
                printIndex(scoreIndex, &scoreIndex[0].index);
                break;
            case 6:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}