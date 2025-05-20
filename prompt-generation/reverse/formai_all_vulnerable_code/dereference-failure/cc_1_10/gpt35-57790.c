//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_DICTIONARY_WORDS 10000

int read_dictionary(char dictionary[][MAX_WORD_SIZE]) {
    FILE *fp = fopen("dictionary.txt", "r");
    int i = 0;

    if (fp != NULL) {
        char word[MAX_WORD_SIZE];

        while (fgets(word, MAX_WORD_SIZE, fp) != NULL && i < MAX_DICTIONARY_WORDS) {
            // remove newline character from the end of the word
            word[strcspn(word, "\n")] = 0;
            strcpy(dictionary[i], word);
            i++;
        }

        fclose(fp);
    }

    return i;
}

int is_word_in_dictionary(char *word, char dictionary[][MAX_WORD_SIZE], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void check_spelling(char *text, char dictionary[][MAX_WORD_SIZE], int num_words) {
    int word_start = 0;
    int word_end = 0;
    
    while (text[word_end] != '\0') {
        if (text[word_end] == ' ' || text[word_end] == '\n' || text[word_end] == '\r') {
            int word_length = word_end - word_start;
            char *word = malloc((word_length + 1) * sizeof(char));
            strncpy(word, &text[word_start], word_length);
            word[word_length] = '\0';

            if (!is_word_in_dictionary(word, dictionary, num_words)) {
                printf("Misspelled word: %s\n", word);
            }

            free(word);
            word_start = word_end + 1;
        }

        word_end++;
    }
}

int main() {
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_SIZE];
    int num_words = read_dictionary(dictionary);

    char *text = "This is an exampel of mispelled words.";
    check_spelling(text, dictionary, num_words);

    return 0;
}