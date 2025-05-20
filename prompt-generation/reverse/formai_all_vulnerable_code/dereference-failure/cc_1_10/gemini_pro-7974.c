//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct csv_row {
    int id;
    char *name;
    int age;
} csv_row;

typedef struct csv_reader {
    FILE *file;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int eof;
    csv_row *row;
} csv_reader;

csv_reader *csv_reader_create(const char *filename) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = fopen(filename, "r");
    pthread_mutex_init(&reader->lock, NULL);
    pthread_cond_init(&reader->cond, NULL);
    reader->eof = 0;
    reader->row = NULL;
    return reader;
}

void csv_reader_destroy(csv_reader *reader) {
    pthread_mutex_destroy(&reader->lock);
    pthread_cond_destroy(&reader->cond);
    fclose(reader->file);
    free(reader->row);
    free(reader);
}

void *csv_reader_thread(void *arg) {
    csv_reader *reader = (csv_reader *)arg;

    while (1) {
        pthread_mutex_lock(&reader->lock);
        while (reader->eof == 0 && reader->row == NULL) {
            pthread_cond_wait(&reader->cond, &reader->lock);
        }
        if (reader->eof == 1) {
            pthread_mutex_unlock(&reader->lock);
            break;
        }

        char line[1024];
        fgets(line, sizeof(line), reader->file);

        char *id = strtok(line, ",");
        char *name = strtok(NULL, ",");
        char *age = strtok(NULL, "\n");

        reader->row = malloc(sizeof(csv_row));
        reader->row->id = atoi(id);
        reader->row->name = strdup(name);
        reader->row->age = atoi(age);

        pthread_cond_signal(&reader->cond);
        pthread_mutex_unlock(&reader->lock);
    }

    return NULL;
}

csv_row *csv_reader_read(csv_reader *reader) {
    pthread_mutex_lock(&reader->lock);
    while (reader->row == NULL) {
        pthread_cond_wait(&reader->cond, &reader->lock);
    }

    csv_row *row = reader->row;
    reader->row = NULL;

    pthread_mutex_unlock(&reader->lock);
    return row;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    csv_reader *reader = csv_reader_create(argv[1]);
    pthread_t thread;
    pthread_create(&thread, NULL, csv_reader_thread, reader);

    while (1) {
        csv_row *row = csv_reader_read(reader);
        if (row == NULL) {
            break;
        }

        printf("ID: %d, Name: %s, Age: %d\n", row->id, row->name, row->age);
        free(row->name);
        free(row);
    }

    pthread_mutex_lock(&reader->lock);
    reader->eof = 1;
    pthread_cond_signal(&reader->cond);
    pthread_mutex_unlock(&reader->lock);

    pthread_join(thread, NULL);
    csv_reader_destroy(reader);

    return 0;
}