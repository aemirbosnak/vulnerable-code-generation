//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// Palindrome checker function
bool is_palindrome(const char* str) {
    // Check if the string is empty or NULL
    if (str == NULL || strlen(str) == 0) {
        return false;
    }

    // Convert the string to lowercase for case-insensitive comparison
    char* lower = strdup(str);
    for (int i = 0; i < strlen(lower); i++) {
        lower[i] = tolower(lower[i]);
    }

    // Check if the string is equal to its reverse
    int len = strlen(lower);
    for (int i = 0; i < len / 2; i++) {
        if (lower[i] != lower[len - i - 1]) {
            free(lower);
            return false;
        }
    }

    free(lower);
    return true;
}

int main() {
    // Sample test cases
    const char* test_cases[] = {
        "",
        "a",
        "1234321",
        "Racecar",
        "madam",
        "level",
        "rotor",
        "kayak",
        "stressed",
        "rotator",
        "palindrome",
        "12321",
        "Palindrome",
        "123!@#321"
    };

    // Run the tests
    for (int i = 0; i < sizeof(test_cases) / sizeof(*test_cases); i++) {
        bool result = is_palindrome(test_cases[i]);
        printf("%s: %s\n", test_cases[i], result ? "Palindrome" : "Not a palindrome");
    }

    // Assert some known results
    assert(is_palindrome("kayak"));
    assert(!is_palindrome("stressed"));

    return 0;
}