//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print a string in uppercase
void print_uppercase(char* str) {
    int i;
    for(i = 0; str[i]!= '\0'; i++) {
        printf("%c", toupper(str[i]));
    }
}

// Function to print a string in lowercase
void print_lowercase(char* str) {
    int i;
    for(i = 0; str[i]!= '\0'; i++) {
        printf("%c", tolower(str[i]));
    }
}

// Function to print a string in reverse order
void print_reverse(char* str) {
    int i, j;
    char* reverse_str = malloc(strlen(str) + 1);
    strcpy(reverse_str, str);
    for(i = strlen(reverse_str) - 1, j = 0; i >= 0; i--, j++) {
        reverse_str[j] = reverse_str[i];
    }
    printf("%s", reverse_str);
    free(reverse_str);
}

// Function to print a string in alternating uppercase and lowercase
void print_alternating(char* str) {
    int i;
    for(i = 0; str[i]!= '\0'; i++) {
        if(i % 2 == 0) {
            printf("%c", toupper(str[i]));
        } else {
            printf("%c", tolower(str[i]));
        }
    }
}

int main() {
    char* str = "Hello, World! ";

    // Print the string in uppercase
    print_uppercase(str);
    printf("\n");

    // Print the string in lowercase
    print_lowercase(str);
    printf("\n");

    // Print the string in reverse order
    print_reverse(str);
    printf("\n");

    // Print the string in alternating uppercase and lowercase
    print_alternating(str);
    printf("\n");

    return 0;
}