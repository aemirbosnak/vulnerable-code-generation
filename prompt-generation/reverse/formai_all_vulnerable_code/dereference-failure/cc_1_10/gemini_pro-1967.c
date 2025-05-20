//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Welcome the user with a futuristic, binary-inspired message
void welcome() {
	printf("01001000 01100101 01101100 00100000 01101001 01110011 00100000 01110111 01101111 01101101\n");
	printf("01001000 01101111 01101110 00100000 01110111 01101111 00100000 01111001 01101111 01110101\n");
	printf("01001011 01101111 01110101 00100000 01110100 01101000 01100101 00100000 01101101 01100001 01100100\n");
	printf("00100000 01101111 01100110 00100000 01100001 01101110 01100111 00100000 01101001 00100000 01101000\n");
	printf("01101001 01110011 00100000 01100001 00100000 01100010 01100101 01100110 01100101 00100000 01101000\n");
	printf("\n");
	printf("Initializing quantum entanglement subroutine...\n");
}

// Generate a random number within a specified range
int generate_random_number(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

// Check if a number is prime
int is_prime(int number) {
	if (number <= 1) {
		return 0;
	}

	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return 0;
		}
	}

	return 1;
}

// Generate a list of prime numbers up to a specified limit
int *generate_prime_numbers(int limit) {
	int *prime_numbers = malloc(sizeof(int) * limit);
	int prime_count = 0;

	for (int i = 2; i <= limit; i++) {
		if (is_prime(i)) {
			prime_numbers[prime_count] = i;
			prime_count++;
		}
	}

	return prime_numbers;
}

// Print a list of prime numbers
void print_prime_numbers(int *prime_numbers, int prime_count) {
	printf("Transmitting prime numbers quantumly...\n");

	for (int i = 0; i < prime_count; i++) {
		printf("%d ", prime_numbers[i]);
	}

	printf("\n");
}

// Main function
int main() {
	// Welcome the user
	welcome();

	// Get the user's input
	int limit;
	printf("Enter the limit for prime number generation: ");
	scanf("%d", &limit);

	// Generate a list of prime numbers
	int *prime_numbers = generate_prime_numbers(limit);

	// Get the count of prime numbers
	int prime_count = sizeof(prime_numbers) / sizeof(prime_numbers[0]);

	// Print the list of prime numbers
	print_prime_numbers(prime_numbers, prime_count);

	// Free the allocated memory
	free(prime_numbers);

	return 0;
}