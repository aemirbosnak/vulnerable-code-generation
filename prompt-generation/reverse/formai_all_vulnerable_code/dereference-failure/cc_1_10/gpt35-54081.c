//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

// This function translates English to Alien Language
void englishToAlien(char *englishWord, char *alienWord) {

    // If the English word ends with a consonant, append "at"
    if (strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", englishWord[strlen(englishWord) - 1])) {
        strcpy(alienWord, englishWord);
        strcat(alienWord, "at");
    }
    // If the English word ends with a vowel, append "in"
    else {
        strcpy(alienWord, englishWord);
        strcat(alienWord, "in");
    }
}

// This function translates Alien Language to English
void alienToEnglish(char *alienWord, char *englishWord) {

    // If the Alien word ends with "at", remove "at"
    if (strstr(alienWord, "at")) {
        strncpy(englishWord, alienWord, strlen(alienWord) - 2);
    }
    // If the Alien word ends with "in", remove "in"
    else if (strstr(alienWord, "in")) {
        strncpy(englishWord, alienWord, strlen(alienWord) - 2);
    }
}

int main() {

    char englishWord[50], alienWord[50], choice, exit = 'n';
    int i;

    printf("##############################################\n");
    printf("#                                            #\n");
    printf("#     WELCOME TO THE ALIEN LANGUAGE TRASLATOR #\n");
    printf("#                                            #\n");
    printf("##############################################\n\n");

    while (exit != 'y') {
        printf("Choose an option: \n");
        printf("1. Translate English to Alien\n");
        printf("2. Translate Alien to English\n");
        printf("3. Exit\n");
        printf("Enter choice (1/2/3): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nEnter an English word: ");
                scanf("%s", englishWord);
                englishToAlien(englishWord, alienWord);
                printf("Translated: %s\n\n", alienWord);
                break;

            case '2':
                printf("\nEnter an Alien word: ");
                scanf("%s", alienWord);
                alienToEnglish(alienWord, englishWord);
                printf("Translated: %s\n\n", englishWord);
                break;

            case '3':
                printf("\nExiting program...");
                exit = 'y';
                break;

            default:
                printf("\nInvalid choice. Please select again.\n\n");
                break;
        }
    }
    return 0;
}