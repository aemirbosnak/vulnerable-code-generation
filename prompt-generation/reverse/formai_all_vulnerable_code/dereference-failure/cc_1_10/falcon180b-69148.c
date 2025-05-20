//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void reverse_string(char *str, int length) {
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int is_palindrome(char *str) {
    int length = strlen(str);
    int i;

    for (i = 0; i < length / 2; i++) {
        if (tolower(str[i])!= tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *clean_line;
    int line_length;
    int is_palindrome_flag = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_length = strlen(line);

        // Remove leading/trailing whitespace and newline character
        clean_line = line + line_length - 1;
        while (clean_line > line && isspace(*clean_line)) {
            *clean_line-- = '\0';
        }

        // Check if the line is a palindrome
        if (is_palindrome(clean_line)) {
            is_palindrome_flag = 1;
        }
    }

    fclose(fp);

    if (is_palindrome_flag) {
        printf("The file contains at least one palindrome.\n");
    } else {
        printf("The file does not contain any palindromes.\n");
    }

    return 0;
}