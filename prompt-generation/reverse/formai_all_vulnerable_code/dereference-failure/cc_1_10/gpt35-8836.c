//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

// Function to generate a private/public key pair and write to respective files
int generate_keypair(const char *priv_keyfile, const char *pub_keyfile, int key_size) {
    int ret = 0;
    RSA * rsa = NULL;
    unsigned long e = RSA_F4;
    FILE * fp_priv = NULL;
    FILE * fp_pub = NULL;

    // Generate key pair
    rsa = RSA_generate_key(key_size, e, NULL, NULL);

    // Write private key to file
    fp_priv = fopen(priv_keyfile, "wb");
    if (!PEM_write_RSAPrivateKey(fp_priv, rsa, NULL, NULL, 0, NULL, NULL)) {
        ret = 1;
        goto CLEANUP;
    }
    fclose(fp_priv);

    // Write public key to file
    fp_pub = fopen(pub_keyfile, "wb");
    if (!PEM_write_RSA_PUBKEY(fp_pub, rsa)) {
        ret = 1;
        goto CLEANUP;
    }
    fclose(fp_pub);

CLEANUP:
    // Cleanup RSA structure
    RSA_free(rsa);

    return ret;
}

// Function to read a public key file and decrypt ciphertext
int decrypt_msg(const char *pub_keyfile, const unsigned char *ciphertext, int ciphertext_len, unsigned char *plain_text) {
    int ret = 0;
    RSA * rsa = NULL;
    FILE * fp_pub = NULL;

    // Read public key from file
    fp_pub = fopen(pub_keyfile,"rb");
    if (!fp_pub) {
        ret = 1;
        goto CLEANUP;
    }
    rsa = PEM_read_RSA_PUBKEY(fp_pub, NULL, NULL, NULL);
    if (!rsa) {
        ret = 1;
        goto CLEANUP;
    }
    fclose(fp_pub);

    // Decrypt ciphertext
    int decrypt_len = RSA_public_decrypt(ciphertext_len, ciphertext, plain_text, rsa, RSA_PKCS1_PADDING);
    if (decrypt_len < 0) {
        ret = 1;
        goto CLEANUP;
    }

CLEANUP:
    // Cleanup RSA structure
    RSA_free(rsa);

    return ret;
}

int main() {
    const char *priv_keyfile = "private_key.pem";
    const char *pub_keyfile = "public_key.pem";
    int key_size = 2048;
    unsigned char plaintext[] = "This is a secret message that will be encrypted and decrypted.";
    int plaintext_len = strlen((char *) plaintext);
    unsigned char ciphertext[4096] = {0};
    unsigned char decrypted_text[4096] = {0};
    int ciphertext_len = 0;

    // Generate keypair
    if (generate_keypair(priv_keyfile, pub_keyfile, key_size)) {
        printf("Error: Failed to generate keypair\n");
        return 1;
    }

    // Encrypt plaintext
    RSA * rsa = NULL;
    FILE * fp_priv = NULL;
    fp_priv = fopen(priv_keyfile, "rb");
    rsa = PEM_read_RSAPrivateKey(fp_priv, NULL, NULL, NULL);
    if (!rsa) {
        printf("Error: Failed to read private key from file\n");
        return 1;
    }
    fclose(fp_priv);
    ciphertext_len = RSA_private_encrypt(plaintext_len, plaintext, ciphertext, rsa, RSA_PKCS1_PADDING);
    if (ciphertext_len < 0) {
        printf("Error: Failed to encrypt the plaintext\n");
        return 1;
    }

    // Decrypt ciphertext
    if (decrypt_msg(pub_keyfile, ciphertext, ciphertext_len, decrypted_text)) {
        printf("Error: Failed to decrypt the ciphertext\n");
        return 1;
    }

    printf("Original plaintext: %s\n", plaintext);
    printf("Decrypted plaintext: %s\n", decrypted_text);

    return 0;
}