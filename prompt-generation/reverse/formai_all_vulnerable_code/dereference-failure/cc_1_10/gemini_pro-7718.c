//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

// Function to compare two strings case-insensitively
int strcasecmp(const char *s1, const char *s2) {
    int i;
    for (i = 0; s1[i] && s2[i]; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

// Function to check if a word is in the dictionary
int is_in_dictionary(const char *word, const char **dictionary, int num_words) {
    int left = 0, right = num_words - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcasecmp(word, dictionary[mid]);
        if (cmp == 0) {
            return 1;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

// Function to spell check a word list
void spell_check(const char **words, int num_words, const char **dictionary, int num_words_dict) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (!is_in_dictionary(words[i], dictionary, num_words_dict)) {
            printf("%s is misspelled.\n", words[i]);
        }
    }
}

// Main function
int main() {
    // Load the dictionary into memory
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }

    char **dictionary = malloc(sizeof(char *) * MAX_WORDS);
    int num_words_dict = 0;
    while (fscanf(fp, "%s", dictionary[num_words_dict++]) != EOF) {
        if (num_words_dict >= MAX_WORDS) {
            break;
        }
    }
    fclose(fp);

    // Get the word list from the user
    char **words = malloc(sizeof(char *) * MAX_WORDS);
    int num_words = 0;
    printf("Enter the word list (one word per line, terminate with an empty line):\n");
    while (1) {
        char word[MAX_WORD_LENGTH + 1];
        scanf("%s", word);
        if (strlen(word) == 0) {
            break;
        }
        words[num_words++] = strdup(word);
        if (num_words >= MAX_WORDS) {
            break;
        }
    }

    // Spell check the word list
    spell_check(words, num_words, dictionary, num_words_dict);

    // Free the allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    for (int i = 0; i < num_words_dict; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return EXIT_SUCCESS;
}