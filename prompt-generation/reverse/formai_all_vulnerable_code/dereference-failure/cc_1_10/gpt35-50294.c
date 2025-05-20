//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
/*
* CSV Reader Example Program
* by Chatbot
* This program reads a CSV file and prints out the contents to the console
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** columns;
    size_t num_columns;
    char*** rows; 
    size_t num_rows;
} CSV;

void destroy_csv(CSV* csv) {
    for (size_t i = 0; i < csv->num_columns; i++) {
        free(csv->columns[i]);
    }
    free(csv->columns);
    for (size_t i = 0; i < csv->num_rows; i++) {
        for (size_t j = 0; j < csv->num_columns; j++) {
            free(csv->rows[i][j]);
        }
        free(csv->rows[i]);
    }
    free(csv->rows);
}

char* strdup(const char* str) { // implement strdup since it's not present in ANSI C
    size_t len = strlen(str) + 1;
    char* new_str = malloc(len);
    if (new_str) {
        memcpy(new_str, str, len);
    }
    return new_str;
}

void parse_csv_line(char* line, char*** row, size_t num_columns) {
    size_t j;
    for (j = 0; j < num_columns - 1; j++) {
        char* comma_pos = strchr(line, ',');
        if (comma_pos == NULL) {
            break;
        }
        size_t len = comma_pos - line;
        (*row)[j] = strndup(line, len);
        line += len + 1;
    }
    (*row)[j] = strdup(line);
}

CSV* read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    CSV* csv = malloc(sizeof(CSV));
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    if ((read = getline(&line, &len, file)) != -1) { // read column names from first line of CSV
        line[read - 1] = '\0'; // remove newline character
        char* token, *saveptr;
        size_t num_columns = 0;
        token = strtok_r(line, ",", &saveptr);
        while (token != NULL) { // count number of columns
            num_columns++;
            token = strtok_r(NULL, ",", &saveptr);
        }
        csv->columns = malloc(num_columns * sizeof(char*));
        csv->num_columns = num_columns;
        size_t i = 0;
        token = strtok_r(line, ",", &saveptr);
        while (token != NULL) { // store column names
            csv->columns[i] = strdup(token);
            i++;
            token = strtok_r(NULL, ",", &saveptr);
        }
    }
    size_t num_rows = 0;
    while ((read = getline(&line, &len, file)) != -1) { // read rows from CSV
        num_rows++;
    }
    csv->num_rows = num_rows;
    csv->rows = malloc(num_rows * sizeof(char**));
    fseek(file, 0L, SEEK_SET);
    getline(&line, &len, file); // discard first line
    for (size_t i = 0; i < num_rows; i++) {
        getline(&line, &len, file);
        line[read - 1] = '\0'; // remove newline character
        char** row = malloc(csv->num_columns * sizeof(char*));
        csv->rows[i] = row;
        parse_csv_line(line, &row, csv->num_columns);
    }
    fclose(file);
    return csv;
}

int main() {
    CSV* csv = read_csv("example.csv");
    if (csv == NULL) {
        printf("Failed to read CSV file\n");
        return 1;
    }
    for (size_t i = 0; i < csv->num_columns; i++) {
        printf("%s\t", csv->columns[i]);
    }
    printf("\n");
    for (size_t i = 0; i < csv->num_rows; i++) {
        for (size_t j = 0; j < csv->num_columns; j++) {
            printf("%s\t", csv->rows[i][j]);
        }
        printf("\n");
    }
    destroy_csv(csv);
    return 0;
}