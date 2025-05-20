//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is an example of a unique implementation of an encryption tool
 * that uses a custom algorithm to encrypt and decrypt messages. This is an
 * expert-level program that requires advanced knowledge of C programming
 * concepts and algorithms.
 *
 * The encryption algorithm consists of the following steps:
 * 1. Generate a random key string of 32 characters
 * 2. XOR the message string with the key string
 * 3. Reverses the order of the bits in the resulting string
 * 4. XOR the resulting string again with the key string
 *
 * To decrypt the message, the algorithm is applied in reverse order.
 */


void generate_rand_key(char *key)
{
    int i;
    for(i = 0; i < 32; i++) {
        int random_num = rand() % 256;
        key[i] = random_num;
    }
}


char *encrypt(char *message, char *key)
{
    char *encrypted = malloc(strlen(message) + 1);
    strcpy(encrypted, message);

    int key_len = strlen(key);
    int msg_len = strlen(message);

    int i;
    for(i = 0; i < msg_len; i++) {
        encrypted[i] ^= key[i % key_len];
    }

    for(i = 0; i < msg_len; i++) {
        unsigned char temp = (unsigned char)encrypted[i];
        int j, rev;
        for(j = 0, rev = 0; j < 8 && temp > 0; j++) {
            rev = (rev << 1) | (temp & 1);
            temp >>= 1;
        }
        encrypted[i] = (char)rev;
    }

    for(i = 0; i < msg_len; i++) {
        encrypted[i] ^= key[i % key_len];
    }

    return encrypted;
}


char *decrypt(char *encrypted, char *key)
{

    char *message = malloc(strlen(encrypted) + 1);
    strcpy(message, encrypted);

    int key_len = strlen(key);
    int msg_len = strlen(encrypted);

    int i;
    for(i = 0; i < msg_len; i++) {
        message[i] ^= key[i % key_len];
    }

    for(i = 0; i < msg_len; i++) {
        unsigned char temp = (unsigned char)message[i];
        int j, rev;
        for(j = 0, rev = 0; j < 8 && temp > 0; j++) {
            rev = (rev << 1) | (temp & 1);
            temp >>= 1;
        }
        message[i] = (char)rev;
    }

    for(i = 0; i < msg_len; i++) {
        message[i] ^= key[i % key_len];
    }

    return message;
}


int main()
{
    char key[33];
    char *message = "This is a secret message";

    generate_rand_key(key);

    printf("Original message: %s\n", message);

    char *encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char *decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);

    return 0;
}