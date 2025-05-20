//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <dirent.h>
#include <math.h>

#define IMAGE_SIZE 64  // Image size (IMAGE_SIZE x IMAGE_SIZE)
#define NUM_CLASSES 10 // Define based on your dataset

// Structure to hold image data
typedef struct {
    unsigned char pixels[IMAGE_SIZE][IMAGE_SIZE][3]; // RGB values
} Image;

// Structure to hold class information
typedef struct {
    char name[50];
    int count;
} Class;

// Function prototypes
Image* load_image(const char* filename);
void classify_image(Image* image, Class classes[], int num_classes);
void display_classification_results(Class classes[], int num_classes);

// Main function
int main() {
    Class classes[NUM_CLASSES] = {{"Cat", 0}, {"Dog", 0}, {"Car", 0}, {"Bike", 0}, {"Tree", 0},
                                    {"Building", 0}, {"Human", 0}, {"Flower", 0}, {"Bird", 0}, {"Other", 0}};

    DIR *dir;
    struct dirent *entry;
    const char *image_folder = "./images/";

    // Open the image directory
    if ((dir = opendir(image_folder)) == NULL) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    // Process each image file in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char filepath[256];
            snprintf(filepath, sizeof(filepath), "%s%s", image_folder, entry->d_name);
            Image* image = load_image(filepath);
            
            if (image != NULL) {
                classify_image(image, classes, NUM_CLASSES);
                free(image);
            }
        }
    }
    closedir(dir);

    display_classification_results(classes, NUM_CLASSES);
    return EXIT_SUCCESS;
}

// Load an image from a file
Image* load_image(const char* filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE * infile;         
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open %s\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    Image* img = malloc(sizeof(Image));
    if (img == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(infile);
        return NULL;
    }

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char* row_pointer[1];
        row_pointer[0] = (unsigned char*)img->pixels[cinfo.output_scanline];
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    return img;
}

// Classify the loaded image (dummy logic for demonstration purposes)
void classify_image(Image* image, Class classes[], int num_classes) {
    // Simple logic to classify based on average color - replace with real logic
    long total_red = 0, total_green = 0, total_blue = 0;
    int pixel_count = IMAGE_SIZE * IMAGE_SIZE;

    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            total_red += image->pixels[i][j][0];
            total_green += image->pixels[i][j][1];
            total_blue += image->pixels[i][j][2];
        }
    }

    // Calculate average color
    int avg_red = total_red / pixel_count;
    int avg_green = total_green / pixel_count;
    int avg_blue = total_blue / pixel_count;

    // Dummy logic for classification - replace thresholds with actual logic
    if (avg_red > 200 && avg_green < 100 && avg_blue < 100) {
        classes[0].count++; // Increment cat count
    } else if (avg_green > 200 && avg_red < 100) {
        classes[1].count++; // Increment dog count
    } else {
        classes[9].count++; // Increment other count
    }
}

// Display the classification results
void display_classification_results(Class classes[], int num_classes) {
    printf("Classification Results:\n");
    for (int i = 0; i < num_classes; i++) {
        printf("%s: %d\n", classes[i].name, classes[i].count);
    }
}