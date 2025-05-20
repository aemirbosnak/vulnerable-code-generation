//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/aes.h>

// Definition of Block size for AES Encryption
#define BLOCK_SIZE 16

//Structure that contains the key for encryption/decryption
typedef struct
{
    unsigned char key[32]; // 256 bit Key
} Key;

//Function to generate SHA256 hash of a message
unsigned char* generateSHA256(char *message, int length)
{
    unsigned char *hash = (unsigned char*)malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, length);
    SHA256_Final(hash, &sha256);
    return hash;
}

//Function to perform AES Encryption for a given message and key
unsigned char* encryptAES(unsigned char* message, unsigned char* key)
{
    AES_KEY aeskey; // AES Key for Encryption
    unsigned char* iv = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_SIZE); // Initialization Vector (IV)
    unsigned char* ciphertext = (unsigned char*)malloc(sizeof(unsigned char)*(BLOCK_SIZE+strlen(message))); // Ciphertext

    //Generation of random IV (16 bytes)
    int i;
    for(i=0;i<BLOCK_SIZE;i++)
    {
        iv[i] = rand()%256 ;
    }

    //Initialize AES Key
    AES_set_encrypt_key(key,256,&aeskey);

    //Encrypt the Message
    AES_cbc_encrypt(message, ciphertext+BLOCK_SIZE, strlen(message), &aeskey, iv, AES_ENCRYPT);

    //Copy IV to the front of the Ciphertext
    memcpy(ciphertext, iv, BLOCK_SIZE);

    return ciphertext;
}

//Function to perform AES Decryption for a given ciphertext, key and initialization vector
unsigned char* decryptAES(unsigned char* ciphertext, unsigned char* key, unsigned char* iv)
{
    AES_KEY aeskey; // AES Key for Decryption
    unsigned char* plaintext = (unsigned char*)malloc(sizeof(unsigned char)*(strlen(ciphertext)-BLOCK_SIZE)); // Plaintext

    //Initialize AES Key
    AES_set_decrypt_key(key, 256, &aeskey);

    //Decrypt the Ciphertext
    AES_cbc_encrypt(ciphertext+BLOCK_SIZE, plaintext, strlen(ciphertext)-BLOCK_SIZE, &aeskey, iv, AES_DECRYPT);

    return plaintext;
}

int main()
{
    char* message = "Hello World!"; // Message to be encrypted

    //Generate SHA-256 Hash of the Message for Key Generation
    unsigned char* hash = generateSHA256(message,strlen(message)+1);

    //Initialize Key
    Key key;
    memcpy(key.key, hash, 32);

    //Free Hash Memory
    free(hash);

    //Encrypt the Message using AES
    unsigned char* ciphertext = encryptAES(message, key.key);

    //Store Initialization Vector
    unsigned char* iv = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_SIZE);
    memcpy(iv, ciphertext, BLOCK_SIZE);

    //Print Initialization Vector and Ciphertext
    printf("Initialization Vector:\n");
    int i;
    for(i=0;i<BLOCK_SIZE;i++)
    {
        printf("%02x", iv[i]);
    }
    printf("\nCiphertext:\n");
    for(i=0;i<strlen(message)+BLOCK_SIZE;i++)
    {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    //Decrypt the Ciphertext using AES
    unsigned char* plaintext = decryptAES(ciphertext, key.key, iv);

    //Print Plaintext
    printf("Plaintext: ");
    printf("%s\n",plaintext);

    //Free all Memory
    free(ciphertext);
    free(iv);
    free(plaintext);

    return 0;
}