//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LEN 25   // Maximum length of a field in a CSV file
#define MAX_LINE_LEN 256   // Maximum length of a line in a CSV file


// Define data structure to hold a CSV record
typedef struct CSVRecord {
    char **fields;   // Array of fields
    int num_fields;  // Number of fields in a record
} CSVRecord;


// Define function to parse a CSV record from a line
CSVRecord parse_CSV_record(char *line) {
    CSVRecord record;
    char *field;
    int i = 0;

    // Allocate memory for the array of fields
    record.fields = (char **)malloc(MAX_FIELD_LEN * sizeof(char *));

    // Parse the line and extract each field
    field = strtok(line, ",");
    while (field != NULL) {
        record.fields[i] = field;
        i++;
        record.num_fields = i;
        field = strtok(NULL, ",");
    }

    return record;
}


// Define function to free memory allocated for a CSV record
void free_CSV_record(CSVRecord record) {
    int i;

    for (i = 0; i < record.num_fields; i++) {
        free(record.fields[i]);
    }
    free(record.fields);
}


// Define function to read a CSV file and print its contents
int read_CSV_file(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    CSVRecord record;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    // Read each line of the file and parse it as a CSV record
    while (fgets(line, MAX_LINE_LEN, fp)) {
        record = parse_CSV_record(line);

        // Print each field of the record
        int i;
        for (i = 0; i < record.num_fields; i++) {
            printf("%s ", record.fields[i]);
        }
        printf("\n");

        free_CSV_record(record);
    }

    // Close the file
    fclose(fp);

    return 0;
}


// Main function to be executed
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s CSV_FILENAME\n", argv[0]);
        return 1;
    }

    if (read_CSV_file(argv[1]) != 0) {
        return 1;
    }

    return 0;
}