//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input_string[MAX_LENGTH];
    char *p;
    int length;

    printf("Enter a string: ");
    fgets(input_string, MAX_LENGTH, stdin);
    length = strlen(input_string);

    printf("Original string: %s\n", input_string);

    // Reverse the string
    p = input_string + length - 1;
    while (p >= input_string) {
        printf("%c", *p);
        p--;
    }
    printf("\n");

    // Remove all whitespace characters
    p = input_string;
    while (*p) {
        if (!isspace(*p)) {
            printf("%c", *p);
        }
        p++;
    }
    printf("\n");

    // Convert all characters to uppercase
    p = input_string;
    while (*p) {
        printf("%c", toupper(*p));
        p++;
    }
    printf("\n");

    // Count the number of words in the string
    p = input_string;
    int word_count = 0;
    while (*p) {
        if (isspace(*p)) {
            word_count++;
        }
        p++;
    }
    printf("Number of words: %d\n", word_count);

    return 0;
}