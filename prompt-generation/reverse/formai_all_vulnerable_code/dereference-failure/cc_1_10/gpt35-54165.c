//FormAI DATASET v1.0 Category: Data mining ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 50

/* Struct to hold dataset */
typedef struct {
    char name[50];
    float values[MAX_COLUMNS];
} Row;

/* Functions to read in data from file */
bool read_data(Row data[], char filename[]);
int get_num_columns(char header[]);
float get_value(char value[]);
void split_data(char data[], char delimiter, char *result[]);

/* Function to perform data mining */
void perform_data_mining(Row data[], int num_rows, int num_columns);

/* Main function */
int main() {
    char filename[] = "data.csv";
    Row data[MAX_ROWS];

    if (read_data(data, filename)) {
        int num_rows = sizeof(data) / sizeof(data[0]);
        int num_columns = sizeof(data[0].values) / sizeof(data[0].values[0]);

        perform_data_mining(data, num_rows, num_columns);
    }

    return 0;
}

/* Read data from file and store in array of Rows */
bool read_data(Row data[], char filename[]) {
    FILE *fp;
    char buffer[200];
    char *result[50];
    int row = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return false;
    }

    /* Read header line and get number of columns */
    fgets(buffer, sizeof(buffer), fp);
    int num_columns = get_num_columns(buffer);

    /* Read in data */
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < MAX_ROWS) {
        split_data(buffer, ',', result);

        strcpy(data[row].name, result[0]);
        for (int i = 0; i < num_columns; i++) {
            data[row].values[i] = get_value(result[i + 1]);
        }

        row++;
    }

    fclose(fp);
    return true;
}

/* Get number of columns in dataset */
int get_num_columns(char header[]) {
    int num_columns = 0;
    char *token = strtok(header, ",");
    while (token != NULL) {
        num_columns++;
        token = strtok(NULL, ",");
    }

    return num_columns - 1;
}

/* Convert string to float */
float get_value(char value[]) {
    char *end_ptr;
    float result = strtof(value, &end_ptr);

    return result;
}

/* Split data line into separate values */
void split_data(char data[], char delimiter, char *result[]) {
    char *token = strtok(data, ",");
    int i = 0;
    while (token != NULL) {
        result[i] = token;
        token = strtok(NULL, ",");
        i++;
    }
}

/* Perform data mining on dataset */
void perform_data_mining(Row data[], int num_rows, int num_columns) {
    /* Your code for data mining goes here */

    printf("Data mining complete!\n");
}