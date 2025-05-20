//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 128

// define a struct to store CSV data
typedef struct {
    int num_fields;
    char *field_names[MAX_NUM_FIELDS];
    char *field_values[MAX_NUM_FIELDS];
} csv_row_t;

// function to print the CSV data
void print_csv_data(csv_row_t *row) {
    printf("Number of fields: %d\n", row->num_fields);
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s: %s\n", row->field_names[i], row->field_values[i]);
    }
}

// function to parse a CSV row and store the data in a struct
void parse_csv_row(char *line, csv_row_t *row, char *delimiter) {
    char *field;
    row->num_fields = 0;
    field = strtok(line, delimiter);
    while (field != NULL) {
        row->field_values[row->num_fields] = field;
        row->num_fields++;
        field = strtok(NULL, delimiter);
    }
}

int main(int argc, char *argv[]) {
    char filename[MAX_LINE_SIZE];
    char delimiter[MAX_LINE_SIZE];
    printf("Enter the CSV filename: ");
    fgets(filename, MAX_LINE_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove '\n' character
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    printf("Enter the delimiter character: ");
    fgets(delimiter, MAX_LINE_SIZE, stdin);
    delimiter[strcspn(delimiter, "\n")] = '\0'; // remove '\n' character
    csv_row_t row;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {
        line[strcspn(line, "\n")] = '\0'; // remove '\n' character
        parse_csv_row(line, &row, delimiter);
        print_csv_data(&row);
        if (row.num_fields == 0) {
            printf("Error: invalid CSV format\n");
            return 1;
        }
    }
    fclose(file);
    return 0;
}