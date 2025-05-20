//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 64

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV_Table;

CSV_Table* create_table(int rows, int cols) {
    CSV_Table *table = malloc(sizeof(CSV_Table));
    table->data = malloc(rows * sizeof(char*));
    
    for (int i = 0; i < rows; i++) {
        table->data[i] = malloc(cols * MAX_LINE_LENGTH); // Memory for each row
    }
    
    table->rows = rows;
    table->cols = cols;
    
    return table;
}

void destroy_table(CSV_Table *table) {
    for (int i = 0; i < table->rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

char** split_line(const char *line, int *num_columns) {
    char **columns = malloc(MAX_COLUMNS * sizeof(char*));
    char *token;
    char *line_copy = strdup(line);
    char *rest = line_copy;
    *num_columns = 0;

    while ((token = strtok_r(rest, ",", &rest))) {
        columns[*num_columns] = strdup(token);
        (*num_columns)++;
    }

    free(line_copy);
    return columns;
}

CSV_Table* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    CSV_Table *table = create_table(100, MAX_COLUMNS); // Arbitrarily large table
    char line[MAX_LINE_LENGTH];
    int row = 0;
    
    while (fgets(line, sizeof(line), file)) {
        int cols;
        char **columns = split_line(line, &cols);
        
        for (int col = 0; col < cols; col++) {
            strcpy(&table->data[row][col * MAX_LINE_LENGTH], columns[col]);
            free(columns[col]);
        }
        
        row++;
        free(columns);
    }
    
    table->rows = row; // Update the actual number of rows read
    fclose(file);
    
    return table;
}

void print_table(CSV_Table *table) {
    printf("Table of Surrealism:\n");
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (strlen(&table->data[i][j * MAX_LINE_LENGTH]) > 0) {
                printf("%s ", &table->data[i][j * MAX_LINE_LENGTH]);
            }
        }
        printf("\n");
    }
}

void dance_with_data(const CSV_Table *table) {
    printf("\nA surrealist dance begins with the data:\n");

    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            if (strlen(&table->data[i][j * MAX_LINE_LENGTH]) > 0) {
                printf("* %s * ", &table->data[i][j * MAX_LINE_LENGTH]);
                for (int k = 0; k < rand() % 5; k++) {
                    printf("~ ");
                }
            }
        }
        printf("\n");
    }
    printf("The dance concludes, leaving echoes of data in the air.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSV_Table *table = read_csv(argv[1]);
    print_table(table);
    dance_with_data(table);
    
    destroy_table(table);
   
    return EXIT_SUCCESS;
}