//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
 * Struct representing a public key.
 */
struct PublicKey {
    int n; // Public modulus
    int e; // Public exponent
};

/*
 * Struct representing a private key.
 */
struct PrivateKey {
    int n; // Public modulus
    int d; // Private exponent
};

/*
 * Function to calculate the greatest common divisor (gcd) of two numbers.
 */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/*
 * Function to generate a random prime number.
 */
int generatePrime() {
    int n, i, flag = 0;
    while (true) {
        n = rand() % 100 + 2;
        for(i=2; i<=sqrt(n); ++i) {
            if(n%i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return n;
        }
        flag = 0;
    }
}

/*
 * Function to generate a public key and a private key.
 */
void generateKeys(struct PublicKey *pubKey, struct PrivateKey *privKey) {
    int p, q, phi_n;
    // Generate two random prime numbers p and q
    p = generatePrime();
    q = generatePrime();

    // Calculate n and phi(n)
    pubKey->n = p * q;
    phi_n = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    do {
        pubKey->e = rand() % (phi_n - 2) + 2;
    } while (gcd(pubKey->e, phi_n) != 1);

    // Calculate d such that d = e^-1 mod phi(n)
    int k = 1;
    while (((k * phi_n) + 1) % pubKey->e != 0) {
        k++;
    }
    privKey->d = ((k * phi_n) + 1) / pubKey->e;
    privKey->n = pubKey->n;
}

/*
 * Function to encrypt a message using the public key.
 */
void encrypt(int message, struct PublicKey pubKey, int *ciphertext) {
    int i;
    for (i = 0; i < message; i++) {
        // Calculate ciphertext = plaintext^e mod n
        ciphertext[i] = pow(i, pubKey.e);
        ciphertext[i] = ciphertext[i] % pubKey.n;
    }
}

/*
 * Function to decrypt a message using the private key.
 */
void decrypt(int *ciphertext, int length, struct PrivateKey privKey, char *plaintext) {
    int i;
    for (i = 0; i < length; i++) {
        // Calculate plaintext = ciphertext^d mod n
        int m = pow(ciphertext[i], privKey.d);
        m = m % privKey.n;
        plaintext[i] = (char) m;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    struct PublicKey pubKey;
    struct PrivateKey privKey;

    // Generate public and private keys
    generateKeys(&pubKey, &privKey);

    // Take input from multiple players
    int numPlayers, i, j, messageLength;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    int *messages[numPlayers];
    for (i = 0; i < numPlayers; i++) {
        printf("Enter the length of message %d: ", i+1);
        scanf("%d", &messageLength);

        // Allocate memory for the message and ciphertext
        messages[i] = (int*) malloc(messageLength * sizeof(int));
        int ciphertext[messageLength];

        printf("Enter the message for player %d: ", i+1);
        for (j = 0; j < messageLength; j++) {
            scanf("%d", &messages[i][j]);
        }

        // Encrypt the message using the public key
        encrypt(messageLength, pubKey, ciphertext);

        printf("Ciphertext generated for player %d: ", i+1);
        for (j = 0; j < messageLength; j++) {
            printf("%d ", ciphertext[j]);
        }
        printf("\n\n");
    }

    // Decrypt the messages
    char plaintext[messageLength];
    for (i = 0; i < numPlayers; i++) {
        decrypt(messages[i], messageLength, privKey, plaintext);
        printf("Decrypted message for player %d: %s\n\n", i+1, plaintext);
    }

    // Free memory
    for (i = 0; i < numPlayers; i++) {
        free(messages[i]);
    }

    return 0;
}