//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold data from each row
typedef struct Row {
    int id;
    char name[50];
    float score;
} Row;

// Define a function to parse a row from a string
Row parse_row(char* row_str) {
    Row row;
    char* token;
    int i = 0;

    // Split the string by commas
    token = strtok(row_str, ",");
    row.id = atoi(token);

    token = strtok(NULL, ",");
    strcpy(row.name, token);

    token = strtok(NULL, ",");
    row.score = atof(token);

    return row;
}

// Define a function to read the entire CSV file into an array of Rows
Row* read_csv(char* filename, int* num_rows) {
    Row* rows = (Row*)malloc(sizeof(Row) * 10);
    FILE* fptr;
    char buffer[1024];

    *num_rows = 0;

    // Open the file for reading
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    // Read each line of the file into a Row struct
    while (fgets(buffer, 1024, fptr) != NULL) {
        // If the array is full, reallocate it
        if (*num_rows % 10 == 0 && *num_rows > 0) {
            rows = (Row*)realloc(rows, sizeof(Row) * (*num_rows + 10));
        }

        Row row = parse_row(buffer);
        rows[*num_rows] = row;
        (*num_rows)++;
    }

    // Close the file and return the array of Rows
    fclose(fptr);
    return rows;
}

int main() {
    int num_rows;
    Row* rows = read_csv("data.csv", &num_rows);

    if (rows == NULL) {
        return 1;
    }

    // Print out each row in the array
    for (int i = 0; i < num_rows; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", rows[i].id, rows[i].name, rows[i].score);
    }

    free(rows);
    return 0;
}