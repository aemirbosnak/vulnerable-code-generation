//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void spell_checker(char **words, int num_words) {
    int i, j, word_length;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < num_words; i++) {
        printf("Enter word: ");
        scanf("%s", word);

        word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: word too long.\n");
            continue;
        }

        for (j = 0; j < word_length; j++) {
            if (!isalnum(word[j])) {
                printf("Error: invalid characters.\n");
                continue;
            }
        }

        words[i] = malloc(word_length + 1);
        strcpy(words[i], word);
    }
}

int main() {
    char **words;
    int num_words;

    printf("Enter number of words: ");
    scanf("%d", &num_words);

    words = malloc(num_words * sizeof(char *));

    spell_checker(words, num_words);

    for (int i = 0; i < num_words; i++) {
        printf("Word: %s\n", words[i]);
    }

    free(words);

    return 0;
}