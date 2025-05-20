//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *input = NULL;
    char *translated = NULL;
    int length;

    printf("Enter a string to translate to cat language: ");
    fgets(input, 100, stdin);

    length = strlen(input);
    translated = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            switch (toupper(input[i])) {
                case 'A': translated[i] = 'N'; break;
                case 'B': translated[i] = 'R'; break;
                case 'C': translated[i] = 'A'; break;
                case 'D': translated[i] = 'K'; break;
                case 'E': translated[i] = 'G'; break;
                case 'F': translated[i] = 'U'; break;
                case 'G': translated[i] = 'T'; break;
                case 'H': translated[i] = 'K'; break;
                case 'I': translated[i] = 'Y'; break;
                case 'J': translated[i] = 'O'; break;
                case 'K': translated[i] = 'O'; break;
                case 'L': translated[i] = 'W'; break;
                case 'M': translated[i] = 'N'; break;
                case 'N': translated[i] = 'K'; break;
                case 'O': translated[i] = 'A'; break;
                case 'P': translated[i] = 'T'; break;
                case 'Q': translated[i] = 'U'; break;
                case 'R': translated[i] = 'R'; break;
                case 'S': translated[i] = 'S'; break;
                case 'T': translated[i] = 'T'; break;
                case 'U': translated[i] = 'I'; break;
                case 'V': translated[i] = 'F'; break;
                case 'W': translated[i] = 'R'; break;
                case 'X': translated[i] = 'S'; break;
                case 'Y': translated[i] = 'Y'; break;
                case 'Z': translated[i] = 'O'; break;
                default: translated[i] = 'N';
            }
        } else {
            translated[i] = input[i];
        }
    }
    translated[length] = '\0';

    printf("Translated string: %s\n", translated);

    free(translated);
    return 0;
}