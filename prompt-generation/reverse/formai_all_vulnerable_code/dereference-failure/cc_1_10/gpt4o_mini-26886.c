//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <jpeglib.h>

#define IMAGE_HEIGHT 128
#define IMAGE_WIDTH 128
#define NUM_CLASSES 3
#define MAX_IMAGES 1000

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int classId;
    Pixel image[IMAGE_HEIGHT][IMAGE_WIDTH];
} ImageData;

ImageData dataset[MAX_IMAGES];
int imageCount = 0;

void classifyImage(const ImageData *inputImage) {
    // Simple pixel comparison as the classification logic
    int rVal = 0, gVal = 0, bVal = 0;

    // Average pixel values for the input image
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            rVal += inputImage->image[i][j].r;
            gVal += inputImage->image[i][j].g;
            bVal += inputImage->image[i][j].b;
        }
    }

    rVal /= (IMAGE_HEIGHT * IMAGE_WIDTH);
    gVal /= (IMAGE_HEIGHT * IMAGE_WIDTH);
    bVal /= (IMAGE_HEIGHT * IMAGE_WIDTH);

    // Classification based on average pixel colors
    if (rVal > gVal && rVal > bVal) {
        printf("Classified as: Red Class\n");
    } else if (gVal > rVal && gVal > bVal) {
        printf("Classified as: Green Class\n");
    } else {
        printf("Classified as: Blue Class\n");
    }
}

int readJPEG(const char *filename, ImageData *imageData) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Cannot open %s\n", filename);
        return 0;
    }

    // Set up the JPEG decompression
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    // Check if the dimensions are the same
    if (cinfo.image_width != IMAGE_WIDTH || cinfo.image_height != IMAGE_HEIGHT) {
        fprintf(stderr, "Image dimensions should be %dx%d\n", IMAGE_WIDTH, IMAGE_HEIGHT);
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return 0;
    }

    // Read the scanlines
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        unsigned char buffer[IMAGE_WIDTH * 3];
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            imageData->image[i][j].r = buffer[j * 3];
            imageData->image[i][j].g = buffer[j * 3 + 1];
            imageData->image[i][j].b = buffer[j * 3 + 2];
        }
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    
    return 1;
}

void loadDataset(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", directory);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            char filepath[256];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            if (readJPEG(filepath, &dataset[imageCount])) {
                dataset[imageCount].classId = imageCount % NUM_CLASSES;  // Assign fake class ID for demonstration
                imageCount++;
                if (imageCount >= MAX_IMAGES) {
                    break;
                }
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    loadDataset(argv[1]);

    for (int i = 0; i < imageCount; i++) {
        printf("Processing image %d...\n", i);
        classifyImage(&dataset[i]);
    }

    return 0;
}