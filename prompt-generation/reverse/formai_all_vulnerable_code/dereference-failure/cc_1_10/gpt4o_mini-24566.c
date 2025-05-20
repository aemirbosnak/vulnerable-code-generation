//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define POSITIVE_FILE "positive-words.txt"
#define NEGATIVE_FILE "negative-words.txt"

typedef struct SentimentData {
    char **positiveWords;
    char **negativeWords;
    int posCount;
    int negCount;
} SentimentData;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int loadWords(const char *filename, char ***words, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int capacity = 10;
    *words = malloc(capacity * sizeof(char *));
    *count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (*count >= capacity) {
            capacity *= 2;
            *words = realloc(*words, capacity * sizeof(char *));
        }
        line[strcspn(line, "\n")] = 0; // Remove newline
        (*words)[*count] = malloc((strlen(line) + 1) * sizeof(char));
        strcpy((*words)[*count], line);
        (*count)++;
    }

    fclose(file);
    return 0;
}

void freeWords(char **words, int count) {
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

SentimentData loadSentimentData() {
    SentimentData data;
    data.positiveWords = NULL;
    data.negativeWords = NULL;
    data.posCount = 0;
    data.negCount = 0;

    if (loadWords(POSITIVE_FILE, &data.positiveWords, &data.posCount) == -1) {
        exit(EXIT_FAILURE);
    }
    
    if (loadWords(NEGATIVE_FILE, &data.negativeWords, &data.negCount) == -1) {
        freeWords(data.positiveWords, data.posCount);
        exit(EXIT_FAILURE);
    }

    return data;
}

int analyzeSentiment(const char *text, SentimentData *data) {
    char *token;
    char *textCopy = strdup(text);
    int sentimentScore = 0;

    token = strtok(textCopy, " ,.;!?\"\n");
    while (token != NULL) {
        toLowerCase(token);
        
        for (int i = 0; i < data->posCount; i++) {
            if (strcmp(token, data->positiveWords[i]) == 0) {
                sentimentScore++;
                break;
            }
        }

        for (int i = 0; i < data->negCount; i++) {
            if (strcmp(token, data->negativeWords[i]) == 0) {
                sentimentScore--;
                break;
            }
        }

        token = strtok(NULL, " ,.;!?\"\n");
    }

    free(textCopy);
    return sentimentScore;
}

void printSentiment(int score) {
    if (score > 0) {
        printf("The sentiment is: Positive (%d)\n", score);
    } else if (score < 0) {
        printf("The sentiment is: Negative (%d)\n", score);
    } else {
        printf("The sentiment is Neutral (0)\n");
    }
}

int main() {
    SentimentData data = loadSentimentData();
    
    char inputText[MAX_LINE_LENGTH];
    printf("Enter text to analyze sentiment (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        if (fgets(inputText, sizeof(inputText), stdin) == NULL) {
            break; // Handle EOF
        }

        inputText[strcspn(inputText, "\n")] = 0; // Remove newline
        
        if (strcmp(inputText, "exit") == 0) {
            break; // Exit the loop
        }

        int sentimentScore = analyzeSentiment(inputText, &data);
        printSentiment(sentimentScore);
    }

    freeWords(data.positiveWords, data.posCount);
    freeWords(data.negativeWords, data.negCount);
    return 0;
}