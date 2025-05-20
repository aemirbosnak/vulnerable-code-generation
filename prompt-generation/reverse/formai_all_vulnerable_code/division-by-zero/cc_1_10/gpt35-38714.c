//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

 // Function to generate prime numbers
int generatePrimeNumber() {
    int num, i, flag;
    do {
        num = rand() % 100 + 1; // Generate a random number between 1 and 100
        flag = 0;
        for (i = 2; i <= num / 2; i++) { // Check if the number is prime
            if (num % i == 0) { 
                flag = 1;
                break;
            }
        }
    } while (flag == 1);
    return num;
}

// Function to calculate GCD (Greatest Common Divisor)
int calculateGCD(int x, int y) {
    int gcd;
    if (y == 0) {
        return x;
    } else {
        return calculateGCD(y, x % y);
    }
}

// Function to calculate modular exponentiation
int calculateModularExponentiation(int base, int exponent, int mod) {
    int res = 1, i;
    for (i = 0; i < exponent; i++) {
        res = (res * base) % mod;
    }
    return res;
}

// Function to generate public and private key pair
void generateKeyPair() {
    int p, q, n, phi, e, d;
    p = generatePrimeNumber(); // Generate first prime number
    q = generatePrimeNumber(); // Generate second prime number
    n = p * q; // Calculate n value
    phi = (p - 1) * (q - 1); // Calculate phi value
    srand(time(0)); // Seed the random number generator
    do {
        e = rand() % phi; // Generate a random number between 1 and phi
    } while (calculateGCD(e, phi) != 1);
    d = calculateModularExponentiation(e, -1, phi); // Calculate d value
    printf("Public key is (%d, %d)\n", e, n);
    printf("Private key is (%d, %d)\n", d, n);
}

// Main function
int main() {
    generateKeyPair(); // Generate key pair
    return 0;
}