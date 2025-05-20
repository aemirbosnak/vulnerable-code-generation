//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
char *string;
int length;
pthread_mutex_t lock;

// Function to check if a character is a delimiter
int isDelimiter(char ch) {
    if (ch == ' ' || ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == '\0')
        return 1;
    return 0;
}

// Function to remove delimiters from a string
void removeDelimiters(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isDelimiter(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverseString(char *str) {
    int i, length = strlen(str);
    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int i, j, length = strlen(str);
    for (i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

// Thread function to check if a substring is a palindrome
void *checkPalindrome(void *arg) {
    int start = *((int *)arg);
    int end = *((int *)arg + 1);
    int i, length = strlen(string);

    // Lock the mutex
    pthread_mutex_lock(&lock);

    // Check if the substring is a palindrome
    for (i = start; i <= end / 2; i++) {
        if (string[i] != string[end - i]) {
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&lock);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    int numThreads, i, length, numSubstrings;

    // Get the input string
    printf("Enter a string: ");
    scanf("%s", string);

    // Remove delimiters from the string
    removeDelimiters(string);

    // Get the length of the string
    length = strlen(string);

    // Calculate the number of substrings
    numSubstrings = length * (length + 1) / 2;

    // Create a mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads to check if substrings are palindromes
    pthread_t threads[numSubstrings];
    for (i = 0; i < numSubstrings; i++) {
        int *args = malloc(2 * sizeof(int));
        args[0] = i;
        args[1] = length - 1 - i;
        pthread_create(&threads[i], NULL, checkPalindrome, (void *)args);
    }

    // Wait for all threads to complete
    for (i = 0; i < numSubstrings; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    // Check if the string is a palindrome
    if (isPalindrome(string)) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }

    return 0;
}