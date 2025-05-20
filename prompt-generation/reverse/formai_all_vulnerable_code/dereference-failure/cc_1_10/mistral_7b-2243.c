//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void count_words_characters(char *str, int *words, int *characters) {
    int state = 0;
    int word_count = 0;
    int char_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (isspace(c)) {
            state = 0;
            word_count++;
        } else {
            if (state == 0) {
                state = 1;
                char_count++;
            }
        }

        if (!isspace(c) && i < MAX_LENGTH - 1 && str[i + 1] != ' ') {
            char_count++;
        }
    }

    *words = word_count;
    *characters = char_count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char str[MAX_LENGTH];
    strcpy(str, argv[1]);

    int words, characters;
    count_words_characters(str, &words, &characters);

    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    return 0;
}