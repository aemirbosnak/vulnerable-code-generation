//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>

#define KEY_LENGTH 2048
#define PUB_KEY_FILE "pubkey.pem"
#define PRI_KEY_FILE "prikey.pem"

int main() {
    RSA *rsa = RSA_new();

    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);

    RSA_generate_key_ex(rsa, KEY_LENGTH, e, NULL);

    // write RSA public key to file
    FILE *pub_key_file = fopen(PUB_KEY_FILE, "wb");
    if(pub_key_file == NULL) {
        printf("Failed to create public key file.\n");
        return -1;
    }
    PEM_write_RSA_PUBKEY(pub_key_file, rsa);
    fclose(pub_key_file);

    // write RSA private key to file
    FILE *pri_key_file = fopen(PRI_KEY_FILE, "wb");
    if(pri_key_file == NULL) {
        printf("Failed to create private key file.\n");
        return -1;
    }
    PEM_write_RSAPrivateKey(pri_key_file, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(pri_key_file);

    // read public key from file
    FILE *pub_key_file_r = fopen(PUB_KEY_FILE, "rb");
    if(pub_key_file_r == NULL) {
        printf("Failed to read public key file.\n");
        return -1;
    }
    RSA *pub_key = PEM_read_RSA_PUBKEY(pub_key_file_r, NULL, NULL, NULL);
    fclose(pub_key_file_r);

    // encrypt data with public key
    char *data = "Hello, world!";
    int data_len = strlen(data);
    unsigned char *encrypted_data = malloc(sizeof(unsigned char) * RSA_size(pub_key));
    int encrypted_data_len = RSA_public_encrypt(data_len, (unsigned char *)data, encrypted_data, pub_key, RSA_PKCS1_PADDING);

    // read private key from file
    FILE *pri_key_file_r = fopen(PRI_KEY_FILE, "rb");
    if(pri_key_file_r == NULL) {
        printf("Failed to read private key file.\n");
        return -1;
    }
    RSA *pri_key = PEM_read_RSAPrivateKey(pri_key_file_r, NULL, NULL, NULL);
    fclose(pri_key_file_r);

    // decrypt encrypted data with private key
    unsigned char *decrypted_data = malloc(sizeof(unsigned char) * encrypted_data_len);
    int decrypted_data_len = RSA_private_decrypt(encrypted_data_len, encrypted_data, decrypted_data, pri_key, RSA_PKCS1_PADDING);

    printf("Original Data: %s\n", data);
    printf("Encrypted Data: ");
    for(int i = 0; i < encrypted_data_len; i++) {
        printf("%02x ", encrypted_data[i]);
    }
    printf("\nDecrypted Data: %s\n", decrypted_data);

    free(encrypted_data);
    free(decrypted_data);
    RSA_free(pub_key);
    RSA_free(pri_key);
    BN_free(e);
    RSA_free(rsa);

    return 0;
}