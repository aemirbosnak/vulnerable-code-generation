//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 1000

bool is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - 1 - i])) {
            return false;
        }
    }
    return true;
}

void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = tolower(str[len - 1 - i]);
    }
    reversed[len] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

void remove_spaces(char* str) {
    int len = strlen(str);
    char* no_spaces = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            no_spaces[j++] = str[i];
        }
    }
    no_spaces[j] = '\0';
    strcpy(str, no_spaces);
    free(no_spaces);
}

int main() {
    char input[MAX_STRING_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_STRING_SIZE, stdin);
    remove_spaces(input);
    reverse_string(input);
    if (is_palindrome(input)) {
        printf("Your string is a palindrome and has been reversed!\n");
    } else {
        printf("Your string is not a palindrome and has been reversed.\n");
    }
    return 0;
}