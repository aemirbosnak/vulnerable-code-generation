//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom string manipulation functions
char *str_replace(char *str, char *needle, char *replacement) {
    char *result;
    char *p = strstr(str, needle);
    if (p) {
        size_t result_len = strlen(str) - strlen(needle) + strlen(replacement);
        result = malloc(result_len + 1);
        if (!result) {
            perror("malloc");
            return NULL;
        }
        memcpy(result, str, p - str);
        memcpy(result + (p - str), replacement, strlen(replacement));
        memcpy(result + (p - str) + strlen(replacement), p + strlen(needle), strlen(p + strlen(needle)) + 1);
        return result;
    }
    return NULL;
}

char *str_trim(char *str) {
    char *p = str;
    while (*p && isspace(*p)) {
        p++;
    }
    if (*p == '\0') {
        return "";
    }
    char *end = str + strlen(str) - 1;
    while (end >= p && isspace(*end)) {
        end--;
    }
    return strndup(p, end - p + 1);
}

// Main program
int main() {
    // Custom string manipulation usage examples
    char str[] = "Hello, world!";
    char *replaced = str_replace(str, "world", "Universe");
    char *trimmed = str_trim(replaced);
    printf("Original string: %s\n", str);
    printf("Replaced string: %s\n", replaced);
    printf("Trimmed string: %s\n", trimmed);

    // Free allocated memory
    free(trimmed);
    free(replaced);

    return 0;
}