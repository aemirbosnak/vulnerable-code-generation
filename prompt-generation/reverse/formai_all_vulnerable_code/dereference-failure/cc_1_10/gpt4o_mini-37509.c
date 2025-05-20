//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to find a substring in a string
int find_substring(const char *source, const char *substring) {
    const char *p = strstr(source, substring);
    return (p != NULL) ? (p - source) : -1; // Returns index or -1 if not found
}

// Function to concatenate two strings
char* concatenate_strings(const char *str1, const char *str2) {
    char *result = malloc(strlen(str1) + strlen(str2) + 1); // +1 for null terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Function to replace spaces with underscores in a string
void replace_spaces_with_underscores(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
}

// Function to trim whitespace from both ends of a string
char* trim_whitespace(char *str) {
    char *end;
    
    // Trim leading space
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    
    // Null terminate the new string
    end[1] = '\0';
    return str;
}

int main() {
    char input[256];
    
    printf("Enter a string (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    printf("Original string: '%s'\n", input);

    // Convert to uppercase
    char uppercase_str[256];
    strcpy(uppercase_str, input);
    to_uppercase(uppercase_str);
    printf("Uppercase: '%s'\n", uppercase_str);

    // Convert to lowercase
    char lowercase_str[256];
    strcpy(lowercase_str, input);
    to_lowercase(lowercase_str);
    printf("Lowercase: '%s'\n", lowercase_str);

    // Reverse the string
    char reversed_str[256];
    strcpy(reversed_str, input);
    reverse_string(reversed_str);
    printf("Reversed: '%s'\n", reversed_str);

    // Find a substring
    char substring[256];
    printf("Enter a substring to find: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = 0;
    
    int index = find_substring(input, substring);
    if (index != -1) {
        printf("Substring '%s' found at index %d\n", substring, index);
    } else {
        printf("Substring '%s' not found\n", substring);
    }

    // Concatenate strings
    char *concat_str = concatenate_strings(input, " is awesome!");
    printf("Concatenated string: '%s'\n", concat_str);
    free(concat_str);

    // Replace spaces with underscores
    char space_str[256];
    strcpy(space_str, input);
    replace_spaces_with_underscores(space_str);
    printf("Spaces replaced: '%s'\n", space_str);

    // Trim whitespace
    char trim_input[256];
    strcpy(trim_input, input);
    char *trimmed_str = trim_whitespace(trim_input);
    printf("Trimmed string: '%s'\n", trimmed_str);

    return 0;
}