//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = "Hello, world!";
    int len = strlen(s);

    printf("Original string: %s\n", s);

    // Reverse the string
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }

    printf("Reversed string: %s\n", s);

    // Convert to uppercase
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }

    printf("Uppercase string: %s\n", s);

    // Convert to lowercase
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }

    printf("Lowercase string: %s\n", s);

    // Remove all spaces
    char *new_s = malloc(len);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
            new_s[j++] = s[i];
        }
    }
    new_s[j] = '\0';

    printf("String without spaces: %s\n", new_s);

    // Free the allocated memory
    free(new_s);

    return 0;
}