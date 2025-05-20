//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define MAX_NUMBER 1000000

// Generate a random number between 1 and MAX_NUMBER
int getRandomNumber() {
    return rand() % MAX_NUMBER;
}

// Generate a random string of length MAX_SIZE
char *getRandomString() {
    char *str = malloc(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    return str;
}

// Check if two numbers are equal
int areNumbersEqual(int a, int b) {
    return a == b;
}

// Check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Generate a random number and print it
    int number = getRandomNumber();
    printf("Random number: %d\n", number);

    // Generate a random string and print it
    char *str = getRandomString();
    printf("Random string: %s\n", str);

    // Check if the number is a palindrome
    if (isPalindrome(str)) {
        printf("The number is a palindrome\n");
    } else {
        printf("The number is not a palindrome\n");
    }

    // Check if two numbers are equal
    int number2 = getRandomNumber();
    if (areNumbersEqual(number, number2)) {
        printf("The two numbers are equal\n");
    } else {
        printf("The two numbers are not equal\n");
    }

    // Free the memory allocated for the random string
    free(str);

    return 0;
}