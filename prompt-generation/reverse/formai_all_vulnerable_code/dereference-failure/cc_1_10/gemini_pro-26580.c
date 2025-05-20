//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom function to reverse a string
char* reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversed[i] = str[j];
    }
    reversed[len] = '\0';
    return reversed;
}

// A custom function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// A custom function to generate a random string
char* random_string(int len) {
    char* str = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
    return str;
}

// A custom function to print a string in a box
void print_in_box(char* str) {
    int len = strlen(str);
    int i, j;
    printf("+");
    for (i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("+\n");
    printf("| ");
    printf("%s", str);
    printf(" |\n");
    printf("+");
    for (i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    // Generate a random string
    char* str = random_string(10);

    // Print the original string
    printf("Original string: %s\n", str);

    // Reverse the string
    char* reversed = reverse(str);

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Check if the string is a palindrome
    int is_pal = is_palindrome(str);

    // Print the result
    if (is_pal) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Print the string in a box
    print_in_box(str);

    // Free the allocated memory
    free(str);
    free(reversed);

    return 0;
}