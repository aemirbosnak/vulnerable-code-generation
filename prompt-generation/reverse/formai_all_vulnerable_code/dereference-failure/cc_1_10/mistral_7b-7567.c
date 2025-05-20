//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given character is a comma
int is_comma(char c) {
    return (c == ',');
}

// Function to check if a given character is a newline
int is_newline(char c) {
    return (c == '\n');
}

// Function to skip leading whitespaces
void skip_whitespace(FILE *file) {
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (!isspace(c)) {
            ungetc(c, file);
            break;
        }
    }
}

// Function to read a single string from CSV file
char *read_string(FILE *file) {
    int c, length = 0;
    char *string = malloc(1);

    while (!is_newline(c = fgetc(file))) {
        if (is_comma(c)) {
            string = realloc(string, length + 2);
            string[length++] = ',';
            string[length++] = '\0';
            break;
        }

        string = realloc(string, length + 2);
        string[length++] = c;
    }

    fseek(file, -1, SEEK_CUR); // move the file pointer back to the previous character
    return string;
}

// Function to read a single cell from CSV file
char **read_cell(FILE *file) {
    char *string = read_string(file);
    char **cell = malloc(sizeof(char *));
    *cell = strdup(string);
    free(string);
    return cell;
}

// Function to read an entire row from CSV file
char **read_row(FILE *file) {
    int cells = 0;
    char **row = NULL;

    while (!is_newline(fgetc(file))) {
        if (cells == 0) {
            row = realloc(row, sizeof(char *) * (cells + 1));
            row[cells++] = read_cell(file);
        }
    }

    fgetc(file); // consume the newline character
    return row;
}

// Function to free an entire row from CSV file
void free_row(char **row, int size) {
    for (int i = 0; i < size; i++) {
        free(row[i]);
    }

    free(row);
}

// Function to read an entire CSV file
char **read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    int rows = 0;
    char **data = NULL;

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        return NULL;
    }

    while (!feof(file)) {
        data = realloc(data, sizeof(char *) * (rows + 1));
        data[rows++] = read_row(file);
    }

    fclose(file);
    return data;
}

// Function to print an entire CSV row
void print_row(char **row, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s, ", row[i]);
    }

    printf("\n");
}

// Main function to read and print a CSV file
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <csv-file>\n", argv[0]);
        return 1;
    }

    char **data = read_csv(argv[1]);

    if (data == NULL) {
        return 1;
    }

    for (int i = 0; i < data[0] ? data[0][0] : 0; i++) {
        print_row(data[i], data[i] ? data[i][0] : 0);
        free_row(data[i], data[i] ? data[i][0] : 0);
    }

    free(data);
    return 0;
}