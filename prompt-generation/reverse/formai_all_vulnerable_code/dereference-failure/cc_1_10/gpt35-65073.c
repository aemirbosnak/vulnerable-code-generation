//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
/*
 * RSA Public-Key Encryption and Decryption 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define KEY_LENGTH  2048
#define PUB_KEY_FILE "public.pem"
#define PRIV_KEY_FILE "private.pem"

typedef struct {
    RSA *key;
    unsigned char *data;
    size_t data_size;
} EncryptedPacket;

void generate_key_pair(int key_length);
int encrypt_data(unsigned char *in_data, size_t in_data_len, EncryptedPacket *out_packet);
int decrypt_data(EncryptedPacket *in_packet, unsigned char **out_data, size_t *out_data_len);

int main(int argc, char **argv) {

    // Generate RSA key pair
    generate_key_pair(KEY_LENGTH);

    // Message to be encrypted
    unsigned char message[] = "Hello, world!";
    size_t message_len = strlen((char *) message);

    // Encrypt message
    EncryptedPacket packet;
    if (encrypt_data(message, message_len, &packet) < 0) {
        fprintf(stderr, "Error: Failed to encrypt data\n");
        return -1;
    }

    // Decrypt message
    unsigned char *plain_text;
    size_t plain_text_len;
    if (decrypt_data(&packet, &plain_text, &plain_text_len) < 0) {
        fprintf(stderr, "Error: Failed to decrypt data\n");
        return -1;
    }

    // Print decrypted message
    printf("Decrypted message: %s\n", plain_text);

    return 0;
}

void generate_key_pair(int key_length) {

    // Generate RSA key pair
    RSA *keypair = RSA_generate_key(key_length, RSA_F4, NULL, NULL);

    // Write public key to file
    FILE *pub_key_file = fopen(PUB_KEY_FILE, "wb");
    PEM_write_RSA_PUBKEY(pub_key_file, keypair);
    fclose(pub_key_file);

    // Write private key to file
    FILE *priv_key_file = fopen(PRIV_KEY_FILE, "wb");
    PEM_write_RSAPrivateKey(priv_key_file, keypair, NULL, NULL, 0, NULL, NULL);
    fclose(priv_key_file);

    // Free RSA key pair
    RSA_free(keypair);
}

int encrypt_data(unsigned char *in_data, size_t in_data_len, EncryptedPacket *out_packet) {

    // Read public key from file
    FILE *pub_key_file = fopen(PUB_KEY_FILE, "rb");
    RSA *pub_key = PEM_read_RSA_PUBKEY(pub_key_file, NULL, NULL, NULL);
    fclose(pub_key_file);

    // Allocate memory for output packet
    out_packet->key = pub_key;
    out_packet->data = malloc(RSA_size(pub_key));
    out_packet->data_size = 0;

    // Encrypt data
    int rv = RSA_public_encrypt(in_data_len, in_data, out_packet->data, pub_key, RSA_PKCS1_OAEP_PADDING);
    if (rv < 0) {
        free(out_packet->data);
        return -1;
    }
    out_packet->data_size = rv;

    // Free public key
    RSA_free(pub_key);

    return 0;
}

int decrypt_data(EncryptedPacket *in_packet, unsigned char **out_data, size_t *out_data_len) {

    // Read private key from file
    FILE *priv_key_file = fopen(PRIV_KEY_FILE, "rb");
    RSA *priv_key = PEM_read_RSAPrivateKey(priv_key_file, NULL, NULL, NULL);
    fclose(priv_key_file);

    // Allocate memory for decrypted data
    *out_data = malloc(RSA_size(priv_key));
    *out_data_len = 0;

    // Decrypt data
    int rv = RSA_private_decrypt(in_packet->data_size, in_packet->data, *out_data, priv_key, RSA_PKCS1_OAEP_PADDING);
    if (rv < 0) {
        free(*out_data);
        RSA_free(priv_key);
        return -1;
    }
    *out_data_len = rv;

    // Free private key
    RSA_free(priv_key);

    return 0;
}