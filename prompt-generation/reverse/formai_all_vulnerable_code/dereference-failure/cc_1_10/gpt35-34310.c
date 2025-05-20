//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
// Sherlock Holmes style CSV Reader program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold CSV data
typedef struct {
    char **rows; // array of strings for each row
    int num_rows; // number of rows in the file
    int num_columns; // number of fields in each row
} CSVData;

CSVData read_csv(const char *filename) {
    FILE *csvfile = fopen(filename, "r");

    if (!csvfile) {
        printf("File %s not found!", filename);
        exit(EXIT_FAILURE);
    }

    // Declare a CSV data structure to return
    CSVData data;

    // Count number of rows and columns in the file
    data.num_rows = 0;
    char line[1024]; // Assume no line is longer than 1024 characters
    while (fgets(line, 1024, csvfile)) {
        data.num_rows++;
        // Parse the line to count the number of fields
        char *field = strtok(line, ",");
        int num_fields = 0;
        while (field) {
            num_fields++;
            field = strtok(NULL, ",");
        }
        // If this is the first row, set the number of columns
        if (data.num_rows == 1) {
            data.num_columns = num_fields;
        } else if (num_fields != data.num_columns) {
            printf("File %s has inconsistent number of fields!", filename);
            exit(EXIT_FAILURE);
        }
    }

    // Allocate memory for the CSV data
    data.rows = malloc(data.num_rows * sizeof(char *));
    for (int i = 0; i < data.num_rows; i++) {
        data.rows[i] = malloc((data.num_columns + 1) * sizeof(char));
        memset(data.rows[i], 0, (data.num_columns + 1) * sizeof(char));
    }

    // Rewind the file pointer to read the data
    rewind(csvfile);

    // Read all rows of the CSV file
    int row = 0;
    while (fgets(line, 1024, csvfile)) {
        // Remove newline character if present
        char *pos = strchr(line, '\n');
        if (pos) {
            *pos = '\0';
        }
        // Parse the line and copy fields to data structure
        char *field = strtok(line, ",");
        int col = 0;
        while (field) {
            strcpy(data.rows[row] + col*(data.num_columns+1), field);
            col++;
            field = strtok(NULL, ",");
        }
        row++;
    }

    // Close the file and return the CSV data
    fclose(csvfile);

    return data;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        return 1;
    }

    CSVData data = read_csv(argv[1]);

    printf("CSV file %s has %d rows and %d columns\n", argv[1], data.num_rows, data.num_columns);

    // Print the CSV data to console
    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_columns; j++) {
            printf("%s, ", data.rows[i] + j*(data.num_columns+1));
        }
        printf("\n");
    }

    // Free memory allocated for CSV data
    for (int i = 0; i < data.num_rows; i++) {
        free(data.rows[i]);
    }
    free(data.rows);

    return 0;
}