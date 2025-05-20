//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to embed a message into an image
void embedMessage(char *image, char *message, int len) {
    int i, j, k;
    // Embed the length of the message in the first 32 bits of the image
    for (i = 0; i < 32; i++) {
        image[i] = (image[i] & 0xFE) | ((len >> i) & 0x01);
    }
    // Embed the message in the remaining bits of the image
    for (i = 32, j = 0; i < len + 32; i++, j++) {
        image[i] = (image[i] & 0xFE) | ((message[j] >> 7) & 0x01);
        image[i + 1] = (image[i + 1] & 0xFE) | ((message[j] >> 6) & 0x01);
        image[i + 2] = (image[i + 2] & 0xFE) | ((message[j] >> 5) & 0x01);
        image[i + 3] = (image[i + 3] & 0xFE) | ((message[j] >> 4) & 0x01);
        image[i + 4] = (image[i + 4] & 0xFE) | ((message[j] >> 3) & 0x01);
        image[i + 5] = (image[i + 5] & 0xFE) | ((message[j] >> 2) & 0x01);
        image[i + 6] = (image[i + 6] & 0xFE) | ((message[j] >> 1) & 0x01);
        image[i + 7] = (image[i + 7] & 0xFE) | (message[j] & 0x01);
    }
}

// Function to extract a message from an image
char *extractMessage(char *image, int len) {
    int i, j, k;
    char *message = malloc(len + 1);
    // Extract the length of the message from the first 32 bits of the image
    for (i = 0, j = 0; i < 32; i++) {
        j |= ((image[i] & 0x01) << i);
    }
    // Extract the message from the remaining bits of the image
    for (i = 32, k = 0; i < len + 32; i++, k++) {
        message[k] = ((image[i] & 0x01) << 7) | ((image[i + 1] & 0x01) << 6) | ((image[i + 2] & 0x01) << 5) | ((image[i + 3] & 0x01) << 4) | ((image[i + 4] & 0x01) << 3) | ((image[i + 5] & 0x01) << 2) | ((image[i + 6] & 0x01) << 1) | (image[i + 7] & 0x01);
        i += 7;
    }
    message[k] = '\0';
    return message;
}

int main() {
    // Read the image file into a buffer
    FILE *fp = fopen("image.bmp", "rb");
    if (!fp) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *image = malloc(fsize);
    fread(image, 1, fsize, fp);
    fclose(fp);

    // Read the message to be embedded into the image
    char message[100];
    printf("Enter the message to be embedded: ");
    scanf("%s", message);

    // Embed the message into the image
    int len = strlen(message);
    embedMessage(image, message, len);

    // Write the modified image to a new file
    fp = fopen("image_with_message.bmp", "wb");
    if (!fp) {
        perror("Error opening output image file");
        return EXIT_FAILURE;
    }
    fwrite(image, 1, fsize, fp);
    fclose(fp);

    // Extract the message from the modified image
    char *extractedMessage = extractMessage(image, len);

    // Print the extracted message
    printf("Extracted message: %s\n", extractedMessage);

    free(image);
    free(extractedMessage);

    return EXIT_SUCCESS;
}