//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PATTERNS 10
#define MAX_PATTERN_LENGTH 50

typedef struct {
    char *pattern;
    int pattern_length;
} pattern_t;

pattern_t patterns[MAX_PATTERNS];
int num_patterns = 0;

void add_pattern(char *pattern) {
    if (num_patterns >= MAX_PATTERNS) {
        printf("Maximum number of patterns reached.\n");
        return;
    }

    patterns[num_patterns].pattern = strdup(pattern);
    patterns[num_patterns].pattern_length = strlen(pattern);
    num_patterns++;
}

int match_pattern(char *line, pattern_t *pattern) {
    int i, j;
    for (i = 0, j = 0; i < strlen(line) && j < pattern->pattern_length; i++) {
        if (tolower(line[i])!= tolower(pattern->pattern[j])) {
            j = 0;
        } else {
            j++;
        }
    }
    return (j == pattern->pattern_length)? 1 : 0;
}

int main() {
    char line[MAX_LINE_LENGTH];
    int line_length;
    pattern_t *matched_pattern = NULL;

    add_pattern("password");
    add_pattern("login");

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }

        for (int i = 0; i < num_patterns; i++) {
            if (match_pattern(line, &patterns[i])) {
                matched_pattern = &patterns[i];
                break;
            }
        }

        if (matched_pattern!= NULL) {
            printf("Intrusion detected: %s\n", matched_pattern->pattern);
        }
    }

    return 0;
}