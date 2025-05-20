//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_keys(RSA **rsa, EVP_PKEY **pkey) {
    int ret;
    BIGNUM *bne = BN_new();
    ret = BN_set_word(bne, RSA_F4);
    if (ret != 1) handleErrors();

    *rsa = RSA_new();
    ret = RSA_generate_key_ex(*rsa, 2048, bne, NULL);
    if (ret != 1) handleErrors();

    *pkey = EVP_PKEY_new();
    ret = EVP_PKEY_assign_RSA(*pkey, *rsa);
    if (ret != 1) handleErrors();

    BN_free(bne);
}

void save_private_key(EVP_PKEY *pkey) {
    FILE *fp = fopen("private_key.pem", "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file for writing\n");
        exit(EXIT_FAILURE);
    }
    if (PEM_write_PrivateKey(fp, pkey, NULL, NULL, 0, NULL, NULL) != 1) {
        fclose(fp);
        handleErrors();
    }
    fclose(fp);
}

void save_public_key(EVP_PKEY *pkey) {
    FILE *fp = fopen("public_key.pem", "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file for writing\n");
        exit(EXIT_FAILURE);
    }
    if (PEM_write_PUBKEY(fp, pkey) != 1) {
        fclose(fp);
        handleErrors();
    }
    fclose(fp);
}

void encrypt_message(const char *message, unsigned char **encrypted, int *encrypted_length, EVP_PKEY *pubkey) {
    *encrypted = (unsigned char *)malloc(RSA_size((RSA *)pubkey));
    if (NULL == *encrypted) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    *encrypted_length = RSA_public_encrypt(strlen(message), (unsigned char *)message, *encrypted, (RSA *)pubkey, RSA_PKCS1_OAEP_PADDING);
    if (*encrypted_length == -1) handleErrors();
}

void decrypt_message(unsigned char *encrypted, int encrypted_length, unsigned char **decrypted, EVP_PKEY *privkey) {
    *decrypted = (unsigned char *)malloc(RSA_size((RSA *)privkey));
    if (NULL == *decrypted) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int decrypted_length = RSA_private_decrypt(encrypted_length, encrypted, *decrypted, (RSA *)privkey, RSA_PKCS1_OAEP_PADDING);
    if (decrypted_length == -1) handleErrors();
    (*decrypted)[decrypted_length] = '\0'; // Null-terminate the decrypted string
}

int main() {
    EVP_PKEY *pkey = NULL;
    RSA *rsa = NULL;

    generate_keys(&rsa, &pkey);

    save_private_key(pkey);
    save_public_key(pkey);
    
    const char *message = "Hello, this is a secret message!";
    unsigned char *encrypted = NULL;
    int encrypted_length = 0;

    encrypt_message(message, &encrypted, &encrypted_length, pkey);

    printf("Encrypted Message:\n");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    unsigned char *decrypted = NULL;
    decrypt_message(encrypted, encrypted_length, &decrypted, pkey);

    printf("Decrypted Message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    EVP_PKEY_free(pkey);
    RSA_free(rsa);

    return 0;
}