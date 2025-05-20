//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
} DictionaryEntry;

void read_dictionary(DictionaryEntry *dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    int i = 0;
    char line[MAX_WORD_LENGTH + 1];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strlen(line) > MAX_WORD_LENGTH) {
            printf("Warning: word '%s' is too long.\n", line);
            continue;
        }
        strcpy(dictionary[i].word, line);
        i++;
    }

    fclose(fp);
}

int is_palindrome(const char *word) {
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right) {
        if (word[left++] != word[right--]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    DictionaryEntry dictionary[DICTIONARY_SIZE];
    read_dictionary(dictionary);

    int valid_words[DICTIONARY_SIZE] = {0};
    int num_valid_words = 0;

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strlen(dictionary[i].word) <= MAX_WORD_LENGTH && is_palindrome(dictionary[i].word[0])) {
            valid_words[num_valid_words++] = i;
        }
    }

    char user_word[MAX_WORD_LENGTH + 1];
    while (1) {
        printf("Enter a word to check ('quit' to exit): ");
        scanf("%s", user_word);

        if (strcmp(user_word, "quit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < num_valid_words; i++) {
            if (strcmp(user_word, dictionary[valid_words[i]].word) == 0) {
                printf("The word '%s' is valid.\n", user_word);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("The word '%s' is not valid.\n", user_word);
        }
    }

    return 0;
}