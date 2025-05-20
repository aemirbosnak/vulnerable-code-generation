//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: genious
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 10

/* struct to hold thread information */
typedef struct {
    pthread_t thread_id;     /* ID of the thread */
    int thread_num;          /* number of the thread */
    char *message;           /* message to print */
} thread_info_t;

/* function to be executed by each thread */
void *thread_function(void *arg) {
    thread_info_t *thread_info = (thread_info_t *) arg;

    printf("Thread #%d: %s\n", thread_info->thread_num, thread_info->message);

    pthread_exit(NULL);
}

/* main function */
int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    thread_info_t thread_info[MAX_THREADS];
    int rc, i;

    for (i = 0; i < MAX_THREADS; i++) {
        /* allocate memory for thread_info */
        thread_info[i].message = (char *) malloc(20 * sizeof(char));
        if (thread_info[i].message == NULL) {
            fprintf(stderr, "Error: unable to allocate memory\n");
            exit(EXIT_FAILURE);
        }

        /* set the parameters of thread_info */
        thread_info[i].thread_num = i;
        sprintf(thread_info[i].message, "Hello from thread #%d", i);

        /* create the thread */
        rc = pthread_create(&threads[i], NULL, thread_function, (void *) &thread_info[i]);
        if (rc) {
            fprintf(stderr, "Error: unable to create thread, rc=%d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    /* wait for all threads to finish */
    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error: unable to join thread, rc=%d\n", rc);
            exit(EXIT_FAILURE);
        }

        /* free memory allocated for thread_info */
        free(thread_info[i].message);
    }

    return EXIT_SUCCESS;
}