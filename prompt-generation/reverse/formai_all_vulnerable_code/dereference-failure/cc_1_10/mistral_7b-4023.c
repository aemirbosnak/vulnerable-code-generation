//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 10000

// Function to shift the text based on user input
void shiftText(char *text, int shiftAmount) {
    int i, len;
    for (i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            len = text[i] - 'a';
            text[i] = (char)(len + shiftAmount % 26 + 'a');
        }
    }
}

// Function to count the occurrences of a word in a line
int countWordOccurrences(char *line, char *word) {
    int count = 0, pos;
    char *token;

    token = strtok(line, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to read the file line by line and count the word occurrences
void countWordOccurrencesInFile(FILE *fp, char *word, int *count) {
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        lineCount++;
        *count += countWordOccurrences(line, word);
    }

    if (feof(fp)) {
        printf("Warning: Reached end of file while processing line %d\n", lineCount);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filePath[1024], word[MAX_WORDS];
    int count = 0;

    if (argc != 3) {
        printf("Usage: %s <file_path> <word>\n", argv[0]);
        return 1;
    }

    strcpy(filePath, argv[1]);
    strcpy(word, argv[2]);

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Counting occurrences of '%s' in '%s'\n", word, filePath);

    // Shift the word based on user input
    int shiftAmount;
    scanf("%d", &shiftAmount);
    shiftText(word, shiftAmount);

    countWordOccurrencesInFile(fp, word, &count);

    printf("The word '%s' occurs %d times in the file.\n", word, count);

    fclose(fp);

    return 0;
}