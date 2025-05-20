//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define DB_SIZE 10

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

Record database[DB_SIZE];
pthread_mutex_t mutex;

void* delete_record(void* arg) {
    int id = *((int*) arg);
    int index = -1;
    for (int i = 0; i < DB_SIZE; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record with ID %d is not found!\n", id);
    } else {
        pthread_mutex_lock(&mutex);
        for (int i = index+1; i < DB_SIZE; i++) {
            database[i-1] = database[i];
        }
        memset(&database[DB_SIZE-1], 0, sizeof(Record));
        printf("Record with ID %d deleted successfully.\n", id);
        pthread_mutex_unlock(&mutex);
    }
    free(arg);
    return NULL;
}

void* add_record(void* arg) {
    Record* record = (Record*) arg;
    pthread_mutex_lock(&mutex);
    int index = -1;
    for (int i = 0; i < DB_SIZE; i++) {
        if (database[i].id == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Database is full!\n");
    } else {
        database[index] = *record;
        printf("Record with ID %d added successfully.\n", record->id);
    }
    pthread_mutex_unlock(&mutex);
    free(record);
    return NULL;
}

void* update_record(void* arg) {
    Record* record = (Record*) arg;
    int index = -1;
    for (int i = 0; i < DB_SIZE; i++) {
        if (database[i].id == record->id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record with ID %d not found!\n", record->id);
    } else {
        pthread_mutex_lock(&mutex);
        database[index] = *record;
        printf("Record with ID %d updated successfully.\n", record->id);
        pthread_mutex_unlock(&mutex);
    }
    free(record);
    return NULL;
}

void* search_record(void* arg) {
    int id = *((int*) arg);
    int index = -1;
    for (int i = 0; i < DB_SIZE; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record with ID %d not found!\n", id);
    } else {
        printf("Record found:\n ID: %d\n Name: %s\n Age: %d\n", database[index].id, database[index].name, database[index].age);
    }
    free(arg);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    memset(database, 0, sizeof(database));
    pthread_t threads[4];
    int ret;
    // adding a record
    Record* record1 = (Record*) malloc(sizeof(Record));
    record1->id = 1;
    strcpy(record1->name, "John");
    record1->age = 25;
    ret = pthread_create(&threads[0], NULL, add_record, (void*) record1);

    // updating a record
    Record* record2 = (Record*) malloc(sizeof(Record));
    record2->id = 1;
    strcpy(record2->name, "John Smith");
    record2->age = 27;
    ret = pthread_create(&threads[1], NULL, update_record, (void*) record2);

    // searching for a record
    int* id = (int*) malloc(sizeof(int));
    *id = 1;
    ret = pthread_create(&threads[2], NULL, search_record, (void*) id);

    // deleting a record
    int* id2 = (int*) malloc(sizeof(int));
    *id2 = 1;
    ret = pthread_create(&threads[3], NULL, delete_record, (void*) id2);

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}