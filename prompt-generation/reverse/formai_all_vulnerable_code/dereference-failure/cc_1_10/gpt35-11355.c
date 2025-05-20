//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of the CSV file line */
#define MAX_LINE_LENGTH 100

/* Define the maximum number of elements per line */
#define MAX_NUM_ELEMENTS 10

/* Define the delimiter character */
#define DELIMITER ','

/* Define the structure for holding a single CSV line */
typedef struct {
    int num_elements;
    char elements[MAX_NUM_ELEMENTS][MAX_LINE_LENGTH];
} CSVLine;

/* Function to parse a single CSV line */
CSVLine parse_line(char *line) {
    /* Create a new CSVLine object */
    CSVLine csv_line;
    csv_line.num_elements = 0;

    /* Tokenize the line based on the delimiter */
    char *token = strtok(line, ",");
    while (token != NULL && csv_line.num_elements < MAX_NUM_ELEMENTS) {
        /* Copy the element to the CSVLine object */
        strcpy(csv_line.elements[csv_line.num_elements], token);
        csv_line.num_elements++;

        /* Get the next token */
        token = strtok(NULL, ",");
    }

    return csv_line;
}

/* Function to read a CSV file */
int read_csv(char *filename, CSVLine **csv_lines) {
    /* Open the file */
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    /* Allocate memory for the CSVLine objects */
    CSVLine *lines = (CSVLine *) malloc(MAX_NUM_ELEMENTS * sizeof(CSVLine));
    if (lines == NULL) {
        printf("Error: Could not allocate memory\n");
        return 0;
    }

    /* Read each line from the file */
    int num_lines = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && num_lines < MAX_NUM_ELEMENTS) {
        /* Parse the line and add it to the array */
        lines[num_lines] = parse_line(line);
        num_lines++;
    }

    /* Close the file */
    fclose(file);

    /* Set the output parameter */
    *csv_lines = lines;
    return num_lines;
}

/* Main function */
int main() {
    /* Read the CSV file */
    CSVLine *csv_lines;
    int num_lines = read_csv("example.csv", &csv_lines);
    if (num_lines == 0) {
        return 0;
    }

    /* Print out the CSV data */
    for (int i = 0; i < num_lines; i++) {
        CSVLine line = csv_lines[i];
        for (int j = 0; j < line.num_elements; j++) {
            printf("%s ", line.elements[j]);
        }
        printf("\n");
    }

    /* Free the memory */
    free(csv_lines);

    return 0;
}