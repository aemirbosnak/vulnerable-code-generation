//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

char **parse_csv_line(const char *line, int *num_fields) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char *field = malloc(MAX_FIELD_LENGTH);
    int index = 0;

    const char *ptr = line;
    while (*ptr) {
        if (*ptr == ',') {
            field[index] = '\0';
            fields[*num_fields] = strdup(field);
            (*num_fields)++;
            index = 0;
        } else {
            field[index++] = *ptr;
        }
        ptr++;
    }
    field[index] = '\0'; // Last field
    fields[*num_fields] = strdup(field);
    (*num_fields)++;
    
    free(field);
    return fields;
}

void free_fields(char **fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];    
    while (fgets(line, sizeof(line), file)) {
        int num_fields = 0;
        char **fields = parse_csv_line(line, &num_fields);
        
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }

        free_fields(fields, num_fields);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    read_csv(filename);

    return EXIT_SUCCESS;
}