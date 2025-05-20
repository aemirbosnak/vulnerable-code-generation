//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <libgen.h>

#define MAX_FIELD_SIZE 256
#define MAX_FIELDS 64
#define BUFFER_SIZE 1024

typedef struct {
    int num_fields;
    char *fields[MAX_FIELDS];
} record_t;

typedef struct {
    FILE *fp;
    record_t *record;
    size_t buffer_size;
    char *buffer;
    pthread_t thread;
} reader_t;

void *read_csv(void *arg) {
    reader_t *reader = (reader_t *)arg;
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read_len;

    while ((read_len = getline(&line, &line_len, reader->fp)) != -1) {
        char *tok, *end;
        int i = 0;
        tok = strtok_r(line, ",", &end);
        while (tok != NULL && i < reader->record->num_fields) {
            strncpy(reader->record->fields[i], tok, MAX_FIELD_SIZE);
            reader->record->fields[i][MAX_FIELD_SIZE-1] = '\0';
            tok = strtok_r(NULL, ",", &end);
            i++;
        }
        if (i != reader->record->num_fields) {
            fprintf(stderr, "Invalid record: %s", line);
        }
    }
    free(line);
    return NULL;
}

reader_t *reader_init(const char *filename, const int num_fields) {
    reader_t *reader = (reader_t *)malloc(sizeof(reader_t));
    reader->fp = fopen(filename, "r");
    if (reader->fp == NULL) {
        fprintf(stderr, "Error opening file: %s", filename);
        free(reader);
        return NULL;
    }
    reader->record = (record_t *)calloc(1, sizeof(record_t));
    reader->record->num_fields = num_fields;
    for (int i = 0; i < num_fields; i++) {
        reader->record->fields[i] = (char *)calloc(1, MAX_FIELD_SIZE);
    }
    reader->buffer_size = BUFFER_SIZE;
    reader->buffer = (char *)malloc(reader->buffer_size);
    return reader;
}

void reader_destroy(reader_t *reader) {
    fclose(reader->fp);
    for (int i = 0; i < reader->record->num_fields; i++) {
        free(reader->record->fields[i]);
    }
    free(reader->record);
    free(reader->buffer);
    free(reader);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <csv_file> <num_fields>\n", basename(argv[0]));
        return 1;
    }
    const char *filename = argv[1];
    const int num_fields = atoi(argv[2]);

    reader_t *reader = reader_init(filename, num_fields);
    if (reader == NULL) {
        return 1;
    }

    if (pthread_create(&reader->thread, NULL, read_csv, reader) != 0) {
        fprintf(stderr, "Error creating thread\n");
        reader_destroy(reader);
        return 1;
    }

    if (pthread_join(reader->thread, NULL) != 0) {
        fprintf(stderr, "Error joining thread\n");
        reader_destroy(reader);
        return 1;
    }

    for (int i = 0; i < num_fields; i++) {
        printf("%s\n", reader->record->fields[i]);
    }

    reader_destroy(reader);
    return 0;
}