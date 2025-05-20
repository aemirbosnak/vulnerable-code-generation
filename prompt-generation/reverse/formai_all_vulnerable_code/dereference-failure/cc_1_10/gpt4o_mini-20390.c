//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void reverse_string(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void remove_vowels(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (!strchr("AEIOUaeiou", *src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

void count_words(char *str) {
    int count = 0;
    char *token = strtok(str, " \n");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }
    printf("Word count: %d\n", count);
}

void print_string_info(char *str) {
    printf("Original string: %s\n", str);
    printf("Length: %zu\n", strlen(str));

    char *str_copy = (char *)malloc(strlen(str) + 1);
    
    // Uppercase
    strcpy(str_copy, str);
    to_uppercase(str_copy);
    printf("Uppercase: %s\n", str_copy);
    
    // Lowercase
    strcpy(str_copy, str);
    to_lowercase(str_copy);
    printf("Lowercase: %s\n", str_copy);

    // Reversed
    strcpy(str_copy, str);
    reverse_string(str_copy);
    printf("Reversed: %s\n", str_copy);
    
    // Without vowels
    strcpy(str_copy, str);
    remove_vowels(str_copy);
    printf("Without vowels: %s\n", str_copy);

    // Word count
    strcpy(str_copy, str);
    count_words(str_copy);

    free(str_copy);
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    print_string_info(input);

    return EXIT_SUCCESS;
}