//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BLOCK_SIZE 256
#define PRIME_LIMIT 10000

typedef struct {
    int n;
    int e;
} public_key;

typedef struct {
    int n;
    int d;
} private_key;

int is_prime(int num) {
    if (num == 2) {
        return 1;
    } else if (num < 2 || num % 2 == 0) {
        return 0;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int gcd(int a, int b) {
    int temp;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int generate_prime() {
    int num;

    do {
        num = rand() % PRIME_LIMIT;
    } while (!is_prime(num));

    return num;
}

int mod_inverse(int a, int b) {
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;

    if (b == 1) {
        return 1;
    }

    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }

    if (x1 < 0) {
        x1 += b0;
    }

    return x1;
}

public_key* generate_public_key() {
    public_key* pub = (public_key*) malloc(sizeof(public_key));
    int p, q, phi, e;

    p = generate_prime();
    q = generate_prime();

    pub->n = p * q;
    phi = (p - 1) * (q - 1);

    do {
        e = rand() % phi;
    } while (gcd(phi, e) != 1);

    pub->e = e;

    return pub;
}

private_key* generate_private_key(public_key* pub) {
    private_key* priv = (private_key*) malloc(sizeof(private_key));
    int p, q, phi;

    p = generate_prime();
    q = generate_prime();

    priv->n = p * q;
    phi = (p - 1) * (q - 1);

    priv->d = mod_inverse(pub->e, phi);

    return priv;
}

int mod_exp(int base, int exp, int modulus) {
    int result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }

        exp = exp >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int encrypt(int plaintext, public_key* pub) {
    return mod_exp(plaintext, pub->e, pub->n);
}

int decrypt(int ciphertext, private_key* priv) {
    return mod_exp(ciphertext, priv->d, priv->n);
}

int main() {
    char message[BLOCK_SIZE + 1];
    int message_len, block_num;
    public_key* pub_key;
    private_key* priv_key;

    printf("Enter message to encrypt: ");
    fgets(message, BLOCK_SIZE + 1, stdin);
    message_len = strlen(message) - 1;

    pub_key = generate_public_key();
    priv_key = generate_private_key(pub_key);

    printf("Public key: (n = %d, e = %d)\n", pub_key->n, pub_key->e);
    printf("Private key: (n = %d, d = %d)\n", priv_key->n, priv_key->d);

    block_num = ceil(message_len / 8.0);

    for (int i = 0; i < block_num; i++) {
        int block_plaintext = 0, block_ciphertext = 0;

        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;

            if (index >= message_len) {
                break;
            }

            block_plaintext = block_plaintext | ((int) message[index] << (8 * (7 - j)));
        }

        block_ciphertext = encrypt(block_plaintext, pub_key);

        printf("%d ", block_ciphertext);
    }

    printf("\n");

    return 0;
}