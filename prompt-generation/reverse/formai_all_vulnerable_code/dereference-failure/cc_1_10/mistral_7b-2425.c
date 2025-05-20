//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove all non-alphanumeric characters and convert to lowercase
void process_string(char *str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (isalnum(str[i])) {
            str[j] = tolower(str[i]);
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    str[j] = '\0'; // Set null terminator
}

// Function to check if two strings are equal
int compare_strings(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }
    return 0;
}

// Function to check if a given string is a palindrome
int is_palindrome(char *str) {
    process_string(str); // Process input string
    int len = strlen(str);
    return compare_strings(str, str + len - 1); // Compare first half with last half
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}