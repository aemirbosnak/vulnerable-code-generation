//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

// Structure to hold the CSV data
typedef struct {
    char **fields;
    int field_count;
} CsvRow;

// Function to free the allocated memory for a CsvRow
void free_csv_row(CsvRow *row) {
    for (int i = 0; i < row->field_count; ++i) {
        free(row->fields[i]);
    }
    free(row->fields);
}

// Function to split a line into fields
void parse_line(char *line, CsvRow *row) {
    row->fields = malloc(MAX_FIELDS * sizeof(char *));
    row->field_count = 0;

    char *token = strtok(line, ",");
    while (token != NULL) {
        row->fields[row->field_count] = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(row->fields[row->field_count], token);
        row->field_count++;
        token = strtok(NULL, ",");
    }
}

// Function to read the CSV file
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open the file!");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CsvRow row;
        parse_line(line, &row);

        // Printing the fields of the CSV row
        for (int i = 0; i < row.field_count; ++i) {
            printf("Field %d: %s\n", i + 1, row.fields[i]);
        }

        free_csv_row(&row);
    }
    fclose(file);
}

// Function to create an artistic greeting
void artistic_banner() {
    printf("\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            Welcome to CSV Reader      *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("\n");
}

int main(int argc, char *argv[]) {
    artistic_banner();

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);
    return 0;
}