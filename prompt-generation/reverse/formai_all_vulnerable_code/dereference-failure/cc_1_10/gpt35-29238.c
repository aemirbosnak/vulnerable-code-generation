//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_MSG_LENGTH 2048

void hide_message(char *image_filename, char *secret_message) {
    FILE *img_file = fopen(image_filename, "rb");
    if (img_file == NULL) {
        printf("Error opening file %s\n", image_filename);
        return;
    }

    // Get image size
    fseek(img_file, 0L, SEEK_END);
    long img_size = ftell(img_file);
    fseek(img_file, 0L, SEEK_SET);

    // Allocate memory for image data
    unsigned char *img_data = (unsigned char*) malloc(img_size);
    if (img_data == NULL) {
        printf("Error allocating memory\n");
        fclose(img_file);
        return;
    }

    // Read image data into memory
    fread(img_data, sizeof(unsigned char), img_size, img_file);
    fclose(img_file);

    // Get secret message length
    int msg_len = strlen(secret_message);

    // Calculate max number of bits that can be hidden in image
    int max_bits = (img_size * 8) / 3;

    // Check if message can be hidden in image
    if (msg_len > max_bits) {
        printf("Error: Message is too long to be hidden in image\n");
        free(img_data);
        return;
    }

    // Convert secret message to binary
    char binary_msg[MAX_MSG_LENGTH*8];
    strcpy(binary_msg, "");
    for (int i = 0; i < msg_len; i++) {
        char binary_char[9];
        sprintf(binary_char, "%08d", atoi(binary_msg[i]));
        strcat(binary_msg, binary_char);
    }

    // Hide message in image
    int data_index = 0;
    for (int i = 0; i < msg_len*8; i += 3) {
        unsigned char red = img_data[data_index] >> 5;
        unsigned char green = (img_data[data_index] & 0x1C) >> 2;
        unsigned char blue = img_data[data_index] & 0x3;

        red = (red << 3) | ((binary_msg[i] & 0x4) >> 2) | ((binary_msg[i+1] & 0x4) >> 3) | (binary_msg[i+2] & 0x4);
        green = (green << 3) | ((binary_msg[i] & 0x2) << 1) | ((binary_msg[i+1] & 0x2) >> 1) | ((binary_msg[i+2] & 0x2) >> 2);
        blue = (blue << 3) | ((binary_msg[i] & 0x1) << 2) | ((binary_msg[i+1] & 0x1) << 1) | (binary_msg[i+2] & 0x1);

        img_data[data_index] = (red << 5) | (green << 2) | blue;
        data_index++;
    }

    // Save modified image
    char output_filename[MAX_FILENAME_LENGTH];
    strcpy(output_filename, "hidden_");
    strcat(output_filename, image_filename);
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        free(img_data);
        return;
    }

    fwrite(img_data, sizeof(unsigned char), img_size, output_file);
    fclose(output_file);
    free(img_data);
}

char *reveal_message(char *image_filename) {
    FILE *img_file = fopen(image_filename, "rb");
    if (img_file == NULL) {
        printf("Error opening file %s\n", image_filename);
        return NULL;
    }

    // Get image size
    fseek(img_file, 0L, SEEK_END);
    long img_size = ftell(img_file);
    fseek(img_file, 0L, SEEK_SET);

    // Allocate memory for image data
    unsigned char *img_data = (unsigned char*) malloc(img_size);
    if (img_data == NULL) {
        printf("Error allocating memory\n");
        fclose(img_file);
        return NULL;
    }

    // Read image data into memory
    fread(img_data, sizeof(unsigned char), img_size, img_file);
    fclose(img_file);

    // Recover hidden message from image
    char binary_msg[MAX_MSG_LENGTH*8];
    memset(binary_msg, 0, sizeof(binary_msg));

    int data_index = 0;
    for (int i = 0; i < MAX_MSG_LENGTH*8; i += 3) {
        unsigned char red = img_data[data_index] >> 5;
        unsigned char green = (img_data[data_index] & 0x1C) >> 2;
        unsigned char blue = img_data[data_index] & 0x3;

        binary_msg[i] = ((red & 0x8) >> 3) + '0';
        binary_msg[i+1] = ((red & 0x4) >> 2) + '0';
        binary_msg[i+2] = ((red & 0x2) >> 1) + '0';

        binary_msg[i+3] = ((green & 0x8) >> 3) + '0';
        binary_msg[i+4] = ((green & 0x4) >> 2) + '0';
        binary_msg[i+5] = ((green & 0x2) >> 1) + '0';

        binary_msg[i+6] = ((blue & 0x8) >> 3) + '0';
        binary_msg[i+7] = ((blue & 0x4) >> 2) + '0';
        binary_msg[i+8] = ((blue & 0x2) >> 1) + '0';

        data_index++;
    }

    // Convert binary message to string
    char *msg = (char*) malloc(sizeof(char) * (MAX_MSG_LENGTH + 1));
    if (msg == NULL) {
        printf("Error allocating memory\n");
        free(img_data);
        return NULL;
    }

    memset(msg, 0, sizeof(msg));

    int index = 0;
    for (int i = 0; i < MAX_MSG_LENGTH*8; i += 8) {
        char binary_char[9];
        memset(binary_char, 0, sizeof(binary_char));
        memcpy(binary_char, &binary_msg[i], 8);
        int decimal_char = strtol(binary_char, NULL, 2);
        msg[index] = decimal_char;
        index++;
    }

    free(img_data);
    return msg;
}

int main() {
    char image_filename[MAX_FILENAME_LENGTH];
    printf("Enter name of image file to hide message in: ");
    fgets(image_filename, sizeof(image_filename), stdin);
    image_filename[strcspn(image_filename, "\n")] = 0;

    char secret_message[MAX_MSG_LENGTH];
    printf("Enter secret message to hide: ");
    fgets(secret_message, sizeof(secret_message), stdin);
    secret_message[strcspn(secret_message, "\n")] = 0;

    hide_message(image_filename, secret_message);

    char *revealed_message = reveal_message("hidden_image.bmp");
    if (revealed_message != NULL) {
        printf("Hidden message: %s\n", revealed_message);
        free(revealed_message);
    } else {
        printf("Error: Failed to reveal hidden message\n");
    }

    return 0;
}