//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <string.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateKeypair(int bits) {
    // Let's create our very own lovely RSA key pair.
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (!rsa) {
        printf("Oh no! Key generation failed! Let's debug...\n");
        handleErrors();
    }
    
    // Save the public key
    FILE *pubKeyFile = fopen("public_key.pem", "wb");
    if (!pubKeyFile) {
        printf("Uh-oh! Couldn't open public_key.pem for writing!\n");
        handleErrors();
    }
    if (PEM_write_RSA_PUBKEY(pubKeyFile, rsa) != 1) {
        printf("Yikes! Couldn't write the public key to file!\n");
        handleErrors();
    }
    fclose(pubKeyFile);
    
    // Save the private key
    FILE *privKeyFile = fopen("private_key.pem", "wb");
    if (!privKeyFile) {
        printf("Oh dear! Couldn't open private_key.pem for writing!\n");
        handleErrors();
    }
    if (PEM_write_RSAPrivateKey(privKeyFile, rsa, NULL, NULL, 0, NULL, NULL) != 1) {
        printf("Eek! Couldn't write the private key to file!\n");
        handleErrors();
    }
    fclose(privKeyFile);
    
    printf("Yay! Successfully generated the RSA key pair!\n");
    RSA_free(rsa); // Free the RSA key object
}

void encryptMessage(const char *message, const char *pubKeyFileName) {
    FILE *pubKeyFile = fopen(pubKeyFileName, "rb");
    if (!pubKeyFile) {
        printf("Oops! Can't open the public key file for reading!\n");
        handleErrors();
    }

    RSA *rsa_pub = PEM_read_RSA_PUBKEY(pubKeyFile, NULL, NULL, NULL);
    if (!rsa_pub) {
        printf("Oh no! Failed to read the public key!\n");
        handleErrors();
    }
    fclose(pubKeyFile);

    int rsaSize = RSA_size(rsa_pub);
    unsigned char *encryptedMessage = malloc(rsaSize);
    if (!encryptedMessage) {
        printf("Yikes! Memory allocation failed!\n");
        handleErrors();
    }

    int encryptLen = RSA_public_encrypt(strlen(message) + 1, (unsigned char*)message, encryptedMessage, rsa_pub, RSA_PKCS1_PADDING);
    if (encryptLen == -1) {
        printf("Oh dear! Encryption failed!\n");
        handleErrors();
    }

    printf("Hooray! Successfully encrypted the message!\n");
    printf("Encrypted message (hex): ");
    for (int i = 0; i < encryptLen; i++) {
        printf("%02x", encryptedMessage[i]);
    }
    printf("\n");

    free(encryptedMessage);
    RSA_free(rsa_pub);
}

void decryptMessage(const char *encryptedMessageHex, const char *privKeyFileName) {
    FILE *privKeyFile = fopen(privKeyFileName, "rb");
    if (!privKeyFile) {
        printf("Oops! Can't open the private key file for reading!\n");
        handleErrors();
    }

    RSA *rsa_priv = PEM_read_RSAPrivateKey(privKeyFile, NULL, NULL, NULL);
    if (!rsa_priv) {
        printf("Oh no! Failed to read the private key!\n");
        handleErrors();
    }
    fclose(privKeyFile);

    size_t len = strlen(encryptedMessageHex) / 2;
    unsigned char *encryptedMessage = malloc(len);
    for (size_t i = 0; i < len; i++) {
        sscanf(&encryptedMessageHex[i * 2], "%2hhx", &encryptedMessage[i]);
    }

    unsigned char *decryptedMessage = malloc(RSA_size(rsa_priv));
    if (!decryptedMessage) {
        printf("Yikes! Memory allocation failed for decrypted message!\n");
        handleErrors();
    }

    int decryptLen = RSA_private_decrypt(len, encryptedMessage, decryptedMessage, rsa_priv, RSA_PKCS1_PADDING);
    if (decryptLen == -1) {
        printf("Oh deer! Decryption failed!\n");
        handleErrors();
    }

    printf("Hooray! Successfully decrypted the message!\n");
    printf("Decrypted message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);
    RSA_free(rsa_priv);
}

int main() {
    printf("Welcome to the RSA Key Management Program!\n");
    printf("Let's generate a cheerful pair of RSA keys!\n");
    
    generateKeypair(2048); // Generate keypair with 2048 bits

    const char *message = "Hello, RSA World!";
    printf("Now let's encrypt a message: \"%s\"\n", message);
    encryptMessage(message, "public_key.pem");

    printf("Let's say we have a hex string (replace with the actual one):\n");
    const char *encryptedMessageHex = "e8d3ef90..."; // This should be replaced with a real encrypted message
    decryptMessage(encryptedMessageHex, "private_key.pem");

    printf("Thank you for using this delightful RSA program! Goodbye!\n");
    return 0;
}