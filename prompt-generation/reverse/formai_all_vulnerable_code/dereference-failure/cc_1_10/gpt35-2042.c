//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // maximum size for each line in CSV file
#define MAX_FIELD_SIZE 256 // maximum size for each field in CSV file
#define MAX_FIELDS 10 // maximum number of fields in CSV file

// Define a struct for holding the parsed CSV data
typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_SIZE];
    int num_fields;
} csv_record;

// Define a function for reading a single line from the CSV file
int read_line(FILE *fp, char *line) {
    int i = 0;
    char c;
    while ((c = fgetc(fp)) != '\n' && c != EOF && i < MAX_LINE_SIZE - 1) {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

// Define a function for parsing a single line into a csv_record
csv_record parse_record(char *line) {
    csv_record record;
    char *token = strtok(line, ",");
    int i = 0;
    while (token != NULL && i < MAX_FIELDS) {
        strncpy(record.fields[i++], token, MAX_FIELD_SIZE - 1);
        record.fields[i - 1][MAX_FIELD_SIZE - 1] = '\0'; // Ensure null-termination
        token = strtok(NULL, ",");
    }
    record.num_fields = i;
    return record;
}

// Define a function for reading the entire CSV file into an array of csv_records
csv_record* read_csv(char *filename, int *num_records) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    // Count the number of lines in the file
    int lines = 0;
    char line[MAX_LINE_SIZE];
    while (read_line(fp, line) > 0) {
        ++lines;
    }
    // Allocate memory for the csv_records and read the file into it
    csv_record *records = malloc(lines * sizeof(csv_record));
    rewind(fp);
    int i = 0;
    while (read_line(fp, line) > 0 && i < lines) {
        records[i++] = parse_record(line);
    }
    *num_records = i;
    fclose(fp);
    return records;
}

int main() {
    int num_records;
    csv_record *records = read_csv("example.csv", &num_records);
    // Print out the parsed CSV data
    for (int i = 0; i < num_records; ++i) {
        printf("Record %d:\n", i + 1);
        for (int j = 0; j < records[i].num_fields; ++j) {
            printf("  %s\n", records[i].fields[j]);
        }
    }
    free(records);
    return 0;
}