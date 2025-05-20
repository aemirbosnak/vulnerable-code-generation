//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
char input_file[100];
char output_file[100];
char *buffer;

void *encrypt_thread(void *arg) {
    int thread_num = *((int *) arg);
    int start_pos = thread_num * BUFFER_SIZE;

    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    while (fread(buffer, 1, BUFFER_SIZE, input_fp) > 0) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = buffer[i] ^ 0xAA;
        }

        fwrite(buffer, 1, BUFFER_SIZE, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program input_file output_file\n");
        exit(1);
    }

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    pthread_t threads[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_num = malloc(sizeof(int));
        *thread_num = i;
        rc = pthread_create(&threads[i], NULL, encrypt_thread, thread_num);
        if (rc) {
            printf("Error creating thread, %d\n", rc);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Encryption complete!\n");
    return 0;
}