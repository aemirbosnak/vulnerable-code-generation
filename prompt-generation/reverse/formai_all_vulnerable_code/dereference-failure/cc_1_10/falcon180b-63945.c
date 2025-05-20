//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define NUM_THREADS 4
#define NUM_SEM 2

sem_t sem[NUM_SEM];

void *color_convert(void *arg) {
    char *input_file = (char *) arg;
    FILE *fp;
    char line[1000];
    int hex[3];
    int red, green, blue;
    int i = 0;
    int j = 0;

    fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%02x%02x%02x", &hex[0], &hex[1], &hex[2]);
        red = hex[0] * 16 + hex[1];
        green = hex[2] * 16 + hex[3];
        blue = 0;

        sem_wait(&sem[0]);
        printf("%d: %02x%02x%02x -> %d%02x%02x\n", i, hex[0], hex[1], hex[2], red, green, blue);
        sem_post(&sem[0]);

        i++;
    }

    fclose(fp);
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t thread_id[NUM_THREADS];
    int i;
    char input_file[100];

    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    strcpy(input_file, argv[1]);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, color_convert, (void *) input_file);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}