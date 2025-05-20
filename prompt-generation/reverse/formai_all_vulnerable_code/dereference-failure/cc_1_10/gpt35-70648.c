//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 4

char file_name[50];
int thread_count = 0;
pthread_mutex_t lock;

void *write_file(void *args) {
    FILE *fptr;
    char message[100];
    int thread_number = *(int *)args;

    pthread_mutex_lock(&lock);
    printf("Thread %d is writing to file %s\n", thread_number, file_name);
    pthread_mutex_unlock(&lock);

    sprintf(message, "This is thread %d writing to file %s\n", thread_number, file_name);

    fptr = fopen(file_name, "a");
    if (fptr != NULL) {
        fprintf(fptr, "%s", message);
        fclose(fptr);
    }   

    pthread_mutex_lock(&lock);
    printf("Thread %d has completed writing to file %s\n", thread_number, file_name);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];
    int i, err_code;

    if (argc != 2) {
        printf("Invalid number of arguments. Usage: %s <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) > 49) {
        printf("File name must be less than 50 characters.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(file_name, argv[1]);

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_lock(&lock);
    printf("Starting multi-threaded file writing...\n");
    pthread_mutex_unlock(&lock);

    for (i = 0; i < MAX_THREADS; i++) {
        thread_args[i] = i;
        err_code = pthread_create(&threads[i], NULL, write_file, &thread_args[i]);
        if (err_code != 0) {
            printf("Thread creation failed: %d\n", err_code);
            exit(EXIT_FAILURE);
        }
        thread_count++;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_lock(&lock);
    printf("Multi-threaded file writing completed. %d threads have written to file %s.\n", thread_count, file_name);
    pthread_mutex_unlock(&lock);

    pthread_mutex_destroy(&lock);

    return 0;
}