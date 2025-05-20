//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    strcpy(reversed, str);
    for (int i = 0; i < len / 2; i++) {
        char temp = reversed[i];
        reversed[i] = reversed[len - i - 1];
        reversed[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

void replace_char(char* str, char old_char, char new_char) {
    int len = strlen(str);
    char* temp = malloc(len + 1);
    strcpy(temp, str);
    for (int i = 0; i < len; i++) {
        if (temp[i] == old_char) {
            temp[i] = new_char;
        }
    }
    printf("Replaced string: %s\n", temp);
    free(temp);
}

void remove_char(char* str, char remove_char) {
    int len = strlen(str);
    char* temp = malloc(len + 1);
    strcpy(temp, str);
    for (int i = 0; i < len; i++) {
        if (temp[i] == remove_char) {
            temp[i] = '\0';
        }
    }
    printf("Removed string: %s\n", temp);
    free(temp);
}

int main() {
    char string[MAX_SIZE];
    printf("Enter a string: ");
    fgets(string, MAX_SIZE, stdin);
    printf("Original string: %s\n", string);
    reverse_string(string);
    replace_char(string, 'a', 'x');
    remove_char(string, 'x');
    return 0;
}