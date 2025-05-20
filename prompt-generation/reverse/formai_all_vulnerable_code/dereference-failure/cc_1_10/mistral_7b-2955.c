//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void str_reverse(char *str, int start, int end);
int get_string_length(char *str);
int is_alphanumeric(char c);
void to_lowercase(char *str);
void print_string(char *str);

int main() {
    char input_str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input_str, MAX_LENGTH, stdin);
    input_str[strcspn(input_str, "\n")] = '\0';

    to_lowercase(input_str);

    int length = get_string_length(input_str);

    char reversed_str[length];

    str_reverse(input_str, 0, length - 1);
    strcpy(reversed_str, input_str);

    for (int i = length - 1; i >= 0; i--) {
        input_str[i] = reversed_str[length - i - 1];
    }

    printf("Original String: %s\n", input_str);
    printf("Reversed String: %s\n", input_str);

    return 0;
}

void str_reverse(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int get_string_length(char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int is_alphanumeric(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        return 1;
    }

    return 0;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i])) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32;
            }
        }
    }
}

void print_string(char *str) {
    printf("%s", str);
}