//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MIN_NUM_WORDS 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int is_word_valid(char *word) {
    int length = strlen(word);
    if (length < MIN_WORD_LENGTH || length > MAX_WORD_LENGTH) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_spam(char *message) {
    int num_words = 0;
    Word *words = malloc(MAX_NUM_WORDS * sizeof(Word));
    char *token;
    char *saveptr;
    token = strtok_r(message, " \n\t\r", &saveptr);
    while (token!= NULL) {
        if (is_word_valid(token)) {
            num_words++;
        }
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (num_words < MIN_NUM_WORDS) {
            Word *new_words = realloc(words, (num_words + 1) * sizeof(Word));
            if (new_words == NULL) {
                free(words);
                return 1;
            }
            words = new_words;
            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
        }
        token = strtok_r(NULL, " \n\t\r", &saveptr);
    }
    free(words);
    return 0;
}

int main() {
    char message[10000];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    int result = is_spam(message);
    if (result == 0) {
        printf("Not spam\n");
    } else {
        printf("Spam\n");
    }
    return 0;
}