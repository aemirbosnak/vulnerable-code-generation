//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - 1 - i])) {
            return false;
        }
    }
    return true;
}

char* reverse_string(char* str) {
    int len = strlen(str);
    char* reversed_str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed_str[i] = tolower(str[len - 1 - i]);
    }
    reversed_str[len] = '\0';
    return reversed_str;
}

char* remove_whitespace(char* str) {
    int len = strlen(str);
    char* new_str = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            new_str[j++] = tolower(str[i]);
        }
    }
    new_str[j] = '\0';
    return new_str;
}

int main() {
    char input_str[1000];
    printf("Enter a string: ");
    fgets(input_str, sizeof(input_str), stdin);
    char* cleaned_str = remove_whitespace(input_str);
    char* reversed_str = reverse_string(cleaned_str);
    bool is_palindrome_result = is_palindrome(reversed_str);
    if (is_palindrome_result) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }
    free(cleaned_str);
    free(reversed_str);
    return 0;
}