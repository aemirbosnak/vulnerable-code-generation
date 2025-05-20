//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 100000

void hide_message(char *image_path, char *message, char *output_image_path);
void extract_message(char *image_path);

int main(int argc, char *argv[]) {
    if (argc == 4 && strcmp(argv[1], "-h") == 0) {
        hide_message(argv[2], argv[3], "./output.png");
    } else if (argc == 3 && strcmp(argv[1], "-e") == 0) {
        extract_message(argv[2]);
    } else {
        printf("Invalid arguments.\nUsage: \n\t-h <image_path> <message> - to hide message in image.\n\t-e <image_path> - to extract message from image.\n");
    }
    return 0;
}

void hide_message(char *image_path, char *message, char *output_image_path) {
    FILE *input_image_file = fopen(image_path, "rb");
    if (input_image_file == NULL) {
        printf("Error: cannot open \"%s\" file.\n", image_path);
        exit(1);
    }

    fseek(input_image_file, 0L, SEEK_END);
    int image_size = ftell(input_image_file);
    fseek(input_image_file, 0L, SEEK_SET);

    char *image_data = malloc((size_t) image_size * sizeof(char));
    fread(image_data, sizeof(char), (size_t) image_size, input_image_file);

    char *data_to_hide = malloc(DATA_SIZE * sizeof(char));
    strcpy(data_to_hide, message);

    // add null terminating character to data_to_hide
    int i;
    for (i = strlen(message); i < DATA_SIZE; i++) {
        data_to_hide[i] = '\0';
    }

    // hide data in the image
    for (i = 0; i < DATA_SIZE; i++) {
        // change the least significant bit of the image byte to the data bit
        image_data[i] = (image_data[i] & ~1) | (data_to_hide[i] & 1);
    }

    // save the modified image
    FILE *output_image_file = fopen(output_image_path, "wb");
    fwrite(image_data, sizeof(char), (size_t) image_size, output_image_file);
    fclose(output_image_file);

    printf("Data has been successfully hidden in \"%s\" file.\n", output_image_path);

    fclose(input_image_file);
    free(image_data);
    free(data_to_hide);
}

void extract_message(char *image_path) {
    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error: cannot open \"%s\" file.\n", image_path);
        exit(1);
    }

    fseek(image_file, 0L, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    char *image_data = malloc((size_t) image_size * sizeof(char));
    fread(image_data, sizeof(char), (size_t) image_size, image_file);

    char *extracted_data = malloc(DATA_SIZE * sizeof(char));
    int i;
    for (i = 0; i < DATA_SIZE; i++) {
        extracted_data[i] = (image_data[i] & 1) + '0';
    }

    // remove padding
    i = DATA_SIZE - 1;
    while (extracted_data[i] == '0') {
        extracted_data[i--] = '\0';
    }

    printf("%s\n", extracted_data);

    fclose(image_file);
    free(image_data);
    free(extracted_data);
}