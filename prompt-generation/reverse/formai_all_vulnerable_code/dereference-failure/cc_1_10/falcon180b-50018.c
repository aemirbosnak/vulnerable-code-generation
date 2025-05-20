//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERNS 10
#define MAX_LENGTH 100

typedef struct {
    char *pattern;
    int length;
} pattern_t;

int main(int argc, char **argv) {
    int i, j, k, num_patterns = 0;
    char input[MAX_LENGTH];
    pattern_t patterns[MAX_PATTERNS];

    // Read in patterns from command line arguments
    for (i = 1; i < argc; i++) {
        strcpy(input, argv[i]);
        num_patterns++;
    }

    // Initialize patterns array
    for (i = 0; i < num_patterns; i++) {
        patterns[i].pattern = malloc(MAX_LENGTH * sizeof(char));
        strcpy(patterns[i].pattern, input);
        patterns[i].length = strlen(input);
    }

    // Read in input file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open input file.\n");
        exit(1);
    }

    // Check for patterns in input file
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fp)!= NULL) {
        for (i = 0; i < num_patterns; i++) {
            j = 0;
            while (j < strlen(line) && j < patterns[i].length) {
                if (tolower(line[j])!= tolower(patterns[i].pattern[j])) {
                    break;
                }
                j++;
            }
            if (j == patterns[i].length) {
                printf("Pattern %d found in line %d:\n%s\n", i+1, num_patterns, line);
            }
        }
    }

    // Close input file
    fclose(fp);

    return 0;
}