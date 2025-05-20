//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PATTERNS 10

struct pattern {
    char *regex;
    regex_t *compiled_regex;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    // Open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        perror("fopen");
        return 1;
    }

    // Compile the regular expressions
    struct pattern patterns[MAX_PATTERNS];
    int num_patterns = 0;
    for (int i = 2; i < argc; i++) {
        patterns[num_patterns].regex = argv[i];
        patterns[num_patterns].compiled_regex = malloc(sizeof(regex_t));
        if (regcomp(patterns[num_patterns].compiled_regex, patterns[num_patterns].regex, REG_EXTENDED) != 0) {
            fprintf(stderr, "Error compiling regular expression: %s\n", patterns[num_patterns].regex);
            return 1;
        }
        num_patterns++;
    }

    // Process the log file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Match the line against each regular expression
        for (int i = 0; i < num_patterns; i++) {
            regmatch_t match;
            if (regexec(patterns[i].compiled_regex, line, 1, &match, 0) == 0) {
                // The line matches the regular expression
                printf("Pattern: %s\n", patterns[i].regex);
                printf("Match: %s\n", line);
            }
        }
    }

    // Close the log file
    fclose(log_file);

    // Free the compiled regular expressions
    for (int i = 0; i < num_patterns; i++) {
        regfree(patterns[i].compiled_regex);
        free(patterns[i].compiled_regex);
    }

    return 0;
}