//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STR_LEN 256

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to get a random character from the alien alphabet
char getRandomAlienCharacter() {
    // The alien alphabet consists of the following characters:
    // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, !, @, #, $, %, ^, &, *, (, ), -, _, +, =, [, ], {, }, |, \, ;, :, ', ", <, >, ., ?, /
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_-+=[{]};:'\",.<>/?\\";
    int index = generateRandomNumber(0, strlen(alphabet) - 1);
    return alphabet[index];
}

// Function to translate a string from English to Alien language
char* translateToAlienLanguage(char* str) {
    char* alienString = malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                alienString[i] = c - 'A' + 'a';
            } else {
                alienString[i] = c - 'a' + 'A';
            }
        } else {
            alienString[i] = getRandomAlienCharacter();
        }
    }
    alienString[strlen(str)] = '\0';
    return alienString;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the input string from the user
    char input[MAX_STR_LEN];
    printf("Enter a string to translate to Alien language: ");
    scanf("%s", input);

    // Translate the string to Alien language
    char* alienString = translateToAlienLanguage(input);

    // Print the translated string
    printf("Translated string: %s\n", alienString);

    // Free the allocated memory
    free(alienString);

    return 0;
}