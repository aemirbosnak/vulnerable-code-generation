//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_DATA_SIZE 1000000

typedef struct {
    unsigned char* data;
    int width;
    int height;
} StegoImage;

void write_data(StegoImage* stego, unsigned char* data, int data_size) {
    int x, y;
    for (y = 0; y < stego->height; y++) {
        for (x = 0; x < stego->width; x++) {
            if (x % 2 == 0 && y % 2 == 0) {
                stego->data[y * stego->width + x] ^= data[y * data_size + x];
            }
        }
    }
}

int main() {
    StegoImage stego;
    unsigned char data[] = "Hello, World!";
    int data_size = strlen(data);

    stego.data = (unsigned char*)malloc(MAX_DATA_SIZE);
    if (stego.data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1;
    }
    stego.width = WIDTH;
    stego.height = HEIGHT;

    write_data(&stego, data, data_size);

    // Save the stego image to a file
    FILE* output = fopen("stego.bmp", "wb");
    if (output == NULL) {
        fprintf(stderr, "Error: Failed to open output file\n");
        free(stego.data);
        return 1;
    }
    fwrite(stego.data, 1, stego.width * stego.height * 3, output);
    fclose(output);

    printf("Stego image saved successfully!\n");

    free(stego.data);

    return 0;
}