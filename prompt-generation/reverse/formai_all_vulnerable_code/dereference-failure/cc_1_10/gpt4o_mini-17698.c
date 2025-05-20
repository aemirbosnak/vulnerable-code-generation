//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void add_borders(char *str) {
    int n = strlen(str);
    char *bordered_string = (char *)malloc(n + 4); // Extra space for borders
    strcpy(bordered_string + 2, str); // Copy original string
    bordered_string[0] = '*'; // Left border
    bordered_string[1] = ' ';
    bordered_string[n + 2] = ' ';
    bordered_string[n + 3] = '*'; // Right border
    bordered_string[n + 4] = '\0'; // Null terminator

    printf("%s\n", bordered_string);
    free(bordered_string);
}

int main() {
    char input[100];
    
    printf("Welcome to the String Decorator!\n");
    printf("Please enter a string (max 99 characters): ");
    
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline character from fgets
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    printf("\nOriginal String: %s\n", input);

    // Make uppercase
    char upper_string[100];
    strcpy(upper_string, input);
    to_uppercase(upper_string);
    printf("Uppercase String: %s\n", upper_string);

    // Reverse string
    char reversed_string[100];
    strcpy(reversed_string, input);
    reverse_string(reversed_string);
    printf("Reversed String: %s\n", reversed_string);

    // Add borders
    printf("String with Borders:\n");
    add_borders(input);

    // Beautifying the string further by using combination of transformations
    printf("Combined Transformation:\n");
    char combined_string[100];
    strcpy(combined_string, input);
    
    reverse_string(combined_string);
    to_uppercase(combined_string);
    add_borders(combined_string);

    printf("Thank you for using the String Decorator!\n");
    return 0;
}