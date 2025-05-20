//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int length;
} Word;

Word *create_word(char *str) {
    Word *word = malloc(sizeof(Word));
    word->word = str;
    word->length = strlen(str);
    return word;
}

void check_spelling(Word *word) {
    int i;
    char *vowels = "aeiouy";
    int num_vowels = strlen(vowels);
    int num_errors = 0;
    for (i = 0; i < word->length; i++) {
        if (word->word[i] == 'c' && i+1 < word->length && strchr(vowels, word->word[i+1]) != NULL) {
            /* missed a vowel after a c */
            printf("Error: missing vowel after 'c' in word '%s'\n", word->word);
            num_errors++;
        } else if (strchr(vowels, word->word[i]) != NULL &&
                   i+1 < word->length &&
                   strchr(vowels, word->word[i+1]) != NULL) {
            /* two vowels in a row */
            printf("Warning: two consecutive vowels in word '%s'\n", word->word);
        } else if (i == word->length - 1 && word->word[i] == 'k') {
            /* ended with a k */
            printf("Warning: word '%s' ends with the letter 'k'\n", word->word);
        }
    }
    if (num_errors == 0) {
        printf("No spelling errors found in word '%s'\n", word->word);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <word>\n", argv[0]);
        return 1;
    }

    Word *word = create_word(argv[1]);
    check_spelling(word);
    free(word);

    return 0;
}