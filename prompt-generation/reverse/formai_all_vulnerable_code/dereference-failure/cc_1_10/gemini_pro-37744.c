//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    if (n % 2 == 0 && n != 2) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a list of prime numbers
int* generate_prime_numbers(int n) {
    int* prime_numbers = malloc(sizeof(int) * n);
    int count = 0;
    int current_number = 2;
    while (count < n) {
        if (is_prime(current_number)) {
            prime_numbers[count] = current_number;
            count++;
        }
        current_number++;
    }
    return prime_numbers;
}

// Function to print a list of prime numbers
void print_prime_numbers(int* prime_numbers, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", prime_numbers[i]);
    }
    printf("\n");
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of prime numbers to generate
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    // Generate a list of prime numbers
    int* prime_numbers = generate_prime_numbers(n);

    // Print the list of prime numbers
    print_prime_numbers(prime_numbers, n);

    // Free the allocated memory
    free(prime_numbers);

    return 0;
}