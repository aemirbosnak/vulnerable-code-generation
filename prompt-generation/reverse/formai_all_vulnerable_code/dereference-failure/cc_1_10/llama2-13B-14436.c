//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STRING_MAX_LEN 1024

void string_reverse(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void string_rotate(char *str, int n) {
    int i, j;
    char temp;

    for (i = 0; i < n / 2; i++) {
        j = strlen(str) - i - 1;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void string_insert(char *str, int pos, char c) {
    int i, j;

    for (i = 0, j = pos - 1; i < j; i++, j--) {
        str[i] = str[j];
    }
    str[j] = c;
}

void string_remove(char *str, int pos) {
    int i, j;

    for (i = 0, j = pos - 1; i < j; i++, j--) {
        str[i] = str[j];
    }
    str[j] = '\0';
}

int main() {
    char str[STRING_MAX_LEN];
    int n;

    printf("Enter a string: ");
    fgets(str, STRING_MAX_LEN, stdin);

    printf("Original string: %s\n", str);

    // Reverse the string
    string_reverse(str);
    printf("Reversed string: %s\n", str);

    // Rotate the string by 3 positions
    string_rotate(str, 3);
    printf("Rotated string: %s\n", str);

    // Insert the character 'a' at position 5
    string_insert(str, 5, 'a');
    printf("Inserted string: %s\n", str);

    // Remove the character 'e' at position 8
    string_remove(str, 8);
    printf("Removed string: %s\n", str);

    return 0;
}