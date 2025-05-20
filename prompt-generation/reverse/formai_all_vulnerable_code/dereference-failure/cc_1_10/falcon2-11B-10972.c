//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <math.h>
#include <png.h>
#include <jpeglib.h>

typedef struct {
    char *img_name;
    char *watermark_name;
    int watermark_strength;
} args_t;

int read_image(const char *img_name, unsigned char *buf, int buf_size) {
    FILE *f = fopen(img_name, "rb");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    int read_bytes = fread(buf, 1, buf_size, f);
    fclose(f);

    return read_bytes;
}

int write_image(const char *img_name, unsigned char *buf, int buf_size) {
    FILE *f = fopen(img_name, "wb");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    int write_bytes = fwrite(buf, 1, buf_size, f);
    fclose(f);

    return write_bytes;
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <image_name> <watermark_name> <watermark_strength> <output_name>\n", argv[0]);
        exit(1);
    }

    args_t args = {
       .img_name = argv[1],
       .watermark_name = argv[2],
       .watermark_strength = atoi(argv[3])
    };

    unsigned char *image_buf = (unsigned char *)malloc(args.watermark_strength * sizeof(unsigned char));
    unsigned char *watermark_buf = (unsigned char *)malloc(args.watermark_strength * sizeof(unsigned char));

    memset(image_buf, 0, args.watermark_strength * sizeof(unsigned char));
    memset(watermark_buf, 0, args.watermark_strength * sizeof(unsigned char));

    int image_read_bytes = read_image(args.img_name, image_buf, args.watermark_strength);
    int watermark_read_bytes = read_image(args.watermark_name, watermark_buf, args.watermark_strength);

    if (image_read_bytes == 0 || watermark_read_bytes == 0) {
        fprintf(stderr, "Error reading input files\n");
        exit(1);
    }

    for (int i = 0; i < args.watermark_strength; i++) {
        image_buf[i] += watermark_buf[i];
    }

    int image_write_bytes = write_image(args.img_name, image_buf, args.watermark_strength);
    int watermark_write_bytes = write_image(args.watermark_name, watermark_buf, args.watermark_strength);

    if (image_write_bytes == 0 || watermark_write_bytes == 0) {
        fprintf(stderr, "Error writing output files\n");
        exit(1);
    }

    free(image_buf);
    free(watermark_buf);

    return 0;
}