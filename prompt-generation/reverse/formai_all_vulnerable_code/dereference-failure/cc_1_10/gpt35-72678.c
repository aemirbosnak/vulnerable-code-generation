//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_WIDTH 80
#define DEFAULT_HEIGHT 40

void print_ascii_art(char *ascii_image);

int main(int argc, char *argv[]) {
    int width = DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [image file]\n", argv[0]);
        return 1;
    }

    if (argc >= 3) {
        width = atoi(argv[2]);
    }

    if (argc == 4) {
        height = atoi(argv[3]);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (!fp) {
        fprintf(stderr, "Error: cannot open file \"%s\"\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (!file_size) {
        fprintf(stderr, "Error: file \"%s\" is empty\n", argv[1]);
        return 1;
    }

    char *image_data = malloc(file_size + 1);

    if (!image_data) {
        fprintf(stderr, "Error: malloc() failed\n");
        return 1;
    }

    fread(image_data, 1, file_size, fp);
    fclose(fp);
    image_data[file_size] = '\0';

    int image_width = DEFAULT_WIDTH;
    int image_height = DEFAULT_HEIGHT;

    char *p = strtok(image_data, ",");
    int is_width_or_height = 0;

    while (p != NULL) {
        if (!is_width_or_height) {
            int w = atoi(p);

            if (w > 0) {
                image_width = w;
            }
        } else {
            int h = atoi(p);

            if (h > 0) {
                image_height = h;
            }
        }

        is_width_or_height = !is_width_or_height;
        p = strtok(NULL, ",");
    }

    char *ascii_image = malloc((width + 1) * height + 1);

    if (!ascii_image) {
        perror("Error: malloc() failed");
        free(image_data);
        return 1;
    }

    char *p_ascii = ascii_image;
    char ascii_chars[] = " .,:;i1tfLCG08@";
    int num_ascii_chars = strlen(ascii_chars);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int image_x = x * image_width / width;
            int image_y = y * image_height / height;
            char c = ascii_chars[(int)(image_data[image_y * image_width + image_x] * (num_ascii_chars - 1) / 255)];
            *p_ascii = c;
            p_ascii++;
        }

        *p_ascii = '\n';
        p_ascii++;
    }

    *p_ascii = '\0';
    free(image_data);
    print_ascii_art(ascii_image);
    free(ascii_image);
    return 0;
}

void print_ascii_art(char *ascii_image) {
    printf("%s\n", ascii_image);
}