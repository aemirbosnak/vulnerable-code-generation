//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include<stdio.h>

int main(){
    printf("Hello! Welcome to the C Image to ASCII art converter program.\n");
    printf("Are you excited to see how your image looks like in ASCII art?\n");

    // Ask the user for the image file path
    char file_path[100];
    printf("Please enter the path to the image file: ");
    scanf("%s", file_path);

    // Open the image file
    FILE *image_file = fopen(file_path, "r");
    if (image_file == NULL){
        printf("Oops! Unable to open the image file. Please check the file path and try again.\n");
        return 0;
    }

    // Read the image dimensions
    int width, height;
    fscanf(image_file, "%d %d", &width, &height);

    // Create a 2D array to store the pixel values of the image
    int pixels[height][width];

    // Read the pixel values from the image file
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            fscanf(image_file, "%d", &pixels[i][j]);
        }
    }

    // Close the image file
    fclose(image_file);

    printf("The image has been successfully loaded.\n");
    printf("Starting the conversion to ASCII art...\n");

    // Create variables to store the ASCII characters and the final ASCII art string
    char ascii_char = '@';
    char ascii_art[height][width];

    // Convert pixel values to ASCII art
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int pixel_value = pixels[i][j];
            if (pixel_value < 50){
                ascii_char = '#';
            } else if (pixel_value < 100){
                ascii_char = '&';
            } else if (pixel_value < 150){
                ascii_char = '$';
            } else {
                ascii_char = '@';
            }
            ascii_art[i][j] = ascii_char;
        }
    }

    // Print the ASCII art to the console
    printf("The ASCII art version of the image is: \n");
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    printf("Conversion complete. Thank you for using the C Image to ASCII art converter program.\n");

    return 0;
}