//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_SIZE 1024          /* Maximum size of one line in the CSV file */
#define MAX_CSV_FIELDS 256             /* Maximum number of fields in one line of the CSV file */

char *csv_fields[MAX_CSV_FIELDS];       /* Array to hold the CSV fields after parsing */

/* Function to read one line from the CSV file using fgets */
char* read_csv_line(FILE* csv_file) {
    char* line = (char*) malloc(MAX_CSV_LINE_SIZE);     /* Allocate memory for one line */
    fgets(line, MAX_CSV_LINE_SIZE, csv_file);           /* Read one line from the CSV file */
    return line;
}

/* Function to parse one line from the CSV file into fields */
int parse_csv_line(char* csv_line, char* delimiter) {
    char* token;                                        /* Pointer for the strtok function */
    int field_count = 0;                                /* Count of fields in the CSV line */

    /* Use strtok to split the line into fields */
    token = strtok(csv_line, delimiter);
    while (token != NULL) {
        csv_fields[field_count++] = strdup(token);      /* Copy each field into the array */
        token = strtok(NULL, delimiter);
    }

    return field_count;
}

/* Function to read the entire CSV file and store all lines and fields in memory */
void read_csv_file(char* filename, char* delimiter) {
    FILE* csv_file = fopen(filename, "r");              /* Open the CSV file for reading */
    if (!csv_file) {
        printf("Error opening CSV file: %s\n", filename);
        exit(1);
    }

    char* csv_line;
    int line_count = 0, field_count;

    /* Loop through each line in the CSV file */
    while ((csv_line = read_csv_line(csv_file)) != NULL) {
        field_count = parse_csv_line(csv_line, delimiter);   /* Parse the line into fields */
        line_count++;
        printf("Line %d: %d fields\n", line_count, field_count);

        /* Do something with the fields here ... */

        free(csv_line);                                 /* Free the memory used by the line */
    }

    fclose(csv_file);                                   /* Close the CSV file */
}

int main() {
    char* filename = "example.csv";
    char* delimiter = ",";

    read_csv_file(filename, delimiter);                /* Call the function to read the CSV file */

    return 0;
}