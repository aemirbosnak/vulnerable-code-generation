//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET ".,:;!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`"

void print_image_ascii(unsigned char *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int value = (int) image[(i * width + j) * 3];
            int index = value % 16;
            printf("%c", CHAR_SET[index]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        printf("Error: could not open input image file.\n");
        return 1;
    }

    fseek(fp_in, 0, SEEK_END);
    long file_size = ftell(fp_in);
    fseek(fp_in, 0, SEEK_SET);

    unsigned char *image_data = (unsigned char *) malloc(file_size);
    if (image_data == NULL) {
        printf("Error: could not allocate memory for image data.\n");
        fclose(fp_in);
        return 1;
    }

    size_t bytes_read = fread(image_data, 1, file_size, fp_in);
    if (bytes_read!= file_size) {
        printf("Error: could not read entire input image file.\n");
        free(image_data);
        fclose(fp_in);
        return 1;
    }

    fclose(fp_in);

    int width, height;
    unsigned char *bmp_header = image_data;
    width = *(int *) (bmp_header + 18);
    height = *(int *) (bmp_header + 22);

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error: could not open output ASCII art file.\n");
        free(image_data);
        return 1;
    }

    int row_size = (width * 3 + 2) / 3;
    int padding = (MAX_WIDTH - row_size) / 2;

    print_image_ascii(image_data + 54, width, height);

    fclose(fp_out);

    free(image_data);

    return 0;
}