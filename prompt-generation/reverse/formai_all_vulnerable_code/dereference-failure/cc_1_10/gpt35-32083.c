//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

#define BMP_HEADER_SIZE 54

void flip_vertical(unsigned char *image, int width, int height) {
    int row_size = width * 3;
    unsigned char *row = (unsigned char*)malloc(sizeof(unsigned char) * row_size);
    for(int i = 0; i < height / 2; i++) {
        int y1 = i * row_size;
        int y2 = (height - 1 - i) * row_size;
        memcpy(row, &image[y1], row_size);
        memcpy(&image[y1], &image[y2], row_size);
        memcpy(&image[y2], row, row_size);
    }
    free(row);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Invalid usage. Expected usage: ./image_editor <input_file_path>.bmp <output_file_path>.bmp\n");
        return 1;
    }

    FILE *file_in = fopen(argv[1], "rb");
    if (file_in == NULL) {
        printf("Unable to open input file %s!\n", argv[1]);
        return 1;
    }

    fseek(file_in, 0, SEEK_END);
    long fsize = ftell(file_in);
    fseek(file_in, 0, SEEK_SET);

    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * fsize);
    fread(image_data, sizeof(unsigned char), fsize, file_in);
    fclose(file_in);

    int header_offset = *(int*)(&image_data[10]);
    int width = *(int*)(&image_data[18]);
    int height = *(int*)(&image_data[22]);
    unsigned char* image_pixels = &image_data[header_offset];

    flip_vertical(image_pixels, width, height);

    FILE *file_out = fopen(argv[2], "wb");
    fwrite(image_data, sizeof(unsigned char), fsize, file_out);
    fclose(file_out);

    free(image_data);

    printf("Operations completed successfully!\n");

    return 0;
}