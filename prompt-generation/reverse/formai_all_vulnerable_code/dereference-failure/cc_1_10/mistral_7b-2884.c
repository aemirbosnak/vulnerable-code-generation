//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_LOG_FILES 100
#define MAX_LINE_LENGTH 1024
#define FIELD_COUNT 6

typedef struct {
    char log_file[MAX_LINE_LENGTH];
    int requests;
    int errors;
    int bytes;
    double average_time;
    double max_time;
} LogAnalyzer;

void parse_log_line(const char *line, LogAnalyzer *analyzer) {
    char field[MAX_LINE_LENGTH];
    char *token;
    int index = 0;

    memset(field, 0, MAX_LINE_LENGTH);

    token = strtok(line, " ");
    strcpy(analyzer->log_file, token);

    for (int i = 0; i < FIELD_COUNT - 1; i++) {
        token = strtok(NULL, " ");
        if (token) {
            if (i == 2) {
                analyzer->requests++;
            } else if (i == 3) {
                analyzer->errors += atoi(token);
            } else if (i == 5) {
                analyzer->bytes += atol(token);
            }

            token = strtok(NULL, " ");
            if (token) {
                if (i == 4) {
                    analyzer->average_time += atof(token);
                    analyzer->max_time = fmax(analyzer->max_time, atof(token));
                }

                index = strlen(token);
                if (index > analyzer->log_file[strlen(analyzer->log_file) - 1] - index - 1) {
                    analyzer->log_file[strlen(analyzer->log_file) - 1] = '\0';
                    strcat(analyzer->log_file, token);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    LogAnalyzer analyzers[MAX_LOG_FILES];
    char line[MAX_LINE_LENGTH];
    FILE *file;
    int num_files = 0;

    if (argc < 2) {
        printf("Usage: %s <log_file> [<log_file> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file) {
            if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
                parse_log_line(line, &analyzers[num_files]);

                while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
                    parse_log_line(line, &analyzers[num_files]);
                }

                fclose(file);
                num_files++;
            }
        }
    }

    printf("Analysis results:\n");

    for (int i = 0; i < num_files; i++) {
        printf("Log file: %s\n", analyzers[i].log_file);
        printf("Requests: %d\n", analyzers[i].requests);
        printf("Errors: %d\n", analyzers[i].errors);
        printf("Bytes: %lld\n", analyzers[i].bytes);
        printf("Average time: %.2f ms\n", analyzers[i].average_time * 1000.0);
        printf("Max time: %.2f ms\n\n", analyzers[i].max_time * 1000.0);
    }

    return 0;
}