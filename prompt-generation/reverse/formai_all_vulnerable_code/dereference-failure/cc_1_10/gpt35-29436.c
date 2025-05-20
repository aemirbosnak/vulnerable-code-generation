//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_SIZE 1024
#define MAX_CSV_FIELDS 10

typedef struct {
    char** fields;
    int num_fields;
} CSVLine;

typedef struct {
    CSVLine* lines;
    int num_lines;
} CSVFile;

CSVFile* readCSV(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file: %s\n", filename);
        return NULL;
    }

    char line[MAX_CSV_LINE_SIZE];
    CSVFile* csv = malloc(sizeof(CSVFile));
    csv->lines = malloc(MAX_CSV_FIELDS * sizeof(CSVLine));
    csv->num_lines = 0;

    while (fgets(line, MAX_CSV_LINE_SIZE, file)) {
        if (csv->num_lines >= MAX_CSV_FIELDS) {
            printf("Too many lines in file: %s\n", filename);
            fclose(file);
            return NULL;
        }

        char* token;
        int field_index = 0;
        char* line_copy = strdup(line);
        CSVLine* csv_line = malloc(sizeof(CSVLine));
        csv_line->fields = malloc(MAX_CSV_FIELDS * sizeof(char*));
        csv_line->num_fields = 0;

        while ((token = strsep(&line_copy, ",")) != NULL) {
            if (csv_line->num_fields >= MAX_CSV_FIELDS) {
                printf("Too many fields in line %d of file %s\n", csv->num_lines+1, filename);
                fclose(file);
                return NULL;
            }

            csv_line->fields[csv_line->num_fields] = strdup(token);
            csv_line->num_fields++;
        }

        csv->lines[csv->num_lines] = *csv_line;
        csv->num_lines++;
    }

    fclose(file);
    return csv;
}

void freeCSV(CSVFile* csv) {
    for (int i = 0; i < csv->num_lines; i++) {
        for (int j = 0; j < csv->lines[i].num_fields; j++) {
            free(csv->lines[i].fields[j]);
        }
        free(csv->lines[i].fields);
    }
    free(csv->lines);
    free(csv);
}

int main() {
    CSVFile* csv = readCSV("example.csv");
    if (!csv) {
        printf("Failed to read CSV file\n");
        return 1;
    }

    for (int i = 0; i < csv->num_lines; i++) {
        CSVLine line = csv->lines[i];
        for (int j = 0; j < line.num_fields; j++) {
            printf("%s | ", line.fields[j]);
        }
        printf("\n");
    }

    freeCSV(csv);
    return 0;
}