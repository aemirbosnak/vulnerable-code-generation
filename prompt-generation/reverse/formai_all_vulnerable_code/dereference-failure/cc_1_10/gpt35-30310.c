//FormAI DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50  // Maximum word length is set to 50

// Function to check if a given character is a valid alphabet
int is_alpha(char c) {
    return isalpha(c) || c == '\'';
}

// Function to check if a given word is spelled correctly
int check_spelling(char *word, char **dictionary, int num_words) {
    // Convert all characters to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    int low = 0, high = num_words - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(word, dictionary[mid]);

        if (cmp == 0) {
            return 1;    // Word is spelled correctly
        }
        else if (cmp < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return 0;    // Word is not spelled correctly
}

// Function to get the next word from a given input string
char *get_next_word(char *input, int *idx) {
    char *word = malloc(MAX_WORD_LEN + 1);
    int len = 0;

    while (input[*idx] && !is_alpha(input[*idx])) {
        (*idx)++;   // Skip non-alphabetic characters
    }

    while (input[*idx] && is_alpha(input[*idx])) {
        word[len++] = input[(*idx)++];
        if (len == MAX_WORD_LEN) {
            break;  // Word is too long, stop reading
        }
    }

    word[len] = '\0';   // Null terminate the word

    return word;
}

// Function to spell check a given input string
void spell_check(char *input, char **dictionary, int num_words) {
    int idx = 0;
    char *word;

    while ((word = get_next_word(input, &idx))) {
        if (!check_spelling(word, dictionary, num_words)) {
            printf("'%s' is misspelled\n", word);
        }

        free(word);
    }
}

int main() {
    char *dictionary[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "indian", "jackfruit", "kiwi", "lemon", "mango"};
    int num_words = sizeof(dictionary) / sizeof(char *);

    char input[1000];
    printf("Enter the text to spell check:\n");
    fgets(input, sizeof(input), stdin);

    spell_check(input, dictionary, num_words);

    return 0;
}