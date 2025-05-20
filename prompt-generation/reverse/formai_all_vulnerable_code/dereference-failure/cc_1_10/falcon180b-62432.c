//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char *string = "The quick brown fox jumps over the lazy dog.";
    char *new_string = malloc(strlen(string)+1);
    strcpy(new_string, string);

    // Remove all vowels
    char vowels[] = "aeiouAEIOU";
    int i, j;
    for (i = 0, j = 0; string[i]; i++) {
        if (strchr(vowels, tolower(string[i])) == NULL) {
            new_string[j++] = tolower(string[i]);
        }
    }
    new_string[j] = '\0';
    printf("New string: %s\n", new_string);

    // Reverse the string
    char *reversed_string = malloc(strlen(new_string)+1);
    strcpy(reversed_string, new_string);
    for (i = strlen(new_string)-1, j = 0; i >= 0; i--, j++) {
        reversed_string[j] = new_string[i];
    }
    reversed_string[j] = '\0';
    printf("Reversed string: %s\n", reversed_string);

    // Count the number of words in the string
    int word_count = 0;
    for (i = 0; string[i]; i++) {
        if (isspace(string[i])) {
            word_count++;
        }
    }
    printf("Number of words: %d\n", word_count);

    // Count the number of characters in the string
    int char_count = 0;
    for (i = 0; string[i]; i++) {
        if (isalpha(string[i])) {
            char_count++;
        }
    }
    printf("Number of characters: %d\n", char_count);

    return 0;
}