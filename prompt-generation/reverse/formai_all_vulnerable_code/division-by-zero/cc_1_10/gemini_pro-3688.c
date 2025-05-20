//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if a number is prime or not
bool isprime(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

// Function to generate a random number between min and max
int getrandom(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

// Function to print a prime number
void printprime(int num) {
	printf("%d ", num);
}

// Main function
int main() {
	// Initialize the random number generator
	srand(time(NULL));

	// Get the upper limit from the user
	int limit;
	printf("Enter the upper limit: ");
	scanf("%d", &limit);

	// Generate and print prime numbers until the limit is reached
	int count = 0;
	int num;
	while (count < limit) {
		num = getrandom(2, limit);
		if (isprime(num)) {
			printprime(num);
			count++;
		}
	}

	// Print a newline at the end
	printf("\n");

	return 0;
}