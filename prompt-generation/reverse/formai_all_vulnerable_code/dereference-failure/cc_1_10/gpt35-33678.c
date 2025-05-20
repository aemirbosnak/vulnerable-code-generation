//FormAI DATASET v1.0 Category: Image Steganography ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define PIXEL_COLOR_DEPTH 256
#define BYTE_SIZE 8

char* get_message_from_image(char *image_file_name);

int main(int argc, char *argv[]) {

    char *image_file_name = "image.bmp";
    char *message = "hidden message";
    int i, j, k, l, pixel, bit_position, message_length;
    unsigned char byte, bit_mask;
    FILE *fp = fopen(image_file_name, "rb+");
    if (fp == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // read image header (we need only the first 54 bytes)
    int header_size = 54;
    unsigned char *image_header = (unsigned char*) malloc(sizeof(unsigned char) * header_size);
    fread(image_header, sizeof(unsigned char), header_size, fp);

    // read pixel data
    int image_data_size = file_size - header_size;
    unsigned char *image_data = (unsigned char*) malloc(sizeof(unsigned char) * image_data_size);
    fread(image_data, sizeof(unsigned char), image_data_size, fp);

    // get message length
    message_length = strlen(message);
    if (message_length * BYTE_SIZE > image_data_size) {
        printf("Error! Message cannot be hidden in the given image\n");
        exit(1);
    }

    // iterate over each pixel and hide the message
    k = 0; // message byte iterator
    byte = 0; // current byte being used to hide message bits
    bit_position = 0; // current bit position within a byte
    bit_mask = 1; // bit mask to be used for setting the bit

    for (i=0; i<image_data_size; i+=3) { // iterate over pixels
        pixel = 0;
        for (j=2; j>=0; j--) { // iterate over color channels for a pixel
            pixel <<= BYTE_SIZE;
            pixel += (unsigned int) *(image_data + i + j);
        }
        for (j=0; j<BYTE_SIZE; j++) { // iterate over bits in a byte
            if (bit_position == BYTE_SIZE) { // if the current byte is full
                *(image_data + i + (BYTE_SIZE/3 - 1)) = byte; // write to image data
                byte = 0; // reset byte
                bit_position = 0; // reset bit position
                k++; // increment message byte iterator
            }
            byte <<= 1; // left shift byte to make space for new bit to hide
            if (k < message_length) { // if message not yet fully hidden
                byte += ((message[k] >> (BYTE_SIZE - 1 - j)) & 1); // set the current bit
            }
            else { // message fully hidden
                byte += ((pixel >> (BYTE_SIZE - 1 - j)) & 1); // copy the pixel bit as it is
            }
            bit_position++; // increment bit position
        }
        for (j=0; j<3; j++) { // iterate over color channels for a pixel
            *(image_data + i + 2 - j) = (unsigned char) (pixel & (PIXEL_COLOR_DEPTH - 1)); // write back to pixel
            pixel >>= BYTE_SIZE;
        }
    }

    // write the last byte, if not already written
    if (bit_position != 0) {
        *(image_data + i + (BYTE_SIZE/3 - 1)) = byte;
    }

    // write the updated image data to file
    rewind(fp);
    fwrite(image_header, sizeof(unsigned char), header_size, fp);
    fwrite(image_data, sizeof(unsigned char), image_data_size, fp);
    fclose(fp);

    char *secret_message = get_message_from_image(image_file_name);
    printf("The hidden message is: %s\n", secret_message);

    return 0;
}

char* get_message_from_image(char *image_file_name) {

    int i, j, k, message_length = 0;
    unsigned char byte, bit_mask;
    char *message = (char*) calloc(1, sizeof(char));
    FILE *fp = fopen(image_file_name, "rb+");
    if (fp == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // read image header (we need only the first 54 bytes)
    int header_size = 54;
    unsigned char *image_header = (unsigned char*) malloc(sizeof(unsigned char) * header_size);
    fread(image_header, sizeof(unsigned char), header_size, fp);

    // read pixel data
    int image_data_size = file_size - header_size;
    unsigned char *image_data = (unsigned char*) malloc(sizeof(unsigned char) * image_data_size);
    fread(image_data, sizeof(unsigned char), image_data_size, fp);

    // iterate over each pixel and extract the message
    byte = 0; // currently extracted byte
    bit_mask = 1; // bit mask to be used for extracting the bit

    for (i=0; i<image_data_size; i+=3) { // iterate over pixels
        for (j=BYTE_SIZE/3-1; j>=0; j--) { // iterate over byte positions within a pixel
            for (k=0; k<BYTE_SIZE; k++) { // iterate over bits in a byte
                byte <<= 1; // left shift to make space for the new bit
                byte += (*(image_data + i + j) & bit_mask); // extract the bit
                if (++message_length % BYTE_SIZE == 0) { // if a full byte is extracted
                    message = (char*) realloc(message, message_length/BYTE_SIZE + 1);
                    *(message + (message_length/BYTE_SIZE - 1)) = byte; // add the byte to the message
                    byte = 0; // reset byte
                }
            }
        }
        if (byte == 0) { // if a full byte was extracted in the previous pixel
            break; // stop the extraction process
        }
    }
    *(message + message_length/BYTE_SIZE) = '\0'; // terminate the message string

    fclose(fp);
    free(image_header);
    free(image_data);

    return message;
}