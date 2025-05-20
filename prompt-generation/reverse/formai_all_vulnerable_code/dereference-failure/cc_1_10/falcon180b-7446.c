//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 1000

// Function to read CSV file and return a 2D array of strings
char **read_csv_file(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    char **data = NULL;
    int rows = 0;
    int cols = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while ((getline(&line, &len, fp))!= -1) {
        if (rows == 0) {
            // Count number of columns in the first row
            int i = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                if (i == MAX_COL_SIZE) {
                    printf("Error: Too many columns in file %s\n", filename);
                    exit(1);
                }
                cols++;
                i++;
                token = strtok(NULL, ",");
            }
        }
        rows++;
    }

    fclose(fp);

    // Allocate memory for 2D array
    data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        data[i] = (char *)malloc((cols + 1) * sizeof(char));
    }

    rewind(fp);

    // Read data from file and store in 2D array
    for (int i = 0; i < rows; i++) {
        if (getline(&line, &len, fp)!= -1) {
            int j = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                if (j == MAX_COL_SIZE) {
                    printf("Error: Too many columns in file %s\n", filename);
                    exit(1);
                }
                strcpy(data[i] + j * MAX_ROW_SIZE, token);
                j++;
                token = strtok(NULL, ",");
            }
        } else {
            printf("Error: Not enough rows in file %s\n", filename);
            exit(1);
        }
    }

    return data;
}

// Function to print 2D array of strings
void print_array(char **data, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i] + j * MAX_ROW_SIZE);
        }
        printf("\n");
    }
}

int main() {
    char **data;
    char *filename = "example.csv";

    data = read_csv_file(filename);
    if (data == NULL) {
        return 1;
    }

    print_array(data, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", toupper(data[i][j]));
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}