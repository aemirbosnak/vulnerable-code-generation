//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STR_SIZE 1024

// Function to generate a random string
char *generate_random_string(int size) {
    char *str = calloc(size, sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    return str;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int len = strlen(str);
    char *rev = calloc(len, sizeof(char));
    for (int i = 0; i < len; i++) {
        rev[len - i - 1] = str[i];
    }
    return rev;
}

// Function to find the longest common prefix of two strings
char *find_lcp(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *lcp = calloc(len1 + len2, sizeof(char));
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                lcp[i + j] = str1[i];
            } else {
                break;
            }
        }
    }
    return lcp;
}

int main() {
    char *str1 = generate_random_string(STR_SIZE);
    char *str2 = generate_random_string(STR_SIZE);
    char *lcp = find_lcp(str1, str2);
    printf("Longest common prefix: %s\n", lcp);
    free(lcp);
    free(str1);
    free(str2);
    return 0;
}