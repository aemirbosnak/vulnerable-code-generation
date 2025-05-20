//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

char* convert_to_ascii(char pixel);
void convert_image(char* img_path);

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: ./converter <image_path>\n");
        return 1;
    }

    char* img_path = argv[1];

    convert_image(img_path);

    return 0;
}

char* convert_to_ascii(char pixel){
    char* ascii_chars = " .:-=+*#%@";
    int index = ((int) pixel) * strlen(ascii_chars) / 256;
    char* ascii_char = malloc(sizeof(char));
    ascii_char[0] = ascii_chars[index];
    return ascii_char;
}

void convert_image(char* img_path){
    FILE* img_file = fopen(img_path, "r");

    if(!img_file){
        printf("Error: could not open image file.\n");
        exit(1);
    }

    int i, j, width, height, color_depth;

    // Get height, width, and color depth from header
    fscanf(img_file, "P3\n%d %d\n%d\n", &width, &height, &color_depth);

    if(width > MAX_WIDTH || height > MAX_HEIGHT){
        printf("Error: image dimensions too large.\n");
        exit(1);
    }

    char pixel[3];

    // Read pixels from file
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            fscanf(img_file, "%s", pixel);
            char* ascii_char = convert_to_ascii(pixel[0]);
            printf("%s", ascii_char);
            free(ascii_char);
        }
        printf("\n");
    }

    fclose(img_file);
}