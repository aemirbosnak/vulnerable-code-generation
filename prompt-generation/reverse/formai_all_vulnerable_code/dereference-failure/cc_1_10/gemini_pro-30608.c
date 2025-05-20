//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Alien Dictionary
char alien_dict[][2] = {
    {'a', 'z'},
    {'b', 'y'},
    {'c', 'x'},
    {'d', 'w'},
    {'e', 'v'},
    {'f', 'u'},
    {'g', 't'},
    {'h', 's'},
    {'i', 'r'},
    {'j', 'q'},
    {'k', 'p'},
    {'l', 'o'},
    {'m', 'n'},
};

//Translate Alien to English
char* alien_to_english(char *alien_text) {
    char *english_text = malloc(strlen(alien_text) + 1); //Allocate memory for the English translation
    int i, j;
    for (i = 0; i < strlen(alien_text); i++) {
        for (j = 0; j < sizeof(alien_dict) / sizeof(alien_dict[0]); j++) {
            if (alien_text[i] == alien_dict[j][0]) {
                english_text[i] = alien_dict[j][1];
                break;
            }
        }
    }
    english_text[i] = '\0'; //Null-terminate the English translation
    return english_text;
}

//Translate English to Alien
char* english_to_alien(char *english_text) {
    char *alien_text = malloc(strlen(english_text) + 1); //Allocate memory for the Alien translation
    int i, j;
    for (i = 0; i < strlen(english_text); i++) {
        for (j = 0; j < sizeof(alien_dict) / sizeof(alien_dict[0]); j++) {
            if (english_text[i] == alien_dict[j][1]) {
                alien_text[i] = alien_dict[j][0];
                break;
            }
        }
    }
    alien_text[i] = '\0'; //Null-terminate the Alien translation
    return alien_text;
}

int main() {
    //Get the Alien text from the user
    char alien_text[100];
    printf("Enter the Alien text: ");
    scanf("%s", alien_text);

    //Translate the Alien text to English
    char *english_text = alien_to_english(alien_text);
    printf("English translation: %s\n", english_text);

    //Translate the English text to Alien
    char *alien_text2 = english_to_alien(english_text);
    printf("Alien translation: %s\n", alien_text2);

    //Free the allocated memory
    free(english_text);
    free(alien_text2);

    return 0;
}