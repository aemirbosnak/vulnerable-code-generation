//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    char *word;
    double score;
} WordScore;

int compareWordScore(const void *a, const void *b) {
    const WordScore *wa = (const WordScore *)a;
    const WordScore *wb = (const WordScore *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    // Load the sentiment lexicon.
    FILE *file = fopen("sentiment_lexicon.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening sentiment lexicon file.\n");
        return 1;
    }
    int num_words = 0;
    fscanf(file, "%d", &num_words);
    WordScore *words = malloc(sizeof(WordScore) * num_words);
    for (int i = 0; i < num_words; i++) {
        fscanf(file, "%s %lf", words[i].word, &words[i].score);
    }
    fclose(file);

    // Get the text to analyze.
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, stdin);

    // Tokenize the text.
    char *token = strtok(text, " ");
    int num_tokens = 0;
    while (token != NULL) {
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score.
    double score = 0.0;
    for (int i = 0; i < num_tokens; i++) {
        // Convert the token to lowercase.
        char *lowercase_token = malloc(strlen(token) + 1);
        strcpy(lowercase_token, token);
        for (int j = 0; j < strlen(lowercase_token); j++) {
            lowercase_token[j] = tolower(lowercase_token[j]);
        }

        // Find the word in the sentiment lexicon.
        WordScore *result = bsearch(lowercase_token, words, num_words, sizeof(WordScore), compareWordScore);
        if (result != NULL) {
            score += result->score;
        }

        free(lowercase_token);
    }

    // Print the sentiment score.
    printf("Sentiment score: %.2f\n", score);

    // Free the allocated memory.
    free(words);
    free(text);

    return 0;
}