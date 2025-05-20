//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ALLOCS 10000

/* Define struct to hold memory allocation details */
typedef struct {
    void *ptr;
    size_t size;
} allocation_t;

/* Global variables */
allocation_t allocation_list[MAX_ALLOCS];
pthread_mutex_t mutex_lock;
size_t allocation_count = 0;

/* Thread function for allocating memory */
void *allocate_memory(void *args) {
    size_t size = *(size_t*)args;
    void *ptr = malloc(size);
    
    pthread_mutex_lock(&mutex_lock);
    
    if (allocation_count < MAX_ALLOCS) {
        allocation_t allocation = {ptr, size};
        allocation_list[allocation_count] = allocation;
        allocation_count++;
    }
    
    pthread_mutex_unlock(&mutex_lock);
    
    pthread_exit(NULL);
}

/* Thread function for freeing memory */
void *free_memory(void *args) {
    size_t index = *(size_t*)args;
    
    pthread_mutex_lock(&mutex_lock);
    
    if (index < allocation_count) {
        free(allocation_list[index].ptr);
        
        allocation_count--;
        allocation_list[index] = allocation_list[allocation_count];
    }
    
    pthread_mutex_unlock(&mutex_lock);
    
    pthread_exit(NULL);
}

/* Entry point of the program */
int main() {
    pthread_t threads[2];
    size_t allocation_size = 100;
    size_t free_index = 1;
    
    /* Initialize mutex lock */
    if (pthread_mutex_init(&mutex_lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    
    /* Create thread for allocating memory */
    if (pthread_create(&threads[0], NULL, allocate_memory, &allocation_size) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }
    
    /* Create thread for freeing memory */
    if (pthread_create(&threads[1], NULL, free_memory, &free_index) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }
    
    /* Wait for threads to finish */
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    
    /* Destroy mutex lock */
    pthread_mutex_destroy(&mutex_lock);
    
    return 0;
}