//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_rows;
    int num_columns;
    char **data;
} Table;

int main() {
    Table *table = NULL;
    char input[MAX_NAME_LENGTH];
    int rows, cols, i, j;

    // Get table name from user
    printf("Enter table name: ");
    scanf("%s", input);

    // Create table with given name
    table = (Table *)malloc(sizeof(Table));
    strcpy(table->name, input);
    table->num_rows = 0;
    table->num_columns = 0;
    table->data = NULL;

    // Get number of rows and columns from user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Initialize table with empty cells
    table->num_rows = rows;
    table->num_columns = cols;
    table->data = (char **)malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        table->data[i] = (char *)malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            table->data[i][j] = '\0';
        }
    }

    // Get data from user and store in table
    printf("Enter data:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%c", &table->data[i][j]);
        }
    }

    // Print table
    printf("\n%s:\n", table->name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);

    return 0;
}