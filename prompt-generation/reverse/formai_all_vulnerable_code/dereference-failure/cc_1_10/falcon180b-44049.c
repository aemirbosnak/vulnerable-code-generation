//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 100

// Structure to hold thread information
struct thread_info {
    int id;
    void *(*func)(void *);
    void *arg;
    struct thread_info *next;
};

// Function prototypes
void *thread_func(void *arg);
void add_thread(int id, void *(*func)(void *), void *arg);
void run_threads();

// Global variables
struct thread_info *thread_list = NULL;
pthread_t threads[MAX_THREADS];
int num_threads = 0;

int main() {
    int i;

    // Add some example threads
    add_thread(1, thread_func, "Thread 1");
    add_thread(2, thread_func, "Thread 2");
    add_thread(3, thread_func, "Thread 3");

    // Run all threads
    run_threads();

    // Clean up
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Thread function
void *thread_func(void *arg) {
    printf("Thread %s starting...\n", (char *) arg);
    sleep(1);
    printf("Thread %s finished.\n", (char *) arg);
    return NULL;
}

// Add a new thread to the list
void add_thread(int id, void *(*func)(void *), void *arg) {
    struct thread_info *new_thread = malloc(sizeof(struct thread_info));
    new_thread->id = id;
    new_thread->func = func;
    new_thread->arg = arg;
    new_thread->next = NULL;

    if (thread_list == NULL) {
        thread_list = new_thread;
    } else {
        struct thread_info *curr_thread = thread_list;
        while (curr_thread->next!= NULL) {
            curr_thread = curr_thread->next;
        }
        curr_thread->next = new_thread;
    }

    num_threads++;
}

// Run all threads in the list
void run_threads() {
    int i;
    struct thread_info *curr_thread = thread_list;

    while (curr_thread!= NULL) {
        pthread_create(&threads[num_threads - 1], NULL, curr_thread->func, curr_thread->arg);
        curr_thread = curr_thread->next;
        num_threads++;
    }
}