//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define variables
    char filename[100];
    int choice, brightness, contrast;

    // Get user input for file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open file in read binary mode
    FILE *imageFile = fopen(filename, "rb");

    // Check if file exists
    if (imageFile == NULL) {
        printf("File not found\n");
        exit(0);
    }

    // Determine the image size for memory allocation
    fseek(imageFile, 0, SEEK_END);
    long int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Allocate memory for the image data
    unsigned char *imageData = (unsigned char*)malloc(imageSize);

    // Read image data into the allocated memory
    fread(imageData, 1, imageSize, imageFile);

    // Close file
    fclose(imageFile);

    // Get user input for image processing operation
    printf("Select an operation to perform:\n");
    printf("1. Flip image horizontally\n");
    printf("2. Flip image vertically\n");
    printf("3. Adjust brightness\n");
    printf("4. Adjust contrast\n");
    printf("5. Quit\n");
    scanf("%d", &choice);

    // Perform selected operation
    switch (choice) {
        case 1:
            // Flip image horizontally by swapping pixel values across vertical axis
            for (int i = 0; i < imageSize; i++) {
                if (i % 3 == 0) {
                    int j = i + 2;
                    int temp = imageData[i];
                    imageData[i] = imageData[j];
                    imageData[j] = temp;
                }
            }

            // Save modified image to file
            FILE *outputFile = fopen("flipped_h.jpg", "wb");
            fwrite(imageData, 1, imageSize, outputFile);
            fclose(outputFile);
            printf("Image flipped horizontally successfully!\n");
            break;

        case 2:
            // Flip image vertically by swapping pixel values across horizontal axis
            for (int i = 0; i < (imageSize / 2); i += 3) {
                int j = imageSize - (i + 3);
                int temp1 = imageData[i];
                int temp2 = imageData[i + 1];
                int temp3 = imageData[i + 2];
                imageData[i] = imageData[j];
                imageData[i + 1] = imageData[j + 1];
                imageData[i + 2] = imageData[j + 2];
                imageData[j] = temp1;
                imageData[j + 1] = temp2;
                imageData[j + 2] = temp3;
            }

            // Save modified image to file
            outputFile = fopen("flipped_v.jpg", "wb");
            fwrite(imageData, 1, imageSize, outputFile);
            fclose(outputFile);
            printf("Image flipped vertically successfully!\n");
            break;

        case 3:
            // Get user input for brightness adjustment
            printf("Enter brightness adjustment value (-255 to 255): ");
            scanf("%d", &brightness);

            // Adjust brightness by adding the same value to all three channels of each pixel
            for (int i = 0; i < imageSize; i++) {
                if (i % 3 == 0) {
                    int channelValue = imageData[i] + brightness;
                    if (channelValue < 0) {
                        channelValue = 0;
                    } else if (channelValue > 255) {
                        channelValue = 255;
                    }
                    imageData[i] = channelValue;
                }
            }

            // Save modified image to file
            outputFile = fopen("brightened.jpg", "wb");
            fwrite(imageData, 1, imageSize, outputFile);
            fclose(outputFile);
            printf("Brightness adjusted successfully!\n");
            break;

        case 4:
            // Get user input for contrast adjustment
            printf("Enter contrast adjustment value (-128 to 128): ");
            scanf("%d", &contrast);

            // Adjust contrast by multiplying the same value to all three channels of each pixel
            int factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
            for (int i = 0; i < imageSize; i++) {
                if (i % 3 == 0) {
                    int channelValue = factor * (imageData[i] - 128) + 128;
                    if (channelValue < 0) {
                        channelValue = 0;
                    } else if (channelValue > 255) {
                        channelValue = 255;
                    }
                    imageData[i] = channelValue;
                }
            }

            // Save modified image to file
            outputFile = fopen("contrasted.jpg", "wb");
            fwrite(imageData, 1, imageSize, outputFile);
            fclose(outputFile);
            printf("Contrast adjusted successfully!\n");
            break;

        case 5:
            // Quit program
            printf("Goodbye!\n");
            break;

        default:
            // Invalid input
            printf("Invalid input\n");
            break;
    }

    // Free allocated memory
    free(imageData);

    return 0;
}