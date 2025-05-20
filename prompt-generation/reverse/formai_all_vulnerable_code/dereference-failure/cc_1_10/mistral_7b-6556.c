//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 5
#define KEYWORD_LENGTH 32

// Custom struct for storing keyword and timestamp information
typedef struct {
    char keyword[KEYWORD_LENGTH];
    time_t last_encountered;
} KeywordData;

KeywordData keywords[MAX_KEYWORDS];

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        for (int i = 0; i < MAX_KEYWORDS; i++) {
            if (strcasematch(line, keywords[i].keyword)) {
                time_t currentTime = time(NULL);
                printf("\033[1;31m[%s] %s\033[0m", ctime(&currentTime), line);
                keywords[i].last_encountered = currentTime;
                break;
            }
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file> [<keyword> [<keyword> ...]]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Initialize keywords with empty strings
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        strcpy(keywords[i].keyword, "");
    }

    // Parse and store keywords if given as arguments
    for (int i = 2; i < argc; i++) {
        strncpy(keywords[i - 1].keyword, argv[i], KEYWORD_LENGTH);
        keywords[i - 1].last_encountered = 0;
    }

    processFile(filename);

    return 0;
}

int strcasematch(const char *string1, const char *string2) {
    size_t len1 = strlen(string1);
    size_t len2 = strlen(string2);

    if (len1 != len2)
        return 0;

    for (size_t i = 0; i < len1; i++) {
        if (tolower((unsigned char)string1[i]) != tolower((unsigned char)string2[i]))
            return 0;
    }

    return 1;
}