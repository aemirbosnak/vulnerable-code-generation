//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEPTH 5
#define MAX_STR_LEN 256

// Function to print a tree
void print_tree(int depth, char *str);

// Function to check if a string is a palindrome
int is_palindrome(char *str);

// Function to reverse a string
char *reverse_str(char *str);

// Function to generate a random string
char *generate_random_str(int len);

int main() {
    int depth = 0;
    char *str = NULL;

    // Generate a random string
    str = generate_random_str(MAX_STR_LEN);

    // Print the string and its reverse
    print_tree(depth, str);
    depth++;
    str = reverse_str(str);
    print_tree(depth, str);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(str);
    return 0;
}

// Function to print a tree
void print_tree(int depth, char *str) {
    if (depth == 0) {
        printf("%s\n", str);
    } else {
        printf("%s ", str);
        for (int i = 0; i < depth - 1; i++) {
            printf(" ");
        }
        print_tree(depth - 1, str);
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

// Function to reverse a string
char *reverse_str(char *str) {
    char *new_str = NULL;
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        new_str[i] = str[j];
        i++;
        j--;
    }

    new_str[i] = '\0';

    return new_str;
}

// Function to generate a random string
char *generate_random_str(int len) {
    char *str = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }

    return str;
}