//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
    int error_count;
    int warning_count;
} LogFile;

void init_log_file(LogFile *log_file, char *filename) {
    log_file->filename = filename;
    log_file->file = fopen(filename, "r");
    log_file->line_count = 0;
    log_file->error_count = 0;
    log_file->warning_count = 0;
}

void close_log_file(LogFile *log_file) {
    fclose(log_file->file);
}

int count_lines(LogFile *log_file) {
    return log_file->line_count;
}

int count_errors(LogFile *log_file) {
    return log_file->error_count;
}

int count_warnings(LogFile *log_file) {
    return log_file->warning_count;
}

char *read_line(LogFile *log_file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (log_file->line_count >= MAX_LOG_SIZE) {
        fprintf(stderr, "Error: Maximum log size exceeded.\n");
        exit(1);
    }

    read = getline(&line, &len, log_file->file);
    if (read <= 0) {
        if (ferror(log_file->file)) {
            perror("Error");
            exit(1);
        }
        if (feof(log_file->file)) {
            fprintf(stderr, "Warning: End of file reached.\n");
        }
    } else {
        log_file->line_count++;
        if (strstr(line, "ERROR")) {
            log_file->error_count++;
        } else if (strstr(line, "WARNING")) {
            log_file->warning_count++;
        }
    }

    return line;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    LogFile log_file;
    init_log_file(&log_file, argv[1]);

    char *line;
    while ((line = read_line(&log_file))!= NULL) {
        printf("%s", line);
    }

    close_log_file(&log_file);

    return 0;
}