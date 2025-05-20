//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int *keys;
    int n;
} PublicKey;

void generate_keys(PublicKey *public_key) {
    int i, j;
    srand(time(NULL));
    public_key->n = rand() % MAX + 2;
    public_key->keys = (int *)malloc(public_key->n * sizeof(int));
    for (i = 0; i < public_key->n; i++) {
        public_key->keys[i] = rand() % MAX + 1;
    }
}

int encrypt(int m, PublicKey *public_key) {
    int i, res = 0;
    for (i = 0; i < public_key->n; i++) {
        res = (res * public_key->keys[i]) % MAX;
    }
    return res;
}

int decrypt(int c, PublicKey *public_key) {
    int i, res = 0, p = 1;
    for (i = public_key->n - 1; i >= 0; i--) {
        res = (res + c / public_key->keys[i]) % MAX;
        c = c % public_key->keys[i];
        p = (p * public_key->keys[i]) % MAX;
    }
    return res;
}

int main() {
    PublicKey public_key;
    int m, c, choice;

    printf("Enter the message to be encrypted: ");
    scanf("%d", &m);

    generate_keys(&public_key);

    c = encrypt(m, &public_key);

    printf("Encrypted message: %d\n", c);

    printf("Enter 1 to decrypt the message or 0 to exit: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int d;
        d = decrypt(c, &public_key);
        printf("Decrypted message: %d\n", d);
    }

    return 0;
}