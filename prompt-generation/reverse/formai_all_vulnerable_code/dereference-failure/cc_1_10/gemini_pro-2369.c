//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

// Generate a new RSA key pair
RSA *generate_key_pair()
{
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, 65537);

    if (RSA_generate_key_ex(rsa, 2048, e, NULL) != 1)
    {
        printf("Error generating RSA key pair.\n");
        return NULL;
    }

    BN_free(e);

    return rsa;
}

// Save the public key to a file
void save_public_key(RSA *rsa, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    PEM_write_RSA_PUBKEY(file, rsa);

    fclose(file);
}

// Save the private key to a file
void save_private_key(RSA *rsa, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    PEM_write_RSAPrivateKey(file, rsa, NULL, NULL, 0, NULL, NULL);

    fclose(file);
}

// Load the public key from a file
RSA *load_public_key(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    RSA *rsa = PEM_read_RSA_PUBKEY(file, NULL, NULL, NULL);

    fclose(file);

    return rsa;
}

// Load the private key from a file
RSA *load_private_key(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    RSA *rsa = PEM_read_RSAPrivateKey(file, NULL, NULL, NULL);

    fclose(file);

    return rsa;
}

// Encrypt data with the public key
int encrypt_data(const char *data, unsigned char **encrypted_data, RSA *public_key)
{
    int data_len = strlen(data);
    int encrypted_data_len = RSA_size(public_key);

    *encrypted_data = malloc(encrypted_data_len);

    if (*encrypted_data == NULL)
    {
        printf("Error allocating memory for encrypted data.\n");
        return -1;
    }

    if (RSA_public_encrypt(data_len, (unsigned char *)data, *encrypted_data, public_key, RSA_PKCS1_OAEP_PADDING) != 1)
    {
        printf("Error encrypting data.\n");
        return -1;
    }

    return encrypted_data_len;
}

// Decrypt data with the private key
int decrypt_data(const unsigned char *encrypted_data, int encrypted_data_len, char **data, RSA *private_key)
{
    int data_len = RSA_size(private_key);

    *data = malloc(data_len);

    if (*data == NULL)
    {
        printf("Error allocating memory for decrypted data.\n");
        return -1;
    }

    if (RSA_private_decrypt(encrypted_data_len, encrypted_data, (unsigned char *)*data, private_key, RSA_PKCS1_OAEP_PADDING) != 1)
    {
        printf("Error decrypting data.\n");
        return -1;
    }

    return data_len;
}

int main()
{
    RSA *public_key = generate_key_pair();
    RSA *private_key = generate_key_pair();

    save_public_key(public_key, "public_key.pem");
    save_private_key(private_key, "private_key.pem");

    char *data = "Hello, world!";

    unsigned char *encrypted_data;
    int encrypted_data_len = encrypt_data(data, &encrypted_data, public_key);

    char *decrypted_data;
    int decrypted_data_len = decrypt_data(encrypted_data, encrypted_data_len, &decrypted_data, private_key);

    printf("Original data: %s\n", data);
    printf("Encrypted data: %s\n", encrypted_data);
    printf("Decrypted data: %s\n", decrypted_data);

    RSA_free(public_key);
    RSA_free(private_key);

    return 0;
}