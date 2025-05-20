//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Constants for data embedding and extraction */
#define BITS_PER_BYTE 8
#define BITS_PER_PIXEL 3
#define MAX_SECRET_MSG_LEN 100

/* Function prototypes */
void embed_secret_message(char *src_image_file, char *secret_message, char *out_image_file);
void extract_secret_message(char *src_image_file, char *out_file);

/* Helper function to check if a file exists */
int file_exists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}

/* Main function */
int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <src_image_file> <out_image_file/extracted_msg_file> [secret_message]\n", argv[0]);
        return 1;
    }

    char *cmd = argv[1];
    char *src_image_file = argv[2];
    char *out_file = argv[3];

    if (strcmp(cmd, "embed") == 0) {
        if (argc < 5) {
            printf("Error: missing secret message.\n");
            return 1;
        }
        char *secret_message = argv[4];
        embed_secret_message(src_image_file, secret_message, out_file);
    } else if (strcmp(cmd, "extract") == 0) {
        extract_secret_message(src_image_file, out_file);
    } else {
        printf("Error: unrecognized command '%s'\n", cmd);
        return 1;
    }

    return 0;
}

/*
 * Embeds the provided secret message into the given source image file, and write the output to the given out image file.
 * Uses LSB (Least Significant Bit) method for data embedding.
 */
void embed_secret_message(char *src_image_file, char *secret_message, char *out_image_file) {
    FILE *src_fp = fopen(src_image_file, "rb");
    if (!src_fp) {
        printf("Error opening source image file '%s': %s\n", src_image_file, strerror(errno));
        exit(1);
    }
    FILE *out_fp = fopen(out_image_file, "wb");
    if (!out_fp) {
        printf("Error creating output image file '%s': %s\n", out_image_file, strerror(errno));
        exit(1);
    }

    char secret_msg_len = strlen(secret_message);
    if (secret_msg_len > MAX_SECRET_MSG_LEN) {
        printf("Error: secret message length exceeds maximum allowed length of %d.\n", MAX_SECRET_MSG_LEN);
        exit(1);
    }

    // Embed secret message length in the first byte of output file
    fputc(secret_msg_len, out_fp);

    // Read pixels from source image file and embed secret message bits in them
    unsigned char pixel[BITS_PER_PIXEL];
    int bitindex = 0; // bit index within secret message
    for (;;) {
        int n = fread(pixel, 1, BITS_PER_PIXEL, src_fp);
        if (n != BITS_PER_PIXEL) break;

        // Embed the next secret message bit in the least significant bit of each pixel byte
        for (int i = 0; i < BITS_PER_PIXEL; i++) {
            if (bitindex < secret_msg_len * BITS_PER_BYTE) {
                int msg_bit = (secret_message[bitindex / BITS_PER_BYTE] >> (bitindex % BITS_PER_BYTE)) & 1;
                pixel[i] = (pixel[i] & 0xFE) | msg_bit;
            }
            bitindex++;
        }

        fwrite(pixel, 1, BITS_PER_PIXEL, out_fp);
    }

    fclose(src_fp);
    fclose(out_fp);
    printf("Secret message embedded in image file '%s'.\n", out_image_file);
}

/*
 * Extracts the secret message from the given source image file, and writes it to the given output file.
 * Uses LSB (Least Significant Bit) method for data extraction.
 */
void extract_secret_message(char *src_image_file, char *out_file) {
    FILE *src_fp = fopen(src_image_file, "rb");
    if (!src_fp) {
        printf("Error opening source image file '%s': %s\n", src_image_file, strerror(errno));
        exit(1);
    }
    FILE *out_fp = fopen(out_file, "wb");
    if (!out_fp) {
        printf("Error creating output file '%s': %s\n", out_file, strerror(errno));
        exit(1);
    }

    // Read secret message length from first byte of source image file
    char secret_msg_len = fgetc(src_fp);

    char secret_message[MAX_SECRET_MSG_LEN + 1];
    int byteindex = 0; // byte index within secret message
    unsigned char pixel[BITS_PER_PIXEL];
    int bitindex = 0; // bit index within secret message
    for (;;) {
        int n = fread(pixel, 1, BITS_PER_PIXEL, src_fp);
        if (n != BITS_PER_PIXEL) break;

        // Extract the next secret message bit from the least significant bit of each pixel byte
        for (int i = 0; i < BITS_PER_PIXEL; i++) {
            if (bitindex < secret_msg_len * BITS_PER_BYTE) {
                int msg_bit = pixel[i] & 1;
                secret_message[byteindex] |= msg_bit << (bitindex % BITS_PER_BYTE);
            }
            bitindex++;
            if (bitindex % BITS_PER_BYTE == 0) byteindex++;
        }
    }

    fclose(src_fp);
    fclose(out_fp);

    // Add null terminator to the secret message string
    secret_message[byteindex] = '\0';

    out_fp = fopen(out_file, "w");
    if (!out_fp) {
        printf("Error creating output file '%s': %s\n", out_file, strerror(errno));
        exit(1);
    }

    fprintf(out_fp, "%s", secret_message);
    fclose(out_fp);

    printf("Secret message extracted from image file '%s' and written to file '%s'.\n", src_image_file, out_file);
}