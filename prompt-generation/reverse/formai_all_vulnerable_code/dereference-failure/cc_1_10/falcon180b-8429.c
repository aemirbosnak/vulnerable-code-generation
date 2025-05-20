//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_THREADS 4
#define MAX_INPUT_SIZE 100000

typedef struct {
    char input_file[100];
    char output_file[100];
    int thread_id;
} ThreadData;

void *compress_thread(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    FILE *input_file = fopen(data->input_file, "r");
    FILE *output_file = fopen(data->output_file, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file in thread %d\n", data->thread_id);
        exit(1);
    }

    int i, j;
    char c;
    int count = 0;

    while ((c = fgetc(input_file))!= EOF) {
        if (isspace(c)) {
            if (count > 0) {
                fprintf(output_file, "%d%c", count, c);
                count = 0;
            }
        } else {
            count++;
        }
    }

    if (count > 0) {
        fprintf(output_file, "%d%c", count, c);
    }

    fclose(input_file);
    fclose(output_file);

    pthread_exit(0);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage:./program input_file output_file num_threads\n");
        exit(1);
    }

    int num_threads = atoi(argv[3]);

    if (num_threads > MAX_THREADS || num_threads <= 0) {
        printf("Invalid number of threads\n");
        exit(1);
    }

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        ThreadData data;
        strcpy(data.input_file, argv[1]);
        strcpy(data.output_file, argv[2]);
        data.thread_id = i + 1;

        int rc = pthread_create(&threads[i], NULL, compress_thread, (void *)&data);

        if (rc) {
            printf("Error creating thread %d\n", i + 1);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Compression completed\n");

    return 0;
}