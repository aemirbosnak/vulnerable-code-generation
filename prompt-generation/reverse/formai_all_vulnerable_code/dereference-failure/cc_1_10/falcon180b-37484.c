//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_CHAR 1000

// function to read CSV file and store data in 2D array
int readCSV(char *filename, char **data) {
    FILE *fp;
    char line[MAX_CHAR];
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // read first line (header) and count number of columns
    fgets(line, MAX_CHAR, fp);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        col++;
        token = strtok(NULL, ",");
    }
    rewind(fp);

    // read data and store in 2D array
    *data = (char **) malloc(row * sizeof(char *));
    for (row = 0; row < MAX_ROW; row++) {
        (*data)[row] = (char *) malloc(col * sizeof(char));
        fgets(line, MAX_CHAR, fp);
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            strcpy((*data)[row] + j * MAX_CHAR, token);
            j++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return 0;
}

// function to print 2D array
void printArray(int row, int col, char **data) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", (*data)[i] + j * MAX_CHAR);
        }
        printf("\n");
    }
}

// main function
int main() {
    char **data;
    int status = readCSV("data.csv", &data);

    if (status == 0) {
        printArray(MAX_ROW, MAX_COL, data);
    } else {
        printf("Error: Failed to read CSV file.\n");
    }

    for (int i = 0; i < MAX_ROW; i++) {
        free((*data)[i]);
    }
    free(data);

    return 0;
}