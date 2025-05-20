//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to read the CSV file and store it in a 2D array
CSV read_csv(const char *filename) {
    CSV csv = {NULL, 0, 0};
    FILE *fp = fopen(filename, "r");
    char line[MAX_ROW_SIZE];
    char *token;
    int i = 0, j = 0;

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_ROW_SIZE, fp)!= NULL) {
        csv.rows++;
        csv.cols = 0;
        token = strtok(line, ",");
        while (token!= NULL) {
            csv.cols++;
            csv.data = (char **)realloc(csv.data, csv.rows * sizeof(char *));
            csv.data[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csv.data[i], token);
            i++;
            j++;
            token = strtok(NULL, ",");
        }
        csv.data = (char **)realloc(csv.data, csv.rows * sizeof(char *));
        csv.data[i] = NULL;
    }

    fclose(fp);
    return csv;
}

// Function to print the CSV data in a formatted manner
void print_csv(CSV csv) {
    int i, j;

    for (i = 0; i < csv.rows; i++) {
        for (j = 0; j < csv.cols; j++) {
            printf("%s\t", csv.data[i * csv.cols + j]);
        }
        printf("\n");
    }
}

int main() {
    CSV csv = read_csv("example.csv");
    print_csv(csv);

    return 0;
}