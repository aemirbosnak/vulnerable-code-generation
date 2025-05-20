//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 64 

uint8_t *message_padding(const uint8_t *input, uint64_t input_length, uint64_t *output_length);
uint32_t left_rotate(uint32_t value, uint32_t count);
void process_message_blocks(const uint8_t *blocks, uint64_t number_of_blocks, uint32_t *hash);
void md5_hash(const uint8_t *input, uint64_t input_length, uint8_t *output);

int main()
{
    uint8_t *input = "This is a test message for MD5 Hash Function.";
    uint8_t output[16];

    md5_hash(input, strlen(input), output);

    printf("MD5 Hash of \"%s\" is : ", input);
    for (int i = 0; i < 16; ++i)
    {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}

uint8_t *message_padding(const uint8_t *input, uint64_t input_length, uint64_t *output_length)
{
    uint64_t new_length = input_length * 8 + 1;
    while (new_length % 512 != 448)
    {
        new_length++;
    }
    new_length /= 8;

    uint8_t *output = calloc(new_length + 8, sizeof(uint8_t));
    memcpy(output, input, input_length);
    output[input_length] = 0x80;

    uint64_t bit_length = input_length * 8;
    memcpy(output + new_length, &bit_length, sizeof(uint64_t));

    *output_length = new_length + 8;

    return output;
}

uint32_t left_rotate(uint32_t value, uint32_t count)
{
    return (value << count) | (value >> (32 - count));
}

void process_message_blocks(const uint8_t *blocks, uint64_t number_of_blocks, uint32_t *hash)
{
    uint32_t a = hash[0];
    uint32_t b = hash[1];
    uint32_t c = hash[2];
    uint32_t d = hash[3];

    for (size_t i = 0; i < number_of_blocks; ++i)
    {
        uint32_t *message_schedule = (uint32_t *)(blocks + i * BLOCK_SIZE);

        uint32_t aa = a;
        uint32_t bb = b;
        uint32_t cc = c;
        uint32_t dd = d;

        for (uint8_t j = 0; j < 64; ++j)
        {
            uint32_t f, g;

            if (j < 16)
            {
                f = (b & c) | (~b & d);
                g = j;
            }
            else if (j < 32)
            {
                f = (d & b) | (~d & c);
                g = (5 * j + 1) % 16;
            }
            else if (j < 48)
            {
                f = b ^ c ^ d;
                g = (3 * j + 5) % 16;
            }
            else
            {
                f = c ^ (b | ~d);
                g = (7 * j) % 16;
            }

            uint32_t temp = d;
            d = c;
            c = b;
            b += left_rotate((a + f + message_schedule[g] + 0x5A827999), 5);
            a = temp;
        }

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
    }
}

void md5_hash(const uint8_t *input, uint64_t input_length, uint8_t *output)
{
    uint64_t padded_length;
    uint8_t *padded_message = message_padding(input, input_length, &padded_length);

    uint32_t hash[] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476};
    process_message_blocks(padded_message, padded_length / BLOCK_SIZE, hash);

    for (uint8_t i = 0; i < 4; ++i)
    {
        output[i * 4] = (hash[i] & 0xff);
        output[i * 4 + 1] = (hash[i] >> 8) & 0xff;
        output[i * 4 + 2] = (hash[i] >> 16) & 0xff;
        output[i * 4 + 3] = (hash[i] >> 24) & 0xff;
    }
    free(padded_message);
}