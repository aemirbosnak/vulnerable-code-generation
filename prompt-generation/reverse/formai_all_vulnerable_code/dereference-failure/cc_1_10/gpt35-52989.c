//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {
    char *ascii_chars[] = {" ", ".", "\'", "\"", "_", "^", "`", ",", ":", ";", "I", "l", "!", "i", ">", "<", "~", "+", "-", "?", "]", "[", "}", "{", "1", ")", "(", "|", "\\", "/", "t", "f", "j", "r", "x", "n", "u", "v", "c", "z", "L", "C", "J", "U", "Y", "X", "Z", "w", "e", "a", "o", "h", "k", "b", "d", "p", "q", "y", "m", "B", "8", "&", "W", "M", "#", "Q", "$", "O", "H", "K", "N", "A", "D", "R", "G", "E", "P", "B", "S", "F", "%", "0"};
    // Array of ASCII characters

    int num_chars = sizeof(ascii_chars)/sizeof(ascii_chars[0]);
    
    char filename[100]; 
    
    printf("Enter the name of the image file to convert: ");
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fseek(fp, 0L, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    unsigned char *image_data = (unsigned char *) malloc(filesize);
    
    if (image_data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    
    fread(image_data, sizeof(char), filesize, fp);
    fclose(fp);
    
    int width = image_data[18] + (image_data[19] << 8);
    int height = image_data[22] + (image_data[23] << 8);
    
    unsigned char *pixel_data = image_data + image_data[10] + 14;

    for (int i = 0; i < height; i += 2) { // Only skip every other row to maintain aspect ratio
        for (int j = 0; j < width; j++) {
            int grayscale_value = 0.299 * pixel_data[3*j] + 0.587 * pixel_data[3*j+1] + 0.114 * pixel_data[3*j+2];
            int character_index = (num_chars - 1) * grayscale_value / 255;
            putchar(*ascii_chars[character_index]);
        }
        putchar('\n');
        pixel_data += 3 * width;
    }

    free(image_data);

    return 0;
}