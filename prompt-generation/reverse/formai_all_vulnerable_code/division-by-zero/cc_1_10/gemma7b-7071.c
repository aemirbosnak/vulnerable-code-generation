//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

    // Declare variables
    char key[20], msg[100], encmsg[100], cipher[100];
    int i, keylen, msglen, encmsglen, n, r;

    // Get the key from the user
    printf("Enter a key (up to 20 characters): ");
    scanf("%s", key);
    keylen = strlen(key);

    // Get the message from the user
    printf("Enter a message (up to 100 characters): ");
    scanf("%s", msg);
    msglen = strlen(msg);

    // Encrypt the message
    encmsglen = encrypt(msg, key, encmsg, msglen, keylen);

    // Print the encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < encmsglen; i++) {
        printf("%c ", encmsg[i]);
    }

    // Newline
    printf("\n");

    // Decrypt the message (optional)
    n = decrypt(encmsg, key, cipher, encmsglen, keylen);

    // Print the decrypted message (optional)
    if (n) {
        printf("Decrypted message: ");
        for (r = 0; r < n; r++) {
            printf("%c ", cipher[r]);
        }
    }

    return 0;
}

int encrypt(char *msg, char *key, char *encmsg, int msglen, int keylen) {
    int i, j, k, encmsglen = 0, n = 0;
    char tmp[keylen];

    // Calculate the length of the encrypted message
    encmsglen = (msglen + keylen - 1) / keylen + 1;

    // Allocate memory for the encrypted message
    encmsg = malloc(encmsglen * sizeof(char));

    // Generate the keystream
    for (i = 0; i < keylen; i++) {
        tmp[i] = key[i] ^ 0x1B;
    }

    // Encrypt the message
    for (i = 0; i < msglen; i++) {
        k = 0;
        for (j = 0; j < keylen; j++) {
            n = (tmp[j] & 0x3F) ^ (msg[i] & 0x3F);
            encmsg[encmsglen++] = n;
            k++;
        }
    }

    return encmsglen;
}

int decrypt(char *encmsg, char *key, char *cipher, int encmsglen, int keylen) {
    int i, j, k, n = 0, r = 0;
    char tmp[keylen];

    // Generate the keystream
    for (i = 0; i < keylen; i++) {
        tmp[i] = key[i] ^ 0x1B;
    }

    // Decrypt the message
    for (i = 0; i < encmsglen; i++) {
        k = 0;
        for (j = 0; j < keylen; j++) {
            n = (encmsg[i] & 0x3F) ^ (tmp[j] & 0x3F);
            cipher[r++] = n;
            k++;
        }
    }

    return r;
}