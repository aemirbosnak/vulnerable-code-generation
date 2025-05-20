//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_IMAGE_SIZE 1024 * 1024
#define HEADER_SIZE 54 // BMP header size

typedef struct {
    uint8_t r, g, b;
} Pixel;

void embed_message(const char *input_image, const char *output_image, const char *message);
char *extract_message(const char *input_image);
Pixel *load_bmp(const char *filename, int *width, int *height);
void save_bmp(const char *filename, Pixel *data, int width, int height);
void clear_memory(Pixel *data);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s -e <input_image> <output_image> <message>\n", argv[0]);
        printf("       %s -d <input_image>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "-e") == 0) {
        embed_message(argv[2], argv[3], argv[4]);
        printf("Message embedded successfully.\n");
    } else if (strcmp(argv[1], "-d") == 0) {
        char *extracted_message = extract_message(argv[2]);
        if (extracted_message) {
            printf("Extracted Message: %s\n", extracted_message);
            free(extracted_message);
        } else {
            printf("No message found in the image.\n");
        }
    } else {
        printf("Invalid option. Use -e for embedding and -d for detection.\n");
    }
    
    return 0;
}

void embed_message(const char *input_image, const char *output_image, const char *message) {
    int width, height;
    Pixel *image_data = load_bmp(input_image, &width, &height);
    if (!image_data) {
        fprintf(stderr, "Error loading image.\n");
        return;
    }

    // Check if the message can fit in the image
    size_t message_length = strlen(message);
    if (message_length > MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Message is too long to embed.\n");
        clear_memory(image_data);
        return;
    }

    // Embedding the message
    for (size_t i = 0; i < message_length; i++) {
        Pixel *pixel = &image_data[i]; // Select pixel in sequence
        pixel->r = (pixel->r & 0xFE) | ((message[i] >> 7) & 0x01); // LSB of red
        pixel->g = (pixel->g & 0xFE) | ((message[i] >> 6) & 0x01); // LSB of green
        pixel->b = (pixel->b & 0xFE) | ((message[i] >> 5) & 0x01); // LSB of blue
    }
    
    // Saving output
    save_bmp(output_image, image_data, width, height);
    clear_memory(image_data);
}

char *extract_message(const char *input_image) {
    int width, height;
    Pixel *image_data = load_bmp(input_image, &width, &height);
    if (!image_data) {
        fprintf(stderr, "Error loading image.\n");
        return NULL;
    }

    char *message = malloc(MAX_MESSAGE_SIZE + 1);
    if (!message) {
        fprintf(stderr, "Memory allocation failed.\n");
        clear_memory(image_data);
        return NULL;
    }
    size_t msg_index = 0;

    // Extracting the message
    for (size_t i = 0; i < MAX_MESSAGE_SIZE; i++) {
        if (msg_index >= MAX_MESSAGE_SIZE) break;
        char extracted_char = 0;
        extracted_char |= (image_data[i].r & 0x01) << 7;
        extracted_char |= (image_data[i].g & 0x01) << 6;
        extracted_char |= (image_data[i].b & 0x01) << 5;
        message[msg_index++] = extracted_char;

        // Stop if we reach null termination
        if (extracted_char == '\0') break;
    }

    clear_memory(image_data);
    return message;
}

Pixel *load_bmp(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }
    
    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);
    fseek(file, HEADER_SIZE, SEEK_SET);

    Pixel *data = malloc((*width) * (*height) * sizeof(Pixel));
    fread(data, sizeof(Pixel), (*width) * (*height), file);
    
    fclose(file);
    return data;
}

void save_bmp(const char *filename, Pixel *data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving image.\n");
        return;
    }

    // Create a simple BMP header
    uint8_t header[HEADER_SIZE] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 
        54, 0, 0, 0, 40, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 24, 0
    };
    int image_size = width * height * sizeof(Pixel);
    int file_size = HEADER_SIZE + image_size;

    header[2] = (uint8_t)(file_size);
    header[3] = (uint8_t)(file_size >> 8);
    header[4] = (uint8_t)(file_size >> 16);
    header[5] = (uint8_t)(file_size >> 24);
    header[18] = (uint8_t)(width);
    header[19] = (uint8_t)(width >> 8);
    header[20] = (uint8_t)(width >> 16);
    header[21] = (uint8_t)(width >> 24);
    header[22] = (uint8_t)(height);
    header[23] = (uint8_t)(height >> 8);
    header[24] = (uint8_t)(height >> 16);
    header[25] = (uint8_t)(height >> 24);
    
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, file);
    fwrite(data, sizeof(Pixel), width * height, file);
    fclose(file);
}

void clear_memory(Pixel *data) {
    free(data);
}