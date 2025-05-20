//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Record {
    char **data;
    int num_fields;
} CSV_Record;

CSV_Record *read_csv_file(char *filename) {
    FILE *fp;
    CSV_Record *record = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Allocate memory for the record
    record = malloc(sizeof(CSV_Record));
    record->data = NULL;
    record->num_fields = 0;

    // Read the header line
    char line[MAX_BUFFER_SIZE];
    fgets(line, MAX_BUFFER_SIZE, fp);

    // Count the number of fields
    char *field = strtok(line, ",");
    while (field) {
        record->num_fields++;
        field = strtok(NULL, ",");
    }

    // Allocate memory for the data
    record->data = malloc(record->num_fields * sizeof(char *));

    // Read the data lines
    while (fgets(line, MAX_BUFFER_SIZE, fp) != NULL) {
        // Split the line into fields
        char **fields = malloc(record->num_fields * sizeof(char *));
        field = strtok(line, ",");
        int i = 0;
        while (field) {
            fields[i++] = strdup(field);
            field = strtok(NULL, ",");
        }

        // Store the fields in the record
        memcpy(record->data, fields, record->num_fields * sizeof(char *));

        // Free the fields memory
        free(fields);
    }

    // Close the file
    fclose(fp);

    return record;
}

int main() {
    char *filename = "data.csv";
    CSV_Record *record = read_csv_file(filename);

    // Print the record data
    for (int i = 0; i < record->num_fields; i++) {
        for (int j = 0; j < record->num_fields; j++) {
            printf("%s,", record->data[i][j]);
        }
        printf("\n");
    }

    // Free the record memory
    free(record->data);
    free(record);

    return 0;
}