//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1000
#define MIN_FREQ 1

typedef struct {
    char *word;
    int freq;
} word_t;

int main() {
    char text[MAX_LENGTH];
    word_t *words;
    int i, j, len;

    // Read the text from the user
    printf("Enter a sentence or paragraph: ");
    fgets(text, MAX_LENGTH, stdin);

    // Tokenize the text into words
    words = (word_t *)calloc(strlen(text) + 1, sizeof(word_t));
    len = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            words[len].word = &text[i];
            words[len].freq = 1;
            len++;
        }
    }

    // Calculate the frequency of each word
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].freq++;
                break;
            }
        }
    }

    // Print the top 5 most frequent words
    for (i = 0; i < 5; i++) {
        printf("%d. %s (%d)\n", i + 1, words[i].word, words[i].freq);
    }

    // Free memory
    free(words);

    return 0;
}