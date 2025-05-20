//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

void remove_whitespace(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        end--;
    }
    if (start > end) {
        str[0] = '\0';
    } else {
        memmove(start, end + 1, strlen(end + 1) + 1);
    }
}

void reverse_string(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void replace_characters(char* str, char find, char replace) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start <= end) {
        if (*start == find) {
            *start = replace;
        }
        start++;
    }
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    remove_whitespace(input_string);
    printf("String with whitespace removed: %s\n", input_string);

    reverse_string(input_string);
    printf("String reversed: %s\n", input_string);

    char find_char, replace_char;
    printf("Enter a character to find: ");
    scanf(" %c", &find_char);
    printf("Enter a character to replace with: ");
    scanf(" %c", &replace_char);

    replace_characters(input_string, find_char, replace_char);
    printf("String with characters replaced: %s\n", input_string);

    return 0;
}