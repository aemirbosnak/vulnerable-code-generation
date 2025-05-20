//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1024

typedef struct {
    char *data;
    int rows;
    int cols;
} Data;

int main() {
    Data db;
    db.data = malloc(MAX_DATA_SIZE);
    db.rows = 0;
    db.cols = 0;

    // Initialize the database with some data
    char data[] = "John,Doe,25,Male\nJane,Doe,30,Female\nBob,Smith,40,Male\n";
    strcpy(db.data, data);
    db.rows = 3;
    db.cols = 4;

    // Print the database
    printf("Database:\n");
    for (int i = 0; i < db.rows; i++) {
        printf("%s\n", db.data + i * db.cols);
    }

    // Query the database for all rows where the age is greater than or equal to 30
    char query[] = "SELECT * FROM database WHERE age >= 30";
    int rows_selected = 0;
    char *result_data = malloc(MAX_DATA_SIZE);
    result_data[0] = '\0'; // Initialize the result data to an empty string

    char *token = strtok(query, " ");
    while (token!= NULL) {
        if (strcmp(token, "SELECT") == 0) {
            rows_selected = 1;
        } else if (strcmp(token, "FROM") == 0) {
            // Do nothing
        } else if (strcmp(token, "WHERE") == 0) {
            // Do nothing
        } else {
            // This is a column name, add it to the result data
            strcat(result_data, token);
            strcat(result_data, ",");
        }
        token = strtok(NULL, " ");
    }
    strcat(result_data, "\n");

    // Loop through the database and select the rows that match the query
    int result_rows = 0;
    char *result = malloc(MAX_DATA_SIZE);
    result[0] = '\0'; // Initialize the result data to an empty string

    char *line = strtok(db.data, "\n");
    while (line!= NULL) {
        int age = atoi(strtok(line, ","));
        if (age >= 30) {
            strcat(result, line);
            strcat(result, "\n");
            result_rows++;
        }
        line = strtok(NULL, "\n");
    }

    // Print the query result
    printf("Query result:\n");
    printf("%s\n", result);

    // Print the number of rows selected
    if (rows_selected) {
        printf("Number of rows selected: %d\n", result_rows);
    } else {
        printf("No rows selected.\n");
    }

    free(db.data);
    free(result_data);
    free(result);

    return 0;
}