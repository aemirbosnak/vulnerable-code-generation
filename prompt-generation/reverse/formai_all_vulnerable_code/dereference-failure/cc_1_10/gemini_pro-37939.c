//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: energetic
// Zaphod Beeblebrox's Universal Babel Fish 2.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Galactic Alphabet (42 characters)
char alphabet[42] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'
};

// Alien Language Ordinal (42 values)
int a_lo[42] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 1, 2, 3, 4,
    5, 6, 7, 8, 9, 10, 11, 12, 13, 14
};

// Function to translate Galactic Alphabet to Alien Language Ordinal
int to_a_lo(char c) {
    for (int i = 0; i < 42; i++) {
        if (c == alphabet[i]) {
            return a_lo[i];
        }
    }
    return -1; // Invalid character
}

// Function to translate Alien Language Ordinal to Galactic Alphabet
char to_gal_alpha(int a) {
    for (int i = 0; i < 42; i++) {
        if (a == a_lo[i]) {
            return alphabet[i];
        }
    }
    return '\0'; // Invalid number
}

// Function to translate a Galactic Alphabet string to Alien Language Ordinal
char *translate_gal_to_a_lo(char *str) {
    int len = strlen(str);
    char *a_lo_str = malloc(len + 1); // +1 for null-terminator
    for (int i = 0; i < len; i++) {
        a_lo_str[i] = to_a_lo(str[i]);
    }
    a_lo_str[len] = '\0';
    return a_lo_str;
}

// Function to translate an Alien Language Ordinal string to Galactic Alphabet
char *translate_a_lo_to_gal(char *str) {
    int len = strlen(str);
    char *gal_str = malloc(len + 1); // +1 for null-terminator
    for (int i = 0; i < len; i++) {
        gal_str[i] = to_gal_alpha(str[i]);
    }
    gal_str[len] = '\0';
    return gal_str;
}

// Main function
int main() {
    // Welcome message
    printf("************************************************************************\n");
    printf("* Zaphod Beeblebrox's Universal Babel Fish 2.0: The Hitchhiker's Guide! *\n");
    printf("************************************************************************\n\n");

    // Get the input string
    char input_str[1000];
    printf("Enter a Galactic Alphabet string to translate: ");
    scanf("%s", input_str);

    // Translate the string
    char *a_lo_str = translate_gal_to_a_lo(input_str);
    char *gal_str = translate_a_lo_to_gal(a_lo_str);

    // Print the translated strings
    printf("\nAlien Language Ordinal Translation: %s\n", a_lo_str);
    printf("Galactic Alphabet Translation: %s\n", gal_str);

    // Farewell message
    printf("\nMay you navigate the cosmos with ease, fellow space traveler!\n");

    // Free the allocated memory
    free(a_lo_str);
    free(gal_str);

    return 0;
}