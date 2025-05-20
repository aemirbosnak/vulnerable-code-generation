//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024

// Function to generate a random string
char *generate_random_string(int len) {
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    char *str = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return str;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int len = strlen(str);
    char *result = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        result[i] = str[len - i - 1];
    }
    return result;
}

// Function to concatenate two strings
char *concat_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = malloc(len1 + len2 + 1);
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
    srand(time(NULL)); // seed the random number generator

    // Generate a random string
    char *str1 = generate_random_string(50);
    printf("Original string: %s\n", str1);

    // Reverse the string
    char *str2 = reverse_string(str1);
    printf("Reversed string: %s\n", str2);

    // Concatenate the string with a random string
    char *str3 = generate_random_string(20);
    char *result = concat_strings(str1, str3);
    printf("Concatenated string: %s\n", result);

    free(str1);
    free(str2);
    free(result);

    return 0;
}