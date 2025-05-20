//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    int index;
    pthread_mutex_t lock;
} ThreadData;

void *parse_xml(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    char *xml_file = "example.xml";
    FILE *fp;
    char ch;

    fp = fopen(xml_file, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", xml_file);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        pthread_mutex_lock(&data->lock);
        if (data->index >= BUFFER_SIZE - 2) {
            printf("Error: Buffer overflow\n");
            pthread_mutex_unlock(&data->lock);
            break;
        }
        data->buffer[data->index++] = ch;
        pthread_mutex_unlock(&data->lock);
    }

    fclose(fp);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, rc;
    ThreadData data;

    data.buffer = (char *) malloc(BUFFER_SIZE);
    if (data.buffer == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }
    memset(data.buffer, 0, BUFFER_SIZE);
    pthread_mutex_init(&data.lock, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, parse_xml, &data);
        if (rc!= 0) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("XML parsing completed successfully\n");
    free(data.buffer);
    pthread_mutex_destroy(&data.lock);
    return 0;
}