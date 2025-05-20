//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_MAGIC_NUMBER 0x4D42
#define MAX_SIZE 1024

#pragma pack(push, 1)
typedef struct {
    short int magic_number;
    int size;
    short int reserved1;
    short int reserved2;
    int offset;
} bmp_file_header;

typedef struct {
    int size;
    int width;
    int height;
    short int planes;
    short int bit_count;
    int compression;
    int image_size;
    int ppm_x;
    int ppm_y;
    int clr_used;
    int clr_important;
} bmp_info_header;
#pragma pack(pop)

void hide_text_in_image(const char *image_path, const char *text_path, const char *output_path)
{
    FILE *image_file = fopen(image_path, "rb");
    if (!image_file) {
        printf("Error: could not open image file %s", image_path);
        exit(1);
    }

    bmp_file_header file_header;
    fread(&file_header, sizeof(bmp_file_header), 1, image_file);
    if (file_header.magic_number != BMP_MAGIC_NUMBER) {
        printf("Error: invalid BMP file format.\n");
        exit(1);
    }

    bmp_info_header info_header;
    fread(&info_header, sizeof(bmp_info_header), 1, image_file);

    if (info_header.bit_count != 24) {
        printf("Error: only 24-bit BMP files are supported.\n");
        exit(1);
    }

    int max_chars_to_hide = (info_header.width * info_header.height * 3) / 8;
    FILE *text_file = fopen(text_path, "rb");
    if (!text_file) {
        printf("Error: could not open text file %s", text_path);
        exit(1);
    }

    fseek(text_file, 0, SEEK_END);
    long text_size = ftell(text_file);
    if (text_size > max_chars_to_hide) {
        printf("Error: text is too large to hide in this image.");
        exit(1);
    }

    fseek(text_file, 0, SEEK_SET);
    char *text = calloc(text_size + 1, 1);
    fread(text, 1, text_size, text_file);

    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        printf("Error: could not open output file %s", output_path);
        exit(1);
    }

    fwrite(&file_header, sizeof(bmp_file_header), 1, output_file);
    fwrite(&info_header, sizeof(bmp_info_header), 1, output_file);

    fseek(image_file, file_header.offset, SEEK_SET);
    char *data = calloc(file_header.size - file_header.offset, 1);
    fread(data, 1, file_header.size - file_header.offset, image_file);

    int data_index = 0;
    int byte_index = 0;
    int bit_index = 0;
    while (byte_index < text_size) {
        unsigned char byte = text[byte_index];
        unsigned char bit = (byte >> bit_index) & 1;

        data[data_index] = (data[data_index] & ~1) | bit;

        bit_index++;
        if (bit_index == 8) {
            byte_index++;
            bit_index = 0;
        }

        data_index++;
    }

    fwrite(data, 1, file_header.size - file_header.offset, output_file);

    fclose(image_file);
    fclose(text_file);
    fclose(output_file);
    free(text);
    free(data);

    printf("Text hidden in image successfully!\n");
}

void extract_text_from_image(const char *image_path, const char *output_path)
{
    FILE *image_file = fopen(image_path, "rb");
    if (!image_file) {
        printf("Error: could not open image file %s", image_path);
        exit(1);
    }

    bmp_file_header file_header;
    fread(&file_header, sizeof(bmp_file_header), 1, image_file);
    if (file_header.magic_number != BMP_MAGIC_NUMBER) {
        printf("Error: invalid image file format.\n");
        exit(1);
    }

    bmp_info_header info_header;
    fread(&info_header, sizeof(bmp_info_header), 1, image_file);

    if (info_header.bit_count != 24) {
        printf("Error: only 24-bit BMP files are supported.\n");
        exit(1);
    }

    fseek(image_file, file_header.offset, SEEK_SET);
    char *data = calloc(file_header.size - file_header.offset, 1);
    fread(data, 1, file_header.size - file_header.offset, image_file);

    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        printf("Error: could not open output file %s", output_path);
        exit(1);
    }

    int data_index = 0;
    int byte_index = 0;
    int bit_index = 0;

    while (byte_index < MAX_SIZE) {
        unsigned char byte = 0;
        for (int i = 0; i < 8; i++) {
            unsigned char bit = data[data_index] & 1;
            byte |= bit << i;

            data_index++;
            bit_index++;

            if (bit_index == 8) {
                bit_index = 0;
                byte_index++;
            }

            if (byte_index == MAX_SIZE)
                break;
        }

        fwrite(&byte, 1, 1, output_file);

        if (byte_index == MAX_SIZE)
            break;
    }

    fclose(image_file);
    fclose(output_file);
    free(data);

    printf("Text extracted from image successfully!\n");
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Error: too few arguments.");
        exit(1);
    }

    if (strcmp(argv[1], "hide") == 0) {
        if (argc < 5) {
            printf("Error: too few arguments.");
            exit(1);
        }

        hide_text_in_image(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        if (argc < 4) {
            printf("Error: too few arguments.");
            exit(1);
        }

        extract_text_from_image(argv[2], argv[3]);
    } else {
        printf("Usage: %s [hide image_path text_path output_path | extract image_path output_path]\n", argv[0]);
        exit(1);
    }

    return 0;
}