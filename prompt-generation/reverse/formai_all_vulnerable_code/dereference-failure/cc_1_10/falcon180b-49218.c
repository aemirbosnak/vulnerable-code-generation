//Falcon-180B DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct thread_data {
    int thread_id;
    FILE *file;
};

void *thread_function(void *arg) {
    struct thread_data *data = arg;
    int thread_id = data->thread_id;
    FILE *file = data->file;

    char filename[10] = {0};
    sprintf(filename, "thread_%d.txt", thread_id);
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Thread %d: Error opening file\n", thread_id);
        exit(1);
    }

    fprintf(file, "Thread %d is writing to the file\n", thread_id);

    fclose(file);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];

    FILE *file = fopen("main_file.txt", "w");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(file, "Main thread is writing to the file\n");
    fclose(file);

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i + 1;
        data[i].file = fopen("thread_file.txt", "w");

        if (data[i].file == NULL) {
            printf("Error opening file\n");
            exit(1);
        }

        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}