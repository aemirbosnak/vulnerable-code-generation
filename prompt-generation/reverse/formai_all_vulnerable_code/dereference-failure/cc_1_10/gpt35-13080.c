//FormAI DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char message[1000], filename[100];
    FILE *fp;

    printf("Enter the message you want to hide: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the filename of the image you want to hide the message in: ");
    scanf("%s", filename);

    // Open the image file and read the header data
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Get the width and height from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the size of the image data and allocate memory for it
    int image_size = 3 * width * height;
    unsigned char* image_data = (unsigned char*)malloc(image_size * sizeof(unsigned char));

    // Read in the image data
    fread(image_data, sizeof(unsigned char), image_size, fp);

    // Close the image file
    fclose(fp);

    // Iterate over the message and hide it in the image data
    int message_length = strlen(message);
    int bit_index = 0;

    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (c >> j) & 1;
            image_data[bit_index] = (image_data[bit_index] & 0xFE) | bit;
            bit_index += 3;
        }
    }

    // Write out the new image data to a new file
    char new_filename[100];
    printf("Enter the filename of the new image: ");
    scanf("%s", new_filename);

    fp = fopen(new_filename, "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(header, sizeof(unsigned char), 54, fp);
    fwrite(image_data, sizeof(unsigned char), image_size, fp);

    fclose(fp);
    free(image_data);

    printf("\nMessage hidden successfully!\n");

    return 0;
}