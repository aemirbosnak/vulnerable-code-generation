//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read CSV file and return a 2D array of strings
char **read_csv_file(FILE *fp) {
    int rows = 0, cols = 0;
    char ch;
    char **data = NULL;

    // Count number of rows and columns
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            rows++;
        }
        cols = (cols > 0)? cols : 1;
        cols += (ch == ',');
    }

    // Allocate memory for 2D array
    data = (char **) malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        data[i] = (char *) malloc((cols - 1) * sizeof(char));
    }

    // Read CSV file and fill 2D array
    rewind(fp);
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            rows++;
            cols = 0;
        } else if (ch == ',') {
            cols++;
        } else if (cols > 0) {
            data[rows - 1][cols - 1] = ch;
        }
    }

    // Close file pointer
    fclose(fp);

    return data;
}

// Function to print 2D array of strings
void print_array(int rows, int cols, char **data) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char **data;

    // Open CSV file
    fp = fopen("example.csv", "r");

    // Check if file is opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read CSV file and store in 2D array
    data = read_csv_file(fp);

    // Print 2D array
    printf("CSV data:\n");
    print_array(data[0], data[0][0] = '\0', data);

    // Free memory allocated for 2D array
    for (int i = 0; i < data[0]; i++) {
        free(data[i]);
    }
    free(data);

    // Close file pointer
    fclose(fp);

    return 0;
}