//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char *english;
    char *alien;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char *english, char *alien) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words exceeded.\n");
        exit(1);
    }

    words[num_words].english = strdup(english);
    words[num_words].alien = strdup(alien);

    num_words++;
}

int main() {
    add_word("hello", "krrrzzzt");
    add_word("world", "zzt");

    char input[MAX_WORD_LEN];

    while (1) {
        printf("Enter a word to translate: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(input, words[i].english) == 0) {
                printf("Alien: %s\n", words[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("No translation found.\n");
        }
    }

    return 0;
}