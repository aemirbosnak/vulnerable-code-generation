//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

// Function to handle OpenSSL errors in a romantic manner
void romanticErrorHandling(const char* msg) {
    fprintf(stderr, "Oh dear heart, something went amiss: %s\n", msg);
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
}

// Function to create a new RSA key pair for our love letter
RSA* createKeyPair(int bits) {
    RSA* keypair = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (keypair == NULL) {
        romanticErrorHandling("The stars did not align for key generation.");
    }
    return keypair;
}

// Function to write the Private Key to a file
void writePrivateKeyToFile(RSA* keypair, const char* filename) {
    FILE* privFile = fopen(filename, "wb");
    if (privFile == NULL) {
        romanticErrorHandling("The ink ran dry, cannot write private key.");
    }
    if (PEM_write_RSAPrivateKey(privFile, keypair, NULL, NULL, 0, NULL, NULL) == 0) {
        romanticErrorHandling("The scroll could not contain the secrets of love.");
    }
    fclose(privFile);
    printf("Ah, true love, your private key is penned onto: %s\n", filename);
}

// Function to write the Public Key to a file
void writePublicKeyToFile(RSA* keypair, const char* filename) {
    FILE* pubFile = fopen(filename, "wb");
    if (pubFile == NULL) {
        romanticErrorHandling("The sun set on our chance to write the public key.");
    }
    if (PEM_write_RSA_PUBKEY(pubFile, keypair) == 0) {
        romanticErrorHandling("Our promises of love could not be inscribed.");
    }
    fclose(pubFile);
    printf("Oh darling, your public key now graces: %s\n", filename);
}

// Function to encrypt the love letter with the public key
void encryptLoveLetter(RSA* keypair, const char* loveLetter) {
    int keySize = RSA_size(keypair);
    unsigned char* encrypted = (unsigned char*)malloc(keySize);
    
    int encryptSize = RSA_public_encrypt(strlen(loveLetter), (unsigned char*)loveLetter, encrypted, keypair, RSA_PKCS1_PADDING);
    if (encryptSize == -1) {
        romanticErrorHandling("The message of love was lost in the ether.");
    }

    printf("My sweet, your encrypted love letter (in hex): ");
    for (int i = 0; i < encryptSize; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    free(encrypted);
}

// Function to decrypt the love letter with the private key
void decryptLoveLetter(RSA* keypair, unsigned char* encrypted, int encryptSize) {
    int keySize = RSA_size(keypair);
    unsigned char* decrypted = (unsigned char*)malloc(keySize);
    
    int decryptSize = RSA_private_decrypt(encryptSize, encrypted, decrypted, keypair, RSA_PKCS1_PADDING);
    if (decryptSize == -1) {
        romanticErrorHandling("Alas, the love letter could not be restored.");
    }

    decrypted[decryptSize] = '\0'; // Null terminate the decrypted message
    printf("Oh my beloved, your love letter is: %s\n", decrypted);

    free(decrypted);
}

// The main function to orchestrate our love story
int main() {
    printf("In a world of cryptographic love...\n");

    // Create a new key pair
    RSA* keypair = createKeyPair(2048);

    // Write the private and public keys to files
    writePrivateKeyToFile(keypair, "private_key.pem");
    writePublicKeyToFile(keypair, "public_key.pem");

    // The love letter we wish to encrypt
    const char* loveLetter = "Dearest, you are the light of my life.";
    // Encrypt said love letter
    encryptLoveLetter(keypair, loveLetter);

    // Encrypt again for demonstration purposes (actual hex would come from previous encrypting)
    unsigned char fakeEncrypted[] = { /* provide the previous hex output here in binary for demo */ };
    decryptLoveLetter(keypair, fakeEncrypted, sizeof(fakeEncrypted));

    // Clean up the key pair
    RSA_free(keypair);

    printf("The story of our love and trust is now forever encrypted.\n");
    return 0;
}