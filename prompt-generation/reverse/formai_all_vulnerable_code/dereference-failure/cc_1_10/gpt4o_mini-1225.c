//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <dirent.h>
#include <math.h>

#define IMAGE_SIZE 128
#define NUM_CLASSES 10

struct Image {
    unsigned char data[IMAGE_SIZE][IMAGE_SIZE][3]; // RGB image
    int label;
};

struct DataSet {
    struct Image *images;
    int size;
};

// A simple function to calculate pixel value differences
double calculate_distance(unsigned char img1[3], unsigned char img2[3]) {
    double diff = 0.0;
    for (int i = 0; i < 3; i++) {
        diff += pow((img1[i] - img2[i]), 2);
    }
    return sqrt(diff);
}

// Function to load images from a directory
struct DataSet load_images(const char *dir_path) {
    struct DataSet dataset;
    dataset.size = 0;
    dataset.images = malloc(1000 * sizeof(struct Image)); // Adjust the size accordingly

    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (dir == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, entry->d_name);

            // Read JPEG image
            FILE *file = fopen(filepath, "rb");
            if (!file) {
                fprintf(stderr, "Could not open file: %s\n", filepath);
                continue;
            }

            struct jpeg_decompress_struct cinfo;
            struct jpeg_error_mgr jerr;
            cinfo.err = jpeg_std_error(&jerr);
            jpeg_create_decompress(&cinfo);
            jpeg_stdio_src(&cinfo, file);
            jpeg_read_header(&cinfo, TRUE);
            jpeg_start_decompress(&cinfo);

            struct Image img;
            img.label = -1; // Set a default label, you can modify this to include label extraction
            for (int y = 0; y < IMAGE_SIZE; y++) {
                for (int x = 0; x < IMAGE_SIZE; x++) {
                    unsigned char pixel[3];
                    if (cinfo.output_scanline < cinfo.output_height) {
                        jpeg_read_scanlines(&cinfo, &pixel, 1);
                        img.data[y][x][0] = pixel[0];
                        img.data[y][x][1] = pixel[1];
                        img.data[y][x][2] = pixel[2];
                    }
                }
            }

            jpeg_finish_decompress(&cinfo);
            fclose(file);
            dataset.images[dataset.size++] = img;
        }
    }
    closedir(dir);
    return dataset;
}

// Dummy classifier - nearest neighbor
int classify_image(struct Image *input_image, struct DataSet *training_set) {
    double min_distance = INFINITY;
    int best_label = -1;

    for (int i = 0; i < training_set->size; i++) {
        struct Image *train_img = &training_set->images[i];
        double distance = 0.0;

        for (int y = 0; y < IMAGE_SIZE; y++) {
            for (int x = 0; x < IMAGE_SIZE; x++) {
                distance += calculate_distance(train_img->data[y][x], input_image->data[y][x]);
            }
        }

        if (distance < min_distance) {
            min_distance = distance;
            best_label = train_img->label;
        }
    }

    return best_label;
}

void free_dataset(struct DataSet *dataset) {
    free(dataset->images);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <training_directory> <test_image>\n", argv[0]);
        return 1;
    }

    const char *train_dir = argv[1];
    const char *test_image_path = argv[2];

    // Load training images
    struct DataSet training_set = load_images(train_dir);
    printf("Loaded %d training images from %s\n", training_set.size, train_dir);

    // Load test image
    FILE *test_file = fopen(test_image_path, "rb");
    if (!test_file) {
        fprintf(stderr, "Could not open test image: %s\n", test_image_path);
        return 1;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, test_file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    struct Image input_image;
    for (int y = 0; y < IMAGE_SIZE; y++) {
        for (int x = 0; x < IMAGE_SIZE; x++) {
            unsigned char pixel[3];
            if (cinfo.output_scanline < cinfo.output_height) {
                jpeg_read_scanlines(&cinfo, &pixel, 1);
                input_image.data[y][x][0] = pixel[0];
                input_image.data[y][x][1] = pixel[1];
                input_image.data[y][x][2] = pixel[2];
            }
        }
    }
    jpeg_finish_decompress(&cinfo);
    fclose(test_file);

    // Classify the test image
    int predicted_label = classify_image(&input_image, &training_set);
    printf("Predicted label for test image: %d\n", predicted_label);

    // Clean up
    free_dataset(&training_set);
    return 0;
}