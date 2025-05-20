//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
    char **field_names;
    int num_fields;
    char **current_row;
} CsvReader;

void csvReaderInit(CsvReader *reader) {
    reader->field_names = NULL;
    reader->num_fields = 0;
    reader->current_row = NULL;
}

void csvReaderCleanup(CsvReader *reader) {
    int i;
    if (reader->field_names) {
        for (i = 0; i < reader->num_fields; i++) {
            free(reader->field_names[i]);
        }
        free(reader->field_names);
    }
    if (reader->current_row) {
        for (i = 0; i < reader->num_fields; i++) {
            free(reader->current_row[i]);
        }
        free(reader->current_row);
    }
}

void parseLine(char *line, char **fields, int *num_fields) {
    char *field, *saveptr;
    int i = 0;
    for (field = strtok_r(line, ",", &saveptr);
         field && i < MAX_FIELDS;
         field = strtok_r(NULL, ",", &saveptr), i++) {
        fields[i] = field;
    }
    *num_fields = i;
}

char *readLine(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        return line;
    }
    free(line);
    return NULL;
}

void readHeader(CsvReader *reader, FILE *file) {
    char *line = readLine(file);
    if (line) {
        reader->field_names = malloc(MAX_FIELDS * sizeof(char *));
        parseLine(line, reader->field_names, &reader->num_fields);
        free(line);
    }
}

void readRow(CsvReader *reader, FILE *file) {
    char *line = readLine(file);
    if (line) {
        reader->current_row = malloc(MAX_FIELDS * sizeof(char *));
        parseLine(line, reader->current_row, &reader->num_fields);
        free(line);
    }
}

typedef struct {
    CsvReader *reader;
    FILE *file;
    void (*callback)(void *data, CsvReader *reader);
    void *data;
} AsyncCsvReader;

void asyncCsvReaderInit(AsyncCsvReader *reader) {
    reader->reader = NULL;
    reader->file = NULL;
    reader->callback = NULL;
    reader->data = NULL;
}

void asyncCsvReaderCleanup(AsyncCsvReader *reader) {
    if (reader->reader) {
        csvReaderCleanup(reader->reader);
        free(reader->reader);
    }
    if (reader->file) {
        fclose(reader->file);
    }
}

void asyncReadHeader(void *data) {
    AsyncCsvReader *asyncReader = data;
    CsvReader *reader = asyncReader->reader;
    FILE *file = asyncReader->file;
    readHeader(reader, file);
    asyncReader->callback(asyncReader->data, reader);
}

void asyncReadRow(void *data) {
    AsyncCsvReader *asyncReader = data;
    CsvReader *reader = asyncReader->reader;
    FILE *file = asyncReader->file;
    readRow(reader, file);
    asyncReader->callback(asyncReader->data, reader);
}

void asyncCsvReaderReadHeader(AsyncCsvReader *reader,
                              const char *filename,
                              void (*callback)(void *data, CsvReader *reader),
                              void *data) {
    reader->reader = malloc(sizeof(CsvReader));
    csvReaderInit(reader->reader);
    reader->file = fopen(filename, "r");
    reader->callback = callback;
    reader->data = data;
    asyncReadHeader(reader);
}

void asyncCsvReaderReadRow(AsyncCsvReader *reader, void (*callback)(void *data, CsvReader *reader), void *data) {
    reader->callback = callback;
    reader->data = data;
    asyncReadRow(reader);
}

int main() {
    CsvReader reader;
    csvReaderInit(&reader);
    FILE *file = fopen("test.csv", "r");
    readHeader(&reader, file);
    readRow(&reader, file);
    printf("Field Names:\n");
    for (int i = 0; i < reader.num_fields; i++) {
        printf("%s\n", reader.field_names[i]);
    }
    printf("First Row:\n");
    for (int i = 0; i < reader.num_fields; i++) {
        printf("%s\n", reader.current_row[i]);
    }
    csvReaderCleanup(&reader);
    fclose(file);

    AsyncCsvReader asyncReader;
    asyncCsvReaderInit(&asyncReader);
    asyncCsvReaderReadHeader(&asyncReader, "test2.csv", &asyncCsvReaderReadRow, &asyncReader);
    return 0;
}