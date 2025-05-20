//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>

#define WIDTH  512
#define HEIGHT 512

typedef struct {
    uint8_t *image;
    int start_row;
    int end_row;
    int width;
} ImageData;

typedef struct {
    uint8_t *image;
    int width;
    int height;
    float brightness;
    float contrast;
} BrightnessContrastData;

void *flip_image(void *arg) {
    ImageData *data = (ImageData *)arg;
    int width = data->width;
    uint8_t *image = data->image;
    
    for (int row = data->start_row; row < data->end_row; row++) {
        for (int col = 0; col < width / 2; col++) {
            uint8_t temp = image[row * width + col];
            image[row * width + col] = image[row * width + (width - 1 - col)];
            image[row * width + (width - 1 - col)] = temp;
        }
    }
    pthread_exit(0);
}

void *adjust_brightness_contrast(void *arg) {
    BrightnessContrastData *data = (BrightnessContrastData *)arg;
    
    for (int i = 0; i < data->width * data->height; i++) {
        int pixel = (int)data->image[i];
        pixel = (int)((pixel - 128) * data->contrast + 128 + data->brightness);
        if (pixel < 0) pixel = 0;
        if (pixel > 255) pixel = 255;
        data->image[i] = (uint8_t)pixel;
    }
    pthread_exit(0);
}

void initialize_image(uint8_t *image) {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = i % 256; // Example pattern
    }
}

int main() {
    pthread_t threads[2];
    uint8_t *image = (uint8_t *)malloc(WIDTH * HEIGHT);
    
    initialize_image(image);

    // Flip the image using two threads
    ImageData flip_data1 = { image, 0, HEIGHT / 2, WIDTH };
    ImageData flip_data2 = { image, HEIGHT / 2, HEIGHT, WIDTH };

    pthread_create(&threads[0], NULL, flip_image, (void *)&flip_data1);
    pthread_create(&threads[1], NULL, flip_image, (void *)&flip_data2);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    // Adjust brightness and contrast
    BrightnessContrastData bc_data = { image, WIDTH, HEIGHT, 50, 1.2 }; // Increase brightness by 50 and contrast by 1.2

    pthread_t bc_thread;
    pthread_create(&bc_thread, NULL, adjust_brightness_contrast, (void *)&bc_data);
    pthread_join(bc_thread, NULL);
    
    // Saving the final image to a file (for demonstration purposes)
    FILE *out_file = fopen("output_image.raw", "wb");
    fwrite(image, sizeof(uint8_t), WIDTH * HEIGHT, out_file);
    fclose(out_file);
    
    free(image);
    return 0;
}