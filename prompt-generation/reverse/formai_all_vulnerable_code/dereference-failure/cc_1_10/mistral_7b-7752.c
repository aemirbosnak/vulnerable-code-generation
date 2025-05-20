//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_LEN];
    int sentiment;
} Word;

Word lexicon[NUM_WORDS];

void load_lexicon() {
    FILE *fp = fopen("lexicon.txt", "r");
    int i = 0;
    char line[100];

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open lexicon file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        char *word = strtok(line, " \t\n");
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(lexicon[j].word, word) == 0) {
                fprintf(stderr, "Error: Duplicate word in lexicon.\n");
                exit(1);
            }
        }

        strcpy(lexicon[i].word, word);
        lexicon[i].sentiment = word[0] == '+' ? 1 : -1;
        i++;
    }

    fclose(fp);
}

int main() {
    load_lexicon();

    char input[100];
    int total_sentiment = 0;
    int num_words = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    char *token = strtok(input, " ");
    while (token != NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(lexicon[i].word, token) == 0) {
                total_sentiment += lexicon[i].sentiment;
                break;
            }
        }

        if (i == num_words) {
            // Add new word to lexicon if it's not already in there
            strcpy(lexicon[num_words].word, token);
            lexicon[num_words].sentiment = 0;
            total_sentiment += 0;
            num_words++;
        }

        token = strtok(NULL, " ");
    }

    printf("Sentiment score: %d\n", total_sentiment);

    return 0;
}