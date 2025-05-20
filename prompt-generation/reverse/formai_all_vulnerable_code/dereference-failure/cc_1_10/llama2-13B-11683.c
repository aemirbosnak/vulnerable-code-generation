//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1024

void print_string(const char *str) {
    printf("String: %s\n", str);
}

void swap_case(char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr + ('A' - 'a');
        }
        ptr++;
    }
}

void reverse_string(char *str) {
    size_t len = strlen(str);
    char *ptr = str;
    char *end = ptr + len - 1;
    while (ptr < end) {
        char temp = *ptr;
        *ptr = *end;
        *end = temp;
        ptr++;
        end--;
    }
}

void print_palindrome(char *str) {
    printf("Palindrome: %s\n", str);
}

void generate_random_string(char *str, size_t len) {
    srand(time(NULL));
    for (size_t i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }
}

int main() {
    char str[MAX_LEN];

    // Example 1: Print a string
    print_string("Hello, World!");

    // Example 2: Swap case of a string
    swap_case(str);
    print_string(str);

    // Example 3: Reverse a string
    reverse_string(str);
    print_string(str);

    // Example 4: Check if a string is a palindrome
    print_palindrome(str);

    // Example 5: Generate a random string
    generate_random_string(str, 10);
    print_string(str);

    return 0;
}