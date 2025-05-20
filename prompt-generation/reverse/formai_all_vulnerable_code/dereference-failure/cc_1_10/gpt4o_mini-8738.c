//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LINE_LENGTH 256
#define POSITIVE_WORDS_FILE "positive_words.txt"
#define NEGATIVE_WORDS_FILE "negative_words.txt"

typedef struct {
    char **positive_words;
    char **negative_words;
    int pos_count;
    int neg_count;
} SentimentAnalysis;

void load_words(const char *filename, char ***words, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *words = malloc(MAX_WORDS * sizeof(char *));
    *count = 0;
    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, sizeof(buffer), file) && *count < MAX_WORDS) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        (*words)[*count] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy((*words)[*count], buffer);
        (*count)++;
    }

    fclose(file);
}

int is_positive(const char *word, SentimentAnalysis *sa) {
    for (int i = 0; i < sa->pos_count; i++) {
        if (strcmp(word, sa->positive_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_negative(const char *word, SentimentAnalysis *sa) {
    for (int i = 0; i < sa->neg_count; i++) {
        if (strcmp(word, sa->negative_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void analyze_sentiment(const char *input, SentimentAnalysis *sa) {
    char *input_copy = malloc((strlen(input) + 1) * sizeof(char));
    strcpy(input_copy, input);

    char *token = strtok(input_copy, " ");
    int positive_count = 0;
    int negative_count = 0;

    while (token != NULL) {
        if (is_positive(token, sa)) {
            positive_count++;
        } else if (is_negative(token, sa)) {
            negative_count++;
        }
        token = strtok(NULL, " ");
    }

    printf("Sentiment Analysis Result:\n");
    printf("Positive words count: %d\n", positive_count);
    printf("Negative words count: %d\n", negative_count);
    if (positive_count > negative_count) {
        printf("Overall sentiment: Positive\n");
    } else if (negative_count > positive_count) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }

    free(input_copy);
}

void free_words(char **words, int count) {
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    SentimentAnalysis sa;
    sa.positive_words = NULL;
    sa.negative_words = NULL;

    load_words(POSITIVE_WORDS_FILE, &sa.positive_words, &sa.pos_count);
    load_words(NEGATIVE_WORDS_FILE, &sa.negative_words, &sa.neg_count);

    char input[MAX_LINE_LENGTH];
    printf("Enter a text for sentiment analysis (type 'exit' to quit):\n");

    while (1) {
        printf("Input: ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        input[strcspn(input, "\n")] = 0; // Remove newline
        analyze_sentiment(input, &sa);
    }

    free_words(sa.positive_words, sa.pos_count);
    free_words(sa.negative_words, sa.neg_count);

    return 0;
}