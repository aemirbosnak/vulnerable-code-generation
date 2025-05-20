//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(char* str);
int count_vowels(char* str);
char* remove_duplicates(char* str);

int main() {
    // reverse_string example
    char str1[] = "hello world";
    char* reversed_str1 = reverse_string(str1);
    printf("Reversed string: %s\n", reversed_str1);

    // count_vowels example
    char str2[] = "this is a test string";
    int num_vowels = count_vowels(str2);
    printf("Number of vowels: %d\n", num_vowels);

    // remove_duplicates example
    char str3[] = "hello world";
    char* filtered_str3 = remove_duplicates(str3);
    printf("Filtered string: %s\n", filtered_str3);

    return 0;
}

// reverses a C string
char* reverse_string(char* str) {
    int len = strlen(str);
    char* reversed_str = malloc(sizeof(char) * (len + 1));
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        reversed_str[j] = str[i];
    }
    reversed_str[j] = '\0';
    return reversed_str;
}

// counts the number of vowels in a C string
int count_vowels(char* str) {
    int num_vowels = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            num_vowels++;
        }
    }
    return num_vowels;
}

// removes duplicate characters from a C string
char* remove_duplicates(char* str) {
    int len = strlen(str);
    char* filtered_str = malloc(sizeof(char) * (len + 1));
    int i, j, k;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (i == j) {
            filtered_str[k++] = str[i];
        }
    }
    filtered_str[k] = '\0';
    return filtered_str;
}