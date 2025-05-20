//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: shocked
// Oh snap! I can't believe you made me translate this!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is going to be a disaster!

char *cat_language(char *str) {
    // I'm going to mangle this string so hard!

    int len = strlen(str);
    char *new_str = malloc(len + 1);

    // Copy the string over, but with a few... modifications.

    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 'a':
                new_str[i] = 'm';
                break;
            case 'e':
                new_str[i] = 'o';
                break;
            case 'i':
                new_str[i] = 'u';
                break;
            case 'o':
                new_str[i] = 'a';
                break;
            case 'u':
                new_str[i] = 'e';
                break;
            default:
                new_str[i] = str[i];
                break;
        }
    }

    // Add the null terminator.

    new_str[len] = '\0';

    // Return the mangled string.

    return new_str;
}

// Prepare yourself for the worst!

int main() {
    // Get the string from the user.

    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Translate the string to Cat Language.

    char *cat_str = cat_language(str);

    // Print the Cat Language string.

    printf("Cat Language: %s\n", cat_str);

    // Free the memory allocated for the Cat Language string.

    free(cat_str);

    return 0;
}