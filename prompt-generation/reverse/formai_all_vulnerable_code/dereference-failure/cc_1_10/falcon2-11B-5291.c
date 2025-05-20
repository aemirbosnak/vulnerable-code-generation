//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *watermark;
    FILE *image;
    char buffer[100];
    char *watermark_str = "This is a digital watermark";

    // Open the image file
    if ((image = fopen(argv[1], "r")) == NULL) {
        printf("Error opening the image file\n");
        return 1;
    }

    // Open the watermark file
    if ((watermark = fopen(argv[2], "r")) == NULL) {
        printf("Error opening the watermark file\n");
        return 1;
    }

    // Read the watermark string
    if (fgets(buffer, sizeof(buffer), watermark) == NULL) {
        printf("Error reading the watermark string\n");
        return 1;
    }

    // Close the watermark file
    fclose(watermark);

    // Read the image file
    if (fgets(buffer, sizeof(buffer), image) == NULL) {
        printf("Error reading the image file\n");
        return 1;
    }

    // Close the image file
    fclose(image);

    // Add the watermark string to the image
    int watermark_length = strlen(watermark_str);
    int image_length = strlen(buffer);
    int start_index = 0;

    while (start_index < image_length) {
        if (strncmp(buffer + start_index, watermark_str, watermark_length) == 0) {
            for (int i = 0; i < watermark_length; i++) {
                buffer[start_index + i] = 'A';
            }
        }
        start_index += watermark_length;
    }

    // Write the modified image to a new file
    char new_file_name[100];
    sprintf(new_file_name, "%s.watermarked", argv[1]);
    FILE *new_image = fopen(new_file_name, "w");
    if (new_image == NULL) {
        printf("Error opening the new image file\n");
        return 1;
    }

    fwrite(buffer, sizeof(char), image_length, new_image);
    fclose(new_image);

    // Print the modified image file name
    printf("Watermarked image saved to %s\n", new_file_name);

    return 0;
}