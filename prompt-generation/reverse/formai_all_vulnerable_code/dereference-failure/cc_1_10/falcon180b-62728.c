//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1000

struct thread_data {
    int thread_id;
    char line[MAX_LINE_LENGTH];
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    printf("Thread %d is parsing line: %s\n", data->thread_id, data->line);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    int line_count = 0;

    fp = fopen("example.c", "r");
    if (fp == NULL) {
        printf("Error: couldn't open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_count++;
        if (thread_count < MAX_THREADS) {
            struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
            data->thread_id = thread_count;
            strcpy(data->line, line);
            pthread_create(&threads[thread_count], NULL, thread_func, data);
            thread_count++;
        } else {
            printf("Error: too many threads.\n");
            exit(1);
        }
    }

    fclose(fp);

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Parsed %d lines with %d threads.\n", line_count, thread_count);
    return 0;
}