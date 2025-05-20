//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

// Alien language dictionary
char alienDictionary[26][26] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "NOPQRSTUVWXYZABCDEFGHIJKLM",
    "GHIJKLMNOPQRSTUVWXYZABCDEF",
    "DEFGHIJKLMNOPQRSTUVWXYZABC",
    "CDEFGHIJKLMNOPQRSTUVWXYZAB",
    "BCDEFGHIJKLMNOPQRSTUVWXYZA",
    "ZABCDEFGHIJKLMNOPQRSTUVWXY",
    "YABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "XABCDEFGHIJKLMNOPQRSTUVWZY",
    "WABCDEFGHIJKLMNOPQRSTUVXYZ",
    "VABCDEFGHIJKLMNOPQRSTUVWXY",
    "UABCDEFGHIJKLMNOPQRSTUVWXY",
    "TABCDEFGHIJKLMNOPQRSTUVWXY",
    "SABCDEFGHIJKLMNOPQRSTUVWXY",
    "RABCDEFGHIJKLMNOPQRSTUVWXY",
    "QABCDEFGHIJKLMNOPQRSTUVWXY",
    "PABCDEFGHIJKLMNOPQRSTUVWXY",
    "OABCDEFGHIJKLMNOPQRSTUVWXY",
    "NABCDEFGHIJKLMNOPQRSTUVWXY",
    "MABCDEFGHIJKLMNOPQRSTUVWXY",
    "LABCDEFGHIJKLMNOPQRSTUVWXY",
    "KABcDEFGHIJKLMNOPQRSTUVWXY",
    "JAbCDEFGHIJKLMNOPQRSTUVWXY",
    "IAbCDEFGHIJKLMNOPQRSTUVWXY",
    "HABcDEFGHIJKLMNOPQRSTUVWXY",
    "GABcDEFGHIJKLMNOPQRSTUVWXY"
};

// Function to translate a string from English to Alien language
char *translateToAlien(char *english) {
    int len = strlen(english);
    char *alien = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = english[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        int index = c - 'A';
        alien[i] = alienDictionary[index][0];
    }
    alien[len] = '\0';
    return alien;
}

// Function to translate a string from Alien language to English
char *translateFromAlien(char *alien) {
    int len = strlen(alien);
    char *english = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = alien[i];
        int index = 0;
        while (c != alienDictionary[index][0]) {
            index++;
        }
        english[i] = index + 'A';
    }
    english[len] = '\0';
    return english;
}

// Main function
int main() {
    // Get the input string from the user
    char english[100];
    printf("Enter a string in English: ");
    scanf("%s", english);

    // Translate the string to Alien language
    char *alien = translateToAlien(english);

    // Print the translated string
    printf("Alien language: %s\n", alien);

    // Translate the string back to English
    char *english2 = translateFromAlien(alien);

    // Print the translated string
    printf("English: %s\n", english2);

    // Free the allocated memory
    free(alien);
    free(english2);

    return 0;
}