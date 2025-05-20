//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/resource.h>

// Thread function to allocate and free memory
void* thread_func(void* arg) {
    int size = *(int*)arg;
    void* ptr;

    // Allocate memory
    ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc");
        return NULL;
    }

    // Keep the memory allocated for a random amount of time
    sleep(rand() % 10);

    // Free the memory
    free(ptr);

    return NULL;
}

int main(int argc, char* argv[]) {
    int num_threads, thread_size;
    pthread_t* threads;

    // Parse command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num_threads> <thread_size>\n", argv[0]);
        return EXIT_FAILURE;
    }
    num_threads = atoi(argv[1]);
    thread_size = atoi(argv[2]);

    // Create threads
    threads = malloc(sizeof(pthread_t) * num_threads);
    if (threads == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, &thread_size) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    // Print peak RAM usage
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) != 0) {
        perror("getrusage");
        return EXIT_FAILURE;
    }
    printf("Peak RAM usage: %ld bytes\n", usage.ru_maxrss * 1024);

    // Free the thread array
    free(threads);

    return EXIT_SUCCESS;
}