//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILES 100
#define IMAGE_LABEL_SIZE 20

typedef struct {
    char file_path[MAX_PATH_LENGTH];
    char label[IMAGE_LABEL_SIZE];
} Image;

void classify_image(const char *filename, Image *image) {
    if (strstr(filename, "cat") != NULL) {
        strcpy(image->label, "cat");
    } else if (strstr(filename, "dog") != NULL) {
        strcpy(image->label, "dog");
    } else {
        strcpy(image->label, "unknown");
    }
}

void list_images(const char *directory, Image *images, int *image_count) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directory);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            if (*image_count < MAX_FILES) {
                snprintf(images[*image_count].file_path, MAX_PATH_LENGTH, "%s/%s", directory, entry->d_name);
                classify_image(entry->d_name, &images[*image_count]);
                (*image_count)++;
            } else {
                printf("Maximum file limit reached.\n");
                break;
            }
        }
    }
    closedir(dir);
}

void print_classified_images(const Image *images, int image_count) {
    printf("%-30s | %s\n", "File Path", "Label");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < image_count; i++) {
        printf("%-30s | %s\n", images[i].file_path, images[i].label);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image images[MAX_FILES];
    int image_count = 0;

    list_images(argv[1], images, &image_count);
    print_classified_images(images, image_count);

    return EXIT_SUCCESS;
}