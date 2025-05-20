//Falcon-180B DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to generate a random string of given length
char *generate_random_string(int length) {
    char *result = malloc(length + 1); // Allocate memory for the string
    if (result == NULL) {
        fprintf(stderr, "Error: Could not allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < length; i++) {
        result[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    result[length] = '\0'; // Null-terminate the string
    return result;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int length = strlen(str);
    char *result = malloc(length + 1);
    if (result == NULL) {
        fprintf(stderr, "Error: Could not allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++) {
        result[i] = str[length - i - 1];
    }
    result[length] = '\0';
    return result;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    char *reverse = reverse_string(str);
    int result = strcmp(str, reverse);
    free(reverse);
    return result;
}

int main() {
    int length;
    printf("Enter the length of the string: ");
    scanf("%d", &length);

    char *str = generate_random_string(length);
    printf("Random string: %s\n", str);

    int is_palindrome_result = is_palindrome(str);
    if (is_palindrome_result == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(str);
    return 0;
}