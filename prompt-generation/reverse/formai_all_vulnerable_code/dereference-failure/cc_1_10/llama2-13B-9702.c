//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 256
#define MAX_WORDS 1000

// Global variables
int word_count = 0;
char words[MAX_WORDS][MAX_WORD_LENGTH];

// Function to get a word from the user
char *get_word() {
    printf("Enter a word: ");
    char word[MAX_WORD_LENGTH];
    fgets(word, MAX_WORD_LENGTH, stdin);
    return word;
}

// Function to count the number of words in a string
int count_words(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            word_count++;
        }
        i++;
    }
    return word_count;
}

int main() {
    // Display the program's banner
    printf("C Word Count Tool\n");
    printf("-----------------\n");

    // Get the input string from the user
    char *input_str = get_word();

    // Count the number of words in the input string
    int word_count = count_words(input_str);

    // Display the number of words and the total number of characters
    printf("Number of words: %d\n", word_count);
    printf("Total characters: %ld\n", strlen(input_str));

    // Free the input string
    free(input_str);

    return 0;
}