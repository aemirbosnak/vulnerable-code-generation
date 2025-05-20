//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find greatest common divisor
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to generate public and private keys
void generateKeys(int p, int q, int *pkey, int *skey)
{
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Finding a number e that is coprime with phi
    int e = 2;
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Finding d such that (d*e)%phi = 1
    int d = 2;
    while ((d * e) % phi != 1)
        d++;

    // Setting public and private keys
    *pkey = e;
    *skey = d;
}

// Function to encrypt message using public key
void encrypt(int plaintext[], int n, int pkey, int encrypted[])
{
    for (int i = 0; i < n; i++)
        encrypted[i] = (plaintext[i] ^ pkey);
}

// Function to decrypt message using private key
void decrypt(int encrypted[], int n, int skey, int decrypted[])
{
    for (int i = 0; i < n; i++)
        decrypted[i] = (encrypted[i] ^ skey);
}

int main()
{
    int p, q, n; // p and q are two prime numbers, n is their product
    int pkey, skey; // public and private keys
    int plaintext[100], encrypted[100], decrypted[100]; // arrays to store plain, encrypted and decrypted messages

    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    // Generating public and private keys
    generateKeys(p, q, &pkey, &skey);

    printf("Public Key: %d\nPrivate Key: %d\n", pkey, skey);

    printf("Enter plaintext message: ");
    char message[100];
    scanf("%s", message);

    // Storing plaintext message as array of integers
    for (int i = 0; i < strlen(message); i++)
        plaintext[i] = (int)message[i];

    // Encrypting message using public key
    encrypt(plaintext, strlen(message), pkey, encrypted);

    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++)
        printf("%d ", encrypted[i]);

    // Decrypting message using private key
    decrypt(encrypted, strlen(message), skey, decrypted);

    // Printing decrypted message
    printf("\nDecrypted message: ");
    for (int i = 0; i < strlen(message); i++)
        printf("%c", decrypted[i]);

    return 0;
}