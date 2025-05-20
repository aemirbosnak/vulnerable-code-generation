//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

#define MAX_COLOR_SIZE 7
#define RGB_SIZE 3

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void check_args(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        fprintf(stderr, "Usage: %s <rgb|hex> <value>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

void *map_file(int fd, size_t size) {
    void *ptr;
    if ((ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
        die("mmap failed");
    return ptr;
}

void unmap_file(void *ptr, size_t size) {
    if (munmap(ptr, size) == -1)
        die("munmap failed");
}

void rgb_to_hex(unsigned char r, unsigned char g, unsigned char b) {
    char hex[MAX_COLOR_SIZE];
    snprintf(hex, sizeof(hex), "#%02x%02x%02x", r, g, b);
    printf("%s\n", hex);
}

void hex_to_rgb(const char *hex, unsigned char *r, unsigned char *g, unsigned char *b) {
    int red = 0, green = 0, blue = 0;
    sscanf(hex, "#%x%x%x", &red, &green, &blue);

    *r = (red >> 5) * 17 / 15;
    *g = (green >> 5) * 17 / 15;
    *b = (blue >> 5) * 17 / 15;
}

int main(int argc, char *argv[]) {
    check_args(argc, argv);

    if (!strcmp(argv[1], "rgb")) {
        unsigned char r, g, b;
        sscanf(argv[2], "%hhu%hhu%hhu", &r, &g, &b);
        rgb_to_hex(r, g, b);
    } else if (!strcmp(argv[1], "hex")) {
        size_t fd, size;
        char *hex_val = argv[2];
        unsigned char r, g, b;

        if (strlen(argv[2]) != 7 && strlen(argv[2]) != 9) {
            fprintf(stderr, "Invalid hexadecimal color code: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        if ((fd = open(argv[3], O_RDONLY)) == -1)
            die("open failed");

        size = strlen(argv[2]) + sizeof(unsigned char) * RGB_SIZE;
        void *map_ptr = map_file(fd, size);

        hex_to_rgb(argv[2], (unsigned char *)&r, &g, &b);

        unmap_file(map_ptr, size);
        close(fd);

        printf("R: %hhu, G: %hhu, B: %hhu\n", r, g, b);
    }

    return EXIT_SUCCESS;
}