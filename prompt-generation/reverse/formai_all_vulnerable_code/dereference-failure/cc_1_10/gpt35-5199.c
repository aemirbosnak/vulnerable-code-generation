//FormAI DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 32
#define IV_SIZE 16

void handleErrors(void)
{
    printf("Encryption failed\n");
    exit(1);
}

int do_crypt(FILE *in, FILE *out, const unsigned char *key, const unsigned char *iv, int do_encrypt)
{
    EVP_CIPHER_CTX *ctx;
    unsigned char inbuf[BUFFER_SIZE], outbuf[BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH];
    int nread, outlen, total = 0;
    
    ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, do_encrypt);
    
    while (1) {
        nread = fread(inbuf, 1, BUFFER_SIZE, in);
        if (nread < BUFFER_SIZE) {
            if (ferror(in))
                handleErrors();
            break;
        }
        if (!EVP_CipherUpdate(ctx, outbuf, &outlen, inbuf, nread))
            handleErrors();
        fwrite(outbuf, 1, outlen, out);
        total += outlen;
    }
    
    if (!EVP_CipherFinal_ex(ctx, outbuf, &outlen))
        handleErrors();
    fwrite(outbuf, 1, outlen, out);
    total += outlen;
    
    EVP_CIPHER_CTX_free(ctx);
    return total;
}

int encrypt_file(const char *in_file, const char *out_file, unsigned char *key, unsigned char *iv)
{
    FILE *fin, *fout;
    int len;
    
    if ((fin = fopen(in_file, "rb")) == NULL) {
        printf("Unable to open input file\n");
        return -1;
    }
    if ((fout = fopen(out_file, "wb")) == NULL) {
        printf("Unable to open output file\n");
        return -1;
    }
    
    len = do_crypt(fin, fout, key, iv, 1);
    
    fclose(fin);
    fclose(fout);
    printf("Encryption complete. %d bytes written to %s\n", len, out_file);
    return 0;
}

int decrypt_file(const char *in_file, const char *out_file, unsigned char *key, unsigned char *iv)
{
    FILE *fin, *fout;
    int len;
    
    if ((fin = fopen(in_file, "rb")) == NULL) {
        printf("Unable to open input file\n");
        return -1;
    }
    if ((fout = fopen(out_file, "wb")) == NULL) {
        printf("Unable to open output file\n");
        return -1;
    }
    
    len = do_crypt(fin, fout, key, iv, 0);
    
    fclose(fin);
    fclose(fout);
    printf("Decryption complete. %d bytes written to %s\n", len, out_file);
    return 0;
}

int main(int argc, char *argv[])
{
    // check arguments
    if (argc < 5) {
        printf("Usage: ./interoperable-crypt <input-file> <output-file> <key> <iv> <mode>\n");
        printf("Modes: -e for encryption, -d for decryption\n");
        return -1;
    }
    
    // read key and iv
    unsigned char key[KEY_SIZE], iv[IV_SIZE];
    if (strlen(argv[3]) != KEY_SIZE * 2 || strlen(argv[4]) != IV_SIZE * 2) {
        printf("Invalid key and/or iv length\n");
        return -1;
    }
    for (int i = 0; i < KEY_SIZE; i++)
        sscanf(&argv[3][i * 2], "%02x", &key[i]);
    for (int i = 0; i < IV_SIZE; i++)
        sscanf(&argv[4][i * 2], "%02x", &iv[i]);
    
    // encrypt or decrypt
    if (strcmp(argv[5], "-e") == 0)
        encrypt_file(argv[1], argv[2], key, iv);
    else if (strcmp(argv[5], "-d") == 0)
        decrypt_file(argv[1], argv[2], key, iv);
    else {
        printf("Invalid mode\n");
        return -1;
    }
    
    return 0;
}