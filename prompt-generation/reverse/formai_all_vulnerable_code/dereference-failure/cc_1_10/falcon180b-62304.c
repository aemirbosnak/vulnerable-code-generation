//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* rev = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[i] = '\0';
    printf("Reversed string: %s\n", rev);
    free(rev);
}

// Function to convert a string to uppercase
void to_uppercase(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase string: %s\n", str);
}

// Function to convert a string to lowercase
void to_lowercase(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase string: %s\n", str);
}

int main() {
    // Example strings
    char* str1 = "The quick brown fox jumps over the lazy dog";
    char* str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char* str3 = "All work and no play makes Jack a dull boy";

    // Call functions to manipulate strings
    reverse_string(str1);
    to_uppercase(str2);
    to_lowercase(str3);

    return 0;
}