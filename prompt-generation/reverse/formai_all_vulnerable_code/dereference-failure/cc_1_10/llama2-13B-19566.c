//LLAMA2-13B DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

int main() {
    char *surprise;
    int i, j, k;
    char magic[MAGIC_NUMBER];

    // Generate a random surprise
    srand(time(NULL));
    for (i = 0; i < MAX_LENGTH; i++) {
        surprise[i] = 'a' + (rand() % 26);
    }

    // Check if the surprise is a palindrome
    for (j = 0; j < MAX_LENGTH / 2; j++) {
        k = j;
        while (k < MAX_LENGTH && surprise[k] == surprise[MAX_LENGTH - k - 1]) {
            k++;
        }
        if (k == MAX_LENGTH) {
            printf("Surprise! You've won a prize!\n");
            break;
        }
    }

    // Check if the surprise is a word
    for (j = 0; j < MAX_LENGTH; j++) {
        if (isalpha(surprise[j]) && isword(surprise + j)) {
            printf("Word found! The surprise is a word.\n");
            break;
        }
    }

    // Check if the surprise is a sentence
    for (j = 0; j < MAX_LENGTH; j++) {
        if (isalpha(surprise[j]) && isword(surprise + j) && isword(surprise + j + 1)) {
            printf("Sentence found! The surprise is a sentence.\n");
            break;
        }
    }

    // Check if the surprise is a palindrome word
    for (j = 0; j < MAX_LENGTH; j++) {
        if (isalpha(surprise[j]) && isword(surprise + j) && ispalindrome(surprise + j, MAX_LENGTH - j - 1)) {
            printf("Palindrome word found! The surprise is a palindrome word.\n");
            break;
        }
    }

    // Check if the surprise is a palindrome sentence
    for (j = 0; j < MAX_LENGTH; j++) {
        if (isalpha(surprise[j]) && isword(surprise + j) && isword(surprise + j + 1) && ispalindrome(surprise + j, MAX_LENGTH - j - 1)) {
            printf("Palindrome sentence found! The surprise is a palindrome sentence.\n");
            break;
        }
    }

    // Print the surprise
    printf("The surprise is: %s\n", surprise);

    return 0;
}

// Function to check if a string is a palindrome
int ispalindrome(const char *str, int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a word
int isword(const char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}