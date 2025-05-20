//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// Declare Mutexes
pthread_mutex_t readMutex;
pthread_mutex_t writeMutex;

// Declare Condtion Variables
pthread_cond_t readersCondtioned;
pthread_cond_t writersCondtioned;

int readers = 0;
bool writing = false;
int data = 0;

// Reader Thread
void* reader(void* arg) {
    int id = *((int*) arg);
    while(true) {
        pthread_mutex_lock(&readMutex);
        while(writing) {
            pthread_cond_wait(&readersCondtioned, &readMutex);
        }
        readers++;
        pthread_mutex_unlock(&readMutex);
        
        // Read the Data
        printf("Reader %d read the data as %d.\n", id, data);
        
        pthread_mutex_lock(&readMutex);
        
        readers--;
        if(readers == 0) {
            pthread_cond_signal(&writersCondtioned);
        }
        
        pthread_mutex_unlock(&readMutex);
        sleep(1);
    }
}

// Writer Thread
void* writer(void* arg) {
    int id = *((int*) arg);
    while(true) {
        pthread_mutex_lock(&writeMutex);
        while(readers > 0 || writing) {
            pthread_cond_wait(&writersCondtioned, &writeMutex);
        }
        writing = true;
        pthread_mutex_unlock(&writeMutex);
        
        // Write the Data
        data++;
        printf("Writer %d wrote the data as %d.\n", id, data);
        
        pthread_mutex_lock(&writeMutex);
        
        writing = false;
        pthread_cond_signal(&readersCondtioned);
        pthread_cond_signal(&writersCondtioned);
        
        pthread_mutex_unlock(&writeMutex);
        sleep(1);
    }
}

int main() {
    int numReaders = 3;
    int numWriters = 2;
    
    pthread_t readerThreads[numReaders];
    pthread_t writerThreads[numWriters];
    
    // Initialize Mutexes and Condtion Variables
    pthread_mutex_init(&readMutex, NULL);
    pthread_mutex_init(&writeMutex, NULL);
    pthread_cond_init(&readersCondtioned, NULL);
    pthread_cond_init(&writersCondtioned, NULL);
    
    // Create Reader Threads
    for(int i = 0; i < numReaders; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&readerThreads[i], NULL, reader, (void*) id);
    }
    
    // Create Writer Threads
    for(int i = 0; i < numWriters; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&writerThreads[i], NULL, writer, (void*) id);
    }
    
    // Wait for Threads to Complete
    for(int i = 0; i < numReaders; i++) {
        pthread_join(readerThreads[i], NULL);
    }
    for(int i = 0; i < numWriters; i++) {
        pthread_join(writerThreads[i], NULL);
    }
    
    // Destroy Mutexes and Condtion Variables
    pthread_mutex_destroy(&readMutex);
    pthread_mutex_destroy(&writeMutex);
    pthread_cond_destroy(&readersCondtioned);
    pthread_cond_destroy(&writersCondtioned);
    
    return 0;
}