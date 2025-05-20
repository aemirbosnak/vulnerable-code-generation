//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 8192

typedef struct line_tag {
    char str[MAX_LINE_LENGTH];
    struct line_tag *next;
} line_t;

line_t *head = NULL;
line_t *current = NULL;

void read_file(const char *filename);
void write_file(const char *filename);
void free_memory(void);
int is_duplicate(const char *line);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_file(argv[1]);
    write_file(argv[2]);
    free_memory();

    return EXIT_SUCCESS;
}

void read_file(const char *filename) {
    FILE *input_file = fopen(filename, "r");

    if (input_file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t read_bytes;

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        size_t line_length = 0;
        char *line_start = buffer;

        while (line_length < read_bytes && (line_start[line_length] != '\n' && line_start[line_length] != '\0')) {
            line_length++;
        }

        if (line_length > 0) {
            line_t *new_line = (line_t *) malloc(sizeof(line_t));
            if (new_line == NULL) {
                perror("Memory allocation failed");
                fclose(input_file);
                return;
            }

            strncpy(new_line->str, line_start, line_length + 1);
            new_line->next = head;
            head = new_line;
        }
    }

    fclose(input_file);
}

void write_file(const char *filename) {
    if (head == NULL) {
        return;
    }

    FILE *output_file = fopen(filename, "w");

    if (output_file == NULL) {
        perror("Error opening file for writing");
        free_memory();
        return;
    }

    current = head;
    while (current != NULL) {
        if (!is_duplicate(current->str)) {
            fputs(current->str, output_file);
        }

        current = current->next;
    }

    fclose(output_file);
}

void free_memory(void) {
    line_t *next_line = NULL;
    current = head;

    while (current != NULL) {
        next_line = current->next;
        free(current);
        current = next_line;
    }
}

int is_duplicate(const char *line) {
    current = head;

    while (current != NULL) {
        if (strcmp(current->str, line) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}