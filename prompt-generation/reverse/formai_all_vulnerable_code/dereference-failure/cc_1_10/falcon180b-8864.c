//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to remove non-alphanumeric characters from a string
char *remove_non_alphanumeric(char *str) {
    char *result = strdup(str);
    char *p = result;
    while (*p) {
        if (!isalnum(*p)) {
            *p = '\0';
        }
        p++;
    }
    return result;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int length = strlen(str);
    char *result = malloc(length + 1);
    char *p = result;
    char *q = str + length - 1;
    while (q >= str) {
        *p++ = *q--;
    }
    *p = '\0';
    return result;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    char *clean_str = remove_non_alphanumeric(str);
    char *reversed_str = reverse_string(clean_str);
    int result = strcmp(clean_str, reversed_str) == 0;
    free(clean_str);
    free(reversed_str);
    return result;
}

int main() {
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        if (is_palindrome(input)) {
            printf("Palindrome\n");
        } else {
            printf("Not a palindrome\n");
        }
    }
    return 0;
}