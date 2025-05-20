//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_WIDTH 64
#define IMG_HEIGHT 64

void encode(char *msg, char *imgname, char *stegname) {
    char img[IMG_WIDTH][IMG_HEIGHT];
    FILE *imgfile, *stegfile;

    // Read image into array
    imgfile = fopen(imgname, "rb");
    fread(img, sizeof(img), 1, imgfile);
    fclose(imgfile);

    // Embed message into image by setting least significant bit of each pixel
    int msglen = strlen(msg);
    int msgidx = 0;
    for (int i = 0; i < IMG_WIDTH; i++) {
        for (int j = 0; j < IMG_HEIGHT; j++) {
            char pixel = img[i][j];
            if (msgidx < msglen) {
                char bit = msg[msgidx] - '0';
                pixel = (pixel & 0xFE) | bit; // set LSB to message bit
                msgidx++;
            }
            img[i][j] = pixel;
        }
    }

    // Write stego image to file
    stegfile = fopen(stegname, "wb");
    fwrite(img, sizeof(img), 1, stegfile);
    fclose(stegfile);
}

void decode(char *stegname) {
    char img[IMG_WIDTH][IMG_HEIGHT];
    FILE *stegfile;

    // Read stego image into array
    stegfile = fopen(stegname, "rb");
    fread(img, sizeof(img), 1, stegfile);
    fclose(stegfile);

    // Extract message from LSB of each pixel
    char msg[IMG_WIDTH * IMG_HEIGHT];
    int msgidx = 0;
    for (int i = 0; i < IMG_WIDTH; i++) {
        for (int j = 0; j < IMG_HEIGHT; j++) {
            char pixel = img[i][j];
            char bit = pixel & 0x01;
            msg[msgidx] = bit + '0'; // convert bit to character
            msgidx++;
        }
    }

    // Print decoded message
    printf("Decoded message: %s\n", msg);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s [encode|decode] <input image> <output image/message>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *infilename = argv[2];
    char *outfilename = argv[3];

    if (strcmp(command, "encode") == 0) {
        printf("Enter message to embed: ");
        char msg[IMG_WIDTH * IMG_HEIGHT];
        fgets(msg, sizeof(msg), stdin);
        encode(msg, infilename, outfilename);
        printf("Message encoded in %s as %s\n", infilename, outfilename);
    } else if (strcmp(command, "decode") == 0) {
        decode(outfilename);
    } else {
        printf("Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}