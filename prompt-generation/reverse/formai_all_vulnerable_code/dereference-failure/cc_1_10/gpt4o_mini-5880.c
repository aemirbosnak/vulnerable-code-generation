//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// A love-struck structure representing the CSV content
typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} CSVRow;

// A function to read a line from the input file
int read_line(FILE *file, char *buffer, size_t size) {
    if (fgets(buffer, size, file) != NULL) {
        // Strip the newline character at the end
        buffer[strcspn(buffer, "\n")] = 0;
        return 1;
    }
    return 0;
}

// A function to split a line into fields based on a delimiter
CSVRow *split_row(char *line) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;

    char *token = strtok(line, ",");
    while (token != NULL) {
        if (row->num_fields < MAX_FIELDS) {
            row->fields[row->num_fields++] = strdup(token);
        }
        token = strtok(NULL, ",");
    }
    return row;
}

// A function to free the memory allocated for a CSVRow
void free_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row);
}

// The ballad of not only, a CSV Reader
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("O, cursed fate! The file cannot be opened, %s.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (read_line(file, line, sizeof(line))) {
        CSVRow *row = split_row(line);
        
        // Here lies our longing for the fields, tender and true
        printf("In this line of breath, a heart's array of fields:\n");
        for (int i = 0; i < row->num_fields; i++) {
            printf("Field %d: %s\n", i + 1, row->fields[i]);
        }
        printf("\n");

        free_row(row); // Release the heart, no longer needed
    }
    
    fclose(file); // Close the chapter upon the file
    printf("Alas, we bid adieu to the CSV file from which we gathered.\n");
}

// By my troth, this is the muse that kindles our flame
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("O gentle souls, provide the path to the CSV!\n");
        return 1;
    }

    // The glorious retreat to gather the content
    read_csv(argv[1]);
    return 0;
}