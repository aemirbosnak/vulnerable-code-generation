//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 // Maximum size of message

typedef struct {
    int e;
    int n;
} public_key;

typedef struct {
    int d;
    int n;
} private_key;

public_key* generate_public_key(int p, int q) {
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (1) {
        if (e % phi == 1) {
            break;
        }
        e++;
    }
    public_key* result = malloc(sizeof(public_key));
    result->e = e;
    result->n = p * q;
    return result;
}

private_key* generate_private_key(public_key* public_key, int p, int q) {
    int phi = (p - 1) * (q - 1);
    int d = 1;
    while (1) {
        if ((d * (p - 1) + 1) % phi == 0) {
            d = (d * (p - 1) + 1) % phi;
        } else {
            d++;
        }
    }
    private_key* result = malloc(sizeof(private_key));
    result->d = d;
    result->n = public_key->n;
    return result;
}

int encrypt(char* message, public_key* public_key) {
    int m = strlen(message);
    int c = 0;
    for (int i = 0; i < m; i++) {
        c = (c * public_key->e) % public_key->n + (int)message[i];
    }
    return c;
}

char* decrypt(int ciphertext, private_key* private_key) {
    int m = (int)pow(ciphertext, private_key->d) % private_key->n;
    char* result = malloc(MAX_SIZE * sizeof(char));
    for (int i = 0; i < m; i++) {
        result[i] = (char)m % 10 + '0';
        m /= 10;
    }
    result[m] = '\0';
    return result;
}

int main() {
    int p = 17, q = 23;
    public_key* public_key = generate_public_key(p, q);
    private_key* private_key = generate_private_key(public_key, p, q);
    char* message = "Hello, world!";
    int ciphertext = encrypt(message, public_key);
    char* decrypted_message = decrypt(ciphertext, private_key);
    printf("Original message: %s\n", message);
    printf("Encrypted message: %d\n", ciphertext);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}