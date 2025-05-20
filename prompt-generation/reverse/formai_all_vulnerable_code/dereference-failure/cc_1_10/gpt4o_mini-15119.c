//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256
#define MAX_IMAGES 100

typedef struct {
    char name[MAX_PATH_LENGTH];
    unsigned char *data;
    int width;
    int height;
} Image;

void classifyImage(Image img) {
    long r_sum = 0, g_sum = 0, b_sum = 0;
    int pixels = img.width * img.height;

    for (int i = 0; i < pixels; i++) {
        r_sum += img.data[i * 3];
        g_sum += img.data[i * 3 + 1];
        b_sum += img.data[i * 3 + 2];
    }

    long r_avg = r_sum / pixels;
    long g_avg = g_sum / pixels;
    long b_avg = b_sum / pixels;

    printf("Classifying image: %s\n", img.name);
    if (g_avg > r_avg && g_avg > b_avg) {
        printf("- Classification: Nature\n");
    } else if (r_avg > g_avg && r_avg > b_avg) {
        printf("- Classification: Urban\n");
    } else {
        printf("- Classification: Ambiguous\n");
    }
}

Image loadImage(const char *filePath) {
    Image img;
    FILE *file = fopen(filePath, "rb");
    
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filePath);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "P6\n%d %d\n255\n", &img.width, &img.height);
    img.data = (unsigned char *)malloc(img.width * img.height * 3);
    fread(img.data, 3, img.width * img.height, file);
    fclose(file);

    strcpy(img.name, filePath);
    return img;
}

void freeImage(Image img) {
    free(img.data);
}

void findAndClassifyImages(char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    char filePath[MAX_PATH_LENGTH];
    Image img;

    if (dp == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", directory);
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (strstr(entry->d_name, ".ppm")) {
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);
            img = loadImage(filePath);
            classifyImage(img);
            freeImage(img);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    findAndClassifyImages(argv[1]);

    return EXIT_SUCCESS;
}