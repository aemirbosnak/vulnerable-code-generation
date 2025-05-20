//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char str1[30] = "Hello, world!";
    char str2[30] = "Happy programming!";
    char str3[30];

    printf("Let's manipulate some strings and have fun!\n");

    // Concatenate two strings
    strcat(str1, str2);
    printf("After concatenating str1 and str2, the new string is: %s\n", str1);

    // Get the length of a string
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("The length of str1 is: %d\n", len1);
    printf("The length of str2 is: %d\n", len2);

    // Copy a string
    strcpy(str3, str1);
    printf("After copying str1 to str3, str3 is now: %s\n", str3);

    // Find a substring
    char *found = strstr(str1, "programming");
    printf("The substring 'programming' was found in str1 at position: %ld\n", found - str1);

    // Convert a string to uppercase
    for (int i = 0; i < len1; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 32; // ASCII value of lowercase letters is 32 greater than uppercase letters 
        }
    }
    printf("After converting str1 to uppercase, it is now: %s\n", str1);

    // Reverse a string
    int i = 0, j = len1-1;
    while (i < j) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
        i++;
        j--;
    }
    printf("After reversing str1, it is now: %s\n", str1);

    printf("Isn't string manipulation so much fun? Let's do it again sometime!\n");
    return 0;
}