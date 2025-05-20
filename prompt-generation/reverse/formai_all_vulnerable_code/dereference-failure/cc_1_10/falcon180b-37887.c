//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed_str = malloc(length + 1);
    int i = 0;
    for (int j = length - 1; j >= 0; j--) {
        reversed_str[i++] = str[j];
    }
    reversed_str[i] = '\0';
    printf("Reversed string: %s\n", reversed_str);
    free(reversed_str);
}

void capitalize_string(char* str) {
    int length = strlen(str);
    char* capitalized_str = malloc(length + 1);
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (isalpha(str[j])) {
            capitalized_str[i++] = toupper(str[j]);
        } else {
            capitalized_str[i++] = str[j];
        }
    }
    capitalized_str[i] = '\0';
    printf("Capitalized string: %s\n", capitalized_str);
    free(capitalized_str);
}

void remove_vowels(char* str) {
    int length = strlen(str);
    char* vowels = "AEIOUaeiou";
    char* result_str = malloc(length + 1);
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (strchr(vowels, tolower(str[j])) == NULL) {
            result_str[i++] = str[j];
        }
    }
    result_str[i] = '\0';
    printf("Result string: %s\n", result_str);
    free(result_str);
}

int main() {
    char* input_str = malloc(MAX_LENGTH);
    printf("Enter a string: ");
    scanf("%s", input_str);

    reverse_string(input_str);
    capitalize_string(input_str);
    remove_vowels(input_str);

    free(input_str);
    return 0;
}