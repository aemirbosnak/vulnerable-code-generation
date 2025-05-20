//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: imaginative
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int p, q, n, totient, e, d, message, encrypted_message, decrypted_message;
    int is_prime(int);

    // Generate two prime numbers
    do {
        p = rand() % 100;
    } while (!is_prime(p));

    do {
        q = rand() % 100;
    } while (!is_prime(q));

    n = p * q;
    totient = (p - 1) * (q - 1);

    // Choose a number e such that e and totient(n) are coprime
    do {
        e = rand() % totient;
    } while (gcd(e, totient) != 1);

    // Calculate d, the modular multiplicative inverse of e
    int k = 1;
    while (TRUE) {
        if ((k * totient + 1) % e == 0) {
            d = (k * totient + 1) / e;
            break;
        }
        k++;
    }

    // Prompt user to enter a message
    printf("Enter a message: ");
    scanf("%d", &message);

    // Encrypt the message
    encrypted_message = 1;
    for (int i = 0; i < e; i++) {
        encrypted_message = (encrypted_message * message) % n;
    }

    // Decrypt the message
    decrypted_message = 1;
    for (int i = 0; i < d; i++) {
        decrypted_message = (decrypted_message * encrypted_message) % n;
    }

    // Print out the original, encrypted, and decrypted messages
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}

int is_prime(int x)
{
    int i;
    if (x == 2 || x == 3)
        return TRUE;
    if (x == 1 || (x % 2) == 0)
        return FALSE;

    for (i = 3; i * i <= x; i += 2)
        if ((x % i) == 0)
            return FALSE;

    return TRUE;
}