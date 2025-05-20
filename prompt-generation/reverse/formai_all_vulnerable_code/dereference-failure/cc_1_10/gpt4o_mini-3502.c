//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 2048
#define PUBLIC_EXPONENT 65537

typedef struct {
    unsigned char *n; // modulus
    unsigned char *e; // public exponent
} PublicKey;

typedef struct {
    unsigned char *n; // modulus
    unsigned char *e; // public exponent
    unsigned char *d; // private exponent
} PrivateKey;

// Function prototypes
void generate_keypair(PublicKey *pubkey, PrivateKey *privkey);
void encrypt(unsigned char *plaintext, unsigned char *ciphertext, PublicKey *pubkey);
void decrypt(unsigned char *ciphertext, unsigned char *plaintext, PrivateKey *privkey);
void generate_random_bytes(unsigned char *buffer, size_t length);
void print_hex(const char *label, unsigned char *data, size_t length);

int main() {
    PublicKey pubkey;
    PrivateKey privkey;
    unsigned char plaintext[128] = "Hello, this is a test message!";
    unsigned char ciphertext[KEY_SIZE / 8];
    unsigned char decrypted[128];

    // Generate RSA key pair
    generate_keypair(&pubkey, &privkey);

    // Encrypt the message
    encrypt(plaintext, ciphertext, &pubkey);
    print_hex("Ciphertext", ciphertext, sizeof(ciphertext));

    // Decrypt the message
    decrypt(ciphertext, decrypted, &privkey);
    printf("Decrypted: %s\n", decrypted);

    // Free allocated memory
    free(pubkey.n);
    free(pubkey.e);
    free(privkey.n);
    free(privkey.e);
    free(privkey.d);

    return 0;
}

void generate_keypair(PublicKey *pubkey, PrivateKey *privkey) {
    pubkey->n = (unsigned char *)malloc(KEY_SIZE / 8);
    pubkey->e = (unsigned char *)malloc(3); // 0x01, 0x00, 0x01 (65537 in byte array)

    // Simulate key generation for the sake of this example (pseudo-randomly generated)
    generate_random_bytes(pubkey->n, KEY_SIZE / 8);
    memcpy(pubkey->e, "\x01\x00\x01", 3);

    // The private key generation is simplified and not secure
    privkey->n = (unsigned char *)malloc(KEY_SIZE / 8);
    privkey->d = (unsigned char *)malloc(KEY_SIZE / 8);
    privkey->e = pubkey->e;

    // Copy n to private key
    memcpy(privkey->n, pubkey->n, KEY_SIZE / 8);
    generate_random_bytes(privkey->d, KEY_SIZE / 8);
}

void encrypt(unsigned char *plaintext, unsigned char *ciphertext, PublicKey *pubkey) {
    // Simulate encryption process (insecure)
    for (size_t i = 0; i < strlen((char *)plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ 0xAA; // Example XOR encryption
    }
}

void decrypt(unsigned char *ciphertext, unsigned char *plaintext, PrivateKey *privkey) {
    // Simulate decryption process (insecure)
    for (size_t i = 0; i < strlen((char *)ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ 0xAA; // Example XOR decryption
    }
}

void generate_random_bytes(unsigned char *buffer, size_t length) {
    srand(time(NULL));
    for (size_t i = 0; i < length; i++) {
        buffer[i] = rand() % 256;
    }
}

void print_hex(const char *label, unsigned char *data, size_t length) {
    printf("%s: ", label);
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}