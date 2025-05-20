//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy little struct to hold a CSV row
typedef struct {
    char **columns;
    size_t num_columns;
} csv_row;

// A happy little function to free a CSV row
void free_csv_row(csv_row *row) {
    for (size_t i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

// A happy little function to read a CSV file
csv_row *read_csv_file(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the file contents
    size_t bytes_read = fread(file_contents, 1, file_size, file);
    if (bytes_read != file_size) {
        fclose(file);
        free(file_contents);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Null-terminate the file contents
    file_contents[file_size] = '\0';

    // Split the file contents into lines
    char **lines = NULL;
    size_t num_lines = 0;
    char *line = strtok(file_contents, "\n");
    while (line != NULL) {
        // Reallocate the lines array if necessary
        if (num_lines >= (size_t)lines) {
            size_t new_size = (num_lines + 1) * sizeof(char *);
            lines = realloc(lines, new_size);
            if (lines == NULL) {
                free(file_contents);
                return NULL;
            }
        }

        // Add the line to the lines array
        lines[num_lines++] = line;

        // Get the next line
        line = strtok(NULL, "\n");
    }

    // Split each line into columns
    csv_row *rows = malloc(num_lines * sizeof(csv_row));
    if (rows == NULL) {
        free(file_contents);
        free(lines);
        return NULL;
    }

    for (size_t i = 0; i < num_lines; i++) {
        // Get the line
        line = lines[i];

        // Split the line into columns
        char **columns = NULL;
        size_t num_columns = 0;
        char *column = strtok(line, ",");
        while (column != NULL) {
            // Reallocate the columns array if necessary
            if (num_columns >= (size_t)columns) {
                size_t new_size = (num_columns + 1) * sizeof(char *);
                columns = realloc(columns, new_size);
                if (columns == NULL) {
                    free(file_contents);
                    free(lines);
                    free(rows);
                    return NULL;
                }
            }

            // Add the column to the columns array
            columns[num_columns++] = column;

            // Get the next column
            column = strtok(NULL, ",");
        }

        // Add the row to the rows array
        rows[i].columns = columns;
        rows[i].num_columns = num_columns;
    }

    // Free the lines array
    free(lines);

    // Free the file contents
    free(file_contents);

    // Return the rows array
    return rows;
}

// A happy little function to print a CSV row
void print_csv_row(csv_row *row) {
    for (size_t i = 0; i < row->num_columns; i++) {
        printf("%s", row->columns[i]);
        if (i < row->num_columns - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// A happy little main function
int main() {
    // Read the CSV file
    csv_row *rows = read_csv_file("data.csv");
    if (rows == NULL) {
        printf("Error reading CSV file\n");
        return -1;
    }

    // Print the CSV rows
    for (size_t i = 0; i < (size_t)rows; i++) {
        print_csv_row(&rows[i]);
    }

    // Free the CSV rows
    for (size_t i = 0; i < (size_t)rows; i++) {
        free_csv_row(&rows[i]);
    }

    return 0;
}