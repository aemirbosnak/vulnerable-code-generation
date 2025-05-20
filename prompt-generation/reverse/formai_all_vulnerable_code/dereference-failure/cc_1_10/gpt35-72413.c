//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER_SIZE 1024

/**
 * Define a struct to represent a row in a CSV file.
 */
typedef struct _csv_row {
    char **data;
    size_t size;
} csv_row;

/**
 * Define a function to split a line into fields (values).
 */
static csv_row *parse_csv_line(char *line) {
    csv_row *row = malloc(sizeof(csv_row));
    row->data = NULL;
    row->size = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        row->data = realloc(row->data, ++row->size * sizeof(char *));
        row->data[row->size - 1] = token;
        token = strtok(NULL, ",");
    }
    return row;
}

/**
 * Define a function to free up memory used by a CSV row.
 */
static void free_csv_row(csv_row *row) {
    for (size_t i = 0; i < row->size; i++) {
        free(row->data[i]);
    }
    free(row->data);
    free(row);
}

/**
 * Define a function to read a CSV file.
 */
static void read_csv_file(FILE *file) {
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        csv_row *row = parse_csv_line(buffer);
        for (size_t i = 0; i < row->size; i++) {
            printf("%s ", row->data[i]);
        }
        printf("\n");
        free_csv_row(row);
    }
}

/**
 * Define the main entry point for the program.
 */
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide a filename.\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }
    read_csv_file(file);
    fclose(file);
    return 0;
}