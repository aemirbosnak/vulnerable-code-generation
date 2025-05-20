//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(MAX_SIZE);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        reversed[i] = str[j];
        i++;
    }
    reversed[i] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

void replace_character(char* str, char old_char, char new_char) {
    int len = strlen(str);
    char* new_str = malloc(MAX_SIZE);
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (str[j] == old_char) {
            new_str[i] = new_char;
        } else {
            new_str[i] = str[j];
        }
        i++;
    }
    new_str[i] = '\0';
    printf("New string: %s\n", new_str);
    free(new_str);
}

void remove_vowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* new_str = malloc(MAX_SIZE);
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (strchr(vowels, str[j]) == NULL) {
            new_str[i] = str[j];
        }
        i++;
    }
    new_str[i] = '\0';
    printf("New string: %s\n", new_str);
    free(new_str);
}

void uppercase_string(char* str) {
    int len = strlen(str);
    char* new_str = malloc(MAX_SIZE);
    int i = 0;
    for (int j = 0; j < len; j++) {
        new_str[i] = toupper(str[j]);
        i++;
    }
    new_str[i] = '\0';
    printf("New string: %s\n", new_str);
    free(new_str);
}

int main() {
    char* str = "Hello, world!";
    reverse_string(str);
    replace_character(str, 'o', '0');
    remove_vowels(str);
    uppercase_string(str);
    return 0;
}