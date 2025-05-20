//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define FILE_NAME_LENGTH 100

// Function to get the path of the file
void getFilePath(char *file_path) {
    printf("Enter the path of the file: ");
    fgets(file_path, FILE_NAME_LENGTH, stdin);
    int len = strlen(file_path);
    // Removing newline character from the end of the file path
    if(file_path[len-1] == '\n') {
        file_path[len-1] = '\0';
    }
}

// Function to get the image width and height
void getImageWidthHeight(int *width, int *height) {
    printf("Enter the width of the image: ");
    scanf("%d", width);
    printf("Enter the height of the image: ");
    scanf("%d", height);
}

// Function to get the image format
char getImageFormat() {
    char ch;
    printf("Enter the image format ('j' for JPEG, 'p' for PNG, 'b' for BMP): ");
    scanf(" %c", &ch);
    ch = tolower(ch);
    while(ch != 'j' && ch != 'p' && ch != 'b') {
        printf("Invalid input! Enter a valid image format: ");
        scanf(" %c", &ch);
        ch = tolower(ch);
    }
    return ch;
}

// Function to get the color value
void getColorValue(int *value) {
    printf("Enter the color value (0-255): ");
    scanf("%d", value);
    while(*value < 0 || *value > 255) {
        printf("Invalid input! Enter a color value between 0 and 255: ");
        scanf("%d", value);
    }
}

// Main function
int main() {

    char file_path[FILE_NAME_LENGTH];
    getFilePath(file_path);

    int width, height;
    getImageWidthHeight(&width, &height);

    char format = getImageFormat();
    printf("Selected image format: %c\n", format);

    int red, green, blue;
    printf("Enter the pixel color values:\n");
    getColorValue(&red);
    getColorValue(&green);
    getColorValue(&blue);

    printf("File path: %s\n", file_path);
    printf("Image size: %d x %d\n", width, height);
    printf("Pixel color values: %d, %d, %d\n", red, green, blue);

    return 0;
}