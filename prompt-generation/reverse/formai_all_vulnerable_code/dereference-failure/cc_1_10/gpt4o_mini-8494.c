//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>
#include <math.h>
#include <dirent.h>

#define IMAGE_SIZE 256
#define TRAINING_IMAGES 100
#define TEST_IMAGES 20
#define LABELS 10

// Function to read JPEG files into a pixel array
unsigned char* read_jpeg_file(const char* filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE* infile = fopen(filename, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Error opening JPEG file %s!\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    unsigned char* buffer = (unsigned char*)malloc(IMAGE_SIZE * IMAGE_SIZE * 3);
    unsigned char* row_pointer[1];

    int row_stride = IMAGE_SIZE * 3;
    while (cinfo.output_scanline < cinfo.output_height) {
        row_pointer[0] = buffer + row_stride * cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    
    return buffer;
}

// Function to compute the histogram of colors in an image
void compute_histogram(unsigned char* img, int* histogram) {
    memset(histogram, 0, 256 * sizeof(int));
    for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE * 3; i++) {
        histogram[img[i]]++;
    }
}

// Function to calculate similarity between histograms
double compare_histograms(int* h1, int* h2) {
    double distance = 0;
    for (int i = 0; i < 256; i++) {
        distance += fabs(h1[i] - h2[i]);
    }
    return distance;
}

// Function to classify the image based on histogram comparison
int classify_image(unsigned char* test_img, int training_histograms[][256], int num_labels) {
    int test_histogram[256];
    compute_histogram(test_img, test_histogram);

    double min_distance = INFINITY;
    int best_label = -1;
    
    for (int i = 0; i < num_labels; i++) {
        double distance = compare_histograms(test_histogram, training_histograms[i]);
        if (distance < min_distance) {
            min_distance = distance;
            best_label = i;
        }
    }
    
    return best_label;
}

// Main function to read images from directories and classify them
int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <training_directory> <test_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int training_histograms[LABELS][256];
    char training_images[TRAINING_IMAGES][256];
    int num_training_images = 0;

    // Read training images and compute their histograms
    DIR* dir = opendir(argv[1]);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL && num_training_images < TRAINING_IMAGES) {
        if (entry->d_type == DT_REG) {
            snprintf(training_images[num_training_images], 256, "%s/%s", argv[1], entry->d_name);
            unsigned char* img = read_jpeg_file(training_images[num_training_images]);
            compute_histogram(img, training_histograms[num_training_images]);
            free(img);
            num_training_images++;
        }
    }
    closedir(dir);

    // Read test images and classify them
    DIR* test_dir = opendir(argv[2]);
    while ((entry = readdir(test_dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char test_img_path[256];
            snprintf(test_img_path, 256, "%s/%s", argv[2], entry->d_name);
            unsigned char* test_img = read_jpeg_file(test_img_path);
            int label = classify_image(test_img, training_histograms, num_training_images);
            printf("Image: %s classified as label: %d\n", test_img_path, label);
            free(test_img);
        }
    }
    closedir(test_dir);

    return EXIT_SUCCESS;
}