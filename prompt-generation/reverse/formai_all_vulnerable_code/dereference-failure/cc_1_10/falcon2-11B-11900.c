//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 10000

// Function to hide a message in an image
void hide_message(char *image_file, char *secret_message, int message_length) {
    FILE *fp;
    int size;
    char buffer[MAX_LENGTH];

    // Open the image file for reading
    fp = fopen(image_file, "rb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    // Get the size of the image file
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the modified image file
    char *modified_image = (char*) malloc(size + message_length + 1);
    if (modified_image == NULL) {
        printf("Error allocating memory for modified image.\n");
        return;
    }

    // Read the image file into the buffer
    fread(buffer, 1, size, fp);

    // Modify the buffer to hide the secret message
    int index = 0;
    for (int i = 0; i < size; i++) {
        int value = buffer[i] ^ (secret_message[index] << 2);
        modified_image[i] = (char) value;
        index++;
    }

    // Add a null terminator to the modified image file
    modified_image[size] = '\0';

    // Write the modified image file back to the original file
    fwrite(modified_image, 1, size + message_length, fp);

    // Close the image file
    fclose(fp);

    // Print success message
    printf("Secret message successfully hidden in image file.\n");
}

// Function to extract the secret message from an image
char *extract_message(char *image_file) {
    FILE *fp;
    int size;
    char buffer[MAX_LENGTH];

    // Open the image file for reading
    fp = fopen(image_file, "rb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        return NULL;
    }

    // Get the size of the image file
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the modified image file
    char *modified_image = (char*) malloc(size + 1);
    if (modified_image == NULL) {
        printf("Error allocating memory for modified image.\n");
        return NULL;
    }

    // Read the image file into the buffer
    fread(buffer, 1, size, fp);

    // Modify the buffer to extract the secret message
    int index = 0;
    for (int i = 0; i < size; i++) {
        int value = buffer[i] ^ (i << 2);
        modified_image[i] = (char) value;
        index++;
    }

    // Add a null terminator to the modified image file
    modified_image[size] = '\0';

    // Close the image file
    fclose(fp);

    // Print success message
    printf("Secret message extracted from image file.\n");

    // Return the modified image file
    return modified_image;
}

int main() {
    char image_file[] = "image.jpg";
    char secret_message[] = "Sherlock Holmes is the best detective ever!";
    int message_length = strlen(secret_message);

    // Hide the secret message in the image
    hide_message(image_file, secret_message, message_length);

    // Extract the secret message from the image
    char *modified_image = extract_message(image_file);
    printf("Extracted message: %s\n", modified_image);

    // Free the memory allocated for the modified image file
    free(modified_image);

    return 0;
}