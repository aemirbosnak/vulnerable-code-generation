//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a word
typedef struct word {
    char* data;
    int length;
} word;

// A function to create a new word
word* new_word(const char* data) {
    word* w = malloc(sizeof(word));
    w->data = malloc(strlen(data) + 1);
    strcpy(w->data, data);
    w->length = strlen(data);
    return w;
}

// A function to free a word
void free_word(word* w) {
    free(w->data);
    free(w);
}

// A function to compare two words
int compare_words(const word* a, const word* b) {
    return strcmp(a->data, b->data);
}

// A function to find the longest word in a list of words
word* find_longest_word(word** words, int num_words) {
    word* longest_word = NULL;
    for (int i = 0; i < num_words; i++) {
        if (words[i]->length > longest_word->length) {
            longest_word = words[i];
        }
    }
    return longest_word;
}

// A function to print a list of words
void print_words(word** words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]->data);
    }
}

// Main function
int main() {
    // Create a list of words
    word** words = malloc(5 * sizeof(word*));
    words[0] = new_word("Hello");
    words[1] = new_word("World");
    words[2] = new_word("This");
    words[3] = new_word("Is");
    words[4] = new_word("A");

    // Find the longest word in the list
    word* longest_word = find_longest_word(words, 5);

    // Print the longest word
    printf("The longest word is: %s\n", longest_word->data);

    // Free the list of words
    for (int i = 0; i < 5; i++) {
        free_word(words[i]);
    }
    free(words);

    return 0;
}