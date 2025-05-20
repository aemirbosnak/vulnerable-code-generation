//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LENGTH 1024

struct CsvRow {
    char* fields[MAX_COLS];
};

struct CsvFile {
    struct CsvRow rows[MAX_ROWS];
    int num_rows;
    int num_cols;
};

bool csv_read_line(FILE* file, char* buffer, int size) {
    int i = 0;
    char c = fgetc(file);
    while (c != EOF && c != '\n' && i < size-1) {
        buffer[i] = c;
        c = fgetc(file);
        i++;
    }
    buffer[i] = '\0';
    return i > 0;
}

void csv_parse_fields(char* line, struct CsvRow* row) {
    if (line[0] == '\0') {
        return;
    }

    char* token = strtok(line, ",");
    int i = 0;

    while (token != NULL && i < MAX_COLS) {
        row->fields[i] = token;
        i++;
        token = strtok(NULL, ",");
    }
}

void csv_read_file(const char* filename, struct CsvFile* file) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s.\n", filename);
        exit(1);
    }

    char buffer[MAX_LINE_LENGTH];

    // Read the header row
    if (!csv_read_line(fp, buffer, MAX_LINE_LENGTH)) {
        printf("Error: empty file %s.\n", filename);
        exit(1);
    }

    csv_parse_fields(buffer, &file->rows[0]);
    file->num_cols = 0;
    while (file->rows[0].fields[file->num_cols] != NULL && file->num_cols < MAX_COLS) {
        file->num_cols++;
    }

    // Read the data rows
    int i = 1;
    while (csv_read_line(fp, buffer, MAX_LINE_LENGTH) && i < MAX_ROWS) {
        csv_parse_fields(buffer, &file->rows[i]);
        i++;
    }
    file->num_rows = i;

    fclose(fp);
}

int main() {
    printf("Romeo and Juliet's CSV Reader\n\n");

    struct CsvFile file;
    csv_read_file("example.csv", &file);

    printf("Number of rows: %d\n", file.num_rows);
    printf("Number of columns: %d\n", file.num_cols);

    for (int i = 0; i < file.num_rows; i++) {
        for (int j = 0; j < file.num_cols; j++) {
            printf("%s%s", file.rows[i].fields[j], j == file.num_cols-1 ? "\n" : ",");
        }
    }

    return 0;
}