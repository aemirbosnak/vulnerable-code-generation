//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Function to calculate the number of times a character appears in a string
int countChar(char *str, char ch) {
    int count = 0;
    while (*str!= '\0') {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}

int main() {
    // Define a string
    char str[] = "The quick brown fox jumps over the lazy dog.";

    // Get the length of the string
    int len = strlen(str);

    // Print the string
    printf("Original string: %s\n", str);

    // Get the length of the string
    printf("String length: %d\n", len);

    // Print the string reversed
    char rev[len+1];
    strcpy(rev, str);
    for (int i = 0; i < len / 2; i++) {
        char temp = rev[i];
        rev[i] = rev[len - i - 1];
        rev[len - i - 1] = temp;
    }
    rev[len] = '\0';
    printf("Reversed string: %s\n", rev);

    // Count the number of times 'o' appears in the string
    int countO = countChar(str, 'o');
    printf("Number of times 'o' appears: %d\n", countO);

    // Replace all occurrences of 'o' with 'x'
    char *newStr = (char *)malloc(len+1);
    strcpy(newStr, str);
    for (int i = 0; i < len; i++) {
        if (newStr[i] == 'o')
            newStr[i] = 'x';
    }
    newStr[len] = '\0';
    printf("New string: %s\n", newStr);

    // Free the dynamically allocated memory
    free(newStr);

    return 0;
}