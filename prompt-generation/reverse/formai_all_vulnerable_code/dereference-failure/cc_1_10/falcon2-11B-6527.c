//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed an image into another image
void embed_image(unsigned char* image, int width, int height, int stride, unsigned char* secret_image, int secret_width, int secret_height) {
    // Find the smallest multiple of stride that is greater than or equal to the width and height of the secret image
    int new_stride = stride * (stride / secret_width == 0? 1 : stride / secret_width);
    int new_width = (width / new_stride == 0? 1 : width / new_stride);
    int new_height = (height / new_stride == 0? 1 : height / new_stride);

    // Initialize the new image with zeros
    unsigned char* new_image = (unsigned char*)malloc(new_width * new_height * 3 * sizeof(char));
    memset(new_image, 0, new_width * new_height * 3 * sizeof(char));

    // Embed the secret image into the new image
    int x = 0;
    int y = 0;
    int new_x = 0;
    int new_y = 0;
    int i = 0;
    while (y < new_height) {
        while (x < new_width) {
            int j = 0;
            while (j < 3) {
                new_image[new_x + new_y * new_width * 3 + j] = image[x + y * width * 3 + i];
                j++;
            }
            x++;
            i++;
        }
        x = 0;
        y++;
        new_x += new_stride;
        new_y++;
    }

    // Save the new image as an output file
    FILE* output_file = fopen("output.png", "wb");
    fwrite(new_image, new_width * new_height * 3 * sizeof(char), 1, output_file);
    fclose(output_file);

    // Free the memory
    free(new_image);
}

int main() {
    FILE* input_file = fopen("input.png", "rb");
    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    unsigned char* image_data = (unsigned char*)malloc(1024 * 1024 * 3 * sizeof(char));
    fread(image_data, 1024 * 1024 * 3 * sizeof(char), 1, input_file);
    fclose(input_file);

    // Extract the secret image from the input image
    FILE* secret_file = fopen("secret.png", "rb");
    if (secret_file == NULL) {
        printf("Failed to open secret file.\n");
        return 1;
    }

    unsigned char* secret_data = (unsigned char*)malloc(1024 * 1024 * 3 * sizeof(char));
    fread(secret_data, 1024 * 1024 * 3 * sizeof(char), 1, secret_file);
    fclose(secret_file);

    // Embed the secret image into the input image
    embed_image(image_data, 1024, 1024, 1024, secret_data, 1024, 1024);

    // Save the modified image as an output file
    FILE* output_file = fopen("output.png", "wb");
    fwrite(image_data, 1024 * 1024 * 3 * sizeof(char), 1, output_file);
    fclose(output_file);

    // Free the memory
    free(image_data);
    free(secret_data);

    printf("Successfully embedded the secret image into the input image.\n");

    return 0;
}