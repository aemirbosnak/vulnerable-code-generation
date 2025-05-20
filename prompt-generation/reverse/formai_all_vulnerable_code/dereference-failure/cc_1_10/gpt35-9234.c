//FormAI DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Run-Length Encoding */
/* This algorithm works by substituting sequences of repeated bytes with a two-byte code consisting of a count and a byte.*/
void RLE_Compress(unsigned char* input, int inLen, unsigned char* output, int* outLen)
{
    int i, j, count;
    unsigned char prev, curr;

    i = 0;
    j = 0;
    count = 1;
    prev = input[0];

    for(i = 1; i < inLen; ++i)
    {
        curr = input[i];
        if(curr == prev)
        {
            ++count;
        }
        else
        {
            output[j++] = count;
            output[j++] = prev;
            count = 1;
            prev = curr;
        }
    }
    output[j++] = count;
    output[j++] = prev;

    *outLen = j;
}

void RLE_Decompress(unsigned char* input, int inLen, unsigned char* output, int* outLen)
{
    int i, j, count;
    unsigned char curr;

    i = 0;
    j = 0;

    while(i < inLen)
    {
        count = input[i++];
        curr = input[i++];

        for(int k = 0; k < count; ++k)
        {
            output[j++] = curr;
        }
    }

    *outLen = j;
}

int main()
{
    unsigned char input[] = {0x41, 0x41, 0x41, 0x42, 0x42, 0x41, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43};
    int inLen = sizeof(input);
    int outLen = 0;
    unsigned char* output = (unsigned char*) malloc(sizeof(unsigned char) * inLen * 2);

    printf("Original input:\n");
    for(int i = 0; i < inLen; ++i)
    {
        printf("%c", input[i]);
    }

    RLE_Compress(input, inLen, output, &outLen);
    printf("\n\nCompressed output:\n");
    for(int i = 0; i < outLen; ++i)
    {
        printf("%c", output[i]);
    }

    unsigned char* decompressed = (unsigned char*) malloc(sizeof(unsigned char) * inLen);
    int decompLen = 0;

    RLE_Decompress(output, outLen, decompressed, &decompLen);
    printf("\n\nDecompressed output:\n");
    for(int i = 0; i < decompLen; ++i)
    {
        printf("%c", decompressed[i]);
    }

    free(output);
    free(decompressed);

    return 0;
}