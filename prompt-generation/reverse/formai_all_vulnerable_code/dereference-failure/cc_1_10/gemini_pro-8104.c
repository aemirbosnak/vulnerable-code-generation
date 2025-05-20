//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *line;
    int line_number;
} LogLine;

int compare_log_lines(const void *a, const void *b) {
    LogLine *log_line_a = (LogLine *)a;
    LogLine *log_line_b = (LogLine *)b;

    return strcmp(log_line_a->line, log_line_b->line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s log_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t line_size = 0;
    int line_number = 0;

    while (getline(&line, &line_size, log_file) != -1) {
        line_number++;

        LogLine *log_line = malloc(sizeof(LogLine));
        log_line->line = line;
        log_line->line_number = line_number;

        line = NULL;
        line_size = 0;

        printf("%d: %s", log_line->line_number, log_line->line);

        free(log_line);
    }

    free(line);

    fclose(log_file);

    return EXIT_SUCCESS;
}