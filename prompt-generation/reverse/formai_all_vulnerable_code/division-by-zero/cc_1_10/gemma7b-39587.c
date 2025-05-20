//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 23

int main()
{
    // Generating random primes
    int p = rand() % MOD;
    int q = rand() % MOD;
    while (p == q)
    {
        q = rand() % MOD;
    }

    // Calculating phi of pq
    int phi = (p - 1) * (q - 1);

    // Choosing a random number as the secret key
    int sk = rand() % phi;

    // Generating the public key
    int n = p * q;
    int e = sk * phi / n;

    // Encrypting a message
    char msg[] = "This is a secret message";
    int msg_len = strlen(msg);
    int enc_msg[msg_len];

    for (int i = 0; i < msg_len; i++)
    {
        enc_msg[i] = (msg[i] - 'a' + e) % n + 'a';
    }

    // Displaying the encrypted message
    printf("Encrypted message:");
    for (int i = 0; i < msg_len; i++)
    {
        printf(" %c", enc_msg[i]);
    }

    printf("\n");

    // Decrypting the message
    int dec_msg[msg_len];

    for (int i = 0; i < msg_len; i++)
    {
        dec_msg[i] = (enc_msg[i] - e) % n + 'a';
    }

    // Displaying the decrypted message
    printf("Decrypted message:");
    for (int i = 0; i < msg_len; i++)
    {
        printf(" %c", dec_msg[i]);
    }

    return 0;
}