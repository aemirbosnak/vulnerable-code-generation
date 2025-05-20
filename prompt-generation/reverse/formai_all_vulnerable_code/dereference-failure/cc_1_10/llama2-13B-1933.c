//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

// Function to generate a random word
char *generate_random_word(void) {
    char word[10];
    int i;

    // Generate a random word
    for (i = 0; i < 10; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to reverse a string
char *reverse_string(char *str) {
    char *result = NULL;
    int i, j;

    // Allocate memory for the reversed string
    result = (char *)malloc(strlen(str) * sizeof(char));

    // Reverse the string
    for (i = 0, j = strlen(str) - 1; i < strlen(str); i++, j++) {
        result[i] = str[j];
    }

    return result;
}

int main() {
    char *word = generate_random_word();
    char *reversed_word = reverse_string(word);

    // Print the original word
    printf("Original word: %s\n", word);

    // Print the reversed word
    printf("Reversed word: %s\n", reversed_word);

    // Free the memory
    free(word);
    free(reversed_word);

    return 0;
}