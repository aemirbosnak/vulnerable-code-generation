//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function to split a string by delimiter
char **split_string(const char *str, const char *delimiter, int *count) {
    char *str_copy = strdup(str); // Duplicate string for manipulation
    char *token;
    char **result = malloc(MAX_COLUMNS * sizeof(char *));
    if (result == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    token = strtok(str_copy, delimiter);
    *count = 0;

    while (token != NULL) {
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }

    free(str_copy);
    return result;
}

// Function to free the split string
void free_split_string(char **array, int count) {
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

// Function to read a CSV file and print its contents
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int column_count;

    // Print header
    if (fgets(line, sizeof(line), file) != NULL) {
        char **header = split_string(line, ",", &column_count);
        printf("Header:\n");
        for (int i = 0; i < column_count; i++) {
            printf("%s ", header[i]);
        }
        printf("\n\n");
        free_split_string(header, column_count);
    }

    // Print data
    printf("Data:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        char **columns = split_string(line, ",", &column_count);
        for (int i = 0; i < column_count; i++) {
            printf("%s ", columns[i]);
        }
        printf("\n");
        free_split_string(columns, column_count);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);
    return EXIT_SUCCESS;
}