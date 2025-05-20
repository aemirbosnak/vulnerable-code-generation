//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000
#define BITS_PER_BYTE 8

/* Function to perform StegoLSB Watermarking */
void stego_lsb(char *file_name, char *message) {
    FILE *input_file, *output_file;
    char buff[MAX_FILE_SIZE];
    char *watermark;
    int i, j, k, len_file, len_watermark, num_bits, bit_pos;

    /* Open file */
    input_file = fopen(file_name, "rb");
    if(!input_file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    /* Get file size */
    fseek(input_file, 0, SEEK_END);
    len_file = ftell(input_file);
    rewind(input_file);

    /* Read file into buffer */
    fread(buff, 1, len_file, input_file);
    fclose(input_file);

    /* Calculate maximum length of watermark */
    len_watermark = len_file / 8;

    /* Allocate memory for watermark */
    watermark = (char *) malloc(len_watermark * sizeof(char));
    strncpy(watermark, message, len_watermark);

    /* Open output file */
    output_file = fopen("output.bmp", "wb");
    if(!output_file) {
        printf("Error: Unable to create output file.\n");
        return;
    }

    /* Write file header */
    fwrite(buff, 1, 54, output_file);

    /* Embed watermark in least significant bits of file data */
    num_bits = 0;
    for(i = 54; i < len_file; i++) {
        bit_pos = num_bits % BITS_PER_BYTE;

        if (num_bits >= len_watermark * BITS_PER_BYTE) {
            /* All bits embedded, just copy the remaining file data */
            fwrite(&buff[i], 1, 1, output_file);
        } else {
            /* Embed watermark bit */
            watermark[num_bits / BITS_PER_BYTE] &= ~(1 << bit_pos);
            watermark[num_bits / BITS_PER_BYTE] |= ((buff[i] & 1) << bit_pos);

            /* Write modified byte to output */
            fwrite(&watermark[num_bits / BITS_PER_BYTE], 1, 1, output_file);
        }
        num_bits++;
    }

    fclose(output_file);
    free(watermark);

    printf("Watermarking successful! Output file saved as 'output.bmp'.\n");
}

/* Test function */
int main(void) {
    char message[] = "Hello, I am a Digital Watermark!";
    stego_lsb("input.bmp", message);
    return 0;
}