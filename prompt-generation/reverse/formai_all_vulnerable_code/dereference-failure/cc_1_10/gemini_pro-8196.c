//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

// Generate a random prime number using the Miller-Rabin primality test
BIGNUM *generate_prime(int bits) {
    BIGNUM *p = BN_new();
    while (!BN_generate_prime_ex(p, bits, 0, NULL, NULL, NULL)) {
        continue;
    }
    return p;
}

// Generate a public-private key pair
RSA *generate_key_pair(int bits) {
    BIGNUM *p = generate_prime(bits / 2);
    BIGNUM *q = generate_prime(bits / 2);
    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *d = BN_new();
    RSA *rsa = RSA_new();

    // Calculate n = p * q
    BN_mul(n, p, q, BN_CTX_new());
    // Calculate phi(n) = (p - 1) * (q - 1)
    BIGNUM *p1 = BN_new();
    BIGNUM *q1 = BN_new();
    BN_sub(p1, p, BN_value_one());
    BN_sub(q1, q, BN_value_one());
    BIGNUM *phi_n = BN_new();
    BN_mul(phi_n, p1, q1, BN_CTX_new());
    // Choose e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    BN_set_word(e, 65537);
    // Calculate d such that d * e = 1 (mod phi(n))
    BN_mod_inverse(d, e, phi_n, BN_CTX_new());
    // Set the public key components
    RSA_set0_key(rsa, n, e, d);
    return rsa;
}

// Encrypt a message using the public key
int encrypt(RSA *rsa, const unsigned char *message, unsigned char **encrypted) {
    int encrypted_length = RSA_size(rsa);
    *encrypted = malloc(encrypted_length);
    int result = RSA_public_encrypt(strlen(message), message, *encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    return result;
}

// Decrypt a message using the private key
int decrypt(RSA *rsa, const unsigned char *encrypted, unsigned char **decrypted) {
    int decrypted_length = RSA_size(rsa);
    *decrypted = malloc(decrypted_length);
    int result = RSA_private_decrypt(strlen(encrypted), encrypted, *decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    return result;
}

int main() {
    // Generate a 2048-bit key pair
    RSA *rsa = generate_key_pair(2048);

    // Convert the public key to PEM format
    BIO *bio = BIO_new(BIO_s_mem());
    PEM_write_RSA_PUBKEY(bio, rsa);
    char *public_key = malloc(BIO_pending(bio));
    BIO_read(bio, public_key, BIO_pending(bio));
    BIO_free(bio);

    // Convert the private key to PEM format
    bio = BIO_new(BIO_s_mem());
    PEM_write_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);
    char *private_key = malloc(BIO_pending(bio));
    BIO_read(bio, private_key, BIO_pending(bio));
    BIO_free(bio);

    // Encrypt a message using the public key
    const unsigned char *message = "Hello, world!";
    unsigned char *encrypted;
    int encrypted_length = encrypt(rsa, message, &encrypted);

    // Decrypt the message using the private key
    unsigned char *decrypted;
    int decrypted_length = decrypt(rsa, encrypted, &decrypted);

    // Print the original message, encrypted message, and decrypted message
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    // Free the allocated memory
    RSA_free(rsa);
    free(public_key);
    free(private_key);
    free(encrypted);
    free(decrypted);

    return 0;
}