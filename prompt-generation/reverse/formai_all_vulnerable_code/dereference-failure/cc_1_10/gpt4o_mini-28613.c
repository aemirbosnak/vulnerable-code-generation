//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <jpeglib.h>

#define MAX_IMAGES 100
#define MAX_LABEL_LENGTH 50
#define IMAGE_FEATURES 3

typedef struct {
    char label[MAX_LABEL_LENGTH];
    float features[IMAGE_FEATURES];
} ImageData;

void extract_features(const char *filename, float *features) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    JSAMPROW row_pointer[1];

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    long total_pixels = cinfo.output_width * cinfo.output_height;
    long sum_r = 0, sum_g = 0, sum_b = 0;

    while (cinfo.output_scanline < cinfo.output_height) {
        row_pointer[0] = (JSAMPROW)malloc(cinfo.output_width * cinfo.output_components);
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
        for (int column = 0; column < cinfo.output_width; column++) {
            sum_r += row_pointer[0][column * 3];
            sum_g += row_pointer[0][column * 3 + 1];
            sum_b += row_pointer[0][column * 3 + 2];
        }
        free(row_pointer[0]);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    features[0] = (float)sum_r / total_pixels;
    features[1] = (float)sum_g / total_pixels;
    features[2] = (float)sum_b / total_pixels;
}

void load_images(const char *directory, ImageData *images, int *count) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", directory);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            // Assuming labels are in a CSV file and images are in the same directory
            char label_file[100];
            snprintf(label_file, sizeof(label_file), "%s/labels.csv", directory);
            FILE *labels = fopen(label_file, "r");
            char line[MAX_LABEL_LENGTH];

            while (fgets(line, sizeof(line), labels)) {
                char image_name[100], label[MAX_LABEL_LENGTH];
                sscanf(line, "%[^,],%s", image_name, label);
                if (strcmp(entry->d_name, image_name) == 0) {
                    strcpy(images[*count].label, label);
                    extract_features(entry->d_name, images[*count].features);
                    (*count)++;
                    break;
                }
            }
            fclose(labels);
        }
    }
    closedir(dp);
}

void classify_images(ImageData *images, int count) {
    for (int i = 0; i < count; i++) {
        printf("Image: %s, Average RGB: (%.2f, %.2f, %.2f)\n", images[i].label, 
                images[i].features[0], images[i].features[1], images[i].features[2]);
    }
}

int main() {
    ImageData images[MAX_IMAGES];
    int count = 0;

    load_images("path_to_images", images, &count);
    classify_images(images, count);

    return 0;
}