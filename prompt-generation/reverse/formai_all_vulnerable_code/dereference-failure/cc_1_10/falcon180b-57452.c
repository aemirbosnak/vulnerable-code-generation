//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80

// Function to convert a string to all uppercase
void str_to_upper(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to convert a string to all lowercase
void str_to_lower(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to print a string centered on the screen
void print_centered(char* str) {
    int length = strlen(str);
    int spaces = (MAX_LINE_LENGTH - length) / 2;
    printf("%*s%s\n", spaces, "", str);
}

// Function to print a string in a box
void print_box(char* str) {
    int length = strlen(str);
    int spaces = (MAX_LINE_LENGTH - length) / 2;
    printf("+%*s+\n", spaces, "");
    printf("|%s|\n", str);
    printf("+%*s+\n", spaces, "");
}

// Function to convert a string to ASCII art
void ascii_art(char* str) {
    int i = 0;
    char* new_str = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (!new_str) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    while (str[i]) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                new_str[i] = '@';
            } else {
                new_str[i] = 'a';
            }
        } else if (isdigit(str[i])) {
            new_str[i] = '0' + (str[i] - '0');
        } else {
            new_str[i] = str[i];
        }
        i++;
    }
    printf("%s\n", new_str);
    free(new_str);
}

int main() {
    char* input;
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        str_to_upper(input);
        print_centered(input);
        str_to_lower(input);
        print_box(input);
        ascii_art(input);
        printf("\n");
    }
    return 0;
}