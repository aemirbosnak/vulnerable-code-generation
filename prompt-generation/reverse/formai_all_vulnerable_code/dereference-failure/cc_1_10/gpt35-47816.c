//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for max length of file path and line
#define FILE_PATH_MAX_LEN 200
#define LINE_MAX_LEN 200

// Helper function to parse the CSV file line
void parse_csv(char *line, char **cols, int num_cols) {
    int i = 0;
    char *col = strtok(line, ",");
    while (col != NULL && i<num_cols) {
        cols[i++] = col;
        col = strtok(NULL, ",");
    }
}

int main() {
    // Define variables to hold file path and line
    char file_path[FILE_PATH_MAX_LEN];
    char line[LINE_MAX_LEN];

    // Get file path from user
    printf("Enter file path: ");
    fgets(file_path, FILE_PATH_MAX_LEN, stdin);
    file_path[strcspn(file_path, "\n")] = '\0'; // remove newline character

    // Open the file for reading
    FILE *fp;
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", file_path);
        return 1;
    }

    // Read the first line to get column names
    fgets(line, LINE_MAX_LEN, fp);
    line[strcspn(line, "\n")] = '\0'; // remove newline character
    int num_cols = 0;
    char *col = strtok(line, ",");
    while (col != NULL) {
        num_cols++;
        col = strtok(NULL, ",");
    }

    // Reset file pointer and allocate memory for column names and values
    fseek(fp, 0, SEEK_SET);
    fgets(line, LINE_MAX_LEN, fp); // skip first line
    char **col_names = (char **) malloc(sizeof(char *) * num_cols);
    char **col_vals = (char **) malloc(sizeof(char *) * num_cols);
    for (int i = 0; i < num_cols; i++) {
        col_names[i] = (char *) malloc(sizeof(char) * LINE_MAX_LEN);
        col_vals[i] = (char *) malloc(sizeof(char) * LINE_MAX_LEN);
    }

    // Read the rest of the file and print each row
    while (fgets(line, LINE_MAX_LEN, fp)) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        parse_csv(line, col_vals, num_cols);
        for (int i = 0; i < num_cols; i++) {
            if (i == 0) {
                // First column is always integer
                int id = atoi(col_vals[i]);
                printf("ID: %d ", id);
            } else {
                // Other columns can be any data type
                strcpy(col_names[i], strtok(col_names[i], "\0"));
                printf("%s: %s ", col_names[i], col_vals[i]);
            }
        }
        printf("\n");
    }

    // Free memory and close file pointer
    for (int i = 0; i < num_cols; i++) {
        free(col_names[i]);
        free(col_vals[i]);
    }
    free(col_names);
    free(col_vals);
    fclose(fp);

    return 0;
}