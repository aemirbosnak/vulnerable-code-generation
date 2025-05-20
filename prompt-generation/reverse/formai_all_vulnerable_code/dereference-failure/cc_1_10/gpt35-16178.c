//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_PATTERN_LENGTH 256

typedef struct Pattern {
    char pattern[MAX_PATTERN_LENGTH];
    int length;
} Pattern;

// function to initialize a pattern structure
Pattern* initializePattern(char* pattern) {
    Pattern* new_pattern = malloc(sizeof(Pattern));
    strcpy(new_pattern->pattern, pattern);
    new_pattern->length = strlen(pattern);
    return new_pattern;
}

// function to check if a given character is present in a pattern
int isCharPresent(char c, Pattern* pattern) {
    int i;
    for (i = 0; i < pattern->length; i++) {
        if (pattern->pattern[i] == c) {
            return 1;
        }
    }
    return 0;
}

// function to check if a given input string contains any pattern
int isPatternPresent(char* input, Pattern** patterns, int num_patterns) {
    int i, j, k, found;
    for (i = 0; i < strlen(input); i++) {
        found = 0;
        for (j = 0; j < num_patterns; j++) {
            if (isCharPresent(input[i], patterns[j])) {
                found = 1;
                for (k = 1; k < patterns[j]->length; k++) {
                    if (i + k >= strlen(input) || input[i+k] != patterns[j]->pattern[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    Pattern* patterns[3];
    patterns[0] = initializePattern("rm -rf");
    patterns[1] = initializePattern("sudo");
    patterns[2] = initializePattern("rm -rf /*");
    char input[MAX_INPUT_LENGTH];
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (isPatternPresent(input, patterns, 3)) {
            printf("Intrusion detected!\n");
        }
    }
    return 0;
}