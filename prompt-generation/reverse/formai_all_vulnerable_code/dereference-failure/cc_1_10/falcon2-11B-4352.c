//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int line_number;
    char* line_content;
} Line;

typedef struct {
    int num_lines;
    Line* lines;
} Log;

int main(int argc, char** argv) {
    Log* log = (Log*)malloc(sizeof(Log));
    log->num_lines = 0;
    log->lines = NULL;

    char* log_file = argv[1];
    FILE* file = fopen(log_file, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", log_file);
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        Line new_line = {0};
        new_line.line_number = log->num_lines;
        new_line.line_content = strdup(line);
        if (log->lines == NULL) {
            log->lines = (Line*)malloc(sizeof(Line));
            log->lines[0] = new_line;
        } else {
            Line* new_lines = (Line*)malloc(sizeof(Line));
            for (int i = 0; i < log->num_lines; i++) {
                new_lines[i] = log->lines[i];
            }
            new_lines[log->num_lines] = new_line;
            log->num_lines++;
            log->lines = new_lines;
        }
    }

    fclose(file);

    // Print out the log analysis report
    printf("Log Analysis Report:\n");
    printf("----------------------\n");
    printf("Number of Lines: %d\n", log->num_lines);
    printf("----------------------\n");

    for (int i = 0; i < log->num_lines; i++) {
        printf("Line %d: %s\n", log->lines[i].line_number, log->lines[i].line_content);
    }

    free(log->lines);
    free(log);

    return 0;
}