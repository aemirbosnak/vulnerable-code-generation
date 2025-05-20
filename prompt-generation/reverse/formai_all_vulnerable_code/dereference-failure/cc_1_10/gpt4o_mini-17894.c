//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FIELDS 100

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

char **parse_csv_line(char *line, int *num_fields) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    if (fields == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *field = strtok(line, ",");
    int count = 0;

    while (field != NULL) {
        fields[count] = malloc(strlen(field) + 1);
        if (fields[count] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(fields[count], field);
        count++;
        field = strtok(NULL, ",");
    }

    *num_fields = count;
    return fields;
}

void free_fields(char **fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        trim_newline(line);
        int num_fields = 0;
        char **fields = parse_csv_line(line, &num_fields);
        
        printf("Parsed line with %d fields:\n", num_fields);
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }
        
        free_fields(fields, num_fields);
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv_file(argv[1]);

    return EXIT_SUCCESS;
}