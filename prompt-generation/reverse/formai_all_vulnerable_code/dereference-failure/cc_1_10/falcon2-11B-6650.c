//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide message within an image
void hideMessage(unsigned char *image, int width, int height, int depth, char *message, int key) {
    // The secret key is used to determine the offset within the image
    int offset = key % width * height * depth;

    // Iterate through each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char *pixel = &image[(y * width + x) * depth];

            // Find the secret key within the message
            int index = 0;
            while (index < 8 &&!isdigit(message[index])) index++;
            if (index == 8) {
                index = 0;
                while (index < 8 &&!isalpha(message[index])) index++;
                if (index == 8) return; // Invalid message format
            }

            // Adjust the offset based on the secret key
            offset = (offset + message[index - 1]) % width * height * depth;

            // Update the pixel value
            pixel[0] = (pixel[0] & 0x80) | (message[index] - 'a' + 1);
            index++;
        }
    }
}

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s input_image message secret_key\n", argv[0]);
        return 1;
    }

    // Read input image
    FILE *imageFile = fopen(argv[1], "rb");
    if (imageFile == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", argv[1]);
        return 1;
    }
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    unsigned char *image = (unsigned char*)malloc(imageSize);
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        return 1;
    }
    if (fread(image, 1, imageSize, imageFile)!= imageSize) {
        fprintf(stderr, "Error reading image file\n");
        return 1;
    }
    fclose(imageFile);

    // Read secret message
    char message[100];
    if (fgets(message, sizeof(message), stdin) == NULL) {
        fprintf(stderr, "Error reading secret message\n");
        return 1;
    }

    // Read secret key
    int key = atoi(argv[4]);

    // Hide the message within the image
    hideMessage(image, 320, 240, 3, message, key);

    // Write the modified image file
    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return 1;
    }
    if (fwrite(image, 1, imageSize, outputFile)!= imageSize) {
        fprintf(stderr, "Error writing output file\n");
        return 1;
    }
    fclose(outputFile);

    printf("Message hidden successfully!\n");
    return 0;
}