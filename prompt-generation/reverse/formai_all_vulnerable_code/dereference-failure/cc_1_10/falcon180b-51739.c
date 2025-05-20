//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random float between min and max (inclusive)
float randFloat(float min, float max) {
    return (float)rand() / RAND_MAX * (max - min) + min;
}

// Function to generate a random string of length n
char* randString(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[n] = '\0';
    return str;
}

int main() {
    srand(time(NULL));

    // Example usage of randInt
    int num1 = randInt(1, 10);
    int num2 = randInt(1, 10);
    int sum = num1 + num2;
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    // Example usage of randFloat
    float num3 = randFloat(1.0, 10.0);
    float num4 = randFloat(1.0, 10.0);
    float product = num3 * num4;
    printf("The product of %.2f and %.2f is %.2f.\n", num3, num4, product);

    // Example usage of randString
    char* str1 = randString(5);
    char* str2 = randString(5);
    printf("Random string 1: %s\n", str1);
    printf("Random string 2: %s\n", str2);

    // Example usage of arithmetic operators
    int num5 = 10;
    int num6 = 5;
    int result1 = num5 + num6;
    int result2 = num5 - num6;
    int result3 = num5 * num6;
    int result4 = num5 / num6;
    printf("Arithmetic operations:\n");
    printf("10 + 5 = %d\n", result1);
    printf("10 - 5 = %d\n", result2);
    printf("10 * 5 = %d\n", result3);
    printf("10 / 5 = %d\n", result4);

    return 0;
}