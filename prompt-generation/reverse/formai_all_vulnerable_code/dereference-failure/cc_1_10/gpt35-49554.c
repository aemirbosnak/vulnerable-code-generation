//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void lowercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

void strip_end_punctuation(char* str) {
    int len = strlen(str);
    if (ispunct(str[len-1])) {
        str[len-1] = '\0';
    }
}

void tokenize(char* text, WordCount* word_counts, int* num_words) {
    char* token = strtok(text, " ");
    while (token != NULL) {
        lowercase(token);
        strip_end_punctuation(token);
        if (strlen(token) == 0) {
            continue;
        }
        int found = 0;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(word_counts[i].word, token) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            int i = *num_words;
            strncpy(word_counts[i].word, token, MAX_WORD_LENGTH);
            word_counts[i].count = 1;
            (*num_words)++;
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter some text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    WordCount word_counts[MAX_TEXT_LENGTH] = {0};
    int num_words = 0;

    tokenize(text, word_counts, &num_words);

    printf("\n\nWord Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}