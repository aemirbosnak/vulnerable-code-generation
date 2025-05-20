//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATION_LENGTH 100

// Function prototypes
void printWelcomeMessage();
void translateToCat(char *input, char *output);
void convertToCatSound(char *word, char *translation);
void convertToCatPurr(char *word, char *translation);
void convertToCatMeow(char *word, char *translation);
void convertToCatChirp(char *word, char *translation);
void convertToCatGrowl(char *word, char *translation);
void convertToCatPaw(char *word, char *translation);

int main() {
    printWelcomeMessage();

    char input[MAX_TRANSLATION_LENGTH];
    char output[MAX_TRANSLATION_LENGTH];

    printf("Please enter a phrase to translate into Cat Language (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline

        if (strcmp(input, "exit") == 0) {
            printf("Exiting Cat Language Translator. Goodbye!\n");
            break;
        }

        translateToCat(input, output);
        printf("Translated to Cat Language: %s\n", output);
    }

    return 0;
}

void printWelcomeMessage() {
    printf("Welcome to the Amazing Cat Language Translator!\n");
    printf("This program will help you speak like a feline in no time!\n");
    printf("Ready to unleash your inner cat? Let's get started!\n\n");
}

void translateToCat(char *input, char *output) {
    char *word;
    char translation[MAX_WORD_LENGTH] = "";
    output[0] = '\0';  // Reset output

    word = strtok(input, " ");
    while (word != NULL) {
        convertToCatSound(word, translation); // Convert the word
        strcat(output, translation);          // Append the translation
        strcat(output, " ");                  // Add space between words
        word = strtok(NULL, " ");             // Next word
    }
    output[strlen(output) - 1] = '\0';  // Remove the last space
}

// Main conversion function
void convertToCatSound(char *word, char *translation) {
    if (strlen(word) == 0) {
        return;
    }

    // Choose a random translation mechanism for extra fun
    int randChoice = rand() % 5; // Generates a number between 0 and 4
    switch (randChoice) {
        case 0:
            convertToCatMeow(word, translation);
            break;
        case 1:
            convertToCatPurr(word, translation);
            break;
        case 2:
            convertToCatChirp(word, translation);
            break;
        case 3:
            convertToCatGrowl(word, translation);
            break;
        case 4:
            convertToCatPaw(word, translation);
            break;
    }
}

// Different "Cat Sound" implementations

void convertToCatMeow(char *word, char *translation) {
    sprintf(translation, "meow-meow-%s", word);
}

void convertToCatPurr(char *word, char *translation) {
    sprintf(translation, "purr-purr-%s", word);
}

void convertToCatChirp(char *word, char *translation) {
    sprintf(translation, "chirp-chirp-%s", word);
}

void convertToCatGrowl(char *word, char *translation) {
    sprintf(translation, "growl-growl-%s", word);
}

void convertToCatPaw(char *word, char *translation) {
    sprintf(translation, "paw-paw-%s", word);
}