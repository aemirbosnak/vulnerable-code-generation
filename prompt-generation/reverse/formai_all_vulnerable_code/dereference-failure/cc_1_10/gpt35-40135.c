//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_COUNT 100

typedef struct {
    char **fields;   // array of string values
    int count;       // number of fields
} CsvLine;

typedef struct {
    CsvLine *lines;  // array of CsvLine objects
    int count;       // number of lines
} CsvTable;

void printCsvTable(CsvTable *table) {
    for(int i = 0; i < table->count; i++) {
        CsvLine *line = &(table->lines[i]);
        for(int j = 0; j < line->count; j++) {
            printf("%s", line->fields[j]);
            if(j < line->count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

CsvTable *readCsvFile(char *filename) {
    FILE *file;
    char buffer[MAX_LINE_SIZE];
    CsvTable *table = (CsvTable*)malloc(sizeof(CsvTable));
    table->count = 0;
    table->lines = NULL;

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: Could not open file: %s\n", filename);
        return NULL;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        int field_count = 0;
        char *field_p;
        CsvLine *line = (CsvLine*)malloc(sizeof(CsvLine));
        line->fields = (char**)malloc(sizeof(char*) * MAX_FIELD_COUNT);
        line->count = 0;

        field_p = strtok(buffer, ",");
        while(field_p != NULL && field_count < MAX_FIELD_COUNT) {
            line->fields[field_count] = strdup(field_p);
            field_count++;
            field_p = strtok(NULL, ",");
        }

        line->count = field_count;
        table->count++;
        table->lines = (CsvLine*)realloc(table->lines, sizeof(CsvLine) * table->count);
        table->lines[table->count - 1] = *line;
    }

    fclose(file);
    return table;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Error: Must provide filename\n");
        return 0;
    }

    CsvTable *table = readCsvFile(argv[1]);
    if(table != NULL) {
        printCsvTable(table);
    }

    // free memory
    for(int i = 0; i < table->count; i++) {
        CsvLine *line = &(table->lines[i]);
        for(int j = 0; j < line->count; j++) {
            free(line->fields[j]);
        }
        free(line->fields);
    }
    free(table->lines);
    free(table);

    return 0;
}