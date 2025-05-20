//FormAI DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_SIZE 100
#define BUFFER_SIZE 250000

struct image {
    int width;
    int height;
    unsigned char *data;
};

// Function to read image from file into image struct
struct image *read_image(char *filename) {
    FILE *fp;
    struct image *img = malloc(sizeof(struct image));
    char format[3];

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Could not open image file.\n");
        exit(1);
    }

    // Read image format
    fscanf(fp, "%2s", format);
    if (strcmp(format, "P5") != 0) {
        printf("Image file format not supported.\n");
        exit(1);
    }

    // Read image dimensions
    fscanf(fp, "%d %d", &img->width, &img->height);

    // Skip max gray value
    fgetc(fp);

    // Allocate memory for image data
    img->data = malloc(img->width * img->height);

    // Read image data
    fread(img->data, img->width * img->height, 1, fp);

    fclose(fp);

    return img;
}

// Function to write image to file from image struct
void write_image(char *filename, struct image *img) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Could not open image file.\n");
        exit(1);
    }

    // Write image format
    fprintf(fp, "P5\n");

    // Write image dimensions
    fprintf(fp, "%d %d\n", img->width, img->height);

    // Write max gray value
    fprintf(fp, "255\n");

    // Write image data
    fwrite(img->data, img->width * img->height, 1, fp);

    fclose(fp);
}

// Function to hide message in image using LSB steganography
void hide_message(struct image *img, char *message) {
    int message_size = strlen(message);
    int i, j, k, idx = 0;
    unsigned char bit_mask = 1;
    unsigned char byte_mask = bit_mask << 7;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < 8; k++) {
                // Set bit at index idx of current image byte to bit at index idx of message byte
                if (idx < message_size) {
                    if ((message[idx] & bit_mask) != 0) {
                        img->data[i * img->width + j] |= byte_mask;
                    } else {
                        img->data[i * img->width + j] &= ~byte_mask;
                    }
                    idx++;
                } else {
                    return;
                }

                // Shift masks to next bit
                bit_mask <<= 1;
                byte_mask >>= 1;
                if (byte_mask == 0) {
                    bit_mask = 1;
                    byte_mask = bit_mask << 7;
                }
            }
        }
    }
}

// Function to retrieve message from image using LSB steganography
char *retrieve_message(struct image *img) {
    int i, j, k, idx = 0;
    unsigned char bit_mask = 1;
    unsigned char byte_mask = bit_mask << 7;
    char *message = malloc(BUFFER_SIZE * sizeof(char));

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < 8; k++) {
                // Read bit at index idx of current image byte
                if ((img->data[i * img->width + j] & byte_mask) != 0) {
                    message[idx] |= bit_mask;
                } else {
                    message[idx] &= ~bit_mask;
                }
                idx++;

                // Shift masks to next bit
                bit_mask <<= 1;
                byte_mask >>= 1;
                if (byte_mask == 0) {
                    bit_mask = 1;
                    byte_mask = bit_mask << 7;
                }

                // Check if message has been fully retrieved
                if (idx == BUFFER_SIZE) {
                    return message;
                }
            }
        }
    }

    return message;
}

int main() {
    char filename[FILENAME_SIZE];
    char message[BUFFER_SIZE];
    char *retrieved_message;
    struct image *img;

    // Read image from file
    printf("Enter name of image file: ");
    fgets(filename, FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;
    img = read_image(filename);

    // Hide message in image
    printf("Enter message to hide: ");
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;
    hide_message(img, message);

    // Write modified image to file
    printf("Enter name of modified image file: ");
    fgets(filename, FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;
    write_image(filename, img);

    // Retrieve message from image
    printf("Enter name of modified image file: ");
    fgets(filename, FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;
    img = read_image(filename);
    retrieved_message = retrieve_message(img);
    printf("Retrieved message: %s\n", retrieved_message);

    return 0;
}