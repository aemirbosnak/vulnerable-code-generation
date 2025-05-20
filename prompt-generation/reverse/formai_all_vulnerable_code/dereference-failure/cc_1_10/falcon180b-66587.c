//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *data;
    size_t length;
} Line;

typedef struct {
    FILE *file;
    Line *lines;
    size_t line_count;
    size_t file_size;
} FileData;

FileData *open_file(const char *filename) {
    FileData *file_data = malloc(sizeof(FileData));
    if (file_data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    file_data->file = fopen(filename, "r");
    if (file_data->file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        free(file_data);
        exit(1);
    }

    file_data->lines = NULL;
    file_data->line_count = 0;
    file_data->file_size = 0;

    return file_data;
}

void close_file(FileData *file_data) {
    if (file_data->lines!= NULL) {
        for (size_t i = 0; i < file_data->line_count; i++) {
            free(file_data->lines[i].data);
        }
        free(file_data->lines);
    }

    fclose(file_data->file);
    free(file_data);
}

void read_file(FileData *file_data) {
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file_data->file)!= NULL) {
        size_t line_length = strlen(buffer);
        if (line_length > 0 && buffer[line_length - 1] == '\n') {
            buffer[--line_length] = '\0';
        }

        Line *new_line = malloc(sizeof(Line));
        if (new_line == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }

        new_line->data = strdup(buffer);
        new_line->length = line_length;

        file_data->lines = realloc(file_data->lines, sizeof(Line) * ++file_data->line_count);
        file_data->lines[file_data->line_count - 1] = *new_line;
    }

    file_data->file_size = ftell(file_data->file);
    rewind(file_data->file);
}

void print_file(FileData *file_data) {
    for (size_t i = 0; i < file_data->line_count; i++) {
        printf("%zu: %.*s\n", i + 1, file_data->lines[i].length, file_data->lines[i].data);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileData *file_data = open_file(argv[1]);
    if (file_data == NULL) {
        return 1;
    }

    read_file(file_data);
    print_file(file_data);

    close_file(file_data);

    return 0;
}