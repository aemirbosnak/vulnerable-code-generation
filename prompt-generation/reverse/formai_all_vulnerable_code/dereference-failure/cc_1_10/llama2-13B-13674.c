//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 50

// Function to generate a random string
void generate_random_string(char *str) {
    int i, j;
    for (i = 0; i < MAX_STR_LEN; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[MAX_STR_LEN] = '\0';
}

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    for (i = 0; i < MAX_STR_LEN / 2; i++) {
        j = MAX_STR_LEN - i - 1;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to find the longest common prefix of two strings
char *find_longest_common_prefix(char *str1, char *str2) {
    int i, j;
    char *result = NULL;
    for (i = 0; i < MAX_STR_LEN; i++) {
        if (str1[i] == str2[i]) {
            result = str1 + i;
            break;
        }
    }
    return result;
}

int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];
    char *longest_common_prefix;

    // Generate two random strings
    generate_random_string(str1);
    generate_random_string(str2);

    // Reverse one of the strings
    reverse_string(str2);

    // Find the longest common prefix of the two strings
    longest_common_prefix = find_longest_common_prefix(str1, str2);

    // Print the longest common prefix
    printf("Longest common prefix: %s\n", longest_common_prefix);

    return 0;
}