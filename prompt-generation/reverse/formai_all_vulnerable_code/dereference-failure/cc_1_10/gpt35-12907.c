//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Function to resize image to maximum width and height
unsigned char* resize(unsigned char* image, int width, int height, int max_width, int max_height) {
    unsigned char* resized = (unsigned char*)malloc(sizeof(unsigned char) * max_width * max_height);
    int scale_w = width / max_width;
    int scale_h = height / max_height;

    for(int y = 0; y < max_height; y++) {
        for(int x = 0; x < max_width; x++) {
            int src_x = x * scale_w;
            int src_y = y * scale_h;
            int src_offset = (src_y * width) + src_x;
            int dst_offset = (y * max_width) + x;

            resized[dst_offset] = image[src_offset];
        }
    }

    return resized;
}

// Function to convert image to ASCII art
void convert_ascii(unsigned char* image, int width, int height) {
    char ascii_chars[] = {'@', '#', '$', '%', 'x', '*', 'o', '/', '!', ';', '.', ' '};

    int num_chars = sizeof(ascii_chars) / sizeof(char);
    int brightness_interval = 256 / num_chars;

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int offset = (y * width) + x;
            int brightness = image[offset];

            int char_index = brightness / brightness_interval;
            if(char_index >= num_chars) {
                char_index = num_chars - 1;
            }

            printf("%c", ascii_chars[char_index]);
        }

        printf("\n");
    }
}

int main() {
    unsigned char image[MAX_WIDTH * MAX_HEIGHT];
    int width, height;

    printf("Enter image width and height (up to %d x %d): ", MAX_WIDTH, MAX_HEIGHT);
    scanf("%d %d", &width, &height);

    printf("Enter image data (0 to 255):\n");
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int offset = (y * width) + x;
            int val;
            scanf("%d", &val);

            if(val < 0) {
                val = 0;
            } else if(val > 255) {
                val = 255;
            }

            image[offset] = (unsigned char)val;
        }
    }

    int max_width, max_height;
    printf("Enter maximum width and height for ASCII art: ");
    scanf("%d %d", &max_width, &max_height);

    unsigned char* resized_image = resize(image, width, height, max_width, max_height);

    convert_ascii(resized_image, max_width, max_height);

    free(resized_image);

    return 0;
}