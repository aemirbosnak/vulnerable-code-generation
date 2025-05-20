//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char *line;
    int significance;
} LineInfo;

int compare(const void *a, const void *b) {
    return ((LineInfo *)b)->significance - ((LineInfo *)a)->significance; 
}

int calculate_significance(const char *line) {
    int score = 0;
    char *token = strtok(strdup(line), " ");
    while (token) {
        if (strlen(token) > 4) {
            score += 2; // Longer words hold more weight
        }
        if (strchr("aeiou", token[0]) != NULL) {
            score += 1; // Start with a vowel adds weight
        }
        token = strtok(NULL, " ");
    }
    return score;
}

void extract_meaning(char **text, int count) {
    LineInfo *lineInfos = malloc(sizeof(LineInfo) * count);
    int i;

    for (i = 0; i < count; i++) {
        lineInfos[i].line = text[i];
        lineInfos[i].significance = calculate_significance(text[i]);
    }

    qsort(lineInfos, count, sizeof(LineInfo), compare);

    printf("~~ Summarized Output ~~\n");
    for (i = 0; i < count && i < 5; i++) { 
        printf("%s\n", lineInfos[i].line);
    }
    free(lineInfos);
}

int main() {
    printf("** Text Summarizer by Cryptic Minds **\n");
    char *text[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    printf("Input your text (type 'END' to finish):\n");

    while (lineCount < MAX_LINES) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0) {
            break;
        }
        text[lineCount] = strdup(line);
        lineCount++;
    }

    extract_meaning(text, lineCount);

    for (int i = 0; i < lineCount; i++) {
        free(text[i]);
    }

    return 0;
}