//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to check if a string contains only alphabetic characters
int isAlphabetic(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only alphabetic characters
int isNumeric(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only alphabetic and numeric characters
int isAlphaNumeric(char* str) {
    return isAlphabetic(str) && isNumeric(str);
}

// Function to spell check a string
void spellCheck(char* str) {
    // Check if the string contains only alphabetic characters
    if (!isAlphaNumeric(str)) {
        printf("The string contains non-alphabetic characters.\n");
        return;
    }

    // Check if the string contains any consecutive repeated characters
    int length = strlen(str);
    for (int i = 1; i < length; i++) {
        if (str[i] == str[i-1]) {
            printf("The string contains consecutive repeated characters.\n");
            return;
        }
    }

    // Check if the string contains any non-alphabetic characters at the end
    int j = length-1;
    while (str[j]!= '\0' &&!isalpha(str[j])) {
        j--;
    }
    if (j < length-1) {
        printf("The string contains non-alphabetic characters at the end.\n");
        return;
    }

    // Check if the string contains any non-alphabetic characters in the middle
    for (int i = 0; i < length-1; i++) {
        if (str[i] == '\0' ||!isalpha(str[i])) {
            printf("The string contains non-alphabetic characters in the middle.\n");
            return;
        }
    }

    // The string is considered to be spelled correctly
    printf("The string is spelled correctly.\n");
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    spellCheck(str);
    return 0;
}