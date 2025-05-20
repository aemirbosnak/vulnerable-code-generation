//FormAI DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 // maximum size of image
#define HEADER_SIZE 54 // size of bitmap header

int main () {
    char file_name[100]; // variable to store filename
    printf("Enter the filename of the image you want to edit: ");
    scanf("%s", file_name);
    FILE *image_file;
    image_file = fopen(file_name, "rb"); // open the image file in binary read mode
    if (image_file == NULL) {
        printf("File not found.");
        return 0;
    }
    unsigned char header[HEADER_SIZE]; // array to store header information
    fread(header, sizeof(unsigned char), HEADER_SIZE, image_file); // read the header
    int width = *(int*)&header[18]; // extract the image width from header
    int height = *(int*)&header[22]; // extract the image height from header
    int padding = 0; // calculate the padding
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }
    unsigned char **pixels = (unsigned char**)malloc(sizeof(unsigned char*) * height); // allocate memory for pixels
    for (int i = 0; i < height; i++) {
        pixels[i] = (unsigned char*)malloc(sizeof(unsigned char) * (width * 3 + padding)); // allocate memory for each row of pixels
    }
    fseek(image_file, HEADER_SIZE, SEEK_SET); // position the file pointer to the start of the pixel data
    for (int i = 0; i < height; i++) {
        fread(pixels[i], sizeof(unsigned char), width * 3 + padding, image_file); // read the pixel data
    }
    fclose(image_file); // close the file
    printf("\nThe image has been loaded successfully.\n");
    printf("Image dimensions: %d x %d pixels\n", width, height);
    int choice = 0; // variable to store user's choice
    do {
        printf("\n*** Image Editing Menu ***\n");
        printf("1. Grayscale\n");
        printf("2. Convert to Sepia\n");
        printf("3. Invert Colors\n");
        printf("4. Flip Horizontally\n");
        printf("5. Flip Vertically\n");
        printf("6. Rotate Clockwise\n");
        printf("7. Rotate Counter-Clockwise\n");
        printf("8. Crop Image\n");
        printf("9. Save Image\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // convert the image to grayscale
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width * 3; j += 3) {
                        int gray = (pixels[i][j] + pixels[i][j + 1] + pixels[i][j + 2]) / 3;
                        pixels[i][j] = gray;
                        pixels[i][j + 1] = gray;
                        pixels[i][j + 2] = gray;
                    }
                }
                printf("Image converted to grayscale.\n");
                break;
            case 2:
                // convert the image to sepia
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width * 3; j += 3) {
                        int r = pixels[i][j];
                        int g = pixels[i][j + 1];
                        int b = pixels[i][j + 2];
                        pixels[i][j] = (unsigned char)((r * 0.393) + (g * 0.769) + (b * 0.189));
                        pixels[i][j + 1] = (unsigned char)((r * 0.349) + (g * 0.686) + (b * 0.168));
                        pixels[i][j + 2] = (unsigned char)((r * 0.272) + (g * 0.534) + (b * 0.131));
                    }
                }
                printf("Image converted to sepia.\n");
                break;
            case 3:
                // invert the colors of the image
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width * 3; j++) {
                        pixels[i][j] = 255 - pixels[i][j];
                    }
                }
                printf("Image colors inverted.\n");
                break;
            case 4:
                // flip the image horizontally
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width / 2 * 3; j += 3) {
                        unsigned char temp = pixels[i][j];
                        pixels[i][j] = pixels[i][width * 3 - j - 3];
                        pixels[i][width * 3 - j - 3] = temp;
                        temp = pixels[i][j + 1];
                        pixels[i][j + 1] = pixels[i][width * 3 - j - 2];
                        pixels[i][width * 3 - j - 2] = temp;
                        temp = pixels[i][j + 2];
                        pixels[i][j + 2] = pixels[i][width * 3 - j - 1];
                        pixels[i][width * 3 - j - 1] = temp;
                    }
                }
                printf("Image flipped horizontally.\n");
                break;
            case 5:
                // flip the image vertically
                for (int i = 0; i < height / 2; i++) {
                    unsigned char *temp = pixels[i];
                    pixels[i] = pixels[height - i - 1];
                    pixels[height - i - 1] = temp;
                }
                printf("Image flipped vertically.\n");
                break;
            case 6:
                // rotate the image clockwise
                {
                    unsigned char **temp_pixels = (unsigned char**)malloc(sizeof(unsigned char*) * width);
                    for (int i = 0; i < width; i++) {
                        temp_pixels[i] = (unsigned char*)malloc(sizeof(unsigned char) * (height * 3));
                    }
                    for (int i = 0; i < width; i++) {
                        for (int j = 0; j < height; j++) {
                            temp_pixels[i][j * 3] = pixels[height - j - 1][i * 3];
                            temp_pixels[i][j * 3 + 1] = pixels[height - j - 1][i * 3 + 1];
                            temp_pixels[i][j * 3 + 2] = pixels[height - j - 1][i * 3 + 2];
                        }
                    }
                    // free the old pixel data
                    for (int i = 0; i < height; i++) {
                        free(pixels[i]);
                    }
                    free(pixels);
                    pixels = temp_pixels;
                    int temp = width;
                    width = height;
                    height = temp;
                }
                printf("Image rotated clockwise.\n");
                break;
            case 7:
                // rotate the image counter-clockwise
                {
                    unsigned char **temp_pixels = (unsigned char**)malloc(sizeof(unsigned char*) * width);
                    for (int i = 0; i < width; i++) {
                        temp_pixels[i] = (unsigned char*)malloc(sizeof(unsigned char) * (height * 3));
                    }
                    for (int i = 0; i < width; i++) {
                        for (int j = 0; j < height; j++) {
                            temp_pixels[i][j * 3] = pixels[j][width * 3 - i * 3 - 3];
                            temp_pixels[i][j * 3 + 1] = pixels[j][width * 3 - i * 3 - 2];
                            temp_pixels[i][j * 3 + 2] = pixels[j][width * 3 - i * 3 - 1];
                        }
                    }
                    // free the old pixel data
                    for (int i = 0; i < height; i++) {
                        free(pixels[i]);
                    }
                    free(pixels);
                    pixels = temp_pixels;
                    int temp = width;
                    width = height;
                    height = temp;
                }
                printf("Image rotated counter-clockwise.\n");
                break;
            case 8:
                // crop the image
                {
                    int x, y, crop_width, crop_height;
                    printf("Enter the x-coordinate of the top-left corner of the crop: ");
                    scanf("%d", &x);
                    printf("Enter the y-coordinate of the top-left corner of the crop: ");
                    scanf("%d", &y);
                    printf("Enter the width of the crop: ");
                    scanf("%d", &crop_width);
                    printf("Enter the height of the crop: ");
                    scanf("%d", &crop_height);
                    if (x + crop_width > width || y + crop_height > height || x < 0 || y < 0 || crop_width < 1 || crop_height < 1) {
                        printf("Invalid crop dimensions.\n");
                        break;
                    }
                    unsigned char **temp_pixels = (unsigned char**)malloc(sizeof(unsigned char*) * crop_height);
                    for (int i = 0; i < crop_height; i++) {
                        temp_pixels[i] = (unsigned char*)malloc(sizeof(unsigned char) * (crop_width * 3 + padding));
                        memcpy(temp_pixels[i], pixels[y + i] + x * 3, crop_width * 3);
                    }
                    // free the old pixel data
                    for (int i = 0; i < height; i++) {
                        free(pixels[i]);
                    }
                    free(pixels);
                    pixels = temp_pixels;
                    width = crop_width;
                    height = crop_height;
                }
                printf("Image cropped.\n");
                break;
            case 9:
                // save the modified image
                {
                    FILE *output_file;
                    char output_file_name[100];
                    printf("Enter the filename of the output file: ");
                    scanf("%s", output_file_name);
                    output_file = fopen(output_file_name, "wb");
                    if (output_file == NULL) {
                        printf("Error creating output file.");
                        break;
                    }
                    // write the header
                    fwrite(header, sizeof(unsigned char), HEADER_SIZE, output_file);
                    // write the pixel data
                    fseek(output_file, HEADER_SIZE, SEEK_SET);
                    for (int i = 0; i < height; i++) {
                        fwrite(pixels[i], sizeof(unsigned char), width * 3 + padding, output_file);
                    }
                    fclose(output_file);
                }
                printf("Image saved.\n");
                break;
            case 0:
                // exit the program
                printf("Goodbye.\n");
                break;
            default:
                // invalid choice
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);
    // free the pixel data
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
    return 0;
}