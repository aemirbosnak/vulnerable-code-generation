//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024] = "image.jpg";
    char message[1024] = "This is a secret message embedded in the image.";

    FILE *fp = fopen(image, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // Calculate the size of the image file
    int size = 0;
    while (!feof(fp))
    {
        size++;
        getc(fp);
    }

    fclose(fp);

    // Allocate memory for the stego image
    char *stego_image = (char *)malloc(size);

    // Open the image file again
    fp = fopen(image, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // Embed the message into the image
    int i = 0;
    while (!feof(fp) && i < size)
    {
        char pixel = getc(fp);
        stego_image[i] = pixel ^ message[i % strlen(message)];
        i++;
    }

    // Close the image file
    fclose(fp);

    // Save the stego image
    fp = fopen("stego_image.jpg", "wb");
    if (fp == NULL)
    {
        perror("Error saving file");
        return -1;
    }

    fwrite(stego_image, size, 1, fp);
    fclose(fp);

    printf("Secret message embedded successfully!\n");

    return 0;
}