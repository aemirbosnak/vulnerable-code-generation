//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Word {
    int count;
    char *word;
} Word;

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    int total_words = 0;
    int total_chars = 0;
    int word_capacity = 10;
    Word *words = malloc(word_capacity * sizeof(Word));

    char input[1024];
    char *token = NULL;
    char *save_ptr = NULL;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        total_chars += strlen(input);

        token = strtok_r(input, " \t\n\r.,;:!?", &save_ptr);
        while (token != NULL) {
            total_words++;

            int i;
            for (i = 0; token[i] != '\0'; i++) {
                if (!is_alpha(token[i])) {
                    token[i] = '\0';
                    break;
                }
            }

            bool word_exists = false;
            int i_word;
            for (i_word = 0; i_word < total_words; i_word++) {
                if (strcmp(words[i_word].word, token) == 0) {
                    words[i_word].count++;
                    word_exists = true;
                    break;
                }
            }

            if (!word_exists) {
                if (total_words >= word_capacity) {
                    word_capacity *= 2;
                    words = realloc(words, word_capacity * sizeof(Word));
                }

                strcpy(words[total_words - 1].word, token);
                words[total_words - 1].count = 1;
            }

            token = strtok_r(NULL, " \t\n\r.,;:!?", &save_ptr);
        }
    }

    printf("Total words: %d\n", total_words);
    printf("Total characters: %d\n", total_chars);

    int i_word;
    for (i_word = 0; i_word < total_words; i_word++) {
        printf("%s: %d\n", words[i_word].word, words[i_word].count);
    }

    free(words);

    return 0;
}