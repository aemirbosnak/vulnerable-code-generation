//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to remove leading and trailing whitespaces
void trim_string(char *str) {
    int i, j;

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

// Function to concatenate two strings
char *concat_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 1);

    for (int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }
    for (int i = 0; i < len2; i++) {
        result[i + len1] = str2[i];
    }
    result[len1 + len2] = '\0';

    return result;
}

int main() {
    char str1[] = "Hello World!";
    char str2[] = " How are you?";
    char *result;

    // Reverse the first string
    reverse_string(str1);

    // Remove leading and trailing whitespaces from both strings
    trim_string(str1);
    trim_string(str2);

    // Concatenate the two strings
    result = concat_strings(str1, str2);

    printf("The concatenated string is: %s\n", result);

    free(result);

    return 0;
}