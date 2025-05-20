//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void remove_whitespace(char *str) {
    int i = 0, j = 0;

    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }

    str[j] = '\0';
}

int is_palindrome(char *str) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char input_str[MAX_LENGTH];
    strcpy(input_str, argv[1]);

    remove_whitespace(input_str);

    if (is_palindrome(input_str)) {
        printf("%s is a palindrome.\n", input_str);
    } else {
        printf("%s is not a palindrome.\n", input_str);
    }

    return 0;
}