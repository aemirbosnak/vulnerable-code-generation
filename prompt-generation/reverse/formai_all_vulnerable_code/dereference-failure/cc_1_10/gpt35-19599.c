//FormAI DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void hide_message(FILE *image, char *msg) {
    // Check if file exists
    if (image == NULL) {
        printf("Error: Image file not found.\n");
        exit(1);
    }

    // Check if message length is within bounds of image size 
    size_t image_size;
    fseek(image, 0, SEEK_END);
    image_size = ftell(image);
    fseek(image, 0, SEEK_SET);
    size_t msg_len = strlen(msg);
    if (8 * msg_len > image_size) {
        printf("Error: Message too long to hide in this image.\n");
        exit(1);
    }

    // Loop through each byte in the message
    for (int i = 0; i < msg_len; i++) {
        char msg_byte = msg[i];
        for (int j = 0; j < 8; j++) {
            // Get the next pixel byte from the image
            char pixel_byte;
            fread(&pixel_byte, sizeof(char), 1, image);

            // Get the least significant bit (LSB) from the pixel byte
            char lsb = pixel_byte & 0x01;

            // Set the LSB to the current bit in the message byte
            char bit = (msg_byte >> j) & 0x01;
            char new_pixel_byte = (pixel_byte & 0xFE) | bit;

            // Write the new pixel byte back to the image
            fseek(image, -1*sizeof(char), SEEK_CUR);
            fwrite(&new_pixel_byte, sizeof(char), 1, image);
        }
    }

    printf("Message hidden in image successfully.\n");
}

void reveal_message(FILE *image) {
    // Check if file exists
    if (image == NULL) {
        printf("Error: Image file not found.\n");
        exit(1);
    }

    char msg[1000];
    int i = 0;

    // Loop through each pixel byte in the image
    while (1) {
        char pixel_byte;
        fread(&pixel_byte, sizeof(char), 1, image);
        char lsb = pixel_byte & 0x01;
        msg[i/8] |= (lsb << (i % 8));
        i++;

        // Break out of loop if end of message is reached
        if (i % 8 == 0 && msg[(i/8) - 1] == '\0') {
            break;
        }

        // Check if message extends beyond allowed length
        if (i/8 > 1000) {
            printf("Error: Message is too long or not found in image.\n");
            exit(1);
        }
    }

    // Print hidden message
    printf("Hidden message: %s\n", msg);
}

int main() {
    char file_name[100];
    printf("Enter the name of the image file: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = 0; // Remove newline character

    char mode;
    printf("Enter 'h' to hide a message and 'r' to reveal a message: ");
    scanf("%c", &mode);

    FILE *image = fopen(file_name, "rb+");

    if (mode == 'h') {
        char msg[1000];
        printf("Enter your message to hide in the image (max 125 characters): ");
        scanf("%s", msg);
        hide_message(image, msg);
    }
    else if (mode == 'r') {
        reveal_message(image);
    }
    else {
        printf("Error: Invalid mode selected.\n");
        exit(1);
    }

    fclose(image);

    return 0;
}