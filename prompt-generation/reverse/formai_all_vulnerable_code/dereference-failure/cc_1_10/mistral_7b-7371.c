//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse_string(char *str, int start, int end) {
    char temp;
    for (; start < end; ++start, --end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

int is_palindrome(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        ++start;
        --end;
    }
    return 1;
}

int main(int argc, char **argv) {
    char *input = NULL;
    int length = 0;
    if (argc < 2) {
        printf("Usage: %s <string|file>\n", argv[0]);
        return 1;
    }

    if (argc > 2 && strstr(argv[1], ".txt") != NULL) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
        fgets(input, MAX_LENGTH, file);
        fclose(file);
        length = strlen(input) - 1;
        input[length] = '\0';
    } else {
        input = argv[1];
        length = strlen(input);
    }

    if (is_palindrome(input, length)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    free(input);
    return 0;
}