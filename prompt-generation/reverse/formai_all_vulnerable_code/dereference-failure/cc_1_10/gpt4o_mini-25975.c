//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define DELIMITERS " .!?;\n"

// Function prototypes
void summarizeText(const char *filename);
int countWords(const char *text);
int countSentences(const char *text);
int countParagraphs(const char *text);
void trim(char *str);

int main() {
    char filename[MAX_SIZE];

    printf("Welcome to the Text Summarizer!\n");
    printf("Please enter the name of the file you want to summarize: ");
    fgets(filename, sizeof(filename), stdin);
    trim(filename); // Remove newline character

    summarizeText(filename);

    return 0;
}

void summarizeText(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open the file %s\n", filename);
        return;
    }

    char *text = (char *)malloc(MAX_SIZE);
    if (text == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(text, sizeof(char), MAX_SIZE, file);
    text[bytesRead] = '\0'; // Null-terminate the string

    fclose(file);

    int wordCount = countWords(text);
    int sentenceCount = countSentences(text);
    int paragraphCount = countParagraphs(text);

    printf("\nSummary of your text:\n");
    printf("Total Words: %d\n", wordCount);
    printf("Total Sentences: %d\n", sentenceCount);
    printf("Total Paragraphs: %d\n", paragraphCount);

    free(text);
}

int countWords(const char *text) {
    int count = 0;
    char *token = strtok((char *)text, DELIMITERS); // Tokenize based on delimiters

    while (token != NULL) {
        if (strlen(token) > 0) {
            count++;
        }
        token = strtok(NULL, DELIMITERS);
    }

    return count;
}

int countSentences(const char *text) {
    int count = 0;
    const char *ptr = text;

    while (*ptr) {
        if (*ptr == '.' || *ptr == '!' || *ptr == '?') {
            count++;
        }
        ptr++;
    }

    return count;
}

int countParagraphs(const char *text) {
    int count = 0;
    const char *ptr = text;

    while (*ptr) {
        if (*ptr == '\n' && (ptr == text || *(ptr - 1) != '\n')) {
            count++;
        }
        ptr++;
    }

    if (count > 0) {
        count++; // Count the last paragraph if there's text after the last newline
    }

    return count;
}

void trim(char *str) {
    while (*str && isspace((unsigned char)*str)) str++; // Trim leading whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--; // Trim trailing whitespace
    end[1] = '\0'; // Null-terminate string
}