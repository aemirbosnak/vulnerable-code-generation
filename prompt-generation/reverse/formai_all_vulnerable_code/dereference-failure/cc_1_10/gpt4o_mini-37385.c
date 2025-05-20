//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Linus Torvalds
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

void generate_keypair(unsigned char **public_key, unsigned char **private_key) {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (!rsa) handleErrors();

    BIO *pub = BIO_new(BIO_s_mem());
    BIO *priv = BIO_new(BIO_s_mem());

    if (!PEM_write_bio_RSA_PUBKEY(pub, rsa)) handleErrors();
    if (!PEM_write_bio_RSAPrivateKey(priv, rsa, NULL, NULL, 0, NULL, NULL)) handleErrors();

    size_t pub_len = BIO_pending(pub);
    size_t priv_len = BIO_pending(priv);

    *public_key = (unsigned char *)malloc(pub_len + 1);
    *private_key = (unsigned char *)malloc(priv_len + 1);

    BIO_read(pub, *public_key, pub_len);
    BIO_read(priv, *private_key, priv_len);

    (*public_key)[pub_len] = '\0';
    (*private_key)[priv_len] = '\0';

    BIO_free_all(pub);
    BIO_free_all(priv);
    RSA_free(rsa);
}

unsigned char* encrypt_data(const unsigned char *data, unsigned char *public_key) {
    RSA *rsa_pubkey = RSA_new();
    BIO *pub = BIO_new_mem_buf(public_key, -1);
    RSA *rsa = PEM_read_bio_RSA_PUBKEY(pub, &rsa_pubkey, NULL, NULL);
    
    if (!rsa) handleErrors();

    int data_len = strlen((const char *)data);
    int rsa_len = RSA_size(rsa_pubkey);
    unsigned char *encrypted = (unsigned char *)malloc(rsa_len);

    int result = RSA_public_encrypt(data_len, data, encrypted, rsa_pubkey, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) handleErrors();

    BIO_free(pub);
    RSA_free(rsa_pubkey);

    return encrypted;
}

unsigned char* decrypt_data(const unsigned char *encrypted_data, unsigned char *private_key) {
    RSA *rsa_privkey = RSA_new();
    BIO *priv = BIO_new_mem_buf(private_key, -1);
    RSA *rsa = PEM_read_bio_RSAPrivateKey(priv, &rsa_privkey, NULL, NULL);

    if (!rsa) handleErrors();

    int rsa_len = RSA_size(rsa_privkey);
    unsigned char *decrypted = (unsigned char *)malloc(rsa_len);

    int result = RSA_private_decrypt(rsa_len, encrypted_data, decrypted, rsa_privkey, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) handleErrors();

    BIO_free(priv);
    RSA_free(rsa_privkey);

    return decrypted;
}

int main() {
    unsigned char *public_key = NULL;
    unsigned char *private_key = NULL;

    printf("Generating RSA Keypair...\n");
    generate_keypair(&public_key, &private_key);

    const unsigned char *data = "Hello, this is a message that needs to be encrypted!";
    printf("Original Data: %s\n", data);

    unsigned char *encrypted_data = encrypt_data(data, public_key);
    printf("Encrypted Data: ");
    for (int i = 0; i < RSA_size(RSA_new()); i++)
        printf("%02X", encrypted_data[i]);
    printf("\n");
    
    unsigned char *decrypted_data = decrypt_data(encrypted_data, private_key);
    printf("Decrypted Data: %s\n", decrypted_data);

    // Clean up
    free(public_key);
    free(private_key);
    free(encrypted_data);
    free(decrypted_data);

    return 0;
}