//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro to check if a character is a vowel
#define IS_VOWEL(c) ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u' || (c) == 'A' || (c) == 'E' || (c) == 'I' || (c) == 'O' || (c) == 'U')

// Define a structure to represent a word
typedef struct word {
    char *str;
    int len;
} word_t;

// Define a function to create a new word
word_t *word_new(const char *str) {
    word_t *word = malloc(sizeof(word_t));
    if (!word) {
        return NULL;
    }

    word->len = strlen(str);
    word->str = malloc(word->len + 1);
    if (!word->str) {
        free(word);
        return NULL;
    }

    strcpy(word->str, str);

    return word;
}

// Define a function to free a word
void word_free(word_t *word) {
    if (!word) {
        return;
    }

    free(word->str);
    free(word);
}

// Define a function to compare two words
int word_cmp(const word_t *w1, const word_t *w2) {
    return strcmp(w1->str, w2->str);
}

// Define a function to print a word
void word_print(const word_t *word) {
    printf("%s", word->str);
}

// Define a function to count the number of vowels in a word
int word_count_vowels(const word_t *word) {
    int count = 0;
    for (int i = 0; i < word->len; i++) {
        if (IS_VOWEL(word->str[i])) {
            count++;
        }
    }

    return count;
}

// Define a function to find the longest word in a list of words
word_t *word_find_longest(word_t **words, int num_words) {
    word_t *longest_word = NULL;

    for (int i = 0; i < num_words; i++) {
        if (!longest_word || words[i]->len > longest_word->len) {
            longest_word = words[i];
        }
    }

    return longest_word;
}

// Define a function to sort a list of words
void word_sort(word_t **words, int num_words) {
    qsort(words, num_words, sizeof(word_t *), (int (*)(const void *, const void *))word_cmp);
}

// Define a function to test the word manipulation functions
void test_word_manipulation() {
    // Create a list of words
    word_t *words[] = {
        word_new("hello"),
        word_new("world"),
        word_new("this"),
        word_new("is"),
        word_new("a"),
        word_new("test"),
    };

    int num_words = sizeof(words) / sizeof(words[0]);

    // Print the words
    printf("Words:\n");
    for (int i = 0; i < num_words; i++) {
        word_print(words[i]);
        printf(" ");
    }
    printf("\n");

    // Count the number of vowels in each word
    printf("Vowels:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%d ", word_count_vowels(words[i]));
    }
    printf("\n");

    // Find the longest word
    word_t *longest_word = word_find_longest(words, num_words);
    printf("Longest word: %s\n", longest_word->str);

    // Sort the words
    word_sort(words, num_words);

    // Print the sorted words
    printf("Sorted words:\n");
    for (int i = 0; i < num_words; i++) {
        word_print(words[i]);
        printf(" ");
    }
    printf("\n");

    // Free the words
    for (int i = 0; i < num_words; i++) {
        word_free(words[i]);
    }
}

int main() {
    test_word_manipulation();

    return 0;
}