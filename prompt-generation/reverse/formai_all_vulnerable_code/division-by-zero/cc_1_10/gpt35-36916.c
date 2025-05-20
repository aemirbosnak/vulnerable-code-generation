//FormAI DATASET v1.0 Category: Math exercise ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));
    
    int num1 = rand() % 100; // generates a random number between 0 and 100
    int num2 = rand() % 100;
    
    printf("Given the following two numbers:\n");
    printf("Num1 = %d\nNum2 = %d\n", num1, num2);
    
    int gcd = find_gcd(num1, num2); // function call to find the gcd of the two numbers
    printf("\nThe greatest common divisor of Num1 and Num2 is %d\n", gcd);
    
    int lcm = find_lcm(num1, num2); // function call to find the lcm of the two numbers
    printf("The least common multiple of Num1 and Num2 is %d\n", lcm);
    
    int power = rand() % 5; // generates a random power between 0 and 5
    int result = power_of_num(num1, power); // function call to find the power of num1
    printf("The result of raising Num1 to the power of %d is %d\n", power, result);
    
    return 0;
}

// function to find the greatest common divisor of two numbers
int find_gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// function to find the least common multiple of two numbers
int find_lcm(int a, int b)
{
    return abs(a * b) / find_gcd(a, b);
}

// function to find the power of a number
int power_of_num(int a, int b)
{
    int result = 1;
    for (int i = 1; i <= b; i++)
    {
        result *= a;
    }
    return result;
}