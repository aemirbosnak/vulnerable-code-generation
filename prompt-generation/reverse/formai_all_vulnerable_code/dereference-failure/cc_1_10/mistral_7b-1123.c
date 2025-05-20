//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int score;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_LENGTH];
    char *token;

    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        token = strtok(line, " \t\n\r,");
        int i;

        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                printf("Warning: Duplicate word found in dictionary.\n");
                goto next_line;
            }
        }

        strcpy(dictionary[num_words].word, token);
        dictionary[num_words].score = 0;
        num_words++;

next_line:
        if (token == NULL) break;
        token = strtok(NULL, " \t\n\r,");
    }

    fclose(fp);
}

int get_score(const char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].score;
        }
    }

    return 0;
}

void analyze_sentiment(const char *sentence) {
    char *token;
    int total_score = 0;
    int num_words_in_sentence = 0;

    token = strtok(sentence, " .!?");

    while (token != NULL) {
        int score = get_score(token);

        if (score > 0) {
            total_score += score;
            num_words_in_sentence++;
        }

        token = strtok(NULL, " .!?");
    }

    printf("Sentence: %s\n", sentence);
    printf("Number of positive words: %d\n", num_words_in_sentence);
    printf("Total score: %d\n", total_score);
    printf("Average score per positive word: %f\n", (float)total_score / num_words_in_sentence);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <dictionary_file> <sentence>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);

    if (argc < 3) {
        printf("Error: No sentence provided.\n");
        return 1;
    }

    analyze_sentiment(argv[2]);

    return 0;
}