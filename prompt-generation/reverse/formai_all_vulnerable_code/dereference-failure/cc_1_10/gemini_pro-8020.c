//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVReader {
    FILE *file;
    char *line;
    size_t line_size;
    char *field;
    size_t field_size;
    int field_count;
    int line_count;
} CSVReader;

CSVReader *CSVReader_new(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = file;
    reader->line = NULL;
    reader->line_size = 0;
    reader->field = NULL;
    reader->field_size = 0;
    reader->field_count = 0;
    reader->line_count = 0;
    return reader;
}

void CSVReader_free(CSVReader *reader) {
    if (reader->line != NULL) {
        free(reader->line);
    }
    if (reader->field != NULL) {
        free(reader->field);
    }
    free(reader);
}

int CSVReader_next_line(CSVReader *reader) {
    if (reader->line != NULL) {
        free(reader->line);
    }
    reader->line = NULL;
    reader->line_size = 0;
    reader->field_count = 0;
    reader->field = NULL;
    reader->field_size = 0;

    char c;
    while ((c = fgetc(reader->file)) != EOF) {
        if (c == '\n') {
            reader->line_count++;
            return 1;
        } else if (c == '"') {
            while ((c = fgetc(reader->file)) != EOF) {
                if (c == '"') {
                    if ((c = fgetc(reader->file)) == '"') {
                        // Escaped quote
                        strncat(reader->line, "\"", 1);
                    } else {
                        // End of field
                        reader->field_count++;
                        return 1;
                    }
                } else {
                    // Normal character
                    strncat(reader->line, &c, 1);
                }
            }
            return 0; // End of file
        } else {
            strncat(reader->line, &c, 1);
        }
    }
    return 0; // End of file
}

char *CSVReader_next_field(CSVReader *reader) {
    if (reader->field != NULL) {
        free(reader->field);
    }
    reader->field = NULL;
    reader->field_size = 0;

    char c;
    while ((c = fgetc(reader->file)) != EOF) {
        if (c == ',') {
            reader->field_count++;
            return reader->field;
        } else if (c == '\n') {
            reader->line_count++;
            return reader->field;
        } else {
            strncat(reader->field, &c, 1);
        }
    }
    return reader->field; // End of file
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    CSVReader *reader = CSVReader_new(file);
    while (CSVReader_next_line(reader)) {
        printf("Line %d: ", reader->line_count);
        char *field;
        while ((field = CSVReader_next_field(reader)) != NULL) {
            printf("%s ", field);
        }
        printf("\n");
    }

    CSVReader_free(reader);
    fclose(file);

    return EXIT_SUCCESS;
}