//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/rsa.h>
#include <openssl/pem.h>

int main()
{
    RSA *rsa;
    FILE *private_key_file, *public_key_file;
    char *message = "Hello, world!";
    size_t message_len = strlen(message);

    // Generate RSA key pair
    rsa = RSA_generate_key(1024, RSA_F4, NULL, NULL);
    if (rsa == NULL) {
        fprintf(stderr, "Error generating RSA key pair!\n");
        exit(1);
    }

    // Save private key to file
    private_key_file = fopen("private_key.pem", "w");
    if (private_key_file == NULL) {
        fprintf(stderr, "Error opening private key file!\n");
        exit(1);
    }
    PEM_write_RSAPrivateKey(private_key_file, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(private_key_file);

    // Save public key to file
    public_key_file = fopen("public_key.pem", "w");
    if (public_key_file == NULL) {
        fprintf(stderr, "Error opening public key file!\n");
        exit(1);
    }
    PEM_write_RSAPublicKey(public_key_file, rsa);
    fclose(public_key_file);

    // Encrypt message with public key
    size_t encrypted_len;
    unsigned char *encrypted = malloc(RSA_size(rsa));
    if (encrypted == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted message!\n");
        exit(1);
    }
    encrypted_len = RSA_public_encrypt(message_len, (unsigned char *) message,
                                       encrypted, rsa, RSA_PKCS1_PADDING);
    if (encrypted_len == -1) {
        fprintf(stderr, "Error encrypting message!\n");
        exit(1);
    }

    // Decrypt message with private key
    size_t decrypted_len;
    unsigned char *decrypted = malloc(RSA_size(rsa));
    if (decrypted == NULL) {
        fprintf(stderr, "Error allocating memory for decrypted message!\n");
        exit(1);
    }
    decrypted_len = RSA_private_decrypt(encrypted_len, encrypted, decrypted,
                                         rsa, RSA_PKCS1_PADDING);
    if (decrypted_len == -1) {
        fprintf(stderr, "Error decrypting message!\n");
        exit(1);
    }

    // Print results
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (size_t i = 0; i < encrypted_len; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\nDecrypted message: %s\n", decrypted);

    // Cleanup
    RSA_free(rsa);
    free(encrypted);
    free(decrypted);

    return 0;
}