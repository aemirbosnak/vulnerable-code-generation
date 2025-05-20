//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *revStr = malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        revStr[i++] = str[j];
    }
    revStr[i] = '\0';
    return revStr;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    char *revStr = reverseString(str);
    int i = 0;
    while (i < len && str[i] == revStr[i]) {
        i++;
    }
    if (i == len) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Post-apocalyptic scenario
    char *message = "Mad Max: Fury Road - Witness me!";

    // Check if the message is a palindrome
    if (isPalindrome(message)) {
        printf("The message is a palindrome.\n");
    } else {
        printf("The message is not a palindrome.\n");
    }

    // Reverse the message
    char *reversedMessage = reverseString(message);
    printf("Reversed message: %s\n", reversedMessage);

    // Convert the message to uppercase
    char *uppercaseMessage = malloc(strlen(message) + 1);
    int i = 0;
    for (int j = 0; j < strlen(message); j++) {
        uppercaseMessage[i++] = toupper(message[j]);
    }
    uppercaseMessage[i] = '\0';
    printf("Uppercase message: %s\n", uppercaseMessage);

    // Convert the message to lowercase
    char *lowercaseMessage = malloc(strlen(message) + 1);
    i = 0;
    for (int j = 0; j < strlen(message); j++) {
        lowercaseMessage[i++] = tolower(message[j]);
    }
    lowercaseMessage[i] = '\0';
    printf("Lowercase message: %s\n", lowercaseMessage);

    return 0;
}