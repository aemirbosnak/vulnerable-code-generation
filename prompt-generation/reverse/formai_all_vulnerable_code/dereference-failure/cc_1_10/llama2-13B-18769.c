//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024

void dynamic_string_example(void) {
    char *str = NULL;
    size_t len = 0;

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    // Trim the string to remove any trailing newline or whitespace
    str[strcspn(str, "\n\r")] = '\0';

    // Split the string into words using a dynamic array
    char *words[5];
    char *p = str;
    int i = 0;
    while (*p != '\0') {
        if (*p == ' ' || *p == '\t') {
            // Find the end of the current word
            p = strchr(p, ' ');
            if (p == NULL) {
                p = str + strlen(str);
            }

            // Add the word to the dynamic array
            words[i++] = p;

            // Move to the next word
            p = strchr(p + 1, ' ');
        }
    }

    // Print the words in the dynamic array
    for (int j = 0; j < i; j++) {
        printf("%s ", words[j]);
    }

    // Free the dynamic array
    for (int j = 0; j < i; j++) {
        free(words[j]);
    }

    return;
}

int main(void) {
    dynamic_string_example();
    return 0;
}