//Falcon-180B DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to count words in a string
int count_words(char *str) {
    int count = 0;
    char *word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Helper function to reverse a string
char *reverse_string(char *str) {
    int length = strlen(str);
    char *reversed_str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed_str[i] = str[length - 1 - i];
    }
    reversed_str[length] = '\0';
    return reversed_str;
}

// Helper function to check if a string is a palindrome
int is_palindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input_string[1000];
    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // Remove newline character

    // Count words in the string
    int word_count = count_words(input_string);
    printf("Number of words: %d\n", word_count);

    // Reverse the string
    char *reversed_string = reverse_string(input_string);
    printf("Reversed string: %s\n", reversed_string);

    // Check if the string is a palindrome
    int is_palindrome_result = is_palindrome(reversed_string);
    if (is_palindrome_result) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(reversed_string);
    return 0;
}