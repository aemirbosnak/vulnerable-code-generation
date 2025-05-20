//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <jpeglib.h>

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128
#define NUM_CLASSES 3
#define MAX_FILENAME_LEN 256

typedef struct {
    char *name;
    int label;
} Class;

// Global variables
Class classes[NUM_CLASSES] = {
    {"cat", 0},
    {"dog", 1},
    {"rabbit", 2}
};

unsigned char *load_image(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open image file");
        return NULL;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;

    unsigned char *buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_height * 3);
    unsigned char *p = buffer;
    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *row_pointer[1];
        row_pointer[0] = p;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
        p += cinfo.output_width * 3;
    }

    jpeg_finish_decompress(&cinfo);
    fclose(file);
    return buffer;
}

int classify_image(unsigned char *image_data) {
    // Dummy classification logic: checks average color
    long total_r = 0, total_g = 0, total_b = 0;
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT * 3; i += 3) {
        total_r += image_data[i];
        total_g += image_data[i + 1];
        total_b += image_data[i + 2];
    }
    int avg_r = total_r / (IMAGE_WIDTH * IMAGE_HEIGHT);
    int avg_g = total_g / (IMAGE_WIDTH * IMAGE_HEIGHT);
    int avg_b = total_b / (IMAGE_WIDTH * IMAGE_HEIGHT);

    // Simple color-based classification
    if (avg_r > avg_g && avg_r > avg_b) {
        return classes[1].label; // Dog
    } else if (avg_g > avg_r && avg_g > avg_b) {
        return classes[0].label; // Cat
    } else {
        return classes[2].label; // Rabbit
    }
}

void process_directory(const char *dir_name) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dir_name))) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir))) {
        // Only process .jpg files
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".jpg")) {
            char file_path[MAX_FILENAME_LEN];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);

            int width, height;
            unsigned char *image_data = load_image(file_path, &width, &height);
            if (!image_data) {
                continue;
            }
            unsigned char resized_image_data[IMAGE_WIDTH * IMAGE_HEIGHT * 3];

            // Dummy resize copy (in real cases, we should properly resize)
            memcpy(resized_image_data, image_data, IMAGE_WIDTH * IMAGE_HEIGHT * 3);

            int label = classify_image(resized_image_data);

            printf("Image: %s; Classified as: %s\n", entry->d_name, classes[label].name);
            free(image_data);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_directory(argv[1]);

    return EXIT_SUCCESS;
}