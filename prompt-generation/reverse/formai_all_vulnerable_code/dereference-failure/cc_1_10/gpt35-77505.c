//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10
#define DELIMITER ','

typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_fields;
} CsvRecord;

CsvRecord* create_csv_record(char* line) {
    CsvRecord* record = malloc(sizeof(CsvRecord));
    record->num_fields = 0;
    char* pch;
    pch = strtok(line, ",");
    while (pch != NULL && record->num_fields < MAX_FIELDS) {
        strncpy(record->fields[record->num_fields], pch, MAX_FIELD_LENGTH);
        record->num_fields++;
        pch = strtok(NULL, ",");
    }
    return record;
}

void free_csv_record(CsvRecord* record) {
    free(record);
}

void print_csv_record(CsvRecord* record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

int read_csv_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        CsvRecord* record = create_csv_record(line);
        print_csv_record(record);
        free_csv_record(record);
    }
    fclose(file);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s file.csv\n", argv[0]);
        return -1;
    }
    read_csv_file(argv[1]);
    return 0;
}