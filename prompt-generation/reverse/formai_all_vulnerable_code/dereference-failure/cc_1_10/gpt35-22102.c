//FormAI DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t data_size;
    uint8_t *data;
} BMP_Image;

void hide_data_in_image(BMP_Image *image, char *message) {
    uint32_t message_len = strlen(message);
    uint32_t data_len = (message_len + 1) * 8;
    uint32_t max_data_len = image->width * image->height * 3;

    if (data_len > max_data_len) {
        printf("The message is too long to fit in the image.\n");
        exit(1);
    }

    uint32_t i = 0, j = 0, k = 0, l = 0, m = 0;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (l >= message_len) {
                image->data[k++] &= 0xFE;
                image->data[k++] &= 0xFE;
                image->data[k++] &= 0xFE;
                break;
            }

            char c = message[l++];
            for (m = 0; m < 8; m++) {
                uint8_t bit = (c >> m) & 1;

                if (bit) {
                    image->data[k] |= 1;
                } else {
                    image->data[k] &= 0xFE;
                }

                k++;

                if (k >= image->data_size) {
                    printf("Data overflowed the image.\n");
                    exit(1);
                }
            }
        }
    }
}

char *extract_data_from_image(BMP_Image *image) {
    uint32_t i = 0, j = 0, k = 0, bit_counter = 0;
    char message[256] = { 0 };

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (bit_counter >= 8) {
                bit_counter = 0;
                k++;

                if (message[k - 1] == '\0') {
                    return strdup(message);
                }
            }

            uint8_t bit = image->data[k] & 1;
            message[k] = (message[k] >> 1) | (bit << 7);

            bit_counter++;
            k++;

            if (k >= image->data_size) {
                printf("Data overflowed the image.\n");
                exit(1);
            }
        }
    }

    return NULL;
}

int main() {
    BMP_Image image;
    FILE *input_file = fopen("image.bmp", "rb");

    if (!input_file) {
        printf("The image file does not exist.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    uint32_t input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    image.data = malloc(input_file_size);

    if (!image.data) {
        printf("Failed to allocate memory for the image.\n");
        exit(1);
    }

    fread(image.data, 1, input_file_size, input_file);
    fclose(input_file);

    uint16_t *header = (uint16_t *)"BM";
    if (memcmp(image.data, header, 2) != 0) {
        printf("Invalid BMP header.\n");
        exit(1);
    }

    uint32_t data_offset = *(uint32_t *)(image.data + 10);
    image.width = *(uint32_t *)(image.data + 18);
    image.height = *(uint32_t *)(image.data + 22);
    image.data_size = input_file_size - data_offset;

    hide_data_in_image(&image, "This is a secret message.");

    char *message = extract_data_from_image(&image);
    printf("Extracted message: %s\n", message);
    free(message);

    FILE *output_file = fopen("output.bmp", "wb");

    if (!output_file) {
        printf("Failed to open the output file.\n");
        exit(1);
    }

    fwrite(image.data, 1, input_file_size, output_file);
    fclose(output_file);

    free(image.data);

    return 0;
}