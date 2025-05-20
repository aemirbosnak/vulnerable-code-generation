//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LOG_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char log_line[MAX_LOG_LINE_LENGTH];
    while (fgets(log_line, MAX_LOG_LINE_LENGTH, log_file) != NULL) {
        // Parse the log line
        regex_t regex;
        int regex_comp_status = regcomp(&regex, "^\\[(.*?)\\] \\[(.*?)\\] \\[(.*?)\\] \\[(.*?)\\] (.*)$", REG_EXTENDED);
        if (regex_comp_status != 0) {
            char error_message[1024];
            regerror(regex_comp_status, &regex, error_message, sizeof(error_message));
            fprintf(stderr, "regcomp: %s\n", error_message);
            return EXIT_FAILURE;
        }

        regmatch_t matches[6];
        int regex_exec_status = regexec(&regex, log_line, 6, matches, 0);
        if (regex_exec_status != 0) {
            char error_message[1024];
            regerror(regex_exec_status, &regex, error_message, sizeof(error_message));
            fprintf(stderr, "regexec: %s\n", error_message);
            return EXIT_FAILURE;
        }

        // Extract the fields from the log line
        char *timestamp = log_line + matches[1].rm_so;
        timestamp[matches[1].rm_eo - matches[1].rm_so] = '\0';

        char *level = log_line + matches[2].rm_so;
        level[matches[2].rm_eo - matches[2].rm_so] = '\0';

        char *logger = log_line + matches[3].rm_so;
        logger[matches[3].rm_eo - matches[3].rm_so] = '\0';

        char *thread = log_line + matches[4].rm_so;
        thread[matches[4].rm_eo - matches[4].rm_so] = '\0';

        char *message = log_line + matches[5].rm_so;

        // Print the fields to the console
        printf("%s %s %s %s %s\n", timestamp, level, logger, thread, message);

        // Free the regex
        regfree(&regex);
    }

    fclose(log_file);

    return EXIT_SUCCESS;
}