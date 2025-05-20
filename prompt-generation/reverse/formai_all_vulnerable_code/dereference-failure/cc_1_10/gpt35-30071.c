//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The program reads a BMP image input file and a user message from the command line arguments. 
It hides the message in the least significant bits of the blue color channel of the output BMP image file. 
The program also provides the functionality to extract the original message from the stego-image. */

// Function to read BMP-image from file
unsigned char* read_bmp(char* filename, int* width, int* height) {
    FILE *file;
    unsigned char *image;
    unsigned long size;
    unsigned char t;
    int i;

    file = fopen(filename, "rb");
    fseek(file, 18, SEEK_SET);
    fread(width, 4, 1, file);
    fread(height, 4, 1, file);
    size = (*width)*(*height)*3;

    fseek(file, 54, SEEK_SET);
    image = (unsigned char *) malloc(size);

    fread(image, size, 1, file);
    for(i=0; i<size; i+=3) {
        t = image[i];
        image[i] = image[i+2];
        image[i+2] = t;
    }

    fclose(file);

    return image;
}

// Function to write BMP-image to file
void write_bmp(unsigned char* image, char* filename, int width, int height) {
    FILE *file;
    unsigned char t;
    int i;

    file = fopen(filename, "wb");

    fwrite("BM", 2, 1, file);   /* Magic number */
    fwrite(&width, 4, 1, file); /* Width */
    fwrite(&height, 4, 1, file); /* Height */
    fwrite("\0\0\0\0", 4, 1, file);
    fwrite("\x3E\0\0\0", 4, 1, file); /* Offset of data */
    fwrite("\x28\0\0\0", 4, 1, file); /* Number of bytes in header */
    fwrite(&width, 4, 1, file);
    fwrite(&height, 4, 1, file);
    fwrite("\x01\0", 2, 1, file);
    fwrite("\x18\0", 2, 1, file);
    fwrite("\0\0\0\0", 4, 1, file);
    fwrite("\x3E\0\0\0", 4, 1, file); /* Number of bytes of image data */
    fwrite("\xC4\x0E\0\0\xC4\x0E\0\0", 8, 1, file);
    fwrite("\0\0\0\0\0\0\0\0", 8, 1, file);
    fwrite(image, width*height*3, 1, file);

    for(i=0; i<width*height*3; i+=3) {
        t = image[i];
        image[i] = image[i+2];
        image[i+2] = t;
    }

    fclose(file);
}

// Function to hide message in image
void hide_message(unsigned char* image, char* message) {
    int i, j, len;
    char* binary_message;

    len = strlen(message);
    binary_message = (char*) malloc(len*8);

    // Convert message to binary
    for(i=0; i<len; i++) {
        for(j=0; j<8; j++) {
            binary_message[8*i+j] = ((message[i] & (1 << (7-j))) >> (7-j));
        }
    }

    // Hide message in image
    for(i=0; i<len*8; i++) {
        if(binary_message[i] == 0) {
            if(image[3*i+2] % 2 == 1) {
                image[3*i+2] -= 1;
            }
        }
        else {
            if(image[3*i+2] % 2 == 0) {
                image[3*i+2] += 1;
            }
        }
    }
}

// Function to extract message from image
char* extract_message(unsigned char* image) {
    int i, j, len;
    char* binary_message;

    len = strlen("Hello, world!");
    binary_message = (char*) malloc(len*8+1);

    // Extract message from image
    for(i=0; i<len*8; i++) {
        if(image[3*i+2] % 2 == 0) {
            binary_message[i] = 0;
        }
        else {
            binary_message[i] = 1;
        }
    }

    // Convert message from binary
    char* message = (char*) malloc(len+1);
    for(i=0; i<len; i++) {
        message[i] = 0;
        for(j=0; j<8; j++) {
            message[i] = (message[i] << 1) | binary_message[8*i+j];
        }
    }

    message[len] = '\0';

    return message;
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: image_steganography <input-bmp-file> <output-bmp-file> <message>\n");
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* message = argv[3];

    int width, height;
    unsigned char* image;

    image = read_bmp(input_file, &width, &height);

    hide_message(image, message);

    write_bmp(image, output_file, width, height);

    printf("Message hidden in image successfully.\n");

    char* extracted_message = extract_message(image);

    printf("Extracted message: %s\n", extracted_message);

    return 0;
}