//FormAI DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

char* readMessage(FILE* input) {
    char* message = malloc(1);
    int message_size = 0;
    char c;
    while ((c = fgetc(input)) != EOF) {
        message = realloc(message, message_size + 2);
        message[message_size++] = c;
        message[message_size] = '\0';
    }
    return message;
}

void writeMessage(FILE* output, char* message) {
    fprintf(output, "%s", message);
}

void hideMessage(Image* image, char* message) {
    int bit_count = 0;
    int message_size = strlen(message);
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            unsigned char* pixel = &image->data[(j * image->width + i) * 3];
            if (bit_count < message_size * 8) {
                int bit = (message[bit_count / 8] >> (bit_count % 8)) & 1;
                *pixel = (*pixel & 0xfe) | bit;
                bit_count++;
            }
        }
    }
}

char* extractMessage(Image* image) {
    char* message = malloc(1);
    int message_size = 0;
    int bit_count = 0;
    char c = 0;
    while (1) {
        for (int i = 0; i < image->width && bit_count / 8 < message_size; i++) {
            for (int j = 0; j < image->height && bit_count / 8 < message_size; j++) {
                unsigned char* pixel = &image->data[(j * image->width + i) * 3];
                c = (c << 1) | (*pixel & 1);
                if (++bit_count % 8 == 0) {
                    message = realloc(message, message_size + 2);
                    message[message_size++] = c;
                    message[message_size] = '\0';
                    c = 0;
                }
            }
        }
        if (bit_count % 8 != 0) {
            message[message_size++] = c;
            message[message_size] = '\0';
        }
        else {
            break;
        }
    }
    return message;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: stego <input_file> <output_file> [message_file]\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "rb");
    if (!input) {
        printf("Error: could not open %s\n", argv[1]);
        return 1;
    }

    Image image;
    fread(&image.width, sizeof(image.width), 1, input);
    fread(&image.height, sizeof(image.height), 1, input);
    image.data = malloc(image.width * image.height * 3);
    fread(image.data, image.width * image.height * 3, 1, input);
    fclose(input);

    if (argc > 3) {
        FILE* message_file = fopen(argv[3], "r");
        if (!message_file) {
            printf("Error: could not open %s\n", argv[3]);
            return 1;
        }
        char* message = readMessage(message_file);
        fclose(message_file);
        hideMessage(&image, message);
    }
    else {
        char* message = extractMessage(&image);
        printf("%s", message);
        free(message);
    }

    FILE* output = fopen(argv[2], "wb");
    if (!output) {
        printf("Error: could not open %s\n", argv[2]);
        return 1;
    }
    fwrite(&image.width, sizeof(image.width), 1, output);
    fwrite(&image.height, sizeof(image.height), 1, output);
    fwrite(image.data, image.width * image.height * 3, 1, output);
    fclose(output);

    free(image.data);
    return 0;
}