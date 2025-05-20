//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

void encrypt_file(char* input_filename, char* output_filename, unsigned char* key, unsigned char* iv)
{
    FILE *ifp, *ofp;
    AES_KEY aes_key;
    unsigned char in_buff[AES_BLOCK_SIZE], out_buff[AES_BLOCK_SIZE];
    int bytes_read, bytes_written;
    ofp = fopen(output_filename, "wb");
    if (ofp == NULL)
    {
        fprintf(stderr, "Could not open output file: %s\n", output_filename);
        exit(1);
    }
    ifp = fopen(input_filename, "rb");
    if (ifp == NULL)
    {
        fprintf(stderr, "Could not open input file: %s\n", input_filename);
        exit(1);
    }
    AES_set_encrypt_key(key, 128, &aes_key);
    while (1)
    {
        bytes_read = fread(in_buff, 1, AES_BLOCK_SIZE, ifp);
        AES_cbc_encrypt(in_buff, out_buff, bytes_read, &aes_key, iv, AES_ENCRYPT);
        bytes_written = fwrite(out_buff, 1, bytes_read, ofp);
        if (bytes_read != AES_BLOCK_SIZE)
            break;
    }
    fclose(ifp);
    fclose(ofp);
}

void decrypt_file(char* input_filename, char* output_filename, unsigned char* key, unsigned char* iv)
{
    FILE *ifp, *ofp;
    AES_KEY aes_key;
    unsigned char in_buff[AES_BLOCK_SIZE], out_buff[AES_BLOCK_SIZE];
    int bytes_read, bytes_written;
    ofp = fopen(output_filename, "wb");
    if (ofp == NULL)
    {
        fprintf(stderr, "Could not open output file: %s\n", output_filename);
        exit(1);
    }
    ifp = fopen(input_filename, "rb");
    if (ifp == NULL)
    {
        fprintf(stderr, "Could not open input file: %s\n", input_filename);
        exit(1);
    }
    AES_set_decrypt_key(key, 128, &aes_key);
    while (1)
    {
        bytes_read = fread(in_buff, 1, AES_BLOCK_SIZE, ifp);
        AES_cbc_encrypt(in_buff, out_buff, bytes_read, &aes_key, iv, AES_DECRYPT);
        bytes_written = fwrite(out_buff, 1, bytes_read, ofp);
        if (bytes_read != AES_BLOCK_SIZE)
            break;
    }
    fclose(ifp);
    fclose(ofp);
}

int main(int argc, char* argv[])
{
    if (argc != 5 || strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0)
    {
        fprintf(stderr, "Usage: %s -e/-d input_file output_file key iv\n", argv[0]);
        exit(1);
    }

    char* input_filename = argv[2];
    char* output_filename = argv[3];
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(key, argv[4], AES_BLOCK_SIZE);
    memcpy(iv, argv[5], AES_BLOCK_SIZE);

    if (strcmp(argv[1], "-e") == 0)
        encrypt_file(input_filename, output_filename, key, iv);
    else if (strcmp(argv[1], "-d") == 0)
        decrypt_file(input_filename, output_filename, key, iv);

    return 0;
}