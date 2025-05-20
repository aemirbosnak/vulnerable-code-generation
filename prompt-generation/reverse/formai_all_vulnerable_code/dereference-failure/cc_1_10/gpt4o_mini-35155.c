//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

#define MAX_MESSAGE_LENGTH 1024

// Function declarations
void encode_lsb(const char *input_image_path, const char *output_image_path, const char *secret_message);
char* decode_lsb(const char *input_image_path);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_image = argv[1];
    const char *output_image = argv[2];
    const char *secret_message = argv[3];

    if (strlen(secret_message) > MAX_MESSAGE_LENGTH) {
        printf("Error: Message length exceeds the maximum limit of %d characters.\n", MAX_MESSAGE_LENGTH);
        return EXIT_FAILURE;
    }

    // Encoding the secret message into the input image
    encode_lsb(input_image, output_image, secret_message);

    // Decoding the secret message from the output image
    char *decoded_message = decode_lsb(output_image);
    if (decoded_message) {
        printf("Decoded message: %s\n", decoded_message);
        free(decoded_message);
    } else {
        printf("No message decoded.\n");
    }

    return EXIT_SUCCESS;
}

void encode_lsb(const char *input_image_path, const char *output_image_path, const char *secret_message) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_compress_struct ccompress;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(input_image_path, "rb");
    FILE *outfile = fopen(output_image_path, "wb");
    
    if (!infile || !outfile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    ccompress.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&ccompress);
    jpeg_stdio_dest(&ccompress, outfile);
    ccompress.image_width = cinfo.image_width;
    ccompress.image_height = cinfo.image_height;
    ccompress.input_components = cinfo.num_components;
    ccompress.in_color_space = cinfo.jpeg_color_space;
    jpeg_set_defaults(&ccompress);
    jpeg_start_compress(&ccompress, TRUE);

    unsigned char *buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.num_components);
    int message_length = strlen(secret_message);
    
    for (int i = 0; i < cinfo.output_height; i++) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int j = 0; j < cinfo.output_width && j < message_length + 1; j++) {
            buffer[j * cinfo.num_components] = (buffer[j * cinfo.num_components] & 0xFE) | ((secret_message[j] >> (i % 8)) & 0x01);
            // For additional bits, shift right to access subsequent bits of the character
        }
        
        jpeg_write_scanlines(&ccompress, &buffer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_finish_compress(&ccompress);
    fclose(infile);
    fclose(outfile);
    free(buffer);
}

char* decode_lsb(const char *input_image_path) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(input_image_path, "rb");
    if (!infile) {
        perror("Error opening file");
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    unsigned char *buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.num_components);
    char *decoded_message = (char *)malloc(MAX_MESSAGE_LENGTH);
    int message_index = 0;

    while (cinfo.output_height--) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        if (message_index >= MAX_MESSAGE_LENGTH - 1) break; // Prevent buffer overflow

        for (int j = 0; j < cinfo.output_width; j++) {
            if (j % cinfo.num_components == 0) { // Only check the first component for LSB
                decoded_message[message_index] = (decoded_message[message_index] << 1) | (buffer[j * cinfo.num_components] & 0x01);
                if (message_index < MAX_MESSAGE_LENGTH - 1) {
                    if (decoded_message[message_index] == '\0') {
                        break; // End of message found
                    }
                }
            }
            if (decoded_message[message_index] == '\0') {
                break; // End of message found
            }
        }
        message_index++;
    }

    decoded_message[message_index] = '\0'; // Null terminate the string
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    free(buffer);
    return decoded_message;
}