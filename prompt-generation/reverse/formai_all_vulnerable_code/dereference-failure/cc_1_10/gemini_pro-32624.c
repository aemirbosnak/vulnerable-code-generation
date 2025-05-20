//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void write_image(Image *image, FILE *file) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fputc(image->data[y * image->width + x], file);
        }
        fputc('\n', file);
    }
}

void convert_text_to_ascii_art(char *text, Image *image) {
    int char_width = 8;
    int char_height = 12;

    int num_chars = strlen(text);
    int num_cols = (num_chars * char_width + image->width - 1) / image->width;
    int num_rows = (num_cols * char_height + image->height - 1) / image->height;

    for (int y = 0; y < num_rows; y++) {
        for (int x = 0; x < num_cols; x++) {
            int char_index = y * num_cols + x;
            if (char_index < num_chars) {
                char *char_data = text + char_index * char_width;
                for (int i = 0; i < char_height; i++) {
                    for (int j = 0; j < char_width; j++) {
                        image->data[(y * image->width + x) * char_height + i] |= (char_data[j] >> (7 - i)) & 1;
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];

    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);

    convert_text_to_ascii_art(text, image);

    write_image(image, stdout);

    destroy_image(image);

    return 0;
}