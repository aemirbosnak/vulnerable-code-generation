//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

unsigned int *generateSBox()
{
    /* Generate S-Box */
    unsigned int *sbox = (unsigned int *)malloc(sizeof(unsigned int) * 256);
    for (int i = 0; i < 256; i++)
    {
        sbox[i] = i;
    }

    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        j = (j + sbox[i]) % 256;
        unsigned int temp = sbox[i];
        sbox[i] = sbox[j];
        sbox[j] = temp;
    }

    return sbox;
}

unsigned int *generateKeySchedule(unsigned char *key, int keyLength, unsigned int *sbox)
{
    /* Generate Key Schedule */
    unsigned int *keySchedule = (unsigned int *)malloc(sizeof(unsigned int) * 64);

    for (int i = 0; i < 64; i++)
    {
        keySchedule[i] = sbox[key[i % keyLength]];
    }

    return keySchedule;
}

unsigned int *processMessage(unsigned char *message, int messageLength, unsigned int *sbox, unsigned int *keySchedule)
{
    /* Process Message */
    unsigned int *hash = (unsigned int *)malloc(sizeof(unsigned int) * 4);

    for (int i = 0; i < 4; i++)
    {
        hash[i] = i * 0x6A09E667;
    }

    unsigned char chunk[64];
    int i = 0, j = 0;

    while (i < messageLength)
    {
        for (int k = 0; k < 64; k++)
        {
            if (i >= messageLength)
            {
                chunk[k] = 0;
                j++;
            }
            else
            {
                chunk[k] = message[i];
                i++;
            }
        }

        unsigned int w[16];

        for (int k = 0; k < 16; k++)
        {
            w[k] = ((unsigned int)chunk[k * 4]) |
                   ((unsigned int)chunk[k * 4 + 1] << 8) |
                   ((unsigned int)chunk[k * 4 + 2] << 16) |
                   ((unsigned int)chunk[k * 4 + 3] << 24);
        }

        unsigned int a = hash[0];
        unsigned int b = hash[1];
        unsigned int c = hash[2];
        unsigned int d = hash[3];

        for (int k = 0; k < 64; k++)
        {
            unsigned int f, g;

            if (k < 16)
            {
                f = (b & c) | ((~b) & d);
                g = k;
            }
            else if (k < 32)
            {
                f = (d & b) | ((~d) & c);
                g = (5 * k + 1) % 16;
            }
            else if (k < 48)
            {
                f = b ^ c ^ d;
                g = (3 * k + 5) % 16;
            }
            else
            {
                f = c ^ (b | (~d));
                g = (7 * k) % 16;
            }

            unsigned int temp = d;
            d = c;
            c = b;
            b = b + ROTATE_LEFT((a + f + keySchedule[g] + w[g]), 7);
            a = temp;
        }

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
    }

    return hash;
}

char *hashMessage(unsigned char *message, int messageLength)
{
    unsigned int *sbox = generateSBox();
    unsigned int *keySchedule = generateKeySchedule((unsigned char *)"password", 8, sbox);
    unsigned int *hash = processMessage(message, messageLength, sbox, keySchedule);

    char *hashString = (char *)malloc(sizeof(char) * 33);

    for (int i = 0; i < 4; i++)
    {
        sprintf(hashString + (i * 8), "%08x", hash[i]);
    }

    free(sbox);
    free(keySchedule);
    free(hash);
    return hashString;
}

int main()
{
    char *message = "Hello, world!";
    char *hash = hashMessage((unsigned char *)message, strlen(message));
    printf("%s\n", hash);
    free(hash);
    return 0;
}