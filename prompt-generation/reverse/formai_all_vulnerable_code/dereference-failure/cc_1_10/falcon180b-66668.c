//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000

// Function to reverse a string
void reverse_str(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void remove_vowels(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            str[i] = '\0';
        }
    }
}

// Function to convert a string to uppercase
void to_uppercase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverse_str(str);
    printf("Reversed string: %s\n", str);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Remove all vowels from the string
    remove_vowels(str);
    printf("String with vowels removed: %s\n", str);

    // Convert the string to uppercase
    to_uppercase(str);
    printf("String in uppercase: %s\n", str);

    return 0;
}