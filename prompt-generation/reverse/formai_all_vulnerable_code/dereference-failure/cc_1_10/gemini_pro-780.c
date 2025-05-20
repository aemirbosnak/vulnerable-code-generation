//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define a string
    char str[] = "Hello, world!";

    // Print the string
    printf("The string is: %s\n", str);

    // Get the length of the string
    int len = strlen(str);

    // Print the length of the string
    printf("The length of the string is: %d\n", len);

    // Concatenate two strings
    char str1[] = "Hello, ";
    char str2[] = "world!";
    char *str3 = strcat(str1, str2);

    // Print the concatenated string
    printf("The concatenated string is: %s\n", str3);

    // Copy one string to another
    char str4[] = "Hello, world!";
    char str5[20];
    strcpy(str5, str4);

    // Print the copied string
    printf("The copied string is: %s\n", str5);

    // Compare two strings
    char str6[] = "Hello, world!";
    char str7[] = "Hello, world!";
    int result = strcmp(str6, str7);

    // Print the result of the comparison
    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("The first string is less than the second string.\n");
    } else {
        printf("The first string is greater than the second string.\n");
    }

    // Find the first occurrence of a character in a string
    char str8[] = "Hello, world!";
    char ch = 'o';
    char *ptr = strchr(str8, ch);

    // Print the index of the first occurrence of the character
    if (ptr != NULL) {
        printf("The first occurrence of the character '%c' is at index %d.\n", ch, ptr - str8);
    } else {
        printf("The character '%c' is not found in the string.\n", ch);
    }

    // Find the last occurrence of a character in a string
    char str9[] = "Hello, world!";
    char ch2 = 'l';
    char *ptr2 = strrchr(str9, ch2);

    // Print the index of the last occurrence of the character
    if (ptr2 != NULL) {
        printf("The last occurrence of the character '%c' is at index %d.\n", ch2, ptr2 - str9);
    } else {
        printf("The character '%c' is not found in the string.\n", ch2);
    }

    // Tokenize a string
    char str10[] = "Hello, world!";
    char *tokens;
    const char *delimiters = " ,";

    // Get the first token
    tokens = strtok(str10, delimiters);

    // Print the first token
    printf("The first token is: %s\n", tokens);

    // Get the next token
    tokens = strtok(NULL, delimiters);

    // Print the next token
    printf("The next token is: %s\n", tokens);

    // Get the next token
    tokens = strtok(NULL, delimiters);

    // Print the next token
    printf("The next token is: %s\n", tokens);

    return 0;
}