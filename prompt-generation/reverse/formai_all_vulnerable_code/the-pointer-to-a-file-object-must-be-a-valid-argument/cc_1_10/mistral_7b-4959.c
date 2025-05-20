//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int score;
} Word;

void load_dictionary(Word words[]) {
    FILE *fp = fopen("dictionary.txt", "r");
    int i = 0;
    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " \t\n");
        strcpy(words[i].word, token);
        words[i].score = 0;
        i++;
    }

    fclose(fp);
}

int analyze_sentiment(Word words[], char text[]) {
    int i, len, score = 0;
    char word[WORD_LEN];

    len = strlen(text);
    for (i = 0; i < len; i++) {
        text[i] = tolower(text[i]);
    }

    text[len] = '\0'; // Add null terminator

    for (i = 0; i < MAX_WORDS; i++) {
        strncpy(word, words[i].word, WORD_LEN);
        if (strstr(text, word) != NULL) {
            words[i].score += 1;
            score += words[i].score;
        }
    }

    return score;
}

int main() {
    Word words[MAX_WORDS];
    int i, score;
    char text[1024];

    load_dictionary(words);

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    score = analyze_sentiment(words, text);

    printf("Sentiment score: %d\n", score);

    return 0;
}