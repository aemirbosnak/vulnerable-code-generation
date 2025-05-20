//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define NUM_THREADS 4
#define CHUNK_SIZE 1024

typedef struct {
    char *input_file;
    char *output_file;
    char *key;
    int thread_id;
} thread_data_t;

void *encrypt_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    FILE *input_file = fopen(data->input_file, "r");
    FILE *output_file = fopen(data->output_file, "w");
    char key = data->key[data->thread_id % strlen(data->key)];

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    char buffer[CHUNK_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'a' + key) % 26 + 'a';
            }
            fputc(c, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void encrypt_file(char *input_file, char *output_file, char *key) {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].input_file = input_file;
        data[i].output_file = output_file;
        data[i].key = key;
        data[i].thread_id = i;

        pthread_create(&threads[i], NULL, encrypt_thread, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key = argv[3];

    encrypt_file(input_file, output_file, key);

    printf("File encrypted successfully\n");
    return 0;
}