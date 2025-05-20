//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#define _CRT_SECURE_NO_WARNINGS //ignore security warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 //maximum line length of CSV file
#define MAX_NUM_COLUMNS 100 //maximum number of columns in CSV file
#define MAX_COLUMN_LENGTH 50 //maximum length of each column in CSV file

typedef struct {
    char **columns; //array of strings to hold each column
} Row;

typedef struct {
    Row *rows; //array of rows to hold each row
    int num_rows; //number of rows in CSV file
    int num_columns; //number of columns in CSV file
    char **header; //array of strings to hold each header
} CSV;

//function to read a line from a CSV file
//returns 0 if end of file is reached, otherwise 1
int read_line(FILE *file, char *line) {
    fgets(line, MAX_LINE_LENGTH, file);
    if (feof(file)) {
        return 0;
    }
    else {
        return 1;
    }
}

//function to split a line into columns
//returns the number of columns found
int split_line(char *line, char **columns) {
    int num_columns = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        columns[num_columns] = (char*)malloc(MAX_COLUMN_LENGTH * sizeof(char));
        strcpy(columns[num_columns], token);
        num_columns++;
        token = strtok(NULL, ",");
    }
    return num_columns;
}

//function to read a CSV file and store the data in a CSV struct
CSV read_csv(char *filename) {
    CSV csv;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    //read header line and store column names
    char header_line[MAX_LINE_LENGTH];
    read_line(file, header_line);
    csv.num_columns = split_line(header_line, csv.header);

    //allocate memory for rows
    csv.rows = (Row*)malloc(MAX_NUM_COLUMNS * sizeof(Row));
    csv.num_rows = 0;

    //read data rows and store in rows array
    char data_line[MAX_LINE_LENGTH];
    while (read_line(file, data_line)) {
        Row row;
        row.columns = (char**)malloc(csv.num_columns * sizeof(char*));
        int num_columns = split_line(data_line, row.columns);
        if (num_columns != csv.num_columns) {
            printf("Error: number of columns in row does not match number of columns in header\n");
            exit(1);
        }
        csv.rows[csv.num_rows] = row;
        csv.num_rows++;
    }

    fclose(file);
    return csv;
}

//function to print the contents of a CSV struct
void print_csv(CSV csv) {
    //print header
    printf("Header:\n");
    for (int i = 0; i < csv.num_columns; i++) {
        printf("%s\t", csv.header[i]);
    }
    printf("\n");

    //print rows
    printf("Data:\n");
    for (int i = 0; i < csv.num_rows; i++) {
        for (int j = 0; j < csv.num_columns; j++) {
            printf("%s\t", csv.rows[i].columns[j]);
        }
        printf("\n");
    }
}

int main() {
    CSV csv = read_csv("data.csv");
    print_csv(csv);
    return 0;
}