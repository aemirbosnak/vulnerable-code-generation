//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define CAT_WORD "meow"
#define CAT_LANG "cat"

void toCatLanguage(char *input);
void fromCatLanguage(char *input);
void printUsage();

int main(int argc, char *argv[]) {
    char input[MAX_LEN];
    int choice;

    if (argc != 2) {
        printUsage();
        return 1;
    }

    printf("Enter the text to translate: ");
    fgets(input, MAX_LEN, stdin);
    
    choice = atoi(argv[1]);
    
    switch (choice) {
        case 1:
            printf("Translating to Cat Language:\n");
            toCatLanguage(input);
            break;
        case 2:
            printf("Translating from Cat Language:\n");
            fromCatLanguage(input);
            break;
        default:
            printf("Invalid choice! Please use 1 to translate to Cat Language or 2 to translate from Cat Language.\n");
            break;
    }

    return 0;
}

void toCatLanguage(char *input) {
    char *token;
    const char *delim = " \n";
    printf("Cat Language Translation:\n");

    token = strtok(input, delim);
    while (token != NULL) {
        printf("%s ", CAT_WORD);
        token = strtok(NULL, delim);
    }
    printf("\n");
}

void fromCatLanguage(char *input) {
    char *token;
    const char *delim = " \n";
    int catCount = 0;

    token = strtok(input, delim);
    while (token != NULL) {
        if (strcmp(token, CAT_WORD) == 0) {
            catCount++;
        }
        token = strtok(NULL, delim);
    }

    if (catCount > 0) {
        printf("Detected %d 'meow' words. The translation back to English is:\n", catCount);
        for (int i = 0; i < catCount; i++) {
            printf("hello ");
        }
        printf("\n");
    } else {
        printf("No cat language detected!\n");
    }
}

void printUsage() {
    printf("Usage:\n");
    printf("  1: To convert English to Cat Language\n");
    printf("  2: To convert Cat Language to English\n");
}