//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    unsigned char *image;
    int width;
    int height;
    char *watermark;
    int watermark_length;
} watermark_data;

void *embed_watermark(void *args) {
    watermark_data *data = (watermark_data *)args;
    
    int i, j, k;
    int watermark_index = 0;
    
    for (i = 0; i < data->height; i++) {
        for (j = 0; j < data->width; j++) {
            for (k = 0; k < 3; k++) {
                // Embed the watermark bit into the least significant bit of the pixel
                data->image[i * data->width * 3 + j * 3 + k] &= ~1;
                data->image[i * data->width * 3 + j * 3 + k] |= (data->watermark[watermark_index] & 1);
                
                // Increment the watermark index
                watermark_index++;
            }
        }
    }
    
    return NULL;
}

void *extract_watermark(void *args) {
    watermark_data *data = (watermark_data *)args;
    
    int i, j, k;
    int watermark_index = 0;
    char extracted_watermark[data->watermark_length + 1];
    
    for (i = 0; i < data->height; i++) {
        for (j = 0; j < data->width; j++) {
            for (k = 0; k < 3; k++) {
                // Extract the watermark bit from the least significant bit of the pixel
                extracted_watermark[watermark_index] = (data->image[i * data->width * 3 + j * 3 + k] & 1) + '0';
                
                // Increment the watermark index
                watermark_index++;
            }
        }
    }
    
    extracted_watermark[watermark_index] = '\0';
    
    printf("Extracted watermark: %s\n", extracted_watermark);
    
    return NULL;
}

int main() {
    // Load the image
    unsigned char *image = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 3);
    FILE *image_file = fopen("image.bmp", "rb");
    fread(image, 1, IMAGE_WIDTH * IMAGE_HEIGHT * 3, image_file);
    fclose(image_file);
    
    // Load the watermark
    char *watermark = (char *)malloc(100);
    FILE *watermark_file = fopen("watermark.txt", "r");
    fread(watermark, 1, 100, watermark_file);
    fclose(watermark_file);
    
    // Create the watermark data structure
    watermark_data data;
    data.image = image;
    data.width = IMAGE_WIDTH;
    data.height = IMAGE_HEIGHT;
    data.watermark = watermark;
    data.watermark_length = strlen(watermark);
    
    // Create the threads
    pthread_t embed_thread, extract_thread;
    
    // Start the embedding thread
    pthread_create(&embed_thread, NULL, embed_watermark, &data);
    
    // Start the extraction thread
    pthread_create(&extract_thread, NULL, extract_watermark, &data);
    
    // Wait for the threads to finish
    pthread_join(embed_thread, NULL);
    pthread_join(extract_thread, NULL);
    
    // Save the watermarked image
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    fwrite(image, 1, IMAGE_WIDTH * IMAGE_HEIGHT * 3, watermarked_image_file);
    fclose(watermarked_image_file);
    
    // Free the allocated memory
    free(image);
    free(watermark);
    
    return 0;
}