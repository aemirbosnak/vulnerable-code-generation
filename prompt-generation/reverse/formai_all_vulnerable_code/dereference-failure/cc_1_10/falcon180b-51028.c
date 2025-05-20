//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_THREADS 10

struct thread_data {
    int id;
    char *filename;
};

void *monitor_thread(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    FILE *file;
    char line[MAX_LINE_SIZE];
    char *token;

    file = fopen(data->filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", data->filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (strcasecmp(token, "admin") == 0) {
                printf("Possible intrusion detected in file %s on line %d\n", data->filename, data->id);
                break;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    int i, rc;
    struct thread_data data[MAX_THREADS];

    if (argc < 3) {
        printf("Usage: %s <filename> <number of threads>\n", argv[0]);
        exit(1);
    }

    strcpy(data[0].filename, argv[1]);
    data[0].id = 1;

    for (i = 1; i < argc - 1; i++) {
        strcpy(data[i].filename, argv[i + 1]);
        data[i].id = i + 2;
    }

    for (i = 0; i < argc - 1; i++) {
        rc = pthread_create(&threads[i], NULL, monitor_thread, &data[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}