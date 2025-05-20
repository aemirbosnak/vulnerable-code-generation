//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaration of the function prototypes
int generateRandomNumber();
float calculateAverage(int[], int);
int calculateFactorial(int);
int calculateSumOfDigits(int);
int calculateGreatestCommonDivisor(int, int);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    int length;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);

    // Declare an array of integers with the user-specified length
    int array[length];

    // Generate random numbers and fill the array
    for (int i = 0; i < length; i++)
    {
        array[i] = generateRandomNumber();
    }

    // Calculate the average of the elements in the array
    float average = calculateAverage(array, length);

    // Print the array and the average
    printf("The elements of the array are:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nThe average of the array elements is %f\n", average);

    // Calculate the factorial of a random number between 1 and 10
    int random_number = generateRandomNumber() % 10 + 1;
    int factorial = calculateFactorial(random_number);

    // Print the random number and its factorial
    printf("The random number is %d\n", random_number);
    printf("The factorial of the random number is %d\n", factorial);

    // Calculate the sum of the digits of a random number between 1 and 1000
    random_number = generateRandomNumber() % 1000 + 1;
    int sum_of_digits = calculateSumOfDigits(random_number);

    // Print the random number and its sum of digits
    printf("The random number is %d\n", random_number);
    printf("The sum of the digits of the random number is %d\n", sum_of_digits);

    // Calculate the greatest common divisor of two random numbers between 1 and 100
    int number1 = generateRandomNumber() % 100 + 1;
    int number2 = generateRandomNumber() % 100 + 1;
    int gcd = calculateGreatestCommonDivisor(number1, number2);

    // Print the two random numbers and their greatest common divisor
    printf("The two random numbers are %d and %d\n", number1, number2);
    printf("The greatest common divisor of the two numbers is %d\n", gcd);

    return 0;
}

// Generate a random number between 1 and 100
int generateRandomNumber()
{
    return rand() % 100 + 1;
}

// Calculate the average of an array of integers
float calculateAverage(int array[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float)sum / length;
}

// Calculate the factorial of a number
int calculateFactorial(int number)
{
    int factorial = 1;
    for (int i = 2; i <= number; i++)
    {
        factorial *= i;
    }
    return factorial;
}

// Calculate the sum of digits of a number
int calculateSumOfDigits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Calculate the greatest common divisor of two numbers
int calculateGreatestCommonDivisor(int number1, int number2)
{
    int gcd;
    for (int i = 1; i <= number1 && i <= number2; i++)
    {
        if (number1 % i == 0 && number2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}