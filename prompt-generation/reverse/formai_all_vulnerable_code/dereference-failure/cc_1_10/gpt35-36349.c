//FormAI DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 33554432  // maximum size for file (32mb)

int encode(char *message_file, char *image_file, char *output_file) {
    FILE *mfile = fopen(message_file, "r");
    FILE *ifile = fopen(image_file, "rb");
    FILE *ofile = fopen(output_file, "wb");

    if (mfile == NULL) {
        printf("Error: Unable to open message file\n");
        return -1;
    }

    if (ifile == NULL) {
        printf("Error: Unable to open image file\n");
        return -1;
    }

    if (ofile == NULL) {
        printf("Error: Unable to create output file\n");
        return -1;
    }

    // copy image header to output file
    unsigned char header[54];
    fread(&header, sizeof(unsigned char), 54, ifile);
    fwrite(&header, sizeof(unsigned char), 54, ofile);

    // get message file size
    fseek(mfile, 0L, SEEK_END);
    int size = ftell(mfile);
    rewind(mfile);

    // check if message size is too big for image
    long img_size;
    fseek(ifile, 0L, SEEK_END);
    img_size = ftell(ifile) - 54;
    rewind(ifile);
    if (size > img_size) {
        printf("Error: Image file not large enough to encode message\n");
        return -1;
    }

    unsigned char pixel[3];
    int i = 0, j = 0, k = 0;
    while (j < size) {
        // get pixel value from image file
        fread(&pixel, sizeof(unsigned char), 3, ifile);
        // encode message bits into pixel values
        pixel[k] &= 0xFC;  // clear 2 least significant bits
        pixel[k] |= ((fgetc(mfile) & 0xC0) >> 6);
        pixel[k+1] &= 0xFC;
        pixel[k+1] |= ((fgetc(mfile) & 0xC0) >> 4);
        pixel[k+2] &= 0xFC;
        pixel[k+2] |= ((fgetc(mfile) & 0xC0) >> 2);
        // write pixel to output file
        fwrite(&pixel, sizeof(unsigned char), 3, ofile);
        j += 3;
        if (k == 0) k++;
        else if (k == 1) k++;
        else k = 0;
    }

    // copy remaining pixels from image file to output file
    while (i < (img_size - j)) {
        fread(&pixel, sizeof(unsigned char), 3, ifile);
        fwrite(&pixel, sizeof(unsigned char), 3, ofile);
        i += 3;
    }

    fclose(mfile);
    fclose(ifile);
    fclose(ofile);

    printf("Message successfully encoded into image!\n");

    return 0;
}

int decode(char *image_file, char *output_file) {
    FILE *ifile = fopen(image_file, "rb");
    FILE *ofile = fopen(output_file, "w");

    if (ifile == NULL) {
        printf("Error: Unable to open image file\n");
        return -1;
    }

    if (ofile == NULL) {
        printf("Error: Unable to create output file\n");
        return -1;
    }

    // skip image header
    fseek(ifile, 54L, SEEK_SET);

    unsigned char pixel[3];
    int i = 0, j = 0, end = 0;
    char c = 0;
    while (!end) {
        // get pixel value from image file
        fread(&pixel, sizeof(unsigned char), 3, ifile);
        // decode message bits from pixel values
        c |= ((pixel[j] & 0x3) << 6);
        c |= ((pixel[j+1] & 0x3) << 4);
        c |= ((pixel[j+2] & 0x3) << 2);
        // write character to output file
        fwrite(&c, sizeof(char), 1, ofile);
        c = 0;
        j += 3;
        if (j == 9) {
            j = 0;
            i += 3;
            if (i >= MAX_FILE_SIZE) {
                printf("Error: Maximum file size exceeded\n");
                return -1;
            }
            if (feof(ifile)) end = 1;
        }
    }

    fclose(ifile);
    fclose(ofile);

    printf("Message successfully decoded from image!\n");

    return 0;
}

int main() {
    char message_file[] = "message.txt";
    char image_file[] = "image.bmp";
    char output_file[] = "output.bmp";

    int result = encode(message_file, image_file, output_file);
    if (result == -1) return -1;

    result = decode(output_file, "output.txt");
    if (result == -1) return -1;

    return 0;
}