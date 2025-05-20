//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        reversed[i] = str[j];
        reversed[j] = str[i];
    }
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

void replace_substring(char* str, char* old_substring, char* new_substring) {
    int length = strlen(str);
    char* result = malloc(length + 1);
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (str[i] == old_substring[j]) {
            j++;
            if (j == strlen(old_substring)) {
                j = 0;
                strcat(result, new_substring);
            }
        } else {
            result[i] = str[i];
        }
    }
    result[length] = '\0';
    printf("Result: %s\n", result);
    free(result);
}

int main() {
    char string1[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(string1, MAX_STRING_LENGTH, stdin);
    reverse_string(string1);

    char string2[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(string2, MAX_STRING_LENGTH, stdin);
    char* old_substring = "world";
    char* new_substring = "universe";
    replace_substring(string2, old_substring, new_substring);

    return 0;
}