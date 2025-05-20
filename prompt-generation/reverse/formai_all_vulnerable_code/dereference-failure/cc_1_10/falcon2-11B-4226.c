//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define MAX_THREADS 4

pthread_mutex_t mutex;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int is_done = 0;

void *read_csv(void *arg) {
    int tid = *((int*)arg);
    int data_size = 0;
    char *data = NULL;

    pthread_mutex_lock(&mutex);

    printf("Thread %d started\n", tid);

    while (is_done == 0) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);

        // Read the CSV file
        FILE *fp = fopen("example.csv", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            exit(1);
        }

        // Get the size of the data
        fseek(fp, 0, SEEK_END);
        data_size = ftell(fp);
        rewind(fp);

        data = malloc(data_size);
        fread(data, data_size, 1, fp);
        fclose(fp);

        // Process the data
        char *token;
        char *delimiter = ",";
        char *line = strtok(data, delimiter);
        int count = 0;
        while (line!= NULL) {
            token = strtok(NULL, delimiter);
            printf("Thread %d: %s\n", tid, token);
            count++;
            line = strtok(NULL, delimiter);
        }

        pthread_mutex_lock(&mutex);
        is_done = 1;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);

        free(data);
    }

    pthread_mutex_unlock(&mutex);

    printf("Thread %d finished\n", tid);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_THREADS; i++) {
        int tid = i;
        pthread_create(&threads[i], NULL, read_csv, &tid);
    }

    pthread_mutex_lock(&mutex);
    is_done = 1;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}