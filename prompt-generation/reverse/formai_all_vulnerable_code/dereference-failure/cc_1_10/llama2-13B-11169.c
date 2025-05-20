//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STRING_SIZE 1024

// Function to generate a random string
void generate_random_string(char *str) {
    int i, j, length = 10;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
}

// Function to reverse a string
void reverse_string(char *str) {
    int i, j, length = strlen(str);
    char temp[length];
    for (i = 0; i < length; i++) {
        temp[j = length - i - 1] = str[i];
    }
    strcpy(str, temp);
}

// Function to find the longest common prefix of two strings
void find_longest_common_prefix(char *str1, char *str2) {
    int i, j, length = strlen(str1);
    char temp[length];
    for (i = 0; i < length; i++) {
        temp[j = i] = str1[i];
    }
    strcpy(str1, temp);
    for (i = 0; i < length; i++) {
        if (str2[i] != str1[i]) break;
    }
    strcpy(str2, temp);
}

int main() {
    char str1[STRING_SIZE], str2[STRING_SIZE], temp[STRING_SIZE];
    generate_random_string(str1);
    generate_random_string(str2);
    find_longest_common_prefix(str1, str2);
    reverse_string(str1);
    reverse_string(str2);
    printf("Original strings: %s %s\n", str1, str2);
    printf("Longest common prefix: %s\n", str1);
    printf("Reversed strings: %s %s\n", str2, str1);
    return 0;
}