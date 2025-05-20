//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple function to print a string in reverse
void print_reverse(char *str) {
    if (str == NULL) {
        printf("Error: NULL string passed to print_reverse()!\n");
        return;
    }

    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// A function to count the number of vowels in a string
int count_vowels(char *str) {
    if (str == NULL) {
        printf("Error: NULL string passed to count_vowels()!\n");
        return -1;
    }

    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

// A function to remove all spaces from a string
char *remove_spaces(char *str) {
    if (str == NULL) {
        printf("Error: NULL string passed to remove_spaces()!\n");
        return NULL;
    }

    int len = strlen(str);
    char *new_str = malloc(len + 1);
    int new_str_idx = 0;
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c != ' ') {
            new_str[new_str_idx++] = c;
        }
    }
    new_str[new_str_idx] = '\0';
    return new_str;
}

// A function to convert a string to uppercase
char *to_uppercase(char *str) {
    if (str == NULL) {
        printf("Error: NULL string passed to to_uppercase()!\n");
        return NULL;
    }

    int len = strlen(str);
    char *new_str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            new_str[i] = c - 32;
        } else {
            new_str[i] = c;
        }
    }
    new_str[len] = '\0';
    return new_str;
}

int main() {
    // A sample string to work with
    char *str = "Hello, world!";

    // Print the original string
    printf("Original string: %s\n", str);

    // Print the string in reverse
    printf("Reversed string: ");
    print_reverse(str);

    // Count the number of vowels in the string
    int vowel_count = count_vowels(str);
    printf("Number of vowels: %d\n", vowel_count);

    // Remove all spaces from the string
    char *new_str = remove_spaces(str);
    printf("String with spaces removed: %s\n", new_str);

    // Convert the string to uppercase
    char *uppercase_str = to_uppercase(str);
    printf("String in uppercase: %s\n", uppercase_str);

    // Free the allocated memory
    free(new_str);
    free(uppercase_str);

    return 0;
}