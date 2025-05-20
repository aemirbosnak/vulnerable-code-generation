//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_VALUE_SIZE 20

int main(void) {

    char file_name[MAX_VALUE_SIZE];
    char *column_names[MAX_COLUMNS];
    char *current_line = NULL;
    char *column_value = NULL;
    char *token = NULL;
    int number_of_columns = 0;
    int line_counter = 1;

    printf("Enter the name of the file to read:\n");
    scanf("%s", file_name);

    FILE *csv_file = fopen(file_name, "r");

    if (csv_file == NULL) {
        printf("Error opening the file\n");
        return 0;
    }

    current_line = malloc(sizeof(char) * MAX_VALUE_SIZE);

    if (fgets(current_line, MAX_VALUE_SIZE, csv_file) != NULL) {

        token = strtok(current_line, ",");
        
        while (token != NULL && number_of_columns < MAX_COLUMNS) {
            column_names[number_of_columns] = malloc(sizeof(char) * MAX_VALUE_SIZE);
            strncpy(column_names[number_of_columns], token, MAX_VALUE_SIZE);
            token = strtok(NULL, ",");
            number_of_columns++;
        }

    } else {
        printf("The file is empty\n");
        return 0;
    }

    while (fgets(current_line, MAX_VALUE_SIZE, csv_file) != NULL) {

        printf("Line %d:\n", line_counter);

        token = strtok(current_line, ",");

        for (int i = 0; i < number_of_columns && token != NULL; i++) {
            column_value = malloc(sizeof(char) * MAX_VALUE_SIZE);
            strncpy(column_value, token, MAX_VALUE_SIZE);
            printf("%s: %s\n", column_names[i], column_value);
            free(column_value);
            token = strtok(NULL, ",");
        }

        line_counter++;
    }

    for (int i = 0; i < number_of_columns; i++) {
        free(column_names[i]);
    }

    free(current_line);
    fclose(csv_file);

    return 0;
}