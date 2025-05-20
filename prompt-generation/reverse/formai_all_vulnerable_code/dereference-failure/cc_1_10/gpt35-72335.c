//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICT_FILE "dictionary.txt"
#define MAX_WORD_LENGTH 100

char *to_lower(char *word) {
    char *s = word;
    while (*s) {
        *s = tolower(*s);
        s++;
    }
    return word;
}

char *remove_punctuations(char *word) {
    char *s = word;
    while (*s) {
        if (ispunct(*s)) {
            memmove(s, s+1, strlen(s));
        } else {
            s++;
        }
    }
    return word;
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(const char **) a, *(const char **) b);
}

int binary_search(char **dictionary, size_t size, char *word) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(dictionary[mid], word);
        if (cmp == 0) {
            return 1;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    // Load dictionary
    FILE *dict_file = fopen(DICT_FILE, "r");
    if (dict_file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }
    char *buffer = malloc(MAX_WORD_LENGTH * sizeof(char));
    size_t dict_size = 0;
    while (fgets(buffer, MAX_WORD_LENGTH, dict_file)) {
        dict_size++;
    }
    char **dictionary = malloc(dict_size * sizeof(char *));
    rewind(dict_file);
    int i = 0;
    while (fgets(buffer, MAX_WORD_LENGTH, dict_file)) {
        dictionary[i++] = strdup(to_lower(remove_punctuations(buffer)));
    }
    fclose(dict_file);

    // Sort dictionary
    qsort(dictionary, dict_size, sizeof(char *), compare_words);

    // Process input
    printf("Enter some text to spell check:\n");
    while (fgets(buffer, MAX_WORD_LENGTH, stdin)) {
        char *stripped = to_lower(remove_punctuations(buffer));
        char *word = strtok(stripped, " \n");
        while (word != NULL) {
            if (!binary_search(dictionary, dict_size, word)) {
                printf("Misspelled word: %s\n", word);
            }
            word = strtok(NULL, " \n");
        }
    }

    // Clean up
    for (i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    free(buffer);

    return 0;
}