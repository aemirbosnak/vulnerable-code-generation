//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers within a range
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random string of given length
char* randStr(int len) {
    char* str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
    return str;
}

int main() {
    srand(time(NULL)); // Initialize random seed with current time

    int num1, num2, result;
    char* str1, *str2;

    // Generate two random integers and perform arithmetic operations
    num1 = randInt(1, 100);
    num2 = randInt(1, 100);
    printf("Random numbers: %d and %d\n", num1, num2);
    result = num1 + num2;
    printf("Sum: %d\n", result);
    result = num1 - num2;
    printf("Difference: %d\n", result);
    result = num1 * num2;
    printf("Product: %d\n", result);

    // Generate two random strings and concatenate them
    str1 = randStr(10);
    str2 = randStr(10);
    printf("Random strings: %s and %s\n", str1, str2);
    char* concat = malloc(strlen(str1) + strlen(str2) + 1);
    strcat(concat, str1);
    strcat(concat, str2);
    printf("Concatenated string: %s\n", concat);

    // Free dynamically allocated memory
    free(str1);
    free(str2);
    free(concat);

    return 0;
}