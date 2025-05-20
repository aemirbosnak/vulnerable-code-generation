//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void surrealist_string_manipulation(char* input_string) {
    char* output_string = malloc(MAX_SIZE * sizeof(char));
    strcpy(output_string, input_string);

    // Reverse the string
    char* reversed_string = malloc(MAX_SIZE * sizeof(char));
    int length = strlen(output_string);
    for (int i = 0; i < length; i++) {
        reversed_string[i] = output_string[length - 1 - i];
    }
    reversed_string[length] = '\0';

    // Replace every other letter with a random character
    for (int i = 0; i < length; i += 2) {
        char random_character = rand() % 26 + 'a';
        reversed_string[i] = random_character;
    }

    // Add some random words to the end of the string
    char* random_words = malloc(MAX_SIZE * sizeof(char));
    for (int i = 0; i < rand() % 10 + 1; i++) {
        char* word = malloc(MAX_SIZE * sizeof(char));
        int word_length = rand() % 10 + 1;
        for (int j = 0; j < word_length; j++) {
            char random_letter = rand() % 26 + 'a';
            strcat(word, &random_letter);
        }
        strcat(random_words, word);
    }
    strcat(reversed_string, random_words);

    // Remove all vowels from the string
    char* vowels = "aeiouAEIOU";
    int vowel_length = strlen(vowels);
    for (int i = 0; i < length; i++) {
        if (strchr(vowels, reversed_string[i])!= NULL) {
            reversed_string[i] = '\0';
        }
    }

    // Print the surrealist string
    printf("Surrealist string: %s\n", reversed_string);
}

int main() {
    char input_string[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input_string);
    surrealist_string_manipulation(input_string);
    return 0;
}