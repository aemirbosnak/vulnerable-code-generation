//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
void reverse_string(char *str) {
    char *temp = str;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = temp[len - i - 1];
    }
}

// Function to count the number of vowels in a string
int count_vowels(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }
    return count;
}

// Function to replace all vowels with their corresponding numbers
char *replace_vowels(char *str) {
    char *new_str = malloc(strlen(str) * sizeof(char));
    int i = 0;
    for (; i < strlen(str); i++) {
        if (str[i] == 'a') {
            new_str[i] = '2';
        } else if (str[i] == 'e') {
            new_str[i] = '3';
        } else if (str[i] == 'i') {
            new_str[i] = '4';
        } else if (str[i] == 'o') {
            new_str[i] = '5';
        } else if (str[i] == 'u') {
            new_str[i] = '6';
        } else {
            new_str[i] = str[i];
        }
    }
    return new_str;
}

int main() {
    char str[] = "Hello World!";
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    int vowel_count = count_vowels(str);
    printf("Number of vowels: %d\n", vowel_count);

    char *new_str = replace_vowels(str);
    printf("Replaced string: %s\n", new_str);

    free(new_str);
    return 0;
}