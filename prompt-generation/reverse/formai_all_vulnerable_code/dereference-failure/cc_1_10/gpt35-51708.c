//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

typedef struct {
    char** values;
    int num_fields;
} csv_row;

typedef struct {
    csv_row* rows;
    int num_rows;
    int num_fields;
} csv_file;

csv_file* read_csv_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    csv_file* file = (csv_file*)malloc(sizeof(csv_file));
    file->rows = NULL;
    file->num_rows = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Allocate space for the row
        csv_row* row = (csv_row*)malloc(sizeof(csv_row));
        row->values = NULL;
        row->num_fields = 0;

        // Parse the line into fields
        char* field = strtok(line, ",");
        while (field != NULL) {
            // Allocate space for the field and copy the value
            char* value = (char*)malloc(sizeof(char) * MAX_FIELD_LENGTH);
            strncpy(value, field, MAX_FIELD_LENGTH);

            // Add the field value to the row
            row->values = (char**)realloc(row->values, sizeof(char*) * (row->num_fields + 1));
            row->values[row->num_fields] = value;
            row->num_fields++;

            // Get the next field
            field = strtok(NULL, ",");
        }

        // Add the row to the file
        file->rows = (csv_row*)realloc(file->rows, sizeof(csv_row) * (file->num_rows + 1));
        file->rows[file->num_rows] = *row;
        file->num_rows++;

        // Free the row
        free(row);
    }

    // Close the file
    fclose(fp);

    // Set the number of fields in the file
    if (file->num_rows > 0) {
        file->num_fields = file->rows[0].num_fields;
    }

    return file;
}

int main() {
    char* filename = "example.csv";
    csv_file* file = read_csv_file(filename);

    printf("Loaded file '%s' with %d rows and %d columns:\n", filename, file->num_rows, file->num_fields);
    for (int i = 0; i < file->num_rows; i++) {
        printf("\tRow %d: ", i + 1);
        for (int j = 0; j < file->num_fields; j++) {
            printf("%s", file->rows[i].values[j]);
            if (j < file->num_fields - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    // Free the file
    for (int i = 0; i < file->num_rows; i++) {
        for (int j = 0; j < file->num_fields; j++) {
            free(file->rows[i].values[j]);
        }
        free(file->rows[i].values);
    }
    free(file->rows);
    free(file);

    return 0;
}