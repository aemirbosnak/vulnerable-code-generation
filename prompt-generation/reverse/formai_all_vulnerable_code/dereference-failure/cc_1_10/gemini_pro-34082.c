//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare and initialize a string.
    char str[] = "Hello, world!";

    // Print the original string.
    printf("Original string: %s\n", str);

    // Reverse the string using a loop.
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Print the reversed string.
    printf("Reversed string: %s\n", str);

    // Convert the string to uppercase using a loop.
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }

    // Print the uppercase string.
    printf("Uppercase string: %s\n", str);

    // Convert the string to lowercase using a loop.
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Print the lowercase string.
    printf("Lowercase string: %s\n", str);

    // Remove all spaces from the string using a loop.
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    // Print the string without spaces.
    printf("String without spaces: %s\n", str);

    // Find the length of the string using a loop.
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    // Print the length of the string.
    printf("Length of the string: %d\n", length);

    // Compare two strings using the strcmp() function.
    char str2[] = "Hello, world!";
    int result = strcmp(str, str2);

    // Print the result of the comparison.
    if (result == 0) {
        printf("The two strings are equal.\n");
    } else if (result < 0) {
        printf("The first string is less than the second string.\n");
    } else {
        printf("The first string is greater than the second string.\n");
    }

    // Concatenate two strings using the strcat() function.
    strcat(str, str2);

    // Print the concatenated string.
    printf("Concatenated string: %s\n", str);

    // Copy one string to another using the strcpy() function.
    strcpy(str2, str);

    // Print the copied string.
    printf("Copied string: %s\n", str2);

    return 0;
}