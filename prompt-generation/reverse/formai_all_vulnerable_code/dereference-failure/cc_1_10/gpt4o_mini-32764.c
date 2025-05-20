//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Structure for image data
typedef struct {
    char filename[256];
    int label; // For classification purposes
} ImageData;

// Function to classify an image (dummy classification)
int classify_image(ImageData img) {
    // Dummy classification logic: Assign label based on file extension
    const char *extension = strrchr(img.filename, '.');
    if (extension != NULL) {
        if (strcasecmp(extension, ".jpg") == 0 || strcasecmp(extension, ".jpeg") == 0) {
            return 0; // Class 0 for JPEGS
        } else if (strcasecmp(extension, ".png") == 0) {
            return 1; // Class 1 for PNGs
        } else if (strcasecmp(extension, ".gif") == 0) {
            return 2; // Class 2 for GIFs
        }
    }
    return -1; // Unknown class
}

// Function to load images from a directory
void load_images(const char *directory, ImageData **images, int *count) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    *count = 0;

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    // Count the number of image files in the directory
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            // Check for image extensions
            if (strstr(entry->d_name, ".jpg") || strstr(entry->d_name, ".png") || strstr(entry->d_name, ".gif")) {
                (*count)++;
            }
        }
    }

    rewinddir(dp);

    *images = malloc(sizeof(ImageData) * (*count));
    int index = 0;
    
    // Load the images into the ImageData struct
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            if (strstr(entry->d_name, ".jpg") || strstr(entry->d_name, ".png") || strstr(entry->d_name, ".gif")) {
                strcpy((*images)[index].filename, entry->d_name);
                (*images)[index].label = classify_image((*images)[index]);
                index++;
            }
        }
    }

    closedir(dp);
}

// Function to print image classifications
void print_classifications(ImageData *images, int count) {
    printf("Image Classifications:\n");
    for (int i = 0; i < count; i++) {
        printf("File: %s, Class: %d\n", images[i].filename, images[i].label);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ImageData *images = NULL;
    int count = 0;

    load_images(argv[1], &images, &count);
    
    if (count == 0) {
        printf("No images found in directory: %s\n", argv[1]);
        return EXIT_SUCCESS;
    }

    print_classifications(images, count);

    free(images);  // Free allocated memory
    return EXIT_SUCCESS;
}