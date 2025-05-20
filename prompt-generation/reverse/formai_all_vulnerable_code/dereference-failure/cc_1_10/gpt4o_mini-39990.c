//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <jpeglib.h>
#include <dirent.h>

#define MAX_IMAGES 100
#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128

typedef struct {
    int label;
    unsigned char pixels[IMAGE_WIDTH][IMAGE_HEIGHT][3]; // RGB pixels
} Image;

Image image_database[MAX_IMAGES];
int image_count = 0;

// Function prototypes
void load_image(const char *filename, Image *image);
void classify_images();
void print_image_label(int label);
void list_directory(const char *dir_path);

// Sample label printout
void print_image_label(int label) {
    switch (label) {
        case 0:
            printf("Detected: A Clue\n");
            break;
        case 1:
            printf("Detected: A Criminal\n");
            break;
        case 2:
            printf("Detected: A Victim\n");
            break;
        default:
            printf("Detected: Unknown\n");
            break;
    }
}

// Load JPEG image and downsize to fixed dimention
void load_image(const char *filename, Image *image) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Cannot open %s: %s\n", filename, strerror(errno));
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    // Convert color values to pixels
    int width = cinfo.output_width;
    int height = cinfo.output_height;
    unsigned char *buffer = (unsigned char *)malloc(width * height * 3);
    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *row_ptr[1];
        row_ptr[0] = buffer + cinfo.output_scanline * width * 3;
        jpeg_read_scanlines(&cinfo, row_ptr, 1);
    }

    // Resize and store in our fixed size pixels
    float width_ratio = (float)width / IMAGE_WIDTH;
    float height_ratio = (float)height / IMAGE_HEIGHT;
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int img_x = (int)(x * width_ratio);
            int img_y = (int)(y * height_ratio);
            for (int color = 0; color < 3; color++) {
                image->pixels[x][y][color] = buffer[(img_y * width + img_x) * 3 + color];
            }
        }
    }

    image->label = -1; // Not classified yet
    free(buffer);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
}

// Simple heuristic classifier (as a placeholder)
void classify_images() {
    for (int i = 0; i < image_count; i++) {
        int criterion = (image_database[i].pixels[0][0][0] + 
                         image_database[i].pixels[0][0][1] + 
                         image_database[i].pixels[0][0][2]) % 3;
        image_database[i].label = criterion;
        print_image_label(image_database[i].label);
    }
}

// List files in a directory and load images
void list_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", strerror(errno));
        return;
    }

    while ((entry = readdir(dp))) {
        if (strstr(entry->d_name, ".jpg") || strstr(entry->d_name, ".jpeg")) {
            char file_path[256];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            if (image_count < MAX_IMAGES) {
                load_image(file_path, &image_database[image_count]);
                printf("Loaded image: %s\n", file_path);
                image_count++;
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    list_directory(argv[1]);
    classify_images();

    return 0;
}