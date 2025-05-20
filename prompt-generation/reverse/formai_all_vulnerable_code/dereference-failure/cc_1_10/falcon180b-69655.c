//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

bool is_palindrome(char* str);

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    if (is_palindrome(input)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    return 0;
}

bool is_palindrome(char* str) {
    int length = strlen(str);
    char* reversed_str = malloc(length + 1); // Allocate memory for reversed string
    int i = 0, j = length - 1;
    while (i < j) {
        if (!isalnum(str[i])) {
            i++;
        } else if (!isalnum(str[j])) {
            j--;
        } else {
            if (tolower(str[i])!= tolower(str[j])) {
                free(reversed_str);
                return false;
            }
            reversed_str[i] = tolower(str[i]);
            reversed_str[j] = tolower(str[j]);
            i++;
            j--;
        }
    }
    if (i >= j) {
        if (!isalnum(str[i])) {
            i++;
        }
        if (!isalnum(str[j])) {
            j--;
        }
        if (tolower(str[i])!= tolower(str[j])) {
            free(reversed_str);
            return false;
        }
        reversed_str[i] = tolower(str[i]);
        reversed_str[j] = tolower(str[j]);
    }
    reversed_str[length] = '\0'; // Add null terminator to reversed string
    if (strcmp(str, reversed_str) == 0) {
        free(reversed_str);
        return true;
    } else {
        free(reversed_str);
        return false;
    }
}