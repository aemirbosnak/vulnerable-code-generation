//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000

void reverse_string(char *str);
void remove_whitespace(char *str);
void capitalize_string(char *str);
void remove_vowels(char *str);
void encrypt_string(char *str);

int main() {
    char input_str[MAX_STR_LEN];
    printf("Enter a string: ");
    fgets(input_str, MAX_STR_LEN, stdin);
    printf("Original String: %s\n", input_str);

    reverse_string(input_str);
    printf("Reversed String: %s\n", input_str);

    remove_whitespace(input_str);
    printf("String with whitespace removed: %s\n", input_str);

    capitalize_string(input_str);
    printf("Capitalized String: %s\n", input_str);

    remove_vowels(input_str);
    printf("String with vowels removed: %s\n", input_str);

    encrypt_string(input_str);
    printf("Encrypted String: %s\n", input_str);

    return 0;
}

void reverse_string(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void remove_whitespace(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        if (isspace(*start)) {
            *start = '\0';
            start++;
        } else {
            start++;
        }
    }
}

void capitalize_string(char *str) {
    int len = strlen(str);
    char *start = str;
    while (start < str + len) {
        if (isalpha(*start)) {
            *start = toupper(*start);
        }
        start++;
    }
}

void remove_vowels(char *str) {
    int len = strlen(str);
    char *start = str;
    while (start < str + len) {
        if (isalpha(*start)) {
            if (*start == 'a' || *start == 'e' || *start == 'i' || *start == 'o' || *start == 'u' || *start == 'A' || *start == 'E' || *start == 'I' || *start == 'O' || *start == 'U') {
                *start = '\0';
            }
        }
        start++;
    }
}

void encrypt_string(char *str) {
    int len = strlen(str);
    char *start = str;
    while (start < str + len) {
        if (isalpha(*start)) {
            *start = (*start + 13) % 26 + 'a';
        }
        start++;
    }
}