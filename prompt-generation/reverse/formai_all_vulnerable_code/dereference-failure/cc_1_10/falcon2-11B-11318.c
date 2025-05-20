//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to uppercase
char *to_upper(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Function to translate a string to another language
char *translate_string(char *str, char *lang) {
    int i, j;
    char *translated_str = (char *)malloc(strlen(str) * sizeof(char));

    // Check if the language is valid
    if (strcmp(lang, "en")!= 0 && strcmp(lang, "fr")!= 0) {
        fprintf(stderr, "Invalid language\n");
        return NULL;
    }

    // Convert the input string to uppercase
    str = to_upper(str);

    // Translate the string based on the language
    for (i = 0; i < strlen(str); i++) {
        if (strcmp(lang, "en") == 0) {
            translated_str[i] = toupper(str[i]);
        } else if (strcmp(lang, "fr") == 0) {
            translated_str[i] = str[i];
        } else {
            fprintf(stderr, "Invalid language\n");
            free(translated_str);
            return NULL;
        }
    }

    // Free the memory used by the original string
    free(str);

    return translated_str;
}

int main() {
    char str[100];
    char lang[10];

    printf("Enter a string to translate: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter the language to translate to (en or fr): ");
    fgets(lang, sizeof(lang), stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    lang[strcspn(lang, "\n")] = '\0';

    char *translated_str = translate_string(str, lang);
    if (translated_str!= NULL) {
        printf("Translated string: %s\n", translated_str);
        free(translated_str);
    } else {
        fprintf(stderr, "Error translating the string\n");
    }

    return 0;
}