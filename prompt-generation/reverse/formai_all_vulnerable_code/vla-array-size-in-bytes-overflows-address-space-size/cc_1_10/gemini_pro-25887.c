//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to embed a secret message into an image
void embedMessage(char *image, char *message, int size) {
    // Convert the message to binary
    int binaryMessage[size];
    for (int i = 0; i < size; i++) {
        binaryMessage[i] = (message[i] & 0x80) >> 7;
        message[i] <<= 1;
    }

    // Embed the binary message into the image
    int imageIndex = 0;
    for (int i = 0; i < size; i++) {
        image[imageIndex] = (image[imageIndex] & 0xFE) | binaryMessage[i];
        imageIndex += 3;
    }
}

// Function to extract a secret message from an image
char *extractMessage(char *image, int size) {
    // Extract the binary message from the image
    int binaryMessage[size];
    int imageIndex = 0;
    for (int i = 0; i < size; i++) {
        binaryMessage[i] = image[imageIndex] & 0x01;
        imageIndex += 3;
    }

    // Convert the binary message to ASCII
    char *message = (char *)malloc(size);
    for (int i = 0; i < size; i++) {
        message[i] = (binaryMessage[i] << 7) | (message[i] >> 1);
    }

    return message;
}

int main() {
    // Open the image file
    FILE *imageFile = fopen("image.bmp", "rb+");
    if (imageFile == NULL) {
        printf("Error opening the image file.\n");
        return 1;
    }

    // Get the size of the image
    fseek(imageFile, 0, SEEK_END);
    int size = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Read the image data into a buffer
    char *image = (char *)malloc(size);
    fread(image, 1, size, imageFile);

    // Read the secret message from the user
    char *message = (char *)malloc(size);
    printf("Enter the secret message to embed: ");
    scanf("%s", message);

    // Embed the secret message into the image
    embedMessage(image, message, size);

    // Write the modified image data back to the file
    fseek(imageFile, 0, SEEK_SET);
    fwrite(image, 1, size, imageFile);

    // Close the image file
    fclose(imageFile);

    // Extract the secret message from the image
    char *extractedMessage = extractMessage(image, size);

    // Print the extracted message
    printf("The extracted secret message is: %s\n", extractedMessage);

    // Free the allocated memory
    free(image);
    free(message);
    free(extractedMessage);

    return 0;
}