//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *data;
    int size;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    char *data = malloc(size + 1);
    if (data == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }

    size_t n = fread(data, 1, size, fp);
    if (n!= size) {
        fprintf(stderr, "Error: Could not read file '%s'\n", filename);
        exit(1);
    }

    data[size] = '\0';
    image_t *img = malloc(sizeof(image_t));
    img->data = data;
    img->size = size;

    fclose(fp);
    return img;
}

void save_image(const char *filename, image_t *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(img->data, 1, img->size, fp);

    fclose(fp);
}

void apply_filter(image_t *img, int (*filter)(char)) {
    for (int i = 0; i < img->size; i++) {
        img->data[i] = filter(img->data[i]);
    }
}

int invert_filter(char c) {
    return ~c;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    image_t *img = load_image(argv[1]);
    apply_filter(img, invert_filter);
    save_image(argv[2], img);

    free(img->data);
    free(img);

    return 0;
}