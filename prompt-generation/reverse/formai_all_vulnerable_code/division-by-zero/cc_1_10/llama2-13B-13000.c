//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_WORD_LEN 20

// Function to generate a random word
void generate_word() {
    char word[MAX_WORD_LEN];
    int i;

    for (i = 0; i < MAX_WORD_LEN; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    printf("Random word: %s\n", word);
}

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to shuffle a string
void shuffle_string(char *str) {
    int i, j, k;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        k = rand() % (i - j + 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to anagram a string
void anagram_string(char *str) {
    int i, j, k;
    char temp[MAX_STR_LEN];

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        k = rand() % (i - j + 1);
        temp[i - k] = str[j];
        str[j] = temp[i - k];
    }
}

int main() {
    srand(time(NULL));

    char str[MAX_STR_LEN];
    generate_word();

    // Reverse the string
    reverse_string(str);

    // Shuffle the string
    shuffle_string(str);

    // Anagram the string
    anagram_string(str);

    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", str);
    printf("Shuffled string: %s\n", str);
    printf("Anagrammed string: %s\n", str);

    return 0;
}