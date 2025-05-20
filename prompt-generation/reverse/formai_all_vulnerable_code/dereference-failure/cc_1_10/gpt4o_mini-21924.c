//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct CSVRow {
    char **fields;
    int field_count;
} CSVRow;

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; ++i) {
        free(row->fields[i]);
    }
    free(row->fields);
}

CSVRow* read_csv_row(FILE *file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file) == NULL) {
        return NULL; // End of file or read error
    }

    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    row->fields = (char **)malloc(MAX_FIELDS * sizeof(char *));
    row->field_count = 0;

    char *token = strtok(line, ",");
    while (token != NULL) {
        row->fields[row->field_count] = (char *)malloc(strlen(token) + 1);
        strcpy(row->fields[row->field_count], token);
        row->field_count++;
        token = strtok(NULL, ",");
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; ++i) {
        printf("Field %d: %s\n", i + 1, row->fields[i]);
    }
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    while (1) {
        CSVRow *row = read_csv_row(file);
        if (row == NULL) {
            break; // End of file or read error
        }

        print_csv_row(row);
        free_csv_row(row);
    }

    fclose(file);
}

void welcome_message() {
    printf("Welcome to the Creative CSV Reader!\n");
    printf("This program will read your CSV file and print its contents.\n");
    printf("--------------------------------------\n");
}

int main(int argc, char *argv[]) {
    welcome_message();

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csvfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv_file(argv[1]);

    printf("Thank you for using the Creative CSV Reader!\n");
    return EXIT_SUCCESS;
}