//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LOG_FILE "happylogs.txt"
#define BUFFER_SIZE 256

void print_line(char *line) {
    printf("%s\n", line);
}

int main() {
    FILE *log_file;
    char buffer[BUFFER_SIZE];
    int line_number = 0;

    log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", LOG_FILE);
        return 1;
    }

    printf("\n===== Happy Log Analyzer =====\n");
    printf("===============================\n");

    while (fgets(buffer, BUFFER_SIZE, log_file) != NULL) {
        line_number++;
        char *level = strtok(buffer, " ");
        level[strcspn(level, "\n")] = 0;

        if (strcmp(level, "INFO") == 0) {
            printf("Line %d: Happy Info: %s\n", line_number, buffer);
        } else if (strcmp(level, "WARNING") == 0) {
            printf("Line %d: Smiley Warning: %s\n", line_number, buffer);
        } else if (strcmp(level, "ERROR") == 0) {
            printf("Line %d: Sad Error: %s\n", line_number, buffer);
        } else {
            printf("Line %d: Unknown Level: %s\n", line_number, buffer);
        }
    }

    fclose(log_file);

    printf("===============================\n");
    printf("===== Happy Log Analyzer Done =====\n");

    return 0;
}