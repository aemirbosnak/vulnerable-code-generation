//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Euclid's algorithm for finding greatest common divisor
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to generate public and private key
void generate_key(int prime[], int *pub_key, int *pri_key) {
    int p, q, n, phi, e, d, flag;
    do {
        flag = 0;
        printf("Enter two prime numbers (p and q): ");
        scanf("%d %d", &p, &q);

        // Check if p and q are prime
        for (int i=2; i<p; i++) {
            if (p % i == 0) {
                flag = 1;
                break;
            }
        }
        for (int i=2; i<q; i++) {
            if (q % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("Invalid input. Please enter prime numbers only.\n");
        }
    } while (flag);

    // Calculate n, phi and e
    n = p * q;
    phi = (p-1) * (q-1);
    do {
        flag = 0;
        printf("Enter a number e (1 < e < %d) that is relatively prime to phi: ", phi);
        scanf("%d", &e);

        // Check if e and phi are relatively prime
        if (gcd(e, phi) != 1) {
            flag = 1;
            printf("%d and %d are not relatively prime. Please try again.\n", e, phi);
        }
    } while (flag);

    // Calculate d
    for (int i=2; i<phi; i++) {
        if ((e*i) % phi == 1) {
            d = i;
            break;
        }
    }

    // Set pub_key and pri_key arrays
    pub_key[0] = e;
    pub_key[1] = n;
    pri_key[0] = d;
    pri_key[1] = n;
}

// Function to encrypt a message using the public key
int* encrypt(char message[], int pub_key[]) {
    int *encrypted = malloc(MAX * sizeof(int));
    for (int i=0; message[i]!='\0'; i++) {
        int m = message[i] - 'a'; // Convert message to number (a=0, b=1, c=2, ...)
        int c = 1;
        for (int j=0; j<pub_key[0]; j++) {
            c = (c * m) % pub_key[1];
        }
        encrypted[i] = c;
    }
    return encrypted;
}

// Function to decrypt a message using the private key
char* decrypt(int encrypted[], int pri_key[], int len) {
    char *decrypted = malloc((len+1) * sizeof(char));
    for (int i=0; i<len; i++) {
        int c = encrypted[i];
        int m = 1;
        for (int j=0; j<pri_key[0]; j++) {
            m = (m * c) % pri_key[1];
        }
        decrypted[i] = m + 'a'; // Convert number to character (0=a, 1=b, 2=c, ...)
    }
    decrypted[len] = '\0';
    return decrypted;
}

int main() {
    int prime[2], pub_key[2], pri_key[2];
    char message[MAX];
    int *encrypted;
    char *decrypted;

    generate_key(prime, pub_key, pri_key);

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);

    encrypted = encrypt(message, pub_key);
    printf("\nEncrypted message: ");
    for (int i=0; message[i]!='\0'; i++) {
        printf("%d ", encrypted[i]);
    }

    decrypted = decrypt(encrypted, pri_key, strlen(message));
    printf("\nDecrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}