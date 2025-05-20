//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define MAX_FILES 10
#define MAX_THREADS 3

typedef struct {
    char name[50];
    int size;
    int id;
} File;

File files[MAX_FILES];

int numFiles = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* createFile(void* args) {
    int fileId = *(int*)args;
    File* file = &files[fileId];
    
    printf("Creating file %s of size %d\n", file->name, file->size);
    pthread_mutex_lock(&mutex);
    numFiles++;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* deleteFile(void* args) {
    int fileId = *(int*)args;
    File* file = &files[fileId];

    printf("Deleting file %s of size %d\n", file->name, file->size);
    pthread_mutex_lock(&mutex);
    numFiles--;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* readFile(void* args) {
    int fileId = *(int*)args;
    File* file = &files[fileId];
    
    printf("Reading file %s of size %d\n", file->name, file->size);
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* writeFile(void* args) {
    int fileId = *(int*)args;
    File* file = &files[fileId];

    printf("Writing to file %s of size %d\n", file->name, file->size);
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int numThreads = 0;

    for (int i = 0; i < MAX_FILES; i++) {
        files[i].name[0] = 'f';
        files[i].size = i;
        files[i].id = i;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        int fileId = rand() % MAX_FILES;
        pthread_create(&threads[numThreads++], NULL, createFile, &fileId);
        pthread_create(&threads[numThreads++], NULL, deleteFile, &fileId);
        pthread_create(&threads[numThreads++], NULL, readFile, &fileId);
        pthread_create(&threads[numThreads++], NULL, writeFile, &fileId);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Number of files: %d\n", numFiles);

    return 0;
}