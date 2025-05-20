//FormAI DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <string.h>
#define MESSAGE_SIZE 1000
#define IMAGE_NAME_SIZE 30

// Function to get the message to be hidden
void getMessage(char *message) {
    printf("Enter the message to be hidden: ");
    fgets(message, MESSAGE_SIZE, stdin);

    //removing the new line character from the end of the message
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
}

// Function to get the image name
void getImageName(char *imageName) {
    printf("Enter the image name: ");
    fgets(imageName, IMAGE_NAME_SIZE, stdin);

    //removing the new line character from the end of the image name
    if (imageName[strlen(imageName) - 1] == '\n') {
        imageName[strlen(imageName) - 1] = '\0';
    }
}

// Function to hide the message in the least significant bit of each pixel color value
void hideMessageInImage(char *imageName, char *message) {
    FILE *image = fopen(imageName, "rb");
    if (image == NULL) {
        printf("Error: Unable to open image file.\n");
        return;
    }

    // Get image width and height
    int width, height;
    fseek(image, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);

    // Get to the pixel data
    fseek(image, 54, SEEK_SET);

    // Get message length and convert it to binary
    int messageLength = strlen(message);
    char messageLengthBinary[9];
    for (int i = 7; i >= 0; i--) {
        messageLengthBinary[7 - i] = ((1 << i) & messageLength) ? '1' : '0';
    }
    messageLengthBinary[8] = '\0';

    // Write the message length binary to the first 8 pixels
    int count = 0;
    char pixelData[3];
    while (count < 8) {
        fread(pixelData, sizeof(char), 3, image);
        for (int i = 0; i < 3; i++) {
            if (((1 << count) & messageLength) != 0) {
                pixelData[i] |= 1;
            } else {
                pixelData[i] &= ~1;
            }
            count++;
            if (count == 8) {
                break;
            }
        }
        fseek(image, -3, SEEK_CUR); // Move back 3 bytes to overwrite the pixel data
        fwrite(pixelData, sizeof(char), 3, image);
    }

    // Write the message to the remaining pixels
    count = 0;
    char currentByteBinary[9];
    char currentByte;
    while (*message != '\0') {
        currentByte = *(message++);
        for (int i = 7; i >= 0; i--) {
            currentByteBinary[7 - i] = ((1 << i) & currentByte) ? '1' : '0';
        }
        currentByteBinary[8] = '\0';
        for (int i = 0; i < 3; i++) {
            fread(pixelData + i, sizeof(char), 1, image);
            if (((1 << count) & currentByte) != 0) {
                pixelData[i] |= 1;
            } else {
                pixelData[i] &= ~1;
            }
            count++;
            if (count == 8) {
                count = 0;
                break;
            }
        }
        fseek(image, -3, SEEK_CUR); // Move back 3 bytes to overwrite the pixel data
        fwrite(pixelData, sizeof(char), 3, image);
    }

    fclose(image);
}

// Function to extract the hidden message from the image
void getMessageFromImage(char *imageName) {
    FILE *image = fopen(imageName, "rb");
    if (image == NULL) {
        printf("Error: Unable to open image file.\n");
        return;
    }

    // Get image width and height
    int width, height;
    fseek(image, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);

    // Get to the pixel data
    fseek(image, 54, SEEK_SET);

    // Read the message length
    int count = 0;
    char pixelData[3];
    char messageLengthBinary[9];
    memset(messageLengthBinary, 0, sizeof(messageLengthBinary));
    while (count < 8) {
        fread(pixelData, sizeof(char), 3, image);
        for (int i = 0; i < 3; i++) {
            messageLengthBinary[count] = ((pixelData[i] & 1) == 1) ? '1' : '0';
            count++;
            if (count == 8) {
                break;
            }
        }
    }
    int messageLength = 0;
    for (int i = 0; i < 8; i++) {
        messageLength |= ((messageLengthBinary[7 - i] - '0') << i);
    }

    // Allocate memory for the message and read the message
    char *message = (char *) malloc(sizeof(char) * (messageLength + 1));
    memset(message, 0, sizeof(char) * (messageLength + 1));
    count = 0;
    char currentByte = 0;
    char currentByteBinary[9];
    memset(currentByteBinary, 0, sizeof(currentByteBinary));
    while (count < messageLength * 8) {
        fread(pixelData, sizeof(char), 3, image);
        for (int i = 0; i < 3; i++) {
            currentByteBinary[count % 8] = ((pixelData[i] & 1) == 1) ? '1' : '0';
            count++;
            if (count % 8 == 0) {
                currentByte = 0;
                for (int j = 0; j < 8; j++) {
                    currentByte |= ((currentByteBinary[7 - j] - '0') << j);
                }
                *(message++) = currentByte;
                if (count == messageLength * 8) {
                    break;
                }
                memset(currentByteBinary, 0, sizeof(currentByteBinary));
            }
        }
    }

    printf("The hidden message is: %s\n", message - messageLength);
    fclose(image);
}

int main() {
    int choice;
    char imageName[IMAGE_NAME_SIZE], message[MESSAGE_SIZE];
    while (1) {
        printf("\n1. Hide message in image\n2. Extract message from image\n3. Exit\n\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left over by scanf
        switch (choice) {
            case 1:
                getImageName(imageName);
                getMessage(message);
                hideMessageInImage(imageName, message);
                printf("Message successfully hidden in the image.\n");
                break;
            case 2:
                getImageName(imageName);
                getMessageFromImage(imageName);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}