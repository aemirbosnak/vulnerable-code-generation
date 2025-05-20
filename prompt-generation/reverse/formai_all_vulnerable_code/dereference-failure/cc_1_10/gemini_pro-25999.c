//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
bool is_palindrome(const char *str) {
    // Convert the string to lowercase
    char *lower_str = strdup(str);
    for (int i = 0; lower_str[i] != '\0'; i++) {
        lower_str[i] = tolower(lower_str[i]);
    }

    // Compare the string to its reverse
    int len = strlen(lower_str);
    for (int i = 0; i < len / 2; i++) {
        if (lower_str[i] != lower_str[len - i - 1]) {
            free(lower_str);
            return false;
        }
    }

    free(lower_str);
    return true;
}

// Function to check if a number is a palindrome
bool is_palindrome_number(int num) {
    // Convert the number to a string
    char num_str[100];
    sprintf(num_str, "%d", num);

    // Check if the string is a palindrome
    return is_palindrome(num_str);
}

// Function to print a palindrome
void print_palindrome(const char *str) {
    // Print the string in reverse
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Function to test the palindrome checker
void test_palindrome_checker() {
    // Test a string
    const char *str = "racecar";
    printf("Is \"%s\" a palindrome? %s\n", str, is_palindrome(str) ? "Yes" : "No");

    // Test a number
    int num = 123454321;
    printf("Is %d a palindrome? %s\n", num, is_palindrome_number(num) ? "Yes" : "No");

    // Print a palindrome
    str = "hello, world";
    printf("The palindrome of \"%s\" is: ", str);
    print_palindrome(str);
}

// Main function
int main() {
    test_palindrome_checker();
    return 0;
}