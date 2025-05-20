//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1024  // Maximum length of a line in the csv file
#define DELIMITER "," // Character that separates the columns in the csv file

// Struct that will hold the data for each row in the csv file
typedef struct {
    char *col1;
    char *col2;
    int col3;
    float col4;
} RowData;

// Function to parse the csv file and store the data in a dynamic array of RowData
RowData *parse_csv_file(char *filename, int *num_rows) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    RowData *data = (RowData *) malloc(sizeof(RowData));
    while((read = getline(&line, &len, fp)) != -1) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        // Split the line by the delimiter and store the values in the RowData struct
        char *token = strtok(line, DELIMITER);
        data[i].col1 = strdup(token);

        token = strtok(NULL, DELIMITER);
        data[i].col2 = strdup(token);

        token = strtok(NULL, DELIMITER);
        data[i].col3 = atoi(token);

        token = strtok(NULL, DELIMITER);
        data[i].col4 = strtof(token, NULL);

        // Increase the size of the data array
        i++;
        data = (RowData *) realloc(data, sizeof(RowData) * (i+1));
    }

    *num_rows = i;
    fclose(fp);

    if(line) {
        free(line);
    }

    return data;
}

int main() {
    char *filename = "example.csv";
    int num_rows;
    RowData *data = parse_csv_file(filename, &num_rows);

    // Print out the data array
    for(int i = 0; i < num_rows; i++) {
        printf("%s, %s, %d, %.2f\n", data[i].col1, data[i].col2, data[i].col3, data[i].col4);
    }

    // Free the memory allocated for the RowData structs and the array itself
    for(int i = 0; i < num_rows; i++) {
        free(data[i].col1);
        free(data[i].col2);
    }

    free(data);

    return 0;
}