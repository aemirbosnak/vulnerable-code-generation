//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n);

int main(void)
{
    int num;
    
    printf("Enter a positive integer to generate primes up to: ");
    scanf("%d", &num);
    
    // Create a dynamic array to store primes
    int *primes = (int *) malloc(num * sizeof(int));
    int index = 0;  // Index for primes array
    
    // Iterate through all numbers to num
    for (int i = 2; i <= num; i++)
    {
        // Check if number i is prime
        if (is_prime(i))
        {
            // Add prime i to primes array
            primes[index] = i;
            index++;
        }
    }
    
    // Print all prime numbers in the primes array
    printf("Prime numbers up to %d:\n", num);
    for (int i = 0; i < index; i++)
    {
        printf("%d ", primes[i]);
    }
    printf("\n");
    
    // Free dynamic memory used for primes array
    free(primes);
    
    return 0;
}

// Function to check if a number is prime
bool is_prime(int n)
{
    // Iterate through all numbers from 2 to n-1
    for (int i = 2; i < n; i++)
    {
        // If n is divisible by i, it is not prime
        if (n % i == 0)
        {
            return false;
        }
    }
    
    // If n is not divisible by any number except 1 and itself, it is prime
    return true;
}