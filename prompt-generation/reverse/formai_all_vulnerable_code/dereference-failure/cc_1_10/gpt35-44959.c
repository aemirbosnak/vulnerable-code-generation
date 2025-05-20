//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128
#define MAX_FIELDS 10

/* The CSV reader function */
int read_csv(const char* filename) {

    /* Open the file for reading */
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return 1;
    }

    /* Allocate memory for line and fields */
    char* line = (char*)malloc(MAX_LINE_SIZE);
    char** fields = (char**)malloc(MAX_FIELDS * sizeof(char*));
    for (int i = 0; i < MAX_FIELDS; i++) {
        fields[i] = (char*)malloc(MAX_FIELD_SIZE);
    }

    /* Read and parse the CSV file */
    int row_count = 0;
    int field_count = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        /* Tokenize the line */
        char* token = strtok(line, ",");
        field_count = 0;
        while (token) {
            if (field_count >= MAX_FIELDS) {
                fprintf(stderr, "Too many fields in row %d\n", row_count);
                return 1;
            }
            strcpy(fields[field_count], token);
            field_count++;
            token = strtok(NULL, ",");
        }
        /* Do something with the parsed fields */
        printf("Row %d, Col 1: %s, Col 2: %s\n", row_count, fields[0], fields[1]);
        row_count++;
    }

    /* Free the memory */
    free(line);
    for (int i = 0; i < MAX_FIELDS; i++) {
        free(fields[i]);
    }
    free(fields);

    /* Close the file and return success */
    fclose(fp);
    return 0;
}

/* The main function */
int main(int argc, char const *argv[]) {

    /* Make sure a filename is specified */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Call the CSV reader function */
    if (read_csv(argv[1])) {
        fprintf(stderr, "Could not read CSV file: %s\n", argv[1]);
        return 1;
    }

    /* Everything went fine */
    return 0;
}