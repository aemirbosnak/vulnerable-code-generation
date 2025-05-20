//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    char *filename;
    int thread_id;
} thread_data;

void *convert_image_to_ascii(void *arg) {
    thread_data *data = (thread_data *) arg;
    FILE *fp;
    char ch;
    int count = 0;
    int ascii_code = 32;

    fp = fopen(data->filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", data->filename);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (count % 80 == 0 && count!= 0) {
            printf("\n");
        }

        if (ch >= 0 && ch <= 127) {
            printf("%c", ch);
        } else {
            printf(".");
        }

        count++;
    }

    fclose(fp);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    int num_threads = 0;
    char **filenames = NULL;
    int i;

    if (argc < 2) {
        printf("Usage: %s image1.jpg image2.jpg...\n", argv[0]);
        exit(1);
    }

    filenames = (char **) malloc(sizeof(char *) * argc);
    for (i = 0; i < argc; i++) {
        filenames[i] = argv[i + 1];
    }

    for (i = 0; i < argc; i++) {
        pthread_create(&threads[num_threads], NULL, convert_image_to_ascii, (void *) &(data[num_threads]));
        data[num_threads].filename = filenames[i];
        data[num_threads].thread_id = i + 1;
        num_threads++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(filenames);
    return 0;
}