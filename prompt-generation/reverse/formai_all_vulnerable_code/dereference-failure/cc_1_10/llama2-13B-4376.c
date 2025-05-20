//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1024

void reverse_string(char *str) {
    int i, j, temp;

    for (i = 0; i < strlen(str); i++) {
        j = strlen(str) - i - 1;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[] = "This is a sample string";
    char *p;

    // Example 1: Reverse a string
    reverse_string(str);
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", str);

    // Example 2: Remove duplicates from a string
    p = str;
    while (*p != '\0') {
        if (strchr(p, *p) == NULL) {
            *p = toupper(*p);
        }
        p++;
    }
    printf("Original string: %s\n", str);
    printf("String after removing duplicates: %s\n", str);

    // Example 3: Replace all occurrences of a substring
    char *sub = "sample";
    char *new_str = "This is a new string";
    int len = strlen(new_str);
    int i, j;

    for (i = 0; i < strlen(str); i++) {
        if (strchr(str, *sub) != NULL) {
            j = strlen(str) - i - 1;
            str[i] = new_str[j];
        }
    }
    printf("Original string: %s\n", str);
    printf("String after replacing substring: %s\n", str);

    return 0;
}