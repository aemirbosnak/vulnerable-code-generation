//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main(void) {
    char filepath[MAX_FILENAME_LENGTH];
    int choice;
    
    printf("Welcome to the Post-Apocalyptic Image Editor\n");
    printf("--------------------------------------------\n");
    printf("Please enter the filepath of the image you would like to edit: ");
    fgets(filepath, MAX_FILENAME_LENGTH, stdin);
    filepath[strlen(filepath) - 1] = '\0'; // Remove newline character
    
    FILE *image = fopen(filepath, "rb+");
    if (!image) {
        printf("Unable to open image file. Exiting...\n");
        return 1;
    }
    
    printf("\nWhat would you like to do?\n");
    printf("--------------------------\n");
    printf("1. Grayscale Filter\n");
    printf("2. Sepia Filter\n");
    printf("3. Negative Filter\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    
    fseek(image, 0, SEEK_END);
    long size = ftell(image);
    rewind(image);
    
    unsigned char *data = malloc(size);
    fread(data, size, 1, image);
    
    switch (choice) {
        case 1:
            for (long i = 0; i < size; i += 3) { // Process RGB values in groups of 3
                unsigned char gray = (data[i] + data[i+1] + data[i+2]) / 3;
                data[i] = gray;
                data[i+1] = gray;
                data[i+2] = gray;
            }
            break;
        case 2:
            for (long i = 0; i < size; i += 3) { // Process RGB values in groups of 3
                unsigned char r = data[i];
                unsigned char g = data[i+1];
                unsigned char b = data[i+2];
                data[i] = (unsigned char)(0.393*r + 0.769*g + 0.189*b);
                data[i+1] = (unsigned char)(0.349*r + 0.686*g + 0.168*b);
                data[i+2] = (unsigned char)(0.272*r + 0.534*g + 0.131*b);
            }
            break;
        case 3:
            for (long i = 0; i < size; i++) {
                data[i] = 255 - data[i];
            }
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }
    
    rewind(image);
    fwrite(data, size, 1, image);
    fclose(image);
    
    printf("Image successfully edited and saved.\n");
    
    free(data);
    
    return 0;
}