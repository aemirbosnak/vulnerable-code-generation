//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

/*
    This is a paranoid digital watermarking program that uses a combination of steganography, cryptography, and randomization to embed a hidden message in a BMP image file. The program takes in two command line arguments:
    1. Path to the input BMP file
    2. Path to the output BMP file that contains the hidden message
*/

#define MSG_SIZE 256                // Maximum size of hidden message
#define RANDOM_CNT 256              // Number of random bytes for key creation
#define BMP_OFFSET 54               // BMP header size
#define BMP_PADDING 4              // BMP row padding size

/*
    Calculates the checksum of a given message using a simple algorithm
*/
uint8_t checksum(char *msg, size_t msg_len)
{
    uint8_t chksum = 0;
    for (size_t i = 0; i < msg_len; i++) {
        chksum += msg[i];
    }
    return chksum;
}

/*
    Encrypts a given message using a simple XOR encryption algorithm
*/
void encrypt(char *msg, uint8_t *key, size_t key_len)
{
    for (size_t i = 0; i < strlen(msg); i++) {
        msg[i] ^= key[i % key_len];
    }
}

/*
    Generates a pseudo-random byte array of given length
*/
void generate_random(uint8_t *rand_bytes, size_t cnt)
{
    FILE *rng = fopen("/dev/urandom", "r");
    fread(rand_bytes, sizeof(*rand_bytes), cnt, rng);
    fclose(rng);
}

/*
    Main program that embeds the hidden message inside a BMP image
*/
int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: ./watermark <input file> <output file>\n");
        return 1;
    }

    char *in_file = argv[1];
    char *out_file = argv[2];

    // Load input BMP file
    FILE *in_fp = fopen(in_file, "rb");
    if (!in_fp) {
        printf("Could not open input file!\n");
        return 1;
    }

    // Get input BMP file size
    fseek(in_fp, 0, SEEK_END);
    size_t in_size = ftell(in_fp);
    rewind(in_fp);

    // Allocate buffer for input BMP file data
    uint8_t *in_buf = (uint8_t*) malloc(sizeof(uint8_t) * in_size);
    fread(in_buf, 1, in_size, in_fp);
    fclose(in_fp);

    // Check if BMP header indicates 24 bit color depth
    uint16_t *bpp = (uint16_t*) (in_buf + 28);
    if (*bpp != 24) {
        printf("Input file must be 24 bit BMP file!\n");
        free(in_buf);
        return 1;
    }

    // Get input BMP file dimensions
    uint32_t *width = (uint32_t*) (in_buf + 18);
    uint32_t *height = (uint32_t*) (in_buf + 22);

    // Calculate input BMP file row size (including padding)
    size_t row_size = (*width * 3) + (*width % BMP_PADDING ? BMP_PADDING - (*width % BMP_PADDING) : 0);

    // Load hidden message from user input
    char msg[MSG_SIZE] = { 0 };
    printf("Enter message to be hidden (max %d characters): ", MSG_SIZE);
    fgets(msg, MSG_SIZE, stdin);
    msg[strcspn(msg, "\n")] = '\0';

    // Check if message is too long to be hidden inside BMP file
    size_t max_len = (*height * row_size) / 8;
    if (strlen(msg) > max_len) {
        printf("Message is too long to be hidden inside BMP file!\n");
        free(in_buf);
        return 1;
    }

    // Calculate the hidden message size (including checksum)
    size_t msg_len = strlen(msg) + 1;
    uint8_t chksum = checksum(msg, strlen(msg));    // Calculate checksum of message
    msg[msg_len - 1] = chksum;                      // Append checksum to message

    // Generate a random byte array for encryption key
    uint8_t key[RANDOM_CNT] = { 0 };
    generate_random(key, RANDOM_CNT);

    // Encrypt the message using the random key
    encrypt(msg, key, RANDOM_CNT);

    // Allocate buffer for output BMP file data
    size_t out_size = in_size + msg_len;
    uint8_t *out_buf = (uint8_t*) malloc(sizeof(uint8_t) * out_size);
    memcpy(out_buf, in_buf, BMP_OFFSET);                // Copy BMP header into output buffer
    memcpy(out_buf + BMP_OFFSET, msg, msg_len);          // Copy encrypted message into output buffer

    // Generate a pseudo-random bit mask to obscure payload
    uint8_t mask[BMP_PADDING] = { 0 };
    generate_random(mask, BMP_PADDING);

    // Embed the hidden message inside the output BMP file
    size_t msg_idx = 0;
    size_t out_idx = BMP_OFFSET + msg_idx / 8;
    size_t bit_idx = msg_idx % 8;
    uint8_t *out_ptr = out_buf + out_idx;
    uint8_t bit_mask[] = {   0x01,  0x02, 0x04,  0x08,  0x10,  0x20,    0x40,    0x80 };
    uint8_t neg_mask[] = {   0xff,  0xfe, 0xfc,  0xf8,  0xf0,  0xe0,    0xc0,    0x80 };
    uint8_t pos_mask[] = {   0x00,  0x01, 0x03,  0x07,  0x0f,  0x1f,    0x3f,    0x7f };

    for (size_t i = BMP_OFFSET; i < out_size; i++) {
        uint8_t cur_byte = out_buf[i];
        uint8_t cur_msg_bit = (msg[msg_idx / 8] & bit_mask[bit_idx]) >> bit_idx;
        uint8_t new_byte = cur_byte;

        // Use random mask to obscure payload
        new_byte &= neg_mask[(bit_idx / 8)];
        new_byte |= (cur_msg_bit ? pos_mask[(bit_idx / 8)] : 0) & mask[(bit_idx / 8)];

        out_ptr[0] = new_byte;

        // Move to next message bit
        msg_idx += 1;
        bit_idx = msg_idx % 8;
        out_idx = BMP_OFFSET + msg_idx / 8;
        out_ptr = out_buf + out_idx;
    }

    // Write output BMP file with hidden message
    FILE *out_fp = fopen(out_file, "wb");
    fwrite(out_buf, 1, out_size, out_fp);
    fclose(out_fp);

    printf("Hidden message successfully embedded inside BMP file!\n");

    free(in_buf);
    free(out_buf);

    return 0;
}