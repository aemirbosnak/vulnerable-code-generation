//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define Thread arguments */
typedef struct {
    int id;
    int nthreads;
    int *data;
    int datasize;
} thread_arg;

/* Define Thread locking mutex */
pthread_mutex_t lock;

/* Thread function to process data in parallel */
void *process_data(void *arg) {
    thread_arg *args = (thread_arg *) arg;
    int id = args->id;
    int nthreads = args->nthreads;
    int *data = args->data;
    int datasize = args->datasize;
    int i;
    int sum = 0;

    /* Process data in chunks */
    for (i=id; i<datasize; i+=nthreads) {
        sum += data[i];
    }

    /* Accumulate results using locking mutex */
    pthread_mutex_lock(&lock);
    *data += sum;
    pthread_mutex_unlock(&lock);

    /* Exit thread */
    pthread_exit(NULL);
}

/* Main program */
int main(int argc, char **argv) {
    int i;
    int datasize = 1000000;
    int *data = malloc(sizeof(int) * datasize);
    int nthreads = atoi(argv[1]);
    pthread_t *threads = malloc(sizeof(pthread_t) * nthreads);
    thread_arg *args = malloc(sizeof(thread_arg) * nthreads);

    /* Initialize data */
    for (i=0; i<datasize; i++) {
        data[i] = i;
    }

    /* Initialize locking mutex */
    pthread_mutex_init(&lock, NULL);

    /* Launch threads */
    for (i=0; i<nthreads; i++) {
        args[i].id = i;
        args[i].nthreads = nthreads;
        args[i].data = data;
        args[i].datasize = datasize;

        pthread_create(&threads[i], NULL, process_data, (void *) &args[i]);
    }

    /* Wait for threads to complete */
    for (i=0; i<nthreads; i++) {
        pthread_join(threads[i], NULL);
    }

    /* Print results */
    printf("Sum: %d\n", *data);

    /* Destroy locking mutex */
    pthread_mutex_destroy(&lock);

    /* Free data and thread resources */
    free(data);
    free(threads);
    free(args);

    /* Exit program */
    return 0;
}