//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complex
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int isPrime(int n) // Function to check if a number is prime or not
 {
    if(n < 2) // Any number less than 2 is not prime
        return 0;
    int i;
    for(i = 2; i <= sqrt(n); i++) // Check for divisors till square root of n
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int gcd(int a, int b) // Function to calculate the GCD of two numbers
{       
    if(a < b) // If a is less than b, swap them
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if(b == 0)
        return a;
    else 
        return gcd(b, a%b); // Recursively check for GCD
}

int main() 
{       
    int p, q, phi, n, e, d, message, i;
    char plaintext[100], ciphertext[100];
  
    printf("Enter the message to encrypt:\n");
    fgets(plaintext, 100, stdin); // Read plaintext from user
    printf("\nPlaintext: %s", plaintext);

    while(1) // Loop to get two distinct random prime numbers p and q
    {
        p = rand() % 50 + 1; // Generate a random number between 1 and 50 for p
        q = rand() % 50 + 1; // Generate a random number between 1 and 50 for q
        if(isPrime(p) && isPrime(q) && p != q) // Check if p and q are both prime and distinct
            break;
    }

    n = p * q; // Calculate n
    phi = (p-1) * (q-1); // Calculate phi

    while(1) // Loop to get e, which is a random number such that gcd(e, phi) = 1
    {      
        e = rand() % (phi-2) + 2; // Generate a random number between 2 and phi-1 for e
        if(gcd(e, phi) == 1) // Check if gcd(e, phi) = 1
            break;
    }

    for(d = 1; d < phi; d++) // Loop to get d such that d*e % phi = 1
    {
        if((d*e) % phi == 1)
            break;
    }

    printf("\nPublic key (n,e): (%d,%d)\n", n, e);
    printf("Private key (d): %d\n", d);

    for(i = 0; i < strlen(plaintext); i++) // Loop to encrypt the message
    {
        message = plaintext[i];
        message = pow(message, e);
        message = message % n;
        ciphertext[i] = message;
    }
    
    printf("\nCiphertext: ");
    for(i = 0; i < strlen(plaintext); i++) // Loop to display the ciphertext
        printf("%d ", ciphertext[i]);
    
    for(i = 0; i < strlen(plaintext); i++) // Loop to decrypt the message
    {
        message = ciphertext[i];
        message = pow(message, d); 
        message = message % n;
        plaintext[i] = message;
    }
    
    printf("\nDecrypted plaintext: %s", plaintext);
    return 0;
}