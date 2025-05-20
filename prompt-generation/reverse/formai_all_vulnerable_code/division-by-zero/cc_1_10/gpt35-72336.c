//FormAI DATASET v1.0 Category: Math exercise ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int get_choice();
int calculate_sum_of_primes(int n);
int is_prime(int n);
int calculate_gcd(int x, int y);
int calculate_lcm(int x, int y);
int main()
{
    int choice, x, y, n, sum;
    printf("Welcome to Math Exercise Program!\n\n");

    do {
        choice = get_choice();
        switch(choice)
        {
            case 1:
                printf("\nEnter a number: ");
                scanf("%d", &n);
                sum = calculate_sum_of_primes(n);
                printf("The sum of all prime numbers less than or equal to %d is %d\n", n, sum);
                break;
            case 2:
                printf("\nEnter two numbers: ");
                scanf("%d%d", &x, &y);
                printf("The GCD of %d and %d is %d\n\n", x, y, calculate_gcd(x, y));
                break;
            case 3:
                printf("\nEnter two numbers: ");
                scanf("%d%d", &x, &y);
                printf("The LCM of %d and %d is %d\n\n", x, y, calculate_lcm(x, y));
                break;
            case 4:
                printf("Thank you for using our program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

    } while(1);
}

int get_choice()
{
    int choice;
    printf("Please choose an option:\n");
    printf("1. Calculate the sum of all prime numbers less than or equal to n\n");
    printf("2. Calculate the GCD of two numbers\n");
    printf("3. Calculate the LCM of two numbers\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    return choice;
}

int calculate_sum_of_primes(int n)
{
    int i, sum = 0;
    for(i = 2; i <= n; i++)
    {
        if(is_prime(i))
        {
            sum += i;
        }
    }
    return sum;
}

int is_prime(int n)
{
    int i;
    if(n <= 1)
    {
        return 0;
    }
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int calculate_gcd(int x, int y)
{
    if(x == 0 || y == 0)
    {
        return x + y;
    }
    return calculate_gcd(y, x % y);
}

int calculate_lcm(int x, int y)
{
    int gcd = calculate_gcd(x, y);
    return abs(x * y) / gcd;
}