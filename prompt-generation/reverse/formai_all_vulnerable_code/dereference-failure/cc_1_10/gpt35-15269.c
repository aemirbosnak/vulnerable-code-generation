//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This is a simple C program that serves as an Alien Language Translator.
    It can translate simple phrases and words in the Alien Language to English
    and vice versa.

    The Alien Language in this program is composed of three unique characters:
    'v', 'z', and 'd'. There are no spaces in the Alien Language, and all phrases
    are written in lowercase.

    To use the translator, simply input the Alien Language phrase or English word
    you wish to translate when prompted. The program will then translate it and
    output the corresponding translation.

    Enjoy!

*/

// Function for translating Alien Language phrases to English
void alienToEnglish(char* alien) {
    int i;
    int len = strlen(alien);

    char* english = (char*) malloc(sizeof(char) * (len + 1));

    for (i = 0; i < len; i++) {
        if (alien[i] == 'v') {
            english[i] = 'a';
        } else if (alien[i] == 'z') {
            english[i] = 'e';
        } else if (alien[i] == 'd') {
            english[i] = 'o';
        }
    }

    english[len] = '\0';
    printf("Translation: %s\n", english);

    free(english);
}

// Function for translating English words to Alien Language
void englishToAlien(char* english) {
    int i;
    int len = strlen(english);

    char* alien = (char*) malloc(sizeof(char) * (len + 1));

    for (i = 0; i < len; i++) {
        if (english[i] == 'a') {
            alien[i] = 'v';
        } else if (english[i] == 'e') {
            alien[i] = 'z';
        } else if (english[i] == 'o') {
            alien[i] = 'd';
        }
    }

    alien[len] = '\0';
    printf("Translation: %s\n", alien);

    free(alien);
}

int main() {
    int choice;
    char input[100];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please select one of the following options:\n");
    printf("1. Translate Alien Language to English\n");
    printf("2. Translate English to Alien Language\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please enter the Alien Language phrase you wish to translate:\n");
            scanf("%s", input);
            alienToEnglish(input);
            break;

        case 2:
            printf("Please enter the English word you wish to translate:\n");
            scanf("%s", input);
            englishToAlien(input);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    printf("Thank you for using the Alien Language Translator!\n");

    return 0;
}