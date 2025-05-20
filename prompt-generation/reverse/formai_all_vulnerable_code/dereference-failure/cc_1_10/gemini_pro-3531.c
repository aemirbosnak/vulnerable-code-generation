//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declare a string
    char *str = "Hello, world!";

    // Print the original string
    printf("Original string: %s\n", str);

    // Get the length of the string
    int len = strlen(str);

    // Convert the string to uppercase
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }

    // Print the uppercase string
    printf("Uppercase string: %s\n", str);

    // Convert the string to lowercase
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Print the lowercase string
    printf("Lowercase string: %s\n", str);

    // Reverse the string
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Duplicate the string
    char *dup = strdup(str);

    // Print the duplicated string
    printf("Duplicated string: %s\n", dup);

    // Concatenate two strings
    char *str1 = "Hello";
    char *str2 = " world!";
    char *concat = strcat(str1, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", concat);

    // Compare two strings
    int cmp = strcmp(str1, str2);

    // Print the result of the comparison
    if (cmp == 0) {
        printf("Strings are equal.\n");
    } else if (cmp < 0) {
        printf("String 1 is less than string 2.\n");
    } else {
        printf("String 1 is greater than string 2.\n");
    }

    // Find a substring in a string
    char *substr = strstr(str, "world");

    // Print the substring if found
    if (substr != NULL) {
        printf("Substring found: %s\n", substr);
    } else {
        printf("Substring not found.\n");
    }

    // Replace a substring in a string
    char *newstr = strstr(str, "world");
    if (newstr != NULL) {
        strcpy(newstr, "universe");
    }

    // Print the new string
    printf("New string: %s\n", str);

    // Free the allocated memory
    free(dup);
    free(concat);

    return 0;
}