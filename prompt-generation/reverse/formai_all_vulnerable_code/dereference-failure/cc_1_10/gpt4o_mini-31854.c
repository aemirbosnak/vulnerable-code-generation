//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

void free_memory(char **fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}

char **parse_csv_line(char *line, int *num_fields) {
    char **fields = malloc(MAX_FIELD_LENGTH * sizeof(char*));
    if (fields == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, ",");
    int count = 0;

    while (token != NULL) {
        fields[count] = malloc((strlen(token) + 1) * sizeof(char));
        if (fields[count] == NULL) {
            perror("Failed to allocate memory for field");
            free_memory(fields, count);
            exit(EXIT_FAILURE);
        }
        strcpy(fields[count], token);
        count++;
        token = strtok(NULL, ",");
    }

    *num_fields = count;
    return fields;
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int num_fields;
        char **fields = parse_csv_line(line, &num_fields);

        printf("Parsed line with %d fields:\n", num_fields);
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }

        free_memory(fields, num_fields);
    }

    if (fclose(file) != 0) {
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv_file(argv[1]);

    return EXIT_SUCCESS;
}