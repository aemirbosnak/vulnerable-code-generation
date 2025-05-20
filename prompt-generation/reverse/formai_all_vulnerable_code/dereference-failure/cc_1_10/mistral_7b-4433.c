//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void reverse_string(char *str, int start, int end) {
    char temp;

    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

bool is_palindrome(char *str, int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

bool is_valid_input(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9') ||
              str[i] == ' ')) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    char input_str[MAX_SIZE];
    int length;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input_str, argv[1]);

    if (!is_valid_input(input_str)) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    length = strlen(input_str);

    // Check if string is a palindrome
    if (is_palindrome(input_str, length)) {
        printf("%s is a palindrome.\n", input_str);
    } else {
        // If not a palindrome, reverse the first half and compare
        reverse_string(input_str, 0, length / 2);

        if (is_palindrome(input_str, length)) {
            printf("%s is a palindrome after reversing the first half.\n", input_str);
        } else {
            printf("%s is not a palindrome.\n", input_str);
        }
    }

    return 0;
}