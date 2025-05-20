//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define INVALID_KEYWORD_INDEX -1

typedef struct {
    char* keyword;
    int count;
} KeywordCount;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: Please provide a log file as an argument.\n");
        exit(1);
    }

    FILE* logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    char* line = NULL;
    size_t lineSize = 0;
    KeywordCount keywords[MAX_NUM_KEYWORDS] = {{"invalid", INVALID_KEYWORD_INDEX}};
    int numKeywords = 1;

    while ((getline(&line, &lineSize, logFile))!= -1) {
        // Reset keyword counts for each line
        for (int i = 0; i < numKeywords; i++) {
            keywords[i].count = 0;
        }

        // Count occurrences of each keyword in the line
        char* token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            for (int i = 0; i < numKeywords; i++) {
                if (strcmp(token, keywords[i].keyword) == 0) {
                    keywords[i].count++;
                    break;
                }
            }

            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    // Print keyword counts
    printf("Keyword Counts:\n");
    for (int i = 0; i < numKeywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    return 0;
}