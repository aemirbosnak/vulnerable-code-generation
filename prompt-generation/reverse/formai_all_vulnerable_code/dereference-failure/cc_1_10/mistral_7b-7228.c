//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int sentiment;
} Word;

Word dictionary[MAX_WORDS];

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    int i = 0;
    char line[1024];

    if (!file) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        int j = 0;

        while (token[j] && j < WORD_LENGTH - 1) {
            dictionary[i].word[j] = token[j];
            j++;
        }

        dictionary[i].word[j] = '\0';
        dictionary[i].sentiment = rand() % 2;
        i++;
    }

    fclose(file);
}

int analyze_sentiment(char *text) {
    int i, sentiment_score = 0;
    char word[WORD_LENGTH];
    int word_index;

    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
        if (isalpha(text[i])) {
            strncpy(word, &text[i], WORD_LENGTH);
            word[i + strlen(&text[i])] = '\0';

            for (word_index = 0; word_index < MAX_WORDS; word_index++) {
                if (strcmp(dictionary[word_index].word, word) == 0) {
                    sentiment_score += dictionary[word_index].sentiment;
                    break;
                }
            }
        }
    }

    return sentiment_score;
}

int main() {
    char filename[100] = "dictionary.txt";
    char input_text[1024];
    int sentiment_score;

    load_dictionary(filename);

    printf("Enter text for sentiment analysis: ");
    scanf("%s", input_text);

    sentiment_score = analyze_sentiment(input_text);

    if (sentiment_score > 0) {
        printf("Sentiment is positive.\n");
    } else if (sentiment_score < 0) {
        printf("Sentiment is negative.\n");
    } else {
        printf("Sentiment is neutral.\n");
    }

    return 0;
}