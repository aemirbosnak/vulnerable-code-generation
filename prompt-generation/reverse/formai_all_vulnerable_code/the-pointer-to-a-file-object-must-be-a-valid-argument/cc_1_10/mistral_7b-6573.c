//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_PATTERNS 2

typedef struct {
    char pattern[MAX_LINE_LENGTH];
    char replacement[MAX_LINE_LENGTH];
} Pattern;

void replace_pattern(char *line, Pattern patterns[], int num_patterns) {
    int i;
    for (i = 0; i < num_patterns; i++) {
        size_t pos = 0;
        while ((pos = strstr(line, patterns[i].pattern)) != NULL) {
            size_t len_pattern = strlen(patterns[i].pattern);
            size_t len_replacement = strlen(patterns[i].replacement);
            memmove(pos + len_replacement, line + pos + len_pattern, strlen(line + pos + len_pattern) - (pos + len_pattern + len_pattern - 1));
            strncpy(line + pos, patterns[i].replacement, len_replacement + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    char line[MAX_LINE_LENGTH];
    Pattern patterns[MAX_NUM_PATTERNS] = {{"pattern1", "replacement1"}, {"pattern2", "replacement2"}};
    int num_patterns = sizeof(patterns) / sizeof(Pattern);

    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        replace_pattern(line, patterns, num_patterns);
        if (argc > 1) {
            fseek(file, ftell(file) - strlen(line), SEEK_SET);
            fputs(line, file);
        } else {
            printf("%s", line);
        }
    }

    if (argc > 1) {
        fclose(file);
    }

    return EXIT_SUCCESS;
}