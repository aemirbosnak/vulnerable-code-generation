//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input[MAX_WORD_LENGTH];
    char *buffer = NULL;
    size_t buffer_size = 0;
    WordCount *word_counts = NULL;
    int num_words = 0;
    int i;

    printf("Enter text to count words:\n");
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        buffer = realloc(buffer, buffer_size + strlen(input) + 1);
        strcat(buffer, input);
        buffer_size += strlen(input);
    }

    word_counts = calloc(MAX_NUM_WORDS, sizeof(WordCount));

    char *token = strtok(buffer, ",.?!:;\"'");
    while (token!= NULL) {
        if (num_words == MAX_NUM_WORDS) {
            printf("Reached maximum number of words (%d).\n", MAX_NUM_WORDS);
            break;
        }

        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Word \"%s\" is too long (max %d characters).\n", token, MAX_WORD_LENGTH);
            continue;
        }

        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }

        if (i == num_words) {
            strcpy(word_counts[num_words].word, token);
            word_counts[num_words].count = 1;
            num_words++;
        }

        token = strtok(NULL, ",.?!:;\"'");
    }

    printf("Total number of words: %d\n", num_words);
    printf("Word counts:\n");

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(buffer);
    free(word_counts);

    return 0;
}