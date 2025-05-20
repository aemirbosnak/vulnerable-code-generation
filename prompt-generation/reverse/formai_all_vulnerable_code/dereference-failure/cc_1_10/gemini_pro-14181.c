//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100

int main() {
    // Declare a string and initialize it with a value
    char str[STR_LEN] = "Hello, world!";

    // Print the original string
    printf("Original string: %s\n", str);

    // Reverse the string using a loop
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Convert the string to uppercase using a loop
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }

    // Print the uppercase string
    printf("Uppercase string: %s\n", str);

    // Convert the string to lowercase using a loop
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Print the lowercase string
    printf("Lowercase string: %s\n", str);

    // Find the length of the string using the strlen() function
    len = strlen(str);

    // Print the length of the string
    printf("Length of the string: %d\n", len);

    // Concatenate two strings using the strcat() function
    char str2[] = " This is a concatenated string.";
    strcat(str, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", str);

    // Compare two strings using the strcmp() function
    int result = strcmp(str, str2);

    // Print the result of the comparison
    if (result == 0) {
        printf("The two strings are equal.\n");
    } else if (result < 0) {
        printf("The first string is less than the second string.\n");
    } else {
        printf("The first string is greater than the second string.\n");
    }

    // Copy a string using the strcpy() function
    char str3[STR_LEN];
    strcpy(str3, str);

    // Print the copied string
    printf("Copied string: %s\n", str3);

    // Allocate memory for a string using the malloc() function
    char *str4 = (char *)malloc(STR_LEN * sizeof(char));

    // Copy the string into the allocated memory
    strcpy(str4, str);

    // Print the string stored in the allocated memory
    printf("String stored in allocated memory: %s\n", str4);

    // Free the allocated memory using the free() function
    free(str4);

    return 0;
}