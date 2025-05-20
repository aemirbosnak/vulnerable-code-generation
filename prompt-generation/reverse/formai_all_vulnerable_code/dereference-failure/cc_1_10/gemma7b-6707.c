//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_RECORDS 1024

typedef struct Record {
    char name[256];
    int age;
    struct Record* next;
} Record;

Record* head = NULL;

pthread_mutex_t mutex;

void insertRecord(char* name, int age) {
    pthread_mutex_lock(&mutex);

    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        Record* currentRecord = head;
        while (currentRecord->next) {
            currentRecord = currentRecord->next;
        }
        currentRecord->next = newRecord;
    }

    pthread_mutex_unlock(&mutex);
}

int main() {
    insertRecord("John Doe", 25);
    insertRecord("Jane Doe", 30);
    insertRecord("Peter Pan", 12);

    Record* currentRecord = head;
    while (currentRecord) {
        printf("%s is %d years old\n", currentRecord->name, currentRecord->age);
        currentRecord = currentRecord->next;
    }

    return 0;
}