//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 256
#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 64
#define POSITIVE_WORDS_FILE "positive.txt"
#define NEGATIVE_WORDS_FILE "negative.txt"

typedef struct {
    char word[MAX_TOKEN_LENGTH];
} Word;

Word *positiveWords;
Word *negativeWords;
int positiveWordCount = 0;
int negativeWordCount = 0;

void loadWords(const char *filename, Word **wordsList, int *wordCount);
void toLower(char *str);
int analyzeSentiment(const char *sentence);
void tokenize(const char *sentence, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *tokenCount);
void freeMemory();

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    int sentimentScore;

    // Load positive and negative words
    loadWords(POSITIVE_WORDS_FILE, &positiveWords, &positiveWordCount);
    loadWords(NEGATIVE_WORDS_FILE, &negativeWords, &negativeWordCount);

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter a sentence to analyze (or 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(sentence, sizeof(sentence), stdin);

        // Remove newline character
        sentence[strcspn(sentence, "\n")] = 0;

        // Check for exit condition
        if (strcmp(sentence, "exit") == 0) {
            break;
        }

        sentimentScore = analyzeSentiment(sentence);
        printf("Sentiment Score: %d\n", sentimentScore);
    }

    // Free allocated memory
    freeMemory();
    return 0;
}

void loadWords(const char *filename, Word **wordsList, int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *wordsList = malloc(sizeof(Word) * 1000); // Basic allocation
    *wordCount = 0;

    while (fscanf(file, "%s", (*wordsList)[*wordCount].word) != EOF) {
        toLower((*wordsList)[*wordCount].word);
        (*wordCount)++;
    }

    fclose(file);
}

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int analyzeSentiment(const char *sentence) {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int tokenCount = 0;
    tokenize(sentence, tokens, &tokenCount);

    int score = 0;
    
    for (int i = 0; i < tokenCount; i++) {
        for (int j = 0; j < positiveWordCount; j++) {
            if (strcmp(tokens[i], positiveWords[j].word) == 0) {
                score++;
                break; // Stop checking further if found
            }
        }
        
        for (int j = 0; j < negativeWordCount; j++) {
            if (strcmp(tokens[i], negativeWords[j].word) == 0) {
                score--;
                break; // Stop checking further if found
            }
        }
    }

    return score;
}

void tokenize(const char *sentence, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *tokenCount) {
    char *token;
    char *sentenceCopy = strdup(sentence); // Duplicate the sentence to tokenize safely

    token = strtok(sentenceCopy, " ");
    while (token != NULL && *tokenCount < MAX_TOKENS) {
        strcpy(tokens[*tokenCount], token);
        (*tokenCount)++;
        token = strtok(NULL, " ");
    }

    free(sentenceCopy); // Free the duplicated sentence
}

void freeMemory() {
    free(positiveWords);
    free(negativeWords);
}