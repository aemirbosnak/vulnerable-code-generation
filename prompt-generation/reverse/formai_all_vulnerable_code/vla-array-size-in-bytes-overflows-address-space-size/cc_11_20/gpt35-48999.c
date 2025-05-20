//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>

int main(void) {

    // Displaying the welcome message
    printf("Welcome to the Grateful Image Editor!\n");
 
    // Prompting user to enter the file name of the image
    char file_name[50];
    printf("Please enter the file name of the image you want to edit: ");
    scanf("%s", file_name);
 
    // Opening the image file
    FILE *file = fopen(file_name, "r+");
 
    // Checking if the image file is found or not
    if (file) {
        printf("Image File Found!\n");
 
        // Reading the image dimensions
        int width, height;
        fscanf(file, "%d %d", &width, &height);
 
        // Creating a new array to store the updated image
        int image[width][height];
 
        // Populating the array with the grayscale values of the original image
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fscanf(file, "%d", &image[j][i]);
            }
        }
 
        // Closing the file since we have already read all data from it
        fclose(file);
 
        // Displaying the original image
        printf("*** Original Image ***\n");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%d ", image[j][i]);
            }
            printf("\n");
        }
 
        // Modifying the image to apply a negative effect
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                image[j][i] = 255 - image[j][i];
            }
        }
 
        // Prompting user to save the modified image
        char save_choice;
        printf("Do you want to save the modified image? (Y/N)\n");
        scanf(" %c", &save_choice);
 
        // If user chooses to save the modified image, updating the original file
        if (save_choice == 'Y' || save_choice == 'y') {
            printf("Saving the modified image...\n");
 
            // Reopening the image file in write mode to overwrite the original image
            file = fopen(file_name, "w+");
 
            // Writing the dimensions of the image
            fprintf(file, "%d %d\n", width, height);
 
            // Writing the grayscale values of the modified image
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    fprintf(file, "%d ", image[j][i]);
                }
                fprintf(file, "\n");
            }
 
            // Closing the image file after writing the modified image
            fclose(file);
 
            printf("Image saved successfully!\n");
        } else {
            printf("Image not saved.\n");
        }
 
    } else {
        printf("Sorry, the image file could not be found.\n");
    }
 
    return 0;
}