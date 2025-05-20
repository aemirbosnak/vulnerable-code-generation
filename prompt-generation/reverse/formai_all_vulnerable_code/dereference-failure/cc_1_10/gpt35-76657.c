//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 512
#define MAX_FIELDS 20

typedef struct {
    int num_fields;
    char *fields[MAX_FIELDS];
} csv_line;

int parse_csv_line(char *line, csv_line *csv) {
    int num_fields = 0;
    char *field;
    field = strtok(line, ",");
    while (field != NULL && num_fields < MAX_FIELDS) {
        csv->fields[num_fields] = malloc(strlen(field) + 1);
        strcpy(csv->fields[num_fields], field);
        num_fields++;
        field = strtok(NULL, ",");
    }
    csv->num_fields = num_fields;
    return num_fields > 0;
}

int read_csv_file(char *filename, csv_line **csv_lines, int *num_lines) {
    FILE *csv_file;
    char line_buffer[MAX_LINE_LENGTH];
    int num_lines_allocated = 10;
    int num_lines_read = 0;
    csv_line *current_csv_line;
    *csv_lines = malloc(num_lines_allocated * sizeof(csv_line));
    csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        *num_lines = 0;
        return 0;
    }
    while (fgets(line_buffer, MAX_LINE_LENGTH, csv_file) != NULL) {
        if (num_lines_read >= num_lines_allocated) {
            num_lines_allocated *= 2;
            *csv_lines = realloc(*csv_lines, num_lines_allocated * sizeof(csv_line));
        }
        current_csv_line = &(*csv_lines)[num_lines_read];
        if (parse_csv_line(line_buffer, current_csv_line)) {
            num_lines_read++;
        }
    }
    *num_lines = num_lines_read;
    fclose(csv_file);
    return 1;
}

int main(int argc, char **argv) {
    char *filename = "example.csv";
    csv_line *csv_lines;
    int num_lines;
    int i, j;
    if (!read_csv_file(filename, &csv_lines, &num_lines)) {
        printf("Failed to read CSV file '%s'\n", filename);
        return 1;
    }
    printf("Successfully read %d lines from CSV file '%s'\n", num_lines, filename);
    printf("CSV contents:\n");
    for (i = 0; i < num_lines; i++) {
        printf("Line %d: ", i + 1);
        for (j = 0; j < csv_lines[i].num_fields; j++) {
            printf("[%s] ", csv_lines[i].fields[j]);
        }
        printf("\n");
    }
    for (i = 0; i < num_lines; i++) {
        for (j = 0; j < csv_lines[i].num_fields; j++) {
            free(csv_lines[i].fields[j]);
        }
    }
    free(csv_lines);
    return 0;
}