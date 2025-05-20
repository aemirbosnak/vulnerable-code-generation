//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_ERROR_MESSAGE_LENGTH 256

typedef struct {
    char *message;
    int count;
} error_message;

error_message *error_messages = NULL;
int num_error_messages = 0;

void process_log_file(char *log_file_name) {
    FILE *log_file = fopen(log_file_name, "r");
    char line[MAX_LOG_LENGTH];
    int line_count = 0;

    while (fgets(line, MAX_LOG_LENGTH, log_file) != NULL) {
        line_count++;
        if (strstr(line, "Error:") != NULL) {
            char *error_message = strtok(line, ": ");
            error_message = strtok(NULL, "\n");
            if (error_message != NULL) {
                error_messages = realloc(error_messages, (num_error_messages + 1) * sizeof(error_message));
                error_messages[num_error_messages].message = error_message;
                error_messages[num_error_messages].count = 1;
                num_error_messages++;
            }
        }
    }
    fclose(log_file);
}

void summary_error_messages() {
    int i;
    int max_count = 0;
    char *max_message = NULL;

    for (i = 0; i < num_error_messages; i++) {
        if (error_messages[i].count > max_count) {
            max_count = error_messages[i].count;
            max_message = error_messages[i].message;
        }
    }

    printf("Most frequent error message: %s (%d times)\n", max_message, max_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file_1> <log_file_2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        process_log_file(argv[i]);
    }

    summary_error_messages();

    return 0;
}