//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the sum of digits in a number
int sumOfDigits(int num) {
    int sum = 0;
    while(num > 0) {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}

// Function to concatenate two C strings
char* concat(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    for(int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }

    for(int j = 0; j < len2; j++) {
        result[len1 + j] = str2[j];
    }

    result[len1 + len2] = '\0';

    return result;
}

int main() {
    char str1[20] = "Mathematical";
    char str2[20] = "Strings";
    char* result;

    // Calculate the length of str1 and str2
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("The length of str1 is %d\n", len1);
    printf("The length of str2 is %d\n", len2);

    // Calculate the sum of digits in the length of str1 and str2
    int sum1 = sumOfDigits(len1);
    int sum2 = sumOfDigits(len2);

    printf("The sum of digits in len1 is %d\n", sum1);
    printf("The sum of digits in len2 is %d\n", sum2);

    // Concatenate str1 and str2
    result = concat(str1, str2);

    printf("The concatenated string is %s\n", result);

    // Calculate the square root of sum1 and sum2
    float sqrt1 = sqrt(sum1);
    float sqrt2 = sqrt(sum2);

    printf("The square root of sum1 is %f\n", sqrt1);
    printf("The square root of sum2 is %f\n", sqrt2);

    // Free the memory allocated to result
    free(result);

    return 0;
}