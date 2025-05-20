//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/hmac.h>

// Function to print the given hash
void printHash(unsigned char *hash, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x", hash[i]);
    }
}

// Function to generate MD5 hash
void generate_MD5_hash(char *str)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*) str, strlen(str), digest);
    printf("MD5 hash of '%s': ", str);
    printHash(digest, MD5_DIGEST_LENGTH);
    printf("\n");
}

// Function to generate HMAC-SHA1 hash
void generate_HMAC_SHA1_hash(char *key, char *data)
{
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int len;
    HMAC(EVP_sha1(), key, strlen(key), (unsigned char*) data, strlen(data), digest, &len);
    printf("HMAC-SHA1 hash of '%s' using key '%s': ", data, key);
    printHash(digest, len);
    printf("\n");
}

int main()
{
    char *key = "mypassword";
    char *data1 = "hello";
    char *data2 = "world";

    generate_MD5_hash(data1);
    generate_MD5_hash(data2);

    generate_HMAC_SHA1_hash(key, data1);
    generate_HMAC_SHA1_hash(key, data2);

    return 0;
}