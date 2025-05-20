//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>

unsigned char *obfuscate(unsigned char *in, unsigned char *key, int len)
{
    unsigned char *out = malloc(len);
    for (int i = 0; i < len; i++)
    {
        out[i] = in[i] ^ key[i % sizeof(key)];
    }
    return out;
}

unsigned char *deobfuscate(unsigned char *in, unsigned char *key, int len)
{
    unsigned char *out = malloc(len);
    for (int i = 0; i < len; i++)
    {
        out[i] = in[i] ^ key[i % sizeof(key)];
    }
    return out;
}

char *random_str(int len)
{
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        str[i] = rand() % 256;
    }
    str[len] = '\0';
    return str;
}

int main()
{
    unsigned char *key = random_str(32); // 256 bit key
    unsigned char *in = random_str(1024); // 8192 bit input

    unsigned char *out = obfuscate(in, key, 1024); // encrypt

    unsigned char *decrypted = deobfuscate(out, key, 1024); // decrypt

    if (memcmp(decrypted, in, 1024) == 0)
    {
        printf("Encryption/decryption successful!\n");
    }
    else
    {
        printf("Encryption/decryption failed!\n");
    }

    free(key);
    free(in);
    free(out);
    free(decrypted);

    return 0;
}