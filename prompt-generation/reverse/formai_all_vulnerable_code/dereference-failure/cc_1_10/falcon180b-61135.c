//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading and trailing spaces
void removeSpaces(char *str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            str[i] = toupper(str[i]);
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
}

// Function to translate English to Cat
void translateEnglishToCat(char *english) {
    char *cat = malloc(strlen(english) + 1);
    strcpy(cat, english);
    removeSpaces(cat);
    if (strcmp(cat, "MEOW") == 0) {
        printf("Cat says: Meow\n");
    } else if (strcmp(cat, "PURRR") == 0) {
        printf("Cat says: Purrr\n");
    } else if (strcmp(cat, "HISS") == 0) {
        printf("Cat says: Hiss\n");
    } else {
        printf("Cat says: Meow\n");
    }
    free(cat);
}

// Function to translate Cat to English
void translateCatToEnglish(char *cat) {
    char *english = malloc(strlen(cat) + 1);
    strcpy(english, cat);
    removeSpaces(english);
    if (strcmp(english, "MEOW") == 0) {
        printf("English says: Meow\n");
    } else if (strcmp(english, "PURRR") == 0) {
        printf("English says: Purrr\n");
    } else if (strcmp(english, "HISS") == 0) {
        printf("English says: Hiss\n");
    } else {
        printf("English says: Meow\n");
    }
    free(english);
}

// Main function
int main() {
    char input[100];
    while (1) {
        printf("Enter a sentence in English or Cat: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (isalpha(input[0])) {
            translateEnglishToCat(input);
        } else {
            translateCatToEnglish(input);
        }
    }
    return 0;
}