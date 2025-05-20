//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "Whaaat? We're using RLE compression?"
#define RLE_COMPRESS

// "Holy moly, a custom compression algorithm!"
#define CUSTOM_COMPRESS

#ifdef RLE_COMPRESS
// RLE (Run-Length Encoding) Compression
unsigned char *rle_compress(const unsigned char *input, size_t input_len, size_t *output_len)
{
    unsigned char *output = malloc(input_len);
    if (!output) return NULL;

    *output_len = 0;
    int count = 1;

    for (size_t i = 1; i < input_len; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            output[(*output_len)++] = count;
            output[(*output_len)++] = input[i - 1];
            count = 1;
        }
    }

    output[(*output_len)++] = count;
    output[(*output_len)++] = input[input_len - 1];

    return output;
}
#endif

#ifdef CUSTOM_COMPRESS
// Our Own Custom Compression Algorithm: "Warp Speed Compression"
unsigned char *custom_compress(const unsigned char *input, size_t input_len, size_t *output_len)
{
    unsigned char *output = malloc(input_len);
    if (!output) return NULL;

    *output_len = 0;

    // Phase 1: Transform the input into a frequency histogram
    int histogram[256] = {0};
    for (size_t i = 0; i < input_len; i++) {
        histogram[input[i]]++;
    }

    // Phase 2: Build a Huffman tree from the histogram
    // ... (This part is a bit too advanced for this example)

    // Phase 3: Encode the input using the Huffman tree
    // ... (This part is also a bit too advanced for this example)

    return output;
}
#endif

int main()
{
    // "Whoa, look at all these compression options!"
    const char *input = "Abracadabra";
    size_t input_len = strlen(input);

    size_t output_len;

    // "RLE Compression: Boom!"
#ifdef RLE_COMPRESS
    unsigned char *rle_compressed = rle_compress((unsigned char *)input, input_len, &output_len);
    printf("RLE Compressed Data: ");
    for (int i = 0; i < output_len; i++) {
        printf("%u ", rle_compressed[i]);
    }
    printf("\n");
#endif

    // "Custom Compression: Prepare to be amazed!"
#ifdef CUSTOM_COMPRESS
    unsigned char *custom_compressed = custom_compress((unsigned char *)input, input_len, &output_len);
    printf("Custom Compressed Data: ");
    for (int i = 0; i < output_len; i++) {
        printf("%u ", custom_compressed[i]);
    }
    printf("\n");
#endif

    return 0;
}