//Falcon-180B DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
} FileContext;

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

void print_system_error(const char *message) {
    fprintf(stderr, "System error: %s\n", message);
}

void close_file(FileContext *context) {
    if (context->file!= NULL) {
        fclose(context->file);
        context->file = NULL;
    }
}

int open_file(const char *filename, FileContext *context) {
    context->filename = strdup(filename);
    context->file = fopen(filename, "r");

    if (context->file == NULL) {
        print_error("Failed to open file");
        return 1;
    }

    context->line_number = 0;
    return 0;
}

int read_line(FileContext *context, char *buffer, size_t buffer_size) {
    char *line = NULL;
    size_t line_length = 0;
    ssize_t bytes_read;

    while ((bytes_read = getline(&line, &line_length, context->file))!= -1) {
        if (bytes_read > 0 && line[bytes_read - 1] == '\n') {
            line[--bytes_read] = '\0';
        }

        if (bytes_read >= buffer_size) {
            print_error("Line too long");
            free(line);
            return 1;
        }

        strncpy(buffer, line, bytes_read);
        context->line_number++;
        free(line);
        return 0;
    }

    if (ferror(context->file)) {
        print_system_error("Error reading file");
        free(line);
        return 1;
    }

    free(line);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileContext context;
    if (open_file(argv[1], &context)) {
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    while (read_line(&context, buffer, sizeof(buffer))) {
        printf("%s:%d: %s", context.filename, context.line_number, buffer);
    }

    close_file(&context);
    return 0;
}