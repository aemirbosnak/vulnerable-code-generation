//FormAI DATASET v1.0 Category: Compression algorithms ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 100
#define MAX_BIT_LENGTH 8

unsigned char ExtractBits(unsigned char pattern, unsigned char bit_count);

unsigned char pack(char *str, char *out)
{
    unsigned char i, j, k, index, temp;
    unsigned char bit_count = strlen(str) * MAX_BIT_LENGTH;
    unsigned char packed_bits_count = (bit_count / MAX_BIT_LENGTH) + ((bit_count % MAX_BIT_LENGTH) ? 1 : 0);

    unsigned char *packed_bits = (unsigned char*)malloc(packed_bits_count);

    memset(packed_bits, 0x00, packed_bits_count);

    index = 0;
    for (i = 0; i < strlen(str); i++)
    {
        temp = str[i];
        for (j = 0, k = MAX_BIT_LENGTH - 1; j < MAX_BIT_LENGTH; j++, k--)
        {
            packed_bits[index] |= ((temp & (1 << k)) ? 1 : 0) << (MAX_BIT_LENGTH - j - 1);
        }
        index++;
    }

    for (i = 0; i < packed_bits_count; i++)
    {
        out[i] = ExtractBits(packed_bits[i], MAX_BIT_LENGTH);
    }

    free(packed_bits);

    out[i] = '\0';

    return packed_bits_count;
}

char *unpack(char *str, unsigned char packed_bits_count)
{
    unsigned char i, j, k, temp;

    unsigned char *packed_bits = (unsigned char*)malloc(packed_bits_count);

    for (i = 0; i < packed_bits_count; i++)
    {
        temp = (unsigned char)str[i];
        for (j = 0, k = MAX_BIT_LENGTH - 1; j < MAX_BIT_LENGTH; j++, k--)
        {
            packed_bits[i] |= ((temp & (1 << k)) ? 1 : 0) << (MAX_BIT_LENGTH - j - 1);
        }
    }

    char *out = (char*)malloc(packed_bits_count / MAX_BIT_LENGTH);

    memset(out, 0x00, packed_bits_count / MAX_BIT_LENGTH);

    for (i = 0, k = 0; i < packed_bits_count; i += MAX_BIT_LENGTH)
    {
        temp = 0x00;
        for (j = 0; j < MAX_BIT_LENGTH; j++)
        {
            temp |= packed_bits[i+j] << (MAX_BIT_LENGTH - j - 1);
        }
        out[k++] = temp;
    }

    out[k] = '\0';

    free(packed_bits);

    return out;
}

unsigned char ExtractBits(unsigned char pattern, unsigned char bit_count)
{
    return (pattern & (0xff << (MAX_BIT_LENGTH - bit_count))) >> (MAX_BIT_LENGTH - bit_count);
}

int main()
{
    char str[MAX_STRING_LENGTH] = "Hello world!";
    char packed_str[MAX_STRING_LENGTH];
    char *unpacked_str;
    unsigned char packed_bits_count;

    printf("Before packing: %s\n", str);

    packed_bits_count = pack(str, packed_str);

    printf("After packing: %s\n", packed_str);

    unpacked_str = unpack(packed_str, packed_bits_count);

    printf("After unpacking: %s\n", unpacked_str);

    free(unpacked_str);

    return 0;
}