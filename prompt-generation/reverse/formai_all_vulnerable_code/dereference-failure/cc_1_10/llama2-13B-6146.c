//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

// Function to generate a random string
char *generate_random_string(int length) {
    char *str = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    return str;
}

int main() {
    // Generate a random string
    char *str = generate_random_string(MIN_LENGTH + (rand() % (MAX_LENGTH - MIN_LENGTH)) + 1);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome!\n");
    } else {
        // Reverse the string
        str = reverse_string(str);

        // Check if the reversed string is a palindrome
        if (is_palindrome(str)) {
            printf("The string is a palindrome after reversing it!\n");
        } else {
            printf("The string is not a palindrome after reversing it.\n");
        }
    }

    // Free the memory
    free(str);

    return 0;
}