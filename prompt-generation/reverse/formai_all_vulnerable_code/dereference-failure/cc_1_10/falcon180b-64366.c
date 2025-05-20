//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    FILE *input_file;
    FILE *output_file;
    int thread_id;
} thread_data_t;

void *encrypt_file(void *data) {
    thread_data_t *thread_data = (thread_data_t *) data;
    char buffer[BUFFER_SIZE];
    int c;

    while ((c = fgetc(thread_data->input_file))!= EOF) {
        if (isalpha(c)) {
            c = toupper(c) + 13;
        } else if (isdigit(c)) {
            c += 5;
        }
        fputc(c, thread_data->output_file);
    }

    fclose(thread_data->input_file);
    fclose(thread_data->output_file);
    return NULL;
}

int create_threads(char *input_file, char *output_file, int num_threads) {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];
    int i;

    for (i = 0; i < num_threads; i++) {
        thread_data[i].input_file = fopen(input_file, "r");
        if (thread_data[i].input_file == NULL) {
            printf("Error opening input file: %s\n", input_file);
            exit(1);
        }

        char output_filename[strlen(output_file) + 5];
        sprintf(output_filename, "%s_%d", output_file, i);
        thread_data[i].output_file = fopen(output_filename, "w");
        if (thread_data[i].output_file == NULL) {
            printf("Error opening output file: %s\n", output_filename);
            exit(1);
        }

        pthread_create(&threads[i], NULL, encrypt_file, &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file num_threads\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int num_threads = atoi(argv[3]);

    create_threads(input_file, output_file, num_threads);

    return 0;
}