//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1024
#define MAX_FILTERS 10

typedef struct {
    char *name;
    int (*filter)(unsigned char *, int, int);
} filter_t;

unsigned char image[MAX_SIZE][MAX_SIZE];
int width, height;

void read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }
    fscanf(fp, "%d %d", &width, &height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%hhu", &image[i][j]);
        }
    }
    fclose(fp);
}

void write_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(fp, "%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "%hhu ", image[i][j]);
        }
    }
    fclose(fp);
}

int grayscale(unsigned char *p, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            unsigned char avg = (p[i * w + j] + p[i * w + j + 1] + p[i * w + j + 2]) / 3;
            p[i * w + j] = avg;
            p[i * w + j + 1] = avg;
            p[i * w + j + 2] = avg;
        }
    }
    return 0;
}

int invert(unsigned char *p, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            p[i * w + j] = 255 - p[i * w + j];
            p[i * w + j + 1] = 255 - p[i * w + j + 1];
            p[i * w + j + 2] = 255 - p[i * w + j + 2];
        }
    }
    return 0;
}

int blur(unsigned char *p, int w, int h) {
    unsigned char tmp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < h && j + l >= 0 && j + l < w) {
                        sum += p[(i + k) * w + (j + l)];
                    }
                }
            }
            tmp[i][j] = sum / 9;
        }
    }
    memcpy(p, tmp, sizeof(tmp));
    return 0;
}

int sharpen(unsigned char *p, int w, int h) {
    unsigned char tmp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < h && j + l >= 0 && j + l < w) {
                        sum += p[(i + k) * w + (j + l)];
                    }
                }
            }
            tmp[i][j] = sum - 9 * p[i * w + j];
        }
    }
    memcpy(p, tmp, sizeof(tmp));
    return 0;
}

filter_t filters[] = {
    { "Grayscale", grayscale },
    { "Invert", invert },
    { "Blur", blur },
    { "Sharpen", sharpen }
};

int num_filters = sizeof(filters) / sizeof(filter_t);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }
    read_image(argv[1]);
    char *filter_name = argv[3];
    int filter_index = -1;
    for (int i = 0; i < num_filters; i++) {
        if (strcmp(filter_name, filters[i].name) == 0) {
            filter_index = i;
            break;
        }
    }
    if (filter_index == -1) {
        printf("Invalid filter \"%s\"\n", filter_name);
        exit(1);
    }
    filters[filter_index].filter(image, width, height);
    write_image(argv[2]);
    return 0;
}