//MISTRAL-7B DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define BUFFER_SIZE (WIDTH * HEIGHT * 3)

typedef struct {
    char name[256];
    char* pixels;
} Image;

Image load_image(const char* path) {
    int fd = open(path, O_RDONLY);
    Image img;

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(img.name, sizeof(char), 256, fd);
    fseek(fd, 100, SEEK_SET);

    img.pixels = mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);

    close(fd);

    return img;
}

void save_image(const Image img, const char* path) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(img.name, sizeof(char), strlen(img.name), fd);

    write(fd, img.pixels, BUFFER_SIZE);

    close(fd);

    munmap(img.pixels, BUFFER_SIZE);
}

void apply_post_apocalyptic_filter(Image* img) {
    int i, j;
    unsigned char* p;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            p = &img->pixels[(i * WIDTH + j) * 3];

            // Apply post-apocalyptic filter
            p[0] = sqrt(abs(p[0] - 128.0)) * 128.0 > 255.0 ? 255.0 : sqrt(abs(p[0] - 128.0)) * 128.0;
            p[1] = sqrt(abs(p[1] - 128.0)) * 128.0 > 255.0 ? 255.0 : sqrt(abs(p[1] - 128.0)) * 128.0;
            p[2] = sqrt(abs(p[2] - 128.0)) * 128.0 > 255.0 ? 255.0 : sqrt(abs(p[2] - 128.0)) * 128.0;
        }
    }
}

int main(int argc, char** argv) {
    Image input_image;

    if (argc < 2) {
        printf("Usage: %s <image_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_image = load_image(argv[1]);
    apply_post_apocalyptic_filter(&input_image);
    save_image(input_image, "output.pgm");

    printf("Post-apocalyptic filter applied to the image and saved as output.pgm.\n");

    return EXIT_SUCCESS;
}