//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_NUM 2

typedef struct {
    unsigned char* img;
    int height;
    int width;
} Image;

Image* read_image(char* filename, int width, int height) {
    FILE* fp;
    Image *image;
    unsigned char *img_data;
    int img_size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error: cannot open file");
        exit(EXIT_FAILURE);
    }

    image = (Image *) malloc(sizeof(Image));
    image->width = width;
    image->height = height;

    img_size = width * height * sizeof(unsigned char);
    img_data = (unsigned char *) malloc(img_size);

    fread(img_data, sizeof(unsigned char), img_size, fp);
    fclose(fp);

    image->img = img_data;
    return image;
}

void write_image(char* filename, Image* image) {
    FILE* fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error: cannot open file");
        exit(EXIT_FAILURE);
    }

    fwrite(image->img, image->height * image->width, sizeof(unsigned char), fp);
    fclose(fp);
}

void* brightness_contrast(void* arg) {
    Image* image = (Image*) arg;
    int i, j;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->img[i * image->width + j] = image->img[i * image->width + j] * 1.5 + 30;
        }
    }
    return NULL;
}

void* flip_image(void* arg) {
    Image* image = (Image*) arg;
    int i, j;
    unsigned char c;
    unsigned char* temp_row;

    temp_row = (unsigned char*) malloc(image->width * sizeof(unsigned char));

    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            c = image->img[i * image->width + j];
            image->img[i * image->width + j] = image->img[(image->height - i - 1) * image->width + j];
            image->img[(image->height - i - 1) * image->width + j] = c;
        }
    }

    free(temp_row);
    return NULL;
}

int main(int argc, char* argv[]) {
    Image* image;
    pthread_t threads[THREADS_NUM];
    int i, rc;

    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <image_width>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int width = atoi(argv[3]);
    int height = 0;
    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error: cannot open file");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    height = ftell(fp) / width;
    fseek(fp, 0L, SEEK_SET);
    fclose(fp);

    image = read_image(argv[1], width, height);

    // Create the threads
    rc = pthread_create(&threads[0], NULL, brightness_contrast, (void*) image);
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&threads[1], NULL, flip_image, (void*) image);
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(EXIT_FAILURE);
    }

    // Wait for the threads to complete
    for (i = 0; i < THREADS_NUM; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    write_image(argv[2], image);

    free(image->img);
    free(image);

    pthread_exit(NULL);
}