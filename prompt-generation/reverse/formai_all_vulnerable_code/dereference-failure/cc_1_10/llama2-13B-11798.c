//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024

// Function to generate a random word
void generate_word(char *word) {
    int i, j;
    for (i = 0; i < 5; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    word[5] = '\0';
}

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;
    for (i = 0; i < strlen(str); i++) {
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

int main() {
    char word[MAX_LENGTH];
    char sentence[MAX_LENGTH];
    char *p;
    int i, j;

    // Generate a random word
    generate_word(word);

    // Print the random word
    printf("Random word: %s\n", word);

    // Read a sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);

    // Reverse the sentence
    reverse_string(sentence);

    // Print the reversed sentence
    printf("Reversed sentence: %s\n", sentence);

    // Find the first vowel in the sentence
    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u') {
            p = sentence + i;
            break;
        }
    }

    // Print the first vowel and its position
    printf("First vowel: %c (position %d)\n", *p, i);

    // Generate a new random word every time the program is run
    srand(time(NULL));

    return 0;
}