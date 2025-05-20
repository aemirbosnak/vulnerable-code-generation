//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define MOD_P 0xffffffffffffffffc90fdaa22168c234c4c6628b80dc1cd129024e088a67cc74020bbea63b139b22514a08798e3404ddef9519b3cd3a431b302b0a6df25f14374fe1356d6d51c245e485b576625e7ec6f44c42e9a637ed6b0bff5cb6f406b7edee386bfb5a899fa5ae9f24117c4b1fe649286651ece45b3dc2007cb8a163bf0598da48361c55d39a69163fa8fd24cf5f83655d23dca3ad961c62f356208552bb9ed529077096966d670c354e4abc9804f1746c08ca237327ffffffffffffffff
#define MOD_A 0xffffffffffffffff
#define MOD_G 0xffffffffffffffffffffffffffffffffffffffff

int main(int argc, char *argv[]) {
    char *publicKey = argv[1];
    char *secretKey = argv[2];

    unsigned char *publicKeyBytes = malloc(strlen(publicKey));
    unsigned char *secretKeyBytes = malloc(strlen(secretKey));
    unsigned char *messageBytes = malloc(strlen(argv[3]));

    strcpy(publicKeyBytes, publicKey);
    strcpy(secretKeyBytes, secretKey);
    strcpy(messageBytes, argv[3]);

    unsigned char *publicKeyEncrypted = malloc(strlen(publicKeyBytes));
    unsigned char *secretKeyEncrypted = malloc(strlen(secretKeyBytes));
    unsigned char *messageEncrypted = malloc(strlen(messageBytes));

    int publicKeyEncryptedLength = encryptPublicKey(publicKeyBytes, secretKeyBytes, publicKeyEncrypted);
    int secretKeyEncryptedLength = encryptSecretKey(secretKeyBytes, messageBytes, secretKeyEncrypted);
    int messageEncryptedLength = encryptMessage(publicKeyEncrypted, secretKeyEncrypted, messageBytes, messageEncrypted);

    printf("Public Key Encrypted: ");
    for (int i = 0; i < publicKeyEncryptedLength; i++) {
        printf("%02x", publicKeyEncrypted[i]);
    }
    printf("\nSecret Key Encrypted: ");
    for (int i = 0; i < secretKeyEncryptedLength; i++) {
        printf("%02x", secretKeyEncrypted[i]);
    }
    printf("\nMessage Encrypted: ");
    for (int i = 0; i < messageEncryptedLength; i++) {
        printf("%02x", messageEncrypted[i]);
    }
    printf("\n");

    free(publicKeyBytes);
    free(secretKeyBytes);
    free(messageBytes);
    free(publicKeyEncrypted);
    free(secretKeyEncrypted);
    free(messageEncrypted);

    return 0;
}

int encryptPublicKey(unsigned char *publicKeyBytes, unsigned char *secretKeyBytes, unsigned char *publicKeyEncrypted) {
    int publicKeyEncryptedLength = 0;

    for (int i = 0; i < strlen(publicKeyBytes); i++) {
        int value = (int)publicKeyBytes[i] ^ (int)secretKeyBytes[i];
        publicKeyEncrypted[publicKeyEncryptedLength++] = (unsigned char)value;
    }

    return publicKeyEncryptedLength;
}

int encryptSecretKey(unsigned char *secretKeyBytes, unsigned char *messageBytes, unsigned char *secretKeyEncrypted) {
    int secretKeyEncryptedLength = 0;

    for (int i = 0; i < strlen(secretKeyBytes); i++) {
        int value = (int)secretKeyBytes[i] ^ (int)messageBytes[i];
        secretKeyEncrypted[secretKeyEncryptedLength++] = (unsigned char)value;
    }

    return secretKeyEncryptedLength;
}

int encryptMessage(unsigned char *publicKeyEncrypted, unsigned char *secretKeyEncrypted, unsigned char *messageBytes, unsigned char *messageEncrypted) {
    int messageEncryptedLength = 0;

    for (int i = 0; i < strlen(messageBytes); i++) {
        int value = (int)publicKeyEncrypted[i] ^ (int)secretKeyEncrypted[i];
        messageEncrypted[messageEncryptedLength++] = (unsigned char)value;
    }

    return messageEncryptedLength;
}