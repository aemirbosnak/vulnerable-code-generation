//FormAI DATASET v1.0 Category: Image Steganography ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *original, char *secret, char *output) {
    FILE *f_original = fopen(original, "rb");
    FILE *f_secret = fopen(secret, "r");
    FILE *f_output = fopen(output, "wb");

    if (f_original == NULL || f_secret == NULL || f_output == NULL) {
        printf("Error: unable to open files...\n");
        exit(EXIT_FAILURE);
    }

    // read the image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, f_original);

    // write the header to output file
    fwrite(header, sizeof(unsigned char), 54, f_output);

    // get the size of the secret file
    fseek(f_secret, 0, SEEK_END);
    int secret_size = ftell(f_secret);
    fseek(f_secret, 0, SEEK_SET);

    // hide the secret file's bytes in the least significant bits of the image pixels
    unsigned char buffer[secret_size];
    fread(buffer, sizeof(unsigned char), secret_size, f_secret);

    int i, j;
    int k = 0;
    unsigned char byte, bit_one, bit_two, bit_three, bit_four;

    for (i = 0; i < header[18]; i++) {
        for (j = 0; j < header[22] * 3; j += 3) {
            if (k < secret_size) {
                byte = buffer[k++];
                bit_one = (byte & 0x80) >> 7;
                bit_two = (byte & 0x40) >> 6;
                bit_three = (byte & 0x20) >> 5;
                bit_four = (byte & 0x10) >> 4;

                header[54 + i * header[22] * 3 + j] &= 0xFE;
                header[54 + i * header[22] * 3 + j + 1] &= 0xFE;
                header[54 + i * header[22] * 3 + j + 2] &= 0xFE;

                header[54 + i * header[22] * 3 + j] |= bit_one;
                header[54 + i * header[22] * 3 + j + 1] |= bit_two;
                header[54 + i * header[22] * 3 + j + 2] |= bit_three;
            }
        }
    }

    fwrite(header, sizeof(unsigned char), 54 + header[18] * header[22] * 3, f_output);

    fclose(f_original);
    fclose(f_secret);
    fclose(f_output);

    printf("File encoded successfully.\n");
}

void decode(char *encoded, char *output) {
    FILE *f_encoded = fopen(encoded, "rb");
    FILE *f_output = fopen(output, "wb");

    if (f_encoded == NULL || f_output == NULL) {
        printf("Error: unable to open files...\n");
        exit(EXIT_FAILURE);
    }

    // read the image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, f_encoded);

    // extract the secret file's bytes from the least significant bits of the image pixels
    unsigned char buffer[header[18] * header[22] * 3];
    int i, j;
    int k = 0;
    unsigned char byte;

    for (i = 0; i < header[18]; i++) {
        for (j = 0; j < header[22] * 3; j += 3) {
            byte = (header[54 + i * header[22] * 3 + j] & 0x01) << 7;
            byte |= (header[54 + i * header[22] * 3 + j + 1] & 0x01) << 6;
            byte |= (header[54 + i * header[22] * 3 + j + 2] & 0x01) << 5;
            buffer[k++] = byte;
        }
    }

    fwrite(buffer, sizeof(unsigned char), k, f_output);

    fclose(f_encoded);
    fclose(f_output);

    printf("File decoded successfully.\n");
}

int main() {
    char *original = "image.bmp";
    char *secret = "secret.txt";
    char *encoded = "encoded.bmp";
    char *decoded = "decoded.txt";

    encode(original, secret, encoded);
    decode(encoded, decoded);

    return 0;
}