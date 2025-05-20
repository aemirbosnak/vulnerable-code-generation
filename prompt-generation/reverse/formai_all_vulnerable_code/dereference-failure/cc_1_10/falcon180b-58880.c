//Falcon-180B DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 80

struct thread_data {
    char *filename;
    FILE *file;
    int thread_id;
};

void *thread_func(void *data) {
    struct thread_data *thread_data = (struct thread_data *)data;
    FILE *file = thread_data->file;
    int thread_id = thread_data->thread_id;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        printf("Thread %d: %s", thread_id, line);
    }

    fclose(file);
    pthread_exit(0);
}

void read_file(char *filename, int num_threads) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    struct thread_data thread_data[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].filename = filename;
        thread_data[i].file = file;
        thread_data[i].thread_id = i + 1;
    }

    int rc;
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_data[i]);
        if (rc) {
            printf("Error: could not create thread, return code: %d\n", rc);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: could not join thread, return code: %d\n", rc);
            exit(1);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <num_threads>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int num_threads = atoi(argv[2]);

    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        printf("Error: number of threads must be between 1 and %d\n", MAX_THREADS);
        exit(1);
    }

    read_file(filename, num_threads);

    return 0;
}