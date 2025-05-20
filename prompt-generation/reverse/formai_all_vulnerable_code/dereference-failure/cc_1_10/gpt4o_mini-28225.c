//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PIXEL_CHANNELS 3 // RGB
#define MAX_MESSAGE_LENGTH 1024
#define MESSAGE_END_FLAG 0x00

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

Image* load_image(const char* filename, int* width, int* height);
void save_image(const char* filename, Image* img);
void embed_message(Image* img, const char* message);
char* extract_message(Image* img);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <image_path> <output_path/message>\n", argv[0]);
        return 1;
    }

    const char *action = argv[1];
    const char *image_path = argv[2];
    const char *output_path = argv[3];
    int width, height;

    Image* img = load_image(image_path, &width, &height);
    if (!img) {
        printf("Error loading image\n");
        return 1;
    }

    if (strcmp(action, "embed") == 0) {
        const char *message = output_path; // Treat this as the message to embed
        embed_message(img, message);
        save_image(image_path, img);
        printf("Message embedded successfully.\n");
    } else if (strcmp(action, "extract") == 0) {
        char *extracted_message = extract_message(img);
        if (extracted_message) {
            printf("Extracted Message: %s\n", extracted_message);
            free(extracted_message);
        } else {
            printf("No message found in the image.\n");
        }
    } else {
        printf("Unknown action. Use 'embed' or 'extract'.\n");
    }

    free(img->pixels);
    free(img);
    return 0;
}

Image* load_image(const char* filename, int* width, int* height) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    // Simple PPM format loader (P6)
    fscanf(f, "P6\n%d %d\n255\n", width, height);
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = *width;
    img->height = *height;
    img->pixels = (Pixel*)malloc(*width * *height * sizeof(Pixel));
    
    fread(img->pixels, sizeof(Pixel), *width * *height, f);
    fclose(f);
    
    return img;
}

void save_image(const char* filename, Image* img) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;

    fprintf(f, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
}

void embed_message(Image* img, const char* message) {
    size_t msg_len = strlen(message);
    if (msg_len > MAX_MESSAGE_LENGTH) {
        printf("Message is too long. Max length is %d\n", MAX_MESSAGE_LENGTH);
        return;
    }

    for (size_t i = 0; i < msg_len; ++i) {
        uint8_t char_value = (uint8_t)message[i];
        for (int j = 0; j < PIXEL_CHANNELS; ++j) {
            if (i * PIXEL_CHANNELS + j < img->width * img->height) {
                img->pixels[i * PIXEL_CHANNELS + j].red = (char_value >> (2 * (2 - j))) & 0x01 ? 
                    (img->pixels[i * PIXEL_CHANNELS + j].red | 0x01) : 
                    (img->pixels[i * PIXEL_CHANNELS + j].red & 0xFE);
            }
        }
    }
    
    // Mark the end of the message
    size_t end_pos = msg_len * PIXEL_CHANNELS;
    for (int j = 0; j < PIXEL_CHANNELS; ++j) {
        if (end_pos + j < img->width * img->height) {
            img->pixels[end_pos + j].red = MESSAGE_END_FLAG;
        }
    }
}

char* extract_message(Image* img) {
    char *message = (char*)malloc(MAX_MESSAGE_LENGTH + 1);
    size_t index = 0, pixels_count = img->width * img->height;

    for (size_t i = 0; i < pixels_count; ++i) {
        if (index >= MAX_MESSAGE_LENGTH) break;
        
        uint8_t char_value = 0;
        for (int j = 0; j < PIXEL_CHANNELS; ++j) {
            char_value |= (img->pixels[i].red & 0x01) << (2 - j);
            img->pixels[i].red >>= 1; // Move to the next bit
        }

        if (char_value == MESSAGE_END_FLAG) {
            break;
        }
        
        message[index++] = char_value;
    }
    
    message[index] = '\0'; // Null-terminate the string
    return message;
}