//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return NULL;
    }

    Image* image = (Image*) malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        fclose(file);
        return NULL;
    }

    image->width = 0;
    image->height = 0;
    image->data = NULL;

    char* buffer = (char*) malloc(sizeof(char) * MAX_FILENAME_LENGTH);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        free(image);
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    image->data = (unsigned char*) malloc(image->width * image->height);
    if (image->data == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        free(buffer);
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

void free_image(Image* image) {
    free(image->data);
    free(image);
}

void display_image(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

void crop_image(Image* image, int x, int y, int width, int height) {
    if (x < 0 || x + width > image->width || y < 0 || y + height > image->height) {
        fprintf(stderr, "Error: Cropping region is out of bounds.\n");
        return;
    }

    Image cropped_image;
    cropped_image.width = width;
    cropped_image.height = height;
    cropped_image.data = (unsigned char*) malloc(cropped_image.width * cropped_image.height);
    if (cropped_image.data == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cropped_image.data[y * width + x] = image->data[y * image->width + x];
        }
    }

    free_image(image);
    image = &cropped_image;
}

void resize_image(Image* image, int width, int height) {
    if (width <= 0 || height <= 0) {
        fprintf(stderr, "Error: Resizing dimensions must be positive.\n");
        return;
    }

    Image resized_image;
    resized_image.width = width;
    resized_image.height = height;
    resized_image.data = (unsigned char*) malloc(resized_image.width * resized_image.height);
    if (resized_image.data == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * image->width + x;
            unsigned char average_color = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int neighbor_index = index + dy * image->width + dx;
                    if (neighbor_index >= 0 && neighbor_index < image->width * image->height) {
                        average_color += image->data[neighbor_index];
                    }
                }
            }
            average_color /= 9;
            resized_image.data[y * width + x] = average_color;
        }
    }

    free_image(image);
    image = &resized_image;
}

void add_filter(Image* image, const char* filter_name) {
    if (strcmp(filter_name, "grayscale") == 0) {
        for (int y = 0; y < image->height; y++) {
            for (int x = 0; x < image->width; x++) {
                int average_color = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int neighbor_index = y * image->width + x + dy * image->width + dx;
                        if (neighbor_index >= 0 && neighbor_index < image->width * image->height) {
                            average_color += image->data[neighbor_index];
                        }
                    }
                }
                average_color /= 9;
                image->data[y * image->width + x] = average_color;
            }
        }
    } else if (strcmp(filter_name, "sepia") == 0) {
        for (int y = 0; y < image->height; y++) {
            for (int x = 0; x < image->width; x++) {
                int average_color = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int neighbor_index = y * image->width + x + dy * image->width + dx;
                        if (neighbor_index >= 0 && neighbor_index < image->width * image->height) {
                            average_color += image->data[neighbor_index];
                        }
                    }
                }
                average_color /= 9;
                image->data[y * image->width + x] = 0.393 * image->data[y * image->width + x] + 0.769 * average_color;
            }
        }
    } else {
        fprintf(stderr, "Error: Invalid filter name.\n");
    }
}

int main() {
    const char* FILENAME = "image.jpg";
    Image* image = load_image(FILENAME);
    if (image == NULL) {
        return 1;
    }

    display_image(image);
    printf("1. Crop\n2. Resize\n3. Add filter\n4. Save\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            int x, y, width, height;
            printf("Enter coordinates of cropping region (x, y, width, height): ");
            scanf("%d%d%d%d", &x, &y, &width, &height);
            crop_image(image, x, y, width, height);
            break;
        }
        case 2: {
            int width, height;
            printf("Enter new width and height: ");
            scanf("%d%d", &width, &height);
            resize_image(image, width, height);
            break;
        }
        case 3: {
            char filter_name[MAX_FILENAME_LENGTH];
            printf("Enter filter name (grayscale/sepia): ");
            fgets(filter_name, MAX_FILENAME_LENGTH, stdin);
            add_filter(image, filter_name);
            break;
        }
        case 4: {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename (without extension): ");
            fgets(filename, MAX_FILENAME_LENGTH, stdin);
            char extension[MAX_FILENAME_LENGTH];
            printf("Enter extension (jpg/png): ");
            fgets(extension, MAX_FILENAME_LENGTH, stdin);
            char new_filename[MAX_FILENAME_LENGTH];
            sprintf(new_filename, "%s%c%s", filename, '_', extension);
            Image new_image = *image;
            free_image(image);
            image = &new_image;
            free_image(&new_image);
            break;
        }
        default:
            fprintf(stderr, "Error: Invalid choice.\n");
            break;
    }

    display_image(image);
    free_image(image);
    return 0;
}