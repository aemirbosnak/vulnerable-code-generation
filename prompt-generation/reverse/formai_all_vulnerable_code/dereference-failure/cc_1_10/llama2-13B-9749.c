//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024
#define MAX_ATTEMPTS 5

// Function to generate a random string
char *generate_random_string(int len) {
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char *str = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        str[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    return str;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            break;
        }
        i++;
        j--;
    }
    return (i == j);
}

int main() {
    // Generate a random string
    char *str = generate_random_string(MAX_LEN);

    // Check if the string is a palindrome
    if (!is_palindrome(str)) {
        // If not a palindrome, print an error message
        printf("Error: %s is not a palindrome\n", str);
        free(str);
        return 1;
    }

    // Print a success message
    printf("Success: %s is a palindrome\n", str);

    // Wait for the user to press a key
    getchar();

    // Free the memory allocated for the string
    free(str);

    return 0;
}