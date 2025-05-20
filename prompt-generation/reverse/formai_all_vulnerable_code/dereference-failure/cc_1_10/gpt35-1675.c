//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128

/* Function declarations */
char** parse_csv_line(char* line, int* num_fields);
void free_csv_fields(char** fields, int num_fields);
void print_csv_fields(char** fields, int num_fields);

int main(int argc, char* argv[]) {
    /* Check for correct usage */
    if (argc != 2) {
        printf("Usage: %s csv_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open csv file for reading */
    FILE* csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        printf("Failed to open csv file\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_SIZE];
    char** fields;
    int num_fields;

    /* Read and parse each line in the csv file */
    while (fgets(line, MAX_LINE_SIZE, csv_file)) {
        fields = parse_csv_line(line, &num_fields);
        print_csv_fields(fields, num_fields);
        free_csv_fields(fields, num_fields);
    }
    
    /* Close csv file */
    fclose(csv_file);

    return 0;
}

/* Function to parse a csv line into an array of strings */
char** parse_csv_line(char* line, int* num_fields) {
    char** fields = NULL;
    char* field = strtok(line, ",");
    int i = 0;

    while (field) {
        fields = realloc(fields, sizeof(char*) * (i+1));
        fields[i] = malloc(sizeof(char) * MAX_FIELD_SIZE);
        strncpy(fields[i], field, MAX_FIELD_SIZE);
        i++;
        field = strtok(NULL, ",");
    }

    *num_fields = i;
    return fields;
}

/* Function to free memory allocated for csv fields */
void free_csv_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}

/* Function to print csv fields */
void print_csv_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        printf("%s\t", fields[i]);
    }
    printf("\n");
}