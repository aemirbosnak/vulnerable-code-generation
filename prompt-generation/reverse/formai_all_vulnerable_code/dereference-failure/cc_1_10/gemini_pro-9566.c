//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to translate a string from English to Cat language
char* cat_translator(char* str) {
    // Allocate memory for the translated string
    char* cat_str = malloc(MAX_STR_LEN);

    // Translate the string character by character
    int i;
    for (i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case 'a':
                cat_str[i] = 'm';
                break;
            case 'e':
                cat_str[i] = 'o';
                break;
            case 'i':
                cat_str[i] = 'e';
                break;
            case 'o':
                cat_str[i] = 'a';
                break;
            case 'u':
                cat_str[i] = 'i';
                break;
            default:
                cat_str[i] = str[i];
                break;
        }
    }

    // Null-terminate the translated string
    cat_str[i] = '\0';

    // Return the translated string
    return cat_str;
}

int main() {
    // Get the input string from the user
    char str[MAX_STR_LEN];
    printf("Enter a string to translate to Cat language: ");
    scanf("%s", str);

    // Translate the string to Cat language
    char* cat_str = cat_translator(str);

    // Print the translated string
    printf("Translation: %s\n", cat_str);

    // Free the memory allocated for the translated string
    free(cat_str);

    return 0;
}