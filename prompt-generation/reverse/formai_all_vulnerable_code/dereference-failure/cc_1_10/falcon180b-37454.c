//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

// Function to remove leading and trailing spaces from a string
void trim(char* str) {
    int len = strlen(str);
    int i = 0, j = len - 1;
    while (i < j) {
        if (!isspace(str[i])) {
            str[i] = str[j];
            i++;
            j--;
        }
        else {
            i++;
        }
    }
    str[i] = '\0';
}

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <output_filename>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 2;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 3;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        trim(line);
        if (is_palindrome(line)) {
            fprintf(output_file, "%s\n", line);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}