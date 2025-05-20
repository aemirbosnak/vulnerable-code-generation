//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to determine if a character is a valid English letter or not
int is_valid_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to remove all non-letter characters and convert to lowercase
void sanitize(char *str) {
    char sanitized[strlen(str)];
    int index = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (is_valid_letter(str[i])) {
            sanitized[index++] = tolower(str[i]);
        }
    }
    sanitized[index] = '\0';
    strcpy(str, sanitized);
}

// Function to check if a string is palindrome
int is_palindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {

    printf("Please enter the secret message: ");

    char message[100];
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0';
    sanitize(message);

    if (is_palindrome(message)) {
        printf("The message is a valid palindrome. Congratulations, my dear client.");
    } else {
        printf("Alas, my dear client. The message you have sent is not a valid palindrome. Please be wary of your enemies.");
    }

    return 0;
}