//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define WORD_LEN_MIN 5
#define WORD_LEN_MAX 256

char word[WORD_LEN_MAX + 1];
int freq[MAX_WORDS][WORD_LEN_MAX];
int num_words;

void increment_word_freq(char *word) {
    int len = strlen(word);
    if (len < WORD_LEN_MIN || len > WORD_LEN_MAX) {
        return;
    }

    int index = 0;
    for (int i = 0; i < len; i++) {
        index = index * 26 + (isalpha(word[i]) - 'a');
    }

    freq[num_words][index]++;
    num_words++;
}

int main() {
    char c;
    int in_word = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (in_word == 0) {
                in_word = 1;
                word[0] = tolower(c);
            }
            word[strlen(word) + 1] = '\0';
            strcat(word, &c);
        } else if (in_word) {
            increment_word_freq(word);
            in_word = 0;
        }
    }

    if (in_word && strlen(word) >= WORD_LEN_MIN) {
        increment_word_freq(word);
    }

    for (int i = 0; i < num_words; i++) {
        int index = 0;
        printf("%s: ", word);
        for (int j = 0; j < WORD_LEN_MAX; j++) {
            index = index * 26 + (freq[i][j] > 0 ? freq[i][j] - '0' : 0);
            putchar(index >= 26 ? 'z' + (index - 26) : 'a' + index);
        }
        printf(" %d\n", freq[i][0]);
    }

    return 0;
}