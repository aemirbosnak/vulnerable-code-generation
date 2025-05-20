//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS_PER_LINE 10

typedef struct {
    char **fields;
    int num_fields;
} CsvLine;

typedef struct {
    CsvLine *lines;
    int num_lines;
} CsvFile;

CsvLine parse_line(char *line) {
    CsvLine csv_line;

    csv_line.fields = (char **)malloc(sizeof(char *) * MAX_FIELDS_PER_LINE);
    csv_line.num_fields = 0;

    char *field = strtok(line, ",");
    while (field != NULL) {
        if (csv_line.num_fields == MAX_FIELDS_PER_LINE) {
            fprintf(stderr, "Error: too many fields in line\n");
            exit(EXIT_FAILURE);
        }

        int length = strlen(field);
        csv_line.fields[csv_line.num_fields] = (char *)malloc(sizeof(char) * (length + 1));
        strncpy(csv_line.fields[csv_line.num_fields], field, length);
        csv_line.fields[csv_line.num_fields][length] = '\0';

        csv_line.num_fields++;

        field = strtok(NULL, ",");
    }

    return csv_line;
}

CsvFile read_csv_file(char *filename) {
    CsvFile csv_file;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    csv_file.lines = (CsvLine *)malloc(sizeof(CsvLine) * MAX_LINE_LENGTH);
    csv_file.num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (csv_file.num_lines == MAX_LINE_LENGTH) {
            fprintf(stderr, "Error: file has too many lines\n");
            exit(EXIT_FAILURE);
        }

        CsvLine parsed_line = parse_line(line);

        csv_file.lines[csv_file.num_lines] = parsed_line;
        csv_file.num_lines++;
    }

    fclose(file);

    return csv_file;
}

int main() {
    CsvFile csv_file = read_csv_file("example.csv");

    for (int i = 0; i < csv_file.num_lines; i++) {
        CsvLine csv_line = csv_file.lines[i];

        for (int j = 0; j < csv_line.num_fields; j++) {
            printf("%s ", csv_line.fields[j]);
            free(csv_line.fields[j]);
        }

        printf("\n");
        free(csv_line.fields);
    }

    free(csv_file.lines);

    return 0;
}