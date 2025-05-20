//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define MAX_FILENAME_LEN 128
#define MAX_THREADS 10

typedef struct {
    unsigned char *image_data;
    int image_height;
    int image_width;
    int brightness;
    int contrast;
    char flip_axis; /* 'h' for horizontal, 'v' for vertical */
} image_t;

/* Functions to flip an image horizontally and vertically */
void flip_horizontally(image_t *in_img, image_t *out_img) {
    int i, j;
    int pixel_count = in_img->image_height * in_img->image_width;
    for (i = 0; i < pixel_count; i++) {
        out_img->image_data[i] = in_img->image_data[i ^ 1];
    }
    out_img->flip_axis = 'h';
}

void flip_vertically(image_t *in_img, image_t *out_img) {
    int i, j;
    int rows = in_img->image_height;
    int cols = in_img->image_width;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            out_img->image_data[(rows - i - 1) * cols + j] =
                in_img->image_data[i * cols + j];
        }
    }
    out_img->flip_axis = 'v';
}

/* Function to adjust image brightness */
void adjust_brightness(image_t *in_img, image_t *out_img) {
    int i;
    int pixel_count = in_img->image_height * in_img->image_width;
    int offset = in_img->brightness;
    for (i = 0; i < pixel_count; i++) {
        int pixel = (int)in_img->image_data[i] + offset;
        out_img->image_data[i] = pixel > 255 ? 255 :
            (pixel < 0 ? 0 : (unsigned char)pixel);
    }
    out_img->brightness = in_img->brightness;
    out_img->contrast = in_img->contrast;
    out_img->flip_axis = in_img->flip_axis;
}

/* Function to adjust image contrast */
void adjust_contrast(image_t *in_img, image_t *out_img) {
    int i;
    int pixel_count = in_img->image_height * in_img->image_width;
    double factor = (259.0 * (in_img->contrast + 255.0)) /
        (255.0 * (259.0 - in_img->contrast));
    for (i = 0; i < pixel_count; i++) {
        int pixel = (int)(factor * ((double)in_img->image_data[i] - 128) + 128);
        out_img->image_data[i] = pixel > 255 ? 255 :
            (pixel < 0 ? 0 : (unsigned char)pixel);
    }
    out_img->brightness = in_img->brightness;
    out_img->contrast = in_img->contrast;
    out_img->flip_axis = in_img->flip_axis;
}

/* Thread function to process image tasks */
void *process_image_task(void *arg) {
    image_t *input_image = (image_t *)arg;
    int result;
    char output_filename[MAX_FILENAME_LEN];
    image_t output_image;
    output_image.image_height = input_image->image_height;
    output_image.image_width = input_image->image_width;
    output_image.image_data = malloc(input_image->image_height *
                                      input_image->image_width *
                                      sizeof(unsigned char));
    if (output_image.image_data == NULL) {
        fprintf(stderr, "Could not allocate memory for output image: %s\n",
                strerror(errno));
        pthread_exit(NULL);
    }

    /* Perform image processing based on the flip axis specified */
    if (input_image->flip_axis == 'h') {
        flip_horizontally(input_image, &output_image);
        result = snprintf(output_filename, MAX_FILENAME_LEN, "result_flip_h.bmp");
    } else if (input_image->flip_axis == 'v') {
        flip_vertically(input_image, &output_image);
        result = snprintf(output_filename, MAX_FILENAME_LEN, "result_flip_v.bmp");
    } else if (input_image->brightness != 0) {
        adjust_brightness(input_image, &output_image);
        result = snprintf(output_filename, MAX_FILENAME_LEN, "result_brightness.bmp");
    } else if (input_image->contrast != 0) {
        adjust_contrast(input_image, &output_image);
        result = snprintf(output_filename, MAX_FILENAME_LEN, "result_contrast.bmp");
    }

    /* Write the output image to file */
    if (result >= MAX_FILENAME_LEN) {
        fprintf(stderr, "Output filename truncated: %s\n", output_filename);
    }
    FILE *f_out = fopen(output_filename, "wb");
    if (f_out == NULL) {
        fprintf(stderr, "Could not create output file: %s\n", strerror(errno));
        pthread_exit(NULL);
    }
    int pixel_count = output_image.image_height * output_image.image_width;
    unsigned char bmp_header[54] = {
        0x42, 0x4D, 0x36, 0x1C, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0x80, 0x02,
        0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x10, 0x1C, 0x00, 0x00, 0x13,
        0x0B, 0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    fwrite(bmp_header, sizeof(unsigned char), 54, f_out);
    fwrite(output_image.image_data, sizeof(unsigned char), pixel_count, f_out);
    fclose(f_out);

    free(output_image.image_data);
    pthread_exit(NULL);
}

int main() {
    char input_filename[MAX_FILENAME_LEN];
    image_t input_image;
    int result;

    /* Read the input image file */
    printf("Enter the input image file name (bmp format): ");
    if (fgets(input_filename, MAX_FILENAME_LEN, stdin) == NULL) {
        fprintf(stderr, "Could not read input filename: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    input_filename[strcspn(input_filename, "\r\n")] = '\0';
    FILE *f_in = fopen(input_filename, "rb");
    if (f_in == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    unsigned char bmp_header[54];
    result = fread(bmp_header, sizeof(unsigned char), 54, f_in);
    if (result != 54) {
        fprintf(stderr, "Could not read BMP header: %s\n", strerror(errno));
        fclose(f_in);
        exit(EXIT_FAILURE);
    }
    input_image.image_height = *(int *)&bmp_header[18];
    input_image.image_width = *(int *)&bmp_header[22];
    int image_size = input_image.image_height * input_image.image_width;
    input_image.image_data = malloc(image_size * sizeof(unsigned char));
    if (input_image.image_data == NULL) {
        fprintf(stderr, "Could not allocate memory for input image: %s\n",
                strerror(errno));
        fclose(f_in);
        exit(EXIT_FAILURE);
    }
    result = fread(input_image.image_data, sizeof(unsigned char), image_size, f_in);
    if (result != image_size) {
        fprintf(stderr, "Could not read input image data: %s\n", strerror(errno));
        fclose(f_in);
        free(input_image.image_data);
        exit(EXIT_FAILURE);
    }
    fclose(f_in);

    /* Prompt user for image processing tasks */
    int task_count = 0;
    pthread_t threads[MAX_THREADS];
    char task_input[MAX_FILENAME_LEN];
    while (task_count < MAX_THREADS) {
        printf("Enter one of the following image processing tasks:\n");
        printf("(1) Flip horizontally\n");
        printf("(2) Flip vertically\n");
        printf("(3) Adjust brightness\n");
        printf("(4) Adjust contrast\n");
        printf("(5) Exit\n");
        printf("Task %d: ", task_count+1);
        if (fgets(task_input, MAX_FILENAME_LEN, stdin) == NULL) {
            fprintf(stderr, "Could not read task input: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        task_input[strcspn(task_input, "\r\n")] = '\0';
        if (strcmp(task_input, "1") == 0) {
            input_image.brightness = 0;
            input_image.contrast = 0;
            input_image.flip_axis = 'h';
        } else if (strcmp(task_input, "2") == 0) {
            input_image.brightness = 0;
            input_image.contrast = 0;
            input_image.flip_axis = 'v';
        } else if (strcmp(task_input, "3") == 0) {
            printf("Enter the brightness offset (-255 to 255): ");
            if (fgets(task_input, MAX_FILENAME_LEN, stdin) == NULL) {
                fprintf(stderr, "Could not read brightness input: %s\n",
                        strerror(errno));
                exit(EXIT_FAILURE);
            }
            input_image.brightness = atoi(task_input);
            if (input_image.brightness < -255 || input_image.brightness > 255) {
                fprintf(stderr, "Invalid brightness offset entered: %d\n",
                        input_image.brightness);
                task_count--;
            }
            input_image.contrast = 0;
            input_image.flip_axis = 'n';
        } else if (strcmp(task_input, "4") == 0) {
            printf("Enter the contrast adjustment (-255 to 255): ");
            if (fgets(task_input, MAX_FILENAME_LEN, stdin) == NULL) {
                fprintf(stderr, "Could not read contrast input: %s\n",
                        strerror(errno));
                exit(EXIT_FAILURE);
            }
            input_image.contrast = atoi(task_input);
            if (input_image.contrast < -255 || input_image.contrast > 255) {
                fprintf(stderr, "Invalid contrast adjustment entered: %d\n",
                        input_image.contrast);
                task_count--;
            }
            input_image.brightness = 0;
            input_image.flip_axis = 'n';
        } else if (strcmp(task_input, "5") == 0) {
            break;
        } else {
            fprintf(stderr, "Invalid task input entered: %s\n", task_input);
            task_count--;
        }
        /* Spawn new thread to process image task */
        if (pthread_create(&threads[task_count], NULL, process_image_task,
                           (void *)&input_image)) {
            fprintf(stderr, "Could not create thread for task %d: %s\n",
                    task_count+1, strerror(errno));
            exit(EXIT_FAILURE);
        }
        task_count++;
    }

    /* Wait for all threads to complete */
    int i;
    for (i = 0; i < task_count; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error waiting for thread %d: %s\n", i+1,
                    strerror(errno));
        }
    }

    free(input_image.image_data);
    exit(EXIT_SUCCESS);
}