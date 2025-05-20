//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME 256
#define MAX_IMAGES 100

typedef struct {
    char filename[MAX_FILENAME];
    int label; // For example: 0 for cat, 1 for dog, etc.
} Image;

// Function prototypes
void classify_image(const char *filename);
void load_images(const char *directory, Image *images, int *count);
void print_classification_results(Image *images, int count);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image images[MAX_IMAGES];
    int count = 0;

    load_images(argv[1], images, &count);
    print_classification_results(images, count);

    return EXIT_SUCCESS;
}

void classify_image(const char *filename) {
    // Simple mock classification based on filename
    if (strstr(filename, "cat") != NULL) {
        printf("Image '%s' classified as: Cat\n", filename);
    } else if (strstr(filename, "dog") != NULL) {
        printf("Image '%s' classified as: Dog\n", filename);
    } else {
        printf("Image '%s' classified as: Unknown\n", filename);
    }
}

void load_images(const char *directory, Image *images, int *count) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG && *count < MAX_IMAGES) { // only process regular files
            snprintf(images[*count].filename, MAX_FILENAME, "%s/%s", directory, entry->d_name);
            classify_image(entry->d_name);
            images[*count].label = (strstr(entry->d_name, "cat") != NULL) ? 0 : (strstr(entry->d_name, "dog") != NULL) ? 1 : -1;
            (*count)++;
        }
    }
    closedir(dp);
}

void print_classification_results(Image *images, int count) {
    printf("\n--- Classification Summary ---\n");
    for (int i = 0; i < count; i++) {
        printf("File: %s, Label: %d\n", images[i].filename, images[i].label);
    }
}