//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *createRSA(unsigned char *key, int public) {
    RSA *rsa = NULL;
    BIO *keybio = BIO_new_mem_buf(key, -1);
    if (keybio == NULL) {
        handleErrors();
    }
    if (public) {
        rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
    } else {
        rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
    }
    if (rsa == NULL) {
        handleErrors();
    }
    BIO_free_all(keybio);
    return rsa;
}

void publicKeyEncrypt() {
    unsigned char *plainText = (unsigned char *)"Hello, Public Key Cryptography!";
    unsigned char ciphertext[256];
    
    // Load the public key
    FILE *pubKeyFile = fopen("public.pem", "r");
    RSA *rsaPublicKey = PEM_read_RSA_PUBKEY(pubKeyFile, NULL, NULL, NULL);
    if (rsaPublicKey == NULL) {
        handleErrors();
    }
    
    int result = RSA_public_encrypt(strlen((char *)plainText), plainText, ciphertext, rsaPublicKey, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    
    printf("Encrypted message with public key:\n");
    for (int i = 0; i < result; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n\n");
    
    RSA_free(rsaPublicKey);
    fclose(pubKeyFile);
}

void privateKeyDecrypt() {
    unsigned char ciphertext[] = {0x8c, 0xa5, 0xae, 0x3c, 0x99, 0xff, 0x37, 0x1f, 0x20, 0xc0, 
                                   0xc0, 0xf3, 0xf2, 0xe8, 0x41, 0x1f, 0x47, 0x55, 0x45, 0x74, 
                                   0xd4, 0x88, 0x7b, 0x53, 0x52, 0xe9, 0x90, 0xf0, 0xf2, 0x2b, 
                                   0x4e, 0x98, 0x5d, 0x61, 0x3e, 0x2c, 0xbf, 0x38, 0x84, 0xe8, 
                                   0x1c, 0x9d, 0x8c, 0x7f, 0xa0, 0xa0, 0xa2, 0x7b, 0x32, 0xa4, 
                                   0x23, 0xe4, 0xd7, 0x00, 0x11, 0xd4, 0x1b, 0x5a, 0xf3, 0x3b, 
                                   0xda, 0x9b, 0xf6, 0x5b, 0x53, 0x70, 0xc8, 0x8c, 0x17};

    unsigned char decryptedText[256];
    
    // Load the private key
    FILE *privKeyFile = fopen("private.pem", "r");
    RSA *rsaPrivateKey = PEM_read_RSAPrivateKey(privKeyFile, NULL, NULL, NULL);
    if (rsaPrivateKey == NULL) {
        handleErrors();
    }
    
    int result = RSA_private_decrypt(sizeof(ciphertext), ciphertext, decryptedText, rsaPrivateKey, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    
    decryptedText[result] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted message with private key:\n");
    printf("%s\n", decryptedText);
    
    RSA_free(rsaPrivateKey);
    fclose(privKeyFile);
}

int main() {
    printf("Welcome to the Enthusiastic Public-Key Cryptography Example!\n\n");
    publicKeyEncrypt();
    privateKeyDecrypt();
    printf("Cryptography operations complete! Keep your keys safe!\n");
    return 0;
}