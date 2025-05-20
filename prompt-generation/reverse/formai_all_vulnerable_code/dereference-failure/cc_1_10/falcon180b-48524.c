//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 100

struct log_file {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    time_t last_modified;
};

struct log_file log_files[MAX_LOG_FILES];
int num_log_files = 0;

void add_log_file(char *filename) {
    if (num_log_files >= MAX_LOG_FILES) {
        printf("Error: Too many log files.\n");
        exit(1);
    }

    log_files[num_log_files].fp = fopen(filename, "r");
    if (log_files[num_log_files].fp == NULL) {
        printf("Error: Could not open log file '%s'.\n", filename);
        exit(1);
    }

    fseek(log_files[num_log_files].fp, 0, SEEK_END);
    log_files[num_log_files].last_modified = time(NULL);
    num_log_files++;
}

void print_log_files() {
    printf("Log files:\n");
    for (int i = 0; i < num_log_files; i++) {
        printf("%s (%ld bytes, last modified %s)\n", log_files[i].filename, ftell(log_files[i].fp), ctime(&log_files[i].last_modified));
    }
}

void search_log_files(char *pattern) {
    for (int i = 0; i < num_log_files; i++) {
        rewind(log_files[i].fp);
        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, log_files[i].fp)!= NULL) {
            if (strstr(line, pattern)!= NULL) {
                printf("%s: %s", log_files[i].filename, line);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <log_file> <search_pattern>\n", argv[0]);
        return 1;
    }

    add_log_file(argv[1]);

    search_log_files(argv[2]);

    return 0;
}