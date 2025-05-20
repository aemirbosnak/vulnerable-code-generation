//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 1024

/* CSV reader struct */
typedef struct {
    char *line;
    char *field;
    int field_count;
    int line_len;
    int field_len;
} csv_reader;

/* Initialize CSV reader */
void csv_init(csv_reader *reader, char *file_path) {
    reader->line = malloc(LINE_LEN);
    reader->field = malloc(LINE_LEN);
    reader->field_count = 0;
    reader->line_len = 0;
    reader->field_len = 0;
    /* Read CSV file */
    FILE *csv_file = fopen(file_path, "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error opening CSV file.\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(reader->line, LINE_LEN, csv_file)) {
        /* Remove newline character */
        reader->line_len = strlen(reader->line);
        if (reader->line[reader->line_len - 1] == '\n') {
            reader->line[reader->line_len - 1] = '\0';
            reader->line_len--;
        }
        /* Split fields */
        char *saveptr;
        char *token = strtok_r(reader->line, ",", &saveptr);
        while (token != NULL) {
            reader->field_len = strlen(token);
            if (reader->field_len > LINE_LEN) {
                fprintf(stderr, "Field length exceeds line length.\n");
                exit(EXIT_FAILURE);
            }
            strncpy(reader->field, token, reader->field_len);
            reader->field_count++;
            /* Do something with the field */
            printf("Field %d: %s\n", reader->field_count, reader->field);
            token = strtok_r(NULL, ",", &saveptr);
        }
    }
    fclose(csv_file);
}

int main(int argc, char **argv) {
    /* Check usage */
    if (argc != 2) {
        fprintf(stderr, "Usage: ./csv_reader <file_path>\n");
        exit(EXIT_FAILURE);
    }
    /* Initialize CSV reader */
    csv_reader reader;
    csv_init(&reader, argv[1]);
    /* Clean up */
    free(reader.line);
    free(reader.field);
    return 0;
}