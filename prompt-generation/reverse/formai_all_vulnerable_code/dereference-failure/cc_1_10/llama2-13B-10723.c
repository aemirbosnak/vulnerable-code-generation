//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1024
#define MIN_LEN 10

// Function to generate a random word
char *generate_word(void) {
    char *word = malloc(sizeof(char) * MAX_LEN);
    int i;

    for (i = 0; i < MAX_LEN; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to check if the input text is a palindrome
int is_palindrome(char *text) {
    int i, j;

    for (i = 0, j = strlen(text) - 1; i < j; i++, j--) {
        if (text[i] != text[j]) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    char *text = NULL;
    char *word = NULL;
    int i, j, len;

    // Generate a random word
    word = generate_word();

    // Generate a random length for the input text
    len = rand() % (MAX_LEN - MIN_LEN) + MIN_LEN;

    // Allocate memory for the input text
    text = malloc(sizeof(char) * len);

    // Fill the input text with random characters
    for (i = 0; i < len; i++) {
        text[i] = 'a' + (rand() % 26);
    }

    // Check if the input text is a palindrome
    if (is_palindrome(text)) {
        printf("The input text is a palindrome!\n");
    } else {
        printf("The input text is not a palindrome.\n");
    }

    free(word);
    free(text);

    return 0;
}