//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128
#define MAX_FIELDS 20

/* Struct to hold CSV data */
typedef struct {
    char* fields[MAX_FIELDS];
    int num_fields;
} CSVRow;

/* Function to tokenize a line into CSV fields */
void tokenize_line(char* line, CSVRow* row) {
    char* field;
    int i = 0;

    /* Tokenize line by commas */
    field = strtok(line, ",");
    while (field != NULL && i < MAX_FIELDS) {
        /* Allocate memory for field and copy to row */
        row->fields[i] = (char*) malloc(sizeof(char) * MAX_FIELD_SIZE);
        strncpy(row->fields[i], field, MAX_FIELD_SIZE);
        /* Remove quotes around field if they exist */
        if (row->fields[i][0] == '"' && row->fields[i][strlen(row->fields[i])-1] == '"') {
            row->fields[i][strlen(row->fields[i])-1] = '\0';
            memmove(row->fields[i], &row->fields[i][1], strlen(row->fields[i]));
        }
        i++;
        field = strtok(NULL, ",");
    }
    /* Update number of fields in row */
    row->num_fields = i;
}

/* Function to free memory allocated to a CSV row */
void free_row(CSVRow* row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
}

/* Function to read a CSV file */
int read_csv(char* filename, CSVRow** rows, int max_rows) {
    FILE* fp;
    char line[MAX_LINE_SIZE];
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        return 0;
    }
    /* Read lines until max_rows reached or end of file */
    while (i < max_rows && fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        /* Allocate memory for new row */
        rows[i] = (CSVRow*) malloc(sizeof(CSVRow));
        /* Tokenize line and add to row */
        tokenize_line(line, rows[i]);
        i++;
    }
    fclose(fp);
    return i;
}

/* Main program */
int main() {
    CSVRow* rows[20];
    int num_rows;
    int i, j;
    /* Read CSV data from file */
    num_rows = read_csv("data.csv", rows, 20);
    /* Print out CSV data */
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < rows[i]->num_fields; j++) {
            printf("%s,", rows[i]->fields[j]);
        }
        printf("\n");
        /* Free memory for row */
        free_row(rows[i]);
        free(rows[i]);
    }
    return 0;
}