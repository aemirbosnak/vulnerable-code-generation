//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100
#define DELIMITER ','

typedef struct {
    char* data;
    size_t length;
} Field;

typedef struct {
    Field* fields;
    size_t numFields;
} Record;

typedef struct {
    char* fileName;
    FILE* file;
    char* line;
    size_t lineLength;
} CSVReader;

CSVReader createCSVReader(char* fileName) {
    CSVReader reader;
    reader.fileName = fileName;
    reader.file = fopen(fileName, "r");
    reader.line = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    reader.lineLength = 0;
    return reader;
}

void destroyCSVReader(CSVReader* reader) {
    fclose(reader->file);
    free(reader->line);
}

size_t parseFields(char* line, Field* fields) {
    size_t numFields = 0;
    char* token = strtok(line, ",");
    while (token != NULL) {
        fields[numFields].data = token;
        fields[numFields].length = strlen(token);
        token = strtok(NULL, ",");
        numFields++;
    }
    return numFields;
}

Record readRecord(CSVReader* reader) {
    Record record;
    record.numFields = 0;
    if (getline(&(reader->line), &(reader->lineLength), reader->file) != -1) {
        record.fields = (Field*)malloc(sizeof(Field) * MAX_FIELD_LENGTH);
        record.numFields = parseFields(reader->line, record.fields);
    }
    return record;
}

void printRecord(Record* record) {
    for (size_t i = 0; i < record->numFields; i++) {
        printf("%.*s\n", (int)record->fields[i].length, record->fields[i].data);
    }
}

int main() {
    CSVReader reader = createCSVReader("example.csv");
    Record record;
    while ((record = readRecord(&reader)).numFields > 0) {
        printRecord(&record);
    }
    destroyCSVReader(&reader);
    return 0;
}