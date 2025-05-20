//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

typedef struct {
    char *line;
    int line_num;
} log_line;

int compare_log_lines(const void *a, const void *b) {
    log_line *l1 = (log_line *) a;
    log_line *l2 = (log_line *) b;
    return strcmp(l1->line, l2->line);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s logfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *logfile = fopen(argv[1], "r");
    if (logfile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 0;

    log_line *lines = NULL;
    int num_lines = 0;

    while ((read = getline(&line, &len, logfile)) != -1) {
        line_num++;
        lines = realloc(lines, (num_lines + 1) * sizeof(log_line));
        lines[num_lines].line = line;
        lines[num_lines].line_num = line_num;
        num_lines++;
        line = NULL;
        len = 0;
    }

    if (ferror(logfile)) {
        perror("getline");
        return EXIT_FAILURE;
    }

    fclose(logfile);

    qsort(lines, num_lines, sizeof(log_line), compare_log_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s", lines[i].line_num, lines[i].line);
        free(lines[i].line);
    }

    free(lines);

    return EXIT_SUCCESS;
}