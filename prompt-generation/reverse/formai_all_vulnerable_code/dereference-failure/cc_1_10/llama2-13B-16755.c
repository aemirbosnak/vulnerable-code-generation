//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    // Reverse the string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to find the longest common prefix of two strings
void find_longest_common_prefix(char *str1, char *str2) {
    int i, j;

    // Find the longest common prefix
    for (i = 0, j = 0; i < strlen(str1) && i < strlen(str2); i++) {
        if (str1[i] == str2[j]) {
            j++;
        } else {
            break;
        }
    }

    // Store the longest common prefix in a new string
    char *prefix = malloc(j + 1);
    for (i = 0; i < j; i++) {
        prefix[i] = str1[i];
    }
    prefix[j] = '\0';

    // Print the longest common prefix
    printf("%s\n", prefix);
}

int main() {
    char str1[] = "banana";
    char str2[] = "ananas";

    // Reverse the first string
    reverse_string(str1);

    // Find the longest common prefix of the two strings
    find_longest_common_prefix(str1, str2);

    return 0;
}