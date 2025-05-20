//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
// Welcome to the Thunderdome, where threads collide!

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Behold, the almighty thread master!
typedef struct thread_master {
    int num_threads;
    pthread_t *threads;
    void *(*thread_func)(void *);
    void *thread_args;
} thread_master_t;

// Some crazy thread logic, executed by every thread
void *thread_logic(void *args) {
    char *s = (char *)args;
    printf("I'm a thread, and I'm here to say: %s\n", s);
    return NULL;
}

// The grand orchestrator, summoning and managing threads
void create_and_join_threads(thread_master_t *master) {
    // Allocate memory for the threads
    master->threads = malloc(sizeof(pthread_t) * master->num_threads);

    // Spawn the threads
    for (int i = 0; i < master->num_threads; i++) {
        if (pthread_create(&master->threads[i], NULL, master->thread_func, master->thread_args) != 0) {
            printf("Thread creation failed!\n");
            exit(1);
        }
    }

    // Wait for the threads to finish their shenanigans
    for (int i = 0; i < master->num_threads; i++) {
        pthread_join(master->threads[i], NULL);
    }

    // Cleanup
    free(master->threads);
}

// Prepare the thread master for its glorious destiny
void initialize_thread_master(thread_master_t *master, int num_threads, void *(*thread_func)(void *), void *thread_args) {
    master->num_threads = num_threads;
    master->thread_func = thread_func;
    master->thread_args = thread_args;
}

int main() {
    // Set the stage for a chaotic symphony
    int num_threads = 5;
    char *thread_args = "Holy smokes, it's a thread party!";

    // Initialize the thread master, the puppeteer of threads
    thread_master_t thread_master;
    initialize_thread_master(&thread_master, num_threads, thread_logic, thread_args);

    // Unleash the thread army!
    create_and_join_threads(&thread_master);

    // The show is over, the threads have left the stage.
    printf("Thread orchestra has concluded its performance!\n");
    return 0;
}