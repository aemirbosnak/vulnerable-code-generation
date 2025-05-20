//Falcon-180B DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_LINE_SIZE 1024

typedef struct {
    FILE *file;
    char line[MAX_LINE_SIZE];
} ThreadData;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    char *token;
    int count = 0;

    while (fgets(data->line, MAX_LINE_SIZE, data->file)!= NULL) {
        token = strtok(data->line, " ");
        while (token!= NULL) {
            printf("%s ", token);
            count++;
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    printf("Thread %d processed %d lines\n", count, count);
    return NULL;
}

int main() {
    FILE *file;
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    char filename[20] = "input.txt";

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ThreadData *data = (ThreadData *) malloc(sizeof(ThreadData));
        data->file = file;
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) data);
        if (rc) {
            printf("Error creating thread, %d\n", rc);
            exit(1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return 0;
}