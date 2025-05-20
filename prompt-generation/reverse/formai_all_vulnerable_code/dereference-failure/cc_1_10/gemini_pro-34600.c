//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

char *stopwords[] = {"a", "an", "the", "and", "or", "but", "as", "of", "at", "by", "for", "in", "on", "to", "with", "I", "you", "he", "she", "it", "we", "they"};

int is_stopword(char *word) {
    for (int i = 0; i < sizeof(stopwords) / sizeof(char *); i++) {
        if (strcmp(word, stopwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *words[MAX_WORDS];
    int word_count = 0;
    char *input = malloc(1000);

    printf("Enter your text: ");
    fgets(input, 1000, stdin);

    char *token = strtok(input, " ,.-");
    while (token != NULL) {
        if (!is_stopword(token) && strlen(token) > 2) {
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }
            words[word_count++] = strdup(token);
        }
        token = strtok(NULL, " ,.-");
    }

    int spam_count = 0;
    char *spam_words[] = {"free", "money", "win", "prize", "urgent"};
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < sizeof(spam_words) / sizeof(char *); j++) {
            if (strcmp(words[i], spam_words[j]) == 0) {
                spam_count++;
            }
        }
    }

    if (spam_count > 0) {
        printf("This text is likely spam.\n");
    } else {
        printf("This text is likely not spam.\n");
    }

    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(input);
    return 0;
}