//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_IMAGES 100
#define IMAGE_NAME_LENGTH 100

// Struct to hold image data
typedef struct {
    char name[IMAGE_NAME_LENGTH];
    int label; // 0: Cat, 1: Dog, 2: Others
} Image;

// Function declarations
void classify_image(const char *image_name, int *label);
void display_result(const char *image_name, int label);
void load_images(const char *directory, Image images[], int *count);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_directory>\n", argv[0]);
        return 1;
    }

    Image images[MAX_IMAGES];
    int image_count = 0;

    // Load images from the specified directory
    load_images(argv[1], images, &image_count);

    // Process and classify images
    for (int i = 0; i < image_count; i++) {
        int label;
        classify_image(images[i].name, &label);
        display_result(images[i].name, label);
    }

    return 0;
}

// Function to classify an image based on its name
void classify_image(const char *image_name, int *label) {
    // Simplified classification based on the name (for demonstration purposes)
    if (strstr(image_name, "cat") != NULL) {
        *label = 0; // Cat
    }
    else if (strstr(image_name, "dog") != NULL) {
        *label = 1; // Dog
    }
    else {
        *label = 2; // Others
    }
}

// Function to display the classification result
void display_result(const char *image_name, int label) {
    switch (label) {
        case 0:
            printf("Image: %s classified as: Cat\n", image_name);
            break;
        case 1:
            printf("Image: %s classified as: Dog\n", image_name);
            break;
        default:
            printf("Image: %s classified as: Others\n", image_name);
            break;
    }
}

// Function to load images from a directory
void load_images(const char *directory, Image images[], int *count) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // If it's a regular file
            if (*count < MAX_IMAGES) {
                strncpy(images[*count].name, entry->d_name, IMAGE_NAME_LENGTH);
                images[*count].name[IMAGE_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
                (*count)++;
            }
        }
    }
    closedir(dir);
}