//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world!";
    char *p = str;

    // Reverse the string
    for (int i = strlen(str) - 1; i >= 0; i--) {
        *p++ = str[i];
    }
    *p = '\0';

    // Print the reversed string
    printf("%s\n", str);

    // Find the first occurrence of the letter 'o'
    p = strchr(str, 'o');

    // If 'o' was found, print its position
    if (p != NULL) {
        printf("The first occurrence of 'o' is at position %d\n", p - str);
    } else {
        printf("The letter 'o' was not found in the string.\n");
    }

    // Find the last occurrence of the letter 'l'
    p = strrchr(str, 'l');

    // If 'l' was found, print its position
    if (p != NULL) {
        printf("The last occurrence of 'l' is at position %d\n", p - str);
    } else {
        printf("The letter 'l' was not found in the string.\n");
    }

    // Find the first occurrence of the substring "llo"
    p = strstr(str, "llo");

    // If "llo" was found, print its position
    if (p != NULL) {
        printf("The first occurrence of \"llo\" is at position %d\n", p - str);
    } else {
        printf("The substring \"llo\" was not found in the string.\n");
    }

    // Concatenate two strings
    char str1[] = "Hello";
    char str2[] = " world!";
    char str3[strlen(str1) + strlen(str2) + 1];

    strcat(str3, str1);
    strcat(str3, str2);

    // Print the concatenated string
    printf("%s\n", str3);

    // Compare two strings
    int result = strcmp(str1, str2);

    // If the strings are equal, print "The strings are equal."
    if (result == 0) {
        printf("The strings are equal.\n");
    }
    // If str1 is less than str2, print "str1 is less than str2."
    else if (result < 0) {
        printf("str1 is less than str2.\n");
    }
    // If str1 is greater than str2, print "str1 is greater than str2."
    else {
        printf("str1 is greater than str2.\n");
    }

    // Convert a string to an integer
    int num = atoi("12345");

    // Print the integer
    printf("%d\n", num);

    // Convert an integer to a string
    char str4[10];
    sprintf(str4, "%d", num);

    // Print the string
    printf("%s\n", str4);

    return 0;
}