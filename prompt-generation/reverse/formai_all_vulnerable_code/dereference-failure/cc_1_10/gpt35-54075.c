//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold a CSV row
struct csv_row {
    char **columns;
    int num_columns;
};

// function to free a CSV row
void free_csv_row(struct csv_row *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

// recursive function to read a CSV file
struct csv_row *read_csv(FILE *file) {
    // allocate space for a row
    struct csv_row *row = malloc(sizeof(struct csv_row));

    // read a line from the file
    char line[1024];
    fgets(line, 1024, file);

    // count the number of commas in the line
    int num_columns = 0;
    char *ptr = line;
    while (*ptr != '\0') {
        if (*ptr == ',') {
            num_columns++;
        }
        ptr++;
    }
    num_columns++;

    // allocate space for the columns in the row
    row->columns = malloc(num_columns * sizeof(char *));
    row->num_columns = num_columns;

    // parse the line and assign the columns
    int i = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        // remove leading and trailing whitespace from the token
        char *trimmed = malloc(strlen(token) + 1);
        char *start = token;
        char *end = token + strlen(token) - 1;
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
            start++;
        }
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') {
            end--;
        }
        strncpy(trimmed, start, end - start + 1);
        trimmed[end - start + 1] = '\0';

        // assign the column value to the row
        row->columns[i] = trimmed;

        // get the next token
        token = strtok(NULL, ",");
        i++;
    }

    // read the next row recursively
    if (!feof(file)) {
        struct csv_row *next_row = read_csv(file);
        if (next_row->num_columns == num_columns) {
            // append the next row to the current row
            int new_num_columns = num_columns + next_row->num_columns;
            char **new_columns = malloc(new_num_columns * sizeof(char *));
            for (int j = 0; j < num_columns; j++) {
                new_columns[j] = row->columns[j];
            }
            for (int j = 0; j < next_row->num_columns; j++) {
                new_columns[num_columns + j] = next_row->columns[j];
            }
            free(row->columns);
            row->columns = new_columns;
            row->num_columns = new_num_columns;
        } else {
            free_csv_row(next_row);
        }
    }

    return row;
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct csv_row *row = read_csv(file);
    while (row != NULL) {
        for (int i = 0; i < row->num_columns; i++) {
            printf("%s,", row->columns[i]);
        }
        printf("\n");
        free_csv_row(row);
        row = read_csv(file);
    }

    fclose(file);
    return 0;
}