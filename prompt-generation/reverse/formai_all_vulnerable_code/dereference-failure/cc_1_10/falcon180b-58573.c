//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char reversed[MAX_LENGTH];
    char *p;
    int i, j;
    bool isPalindrome = true;

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing whitespace
    p = input;
    while (*p!= '\0' && isspace(*p)) {
        p++;
    }
    j = strlen(p) - 1;
    while (isspace(p[j]) && j > 0) {
        p[j--] = '\0';
    }

    // Convert to lowercase
    for (i = 0; p[i]!= '\0'; i++) {
        p[i] = tolower(p[i]);
    }

    // Reverse the string
    strcpy(reversed, p);
    for (i = 0, j = strlen(p) - 1; i < j; i++, j--) {
        char temp = reversed[i];
        reversed[i] = reversed[j];
        reversed[j] = temp;
    }

    // Check if reversed string is a palindrome
    for (i = 0; i < strlen(reversed); i++) {
        if (reversed[i]!= p[i]) {
            isPalindrome = false;
            break;
        }
    }

    // Output result
    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}