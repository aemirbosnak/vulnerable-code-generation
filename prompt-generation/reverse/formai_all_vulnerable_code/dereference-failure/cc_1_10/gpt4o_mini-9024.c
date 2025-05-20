//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <unistd.h>
#include <dirent.h>
#include <math.h>

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128
#define NUM_CLASSES 3
#define MAX_FILES 100
#define BUFFER_SIZE 256

typedef struct {
    char name[BUFFER_SIZE];
    unsigned char pixels[IMAGE_HEIGHT][IMAGE_WIDTH][3]; // RGB
} Image;

const char *class_names[NUM_CLASSES] = {"cat", "dog", "horse"};
Image images[MAX_FILES];
int image_count = 0;

void read_jpeg_file(const char *filename, Image *img) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile;
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", filename);
        return;
    }
    
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);
    
    img->name[0] = '\0';
    strcat(img->name, filename);
    
    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *rowptr[1];
        rowptr[0] = img->pixels[cinfo.output_scanline];
        jpeg_read_scanlines(&cinfo, rowptr, 1);
    }
    
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

double euclidean_distance(unsigned char *a, unsigned char *b) {
    double sum = 0.0;
    for (int i = 0; i < 3; i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

int classify_image(Image *img) {
    unsigned char avg_pixel[3] = {0};
    int total_pixels = IMAGE_WIDTH * IMAGE_HEIGHT;
    
    for (int x = 0; x < IMAGE_WIDTH; x++) {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            avg_pixel[0] += img->pixels[y][x][0]; // R
            avg_pixel[1] += img->pixels[y][x][1]; // G
            avg_pixel[2] += img->pixels[y][x][2]; // B
        }
    }

    avg_pixel[0] /= total_pixels;
    avg_pixel[1] /= total_pixels;
    avg_pixel[2] /= total_pixels;

    double min_distance = 1e9;
    int class_index = -1;
    for (int i = 0; i < NUM_CLASSES; i++) {
        unsigned char class_avg_pixel[3] = {255, 255, 255}; // Placeholder for class average pixels
        double distance = euclidean_distance(avg_pixel, class_avg_pixel);

        if (distance < min_distance) {
            min_distance = distance;
            class_index = i;
        }
    }
    
    return class_index;
}

void load_images(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(directory)) == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", directory);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && image_count < MAX_FILES) {
            char filepath[BUFFER_SIZE];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            read_jpeg_file(filepath, &images[image_count]);
            image_count++;
        }
    }
    closedir(dir);
}

void display_results() {
    for (int i = 0; i < image_count; i++) {
        int class_index = classify_image(&images[i]);
        printf("Image: %s classified as: %s\n", images[i].name, class_names[class_index]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_with_jpeg_images>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_images(argv[1]);
    display_results();

    return EXIT_SUCCESS;
}