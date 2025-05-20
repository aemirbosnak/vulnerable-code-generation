//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ELEMENTS 100

struct Data {
    int index;
    char data[20];
};

struct Index {
    char key[10];
    struct Data *data[MAX_ELEMENTS];
    int count;
};

struct Index indices[MAX_ELEMENTS];
int indexCount = 0;
int dataCount = 0;

pthread_mutex_t index_mutex = PTHREAD_MUTEX_INITIALIZER;

void printData(struct Data *data) {
    printf("%d: %s\n", data->index, data->data);
}

void printIndex(struct Index *index) {
    printf("Index Key: %s, Data Count: %d\n", index->key, index->count);
    for(int i=0; i<index->count; i++) {
        struct Data *data = index->data[i];
        printData(data);
    }
}

void insertData(char *key, char *data) {
    struct Index *index = NULL;
    struct Data *newData = (struct Data*) malloc(sizeof(struct Data));
    newData->index = ++dataCount;
    strncpy(newData->data, data, 20);
    newData->data[19] = '\0';

    pthread_mutex_lock(&index_mutex);
    for(int i=0; i<indexCount; i++) {
        if(!strcmp(indices[i].key, key)) {
            index = &indices[i];
            break;
        }
    }
    if(index == NULL) {
        index = &indices[indexCount++];
        strncpy(index->key, key, 10);
        index->count = 0;
    }
    index->data[index->count++] = newData;
    pthread_mutex_unlock(&index_mutex);
}

void *consumer(void *arg) {
    char *key = (char*) arg;
    struct Index *index = NULL;

    pthread_mutex_lock(&index_mutex);
    for(int i=0; i<indexCount; i++) {
        if(!strcmp(indices[i].key, key)) {
            index = &indices[i];
            break;
        }
    }
    if(index == NULL) {
        printf("Consumer for key '%s' failed to find index!\n", key);
    } else {
        printf("Consumer for key '%s' found the following data:\n", key);
        printIndex(index);
    }
    pthread_mutex_unlock(&index_mutex);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char keys[MAX_THREADS][10] = {"key1", "key2", "key3", "key4", "key5", "key6", "key7", "key8", "key9", "key10"};
    char data[MAX_ELEMENTS][20] = {"data1", "data2", "data3", "data4", "data5", "data6", "data7", "data8", "data9", "data10",
                               "data11", "data12", "data13", "data14", "data15", "data16", "data17", "data18", "data19", "data20",
                               "data21", "data22", "data23", "data24", "data25", "data26", "data27", "data28", "data29", "data30",
                               "data31", "data32", "data33", "data34", "data35", "data36", "data37", "data38", "data39", "data40",
                               "data41", "data42", "data43", "data44", "data45", "data46", "data47", "data48", "data49", "data50"};

    for(int i=0; i<MAX_THREADS; i++) {
        insertData(keys[i], data[i]);
    }

    for(int i=0; i<MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, consumer, (void*) keys[i]);
    }

    for(int i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}