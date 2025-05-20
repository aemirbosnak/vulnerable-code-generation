//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    float float1, float2, result2;
    double double1, double2, result3;
    char str1[100];
    char str2[100];

    srand(time(NULL));

    printf("Welcome to the Math Playground! \n");

    // Section 1: Addition
    num1 = rand() % 100;
    num2 = rand() % 100;
    result = num1 + num2;
    printf("The sum of %d and %d is %d. \n", num1, num2, result);

    // Section 2: Subtraction
    num1 = rand() % 100;
    num2 = rand() % 100;
    result = num1 - num2;
    printf("The difference of %d and %d is %d. \n", num1, num2, result);

    // Section 3: Multiplication
    num1 = rand() % 100;
    num2 = rand() % 100;
    result = num1 * num2;
    printf("The product of %d and %d is %d. \n", num1, num2, result);

    // Section 4: Division
    num1 = rand() % 100;
    num2 = rand() % 100;
    result = num1 / num2;
    printf("The quotient of %d and %d is %d. \n", num1, num2, result);

    // Section 5: Modulus
    num1 = rand() % 100;
    num2 = rand() % 100;
    result = num1 % num2;
    printf("The remainder of %d and %d is %d. \n", num1, num2, result);

    // Section 6: Floating Point Arithmetic
    float1 = rand() % 100;
    float2 = rand() % 100;
    result2 = float1 + float2;
    printf("The sum of %f and %f is %f. \n", float1, float2, result2);

    float1 = rand() % 100;
    float2 = rand() % 100;
    result2 = float1 - float2;
    printf("The difference of %f and %f is %f. \n", float1, float2, result2);

    float1 = rand() % 100;
    float2 = rand() % 100;
    result2 = float1 * float2;
    printf("The product of %f and %f is %f. \n", float1, float2, result2);

    float1 = rand() % 100;
    float2 = rand() % 100;
    result2 = float1 / float2;
    printf("The quotient of %f and %f is %f. \n", float1, float2, result2);

    // Section 7: String Manipulation
    str1[0] = 'A';
    str1[1] = 'B';
    str1[2] = 'C';
    str2[0] = 'a';
    str2[1] = 'b';
    str2[2] = 'c';
    result = strcmp(str1, str2);
    printf("The comparison of %s and %s is %d. \n", str1, str2, result);

    // Section 8: Miscellaneous
    double1 = rand() % 100;
    double2 = rand() % 100;
    result3 = double1 + double2;
    printf("The sum of %lf and %lf is %lf. \n", double1, double2, result3);

    double1 = rand() % 100;
    double2 = rand() % 100;
    result3 = double1 - double2;
    printf("The difference of %lf and %lf is %lf. \n", double1, double2, result3);

    double1 = rand() % 100;
    double2 = rand() % 100;
    result3 = double1 * double2;
    printf("The product of %lf and %lf is %lf. \n", double1, double2, result3);

    double1 = rand() % 100;
    double2 = rand() % 100;
    result3 = double1 / double2;
    printf("The quotient of %lf and %lf is %lf. \n", double1, double2, result3);

    return 0;
}