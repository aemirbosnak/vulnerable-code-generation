//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 5
#define BUFFER_SIZE 10

pthread_mutex_t mutex;
pthread_cond_t cond_var;
char *buffer[BUFFER_SIZE];
int count = 0;

void *detective(void *arg) {
    int thread_id = *((int *)arg);
    char *suspects[] = {
        "Dr. Watson",
        "Mrs. Hudson",
        "Inspector Lestrade",
        "Professor Moriarty",
        "Miss Adler"
    };

    while (1) {
        usleep(rand() % 1000000); // Simulate thinking time
        pthread_mutex_lock(&mutex);
        
        // Adding a suspect to the buffer
        if (count < BUFFER_SIZE) {
            buffer[count] = suspects[thread_id];
            printf("Thread #%d has found a suspect: %s\n", thread_id, suspects[thread_id]);
            count++;
            pthread_cond_signal(&cond_var); // Signal that there's new evidence
        }

        pthread_mutex_unlock(&mutex);
    }
}

void *inspector(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        // Wait until there's something in the buffer
        while (count == 0) {
            pthread_cond_wait(&cond_var, &mutex);
        }

        // Retrieving evidence
        count--;
        char *evidence = buffer[count];
        printf("Inspector Leslie is examining the evidence: %s\n", evidence);

        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulating time taken to examine evidence
    }
}

int main() {
    pthread_t detective_threads[NUM_THREADS], inspector_thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);
    
    // Start detective threads
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&detective_threads[i], NULL, detective, (void *)&thread_ids[i]);
    }

    // Start inspector thread
    pthread_create(&inspector_thread, NULL, inspector, NULL);

    // Let the threads run for a while
    sleep(5); // Let the detectives work for 5 seconds

    // Cleanup
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cancel(detective_threads[i]);
    }
    pthread_cancel(inspector_thread);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);
    
    printf("Ending the investigation.\n");
    return 0;
}