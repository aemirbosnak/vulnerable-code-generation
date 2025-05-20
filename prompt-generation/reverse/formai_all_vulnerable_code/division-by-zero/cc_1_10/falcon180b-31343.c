//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 1000000

typedef struct {
    int public_key;
    int private_key;
} key_pair;

void generate_keys(key_pair* keys) {
    int p, q, n, phi_n;
    int e, d;

    // generate two prime numbers p and q
    do {
        p = rand() % MAX_VALUE;
        q = rand() % MAX_VALUE;
    } while (gcd(p, q)!= 1);

    // calculate n and phi_n
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // choose an integer e such that 1 < e < phi_n and e is coprime to phi_n
    do {
        e = rand() % phi_n;
    } while (gcd(e, phi_n)!= 1);

    // calculate d such that e * d = 1 mod phi_n
    d = (e * phi_n + 1) % phi_n;

    // set the values in the key_pair struct
    keys->public_key = e;
    keys->private_key = d;
}

int gcd(int a, int b) {
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int encrypt(int message, int public_key, int n) {
    return (message * public_key) % n;
}

int decrypt(int ciphertext, int private_key, int n) {
    return (ciphertext * private_key) % n;
}

int main() {
    key_pair keys;
    int message, ciphertext;

    // generate public and private keys
    generate_keys(&keys);

    // get the message to be encrypted from the user
    printf("enter message to be encrypted: ");
    scanf("%d", &message);

    // encrypt the message using the public key
    ciphertext = encrypt(message, keys.public_key, keys.private_key * keys.public_key);

    // print the encrypted message
    printf("encrypted message: %d\n", ciphertext);

    // decrypt the message using the private key
    int decrypted_message = decrypt(ciphertext, keys.private_key, keys.public_key * keys.private_key);

    // print the decrypted message
    printf("decrypted message: %d\n", decrypted_message);

    return 0;
}