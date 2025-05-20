//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 10

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_watermarked_image>\n", argv[0]);
        return 1;
    }

    unsigned char *input_image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    unsigned char *output_image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    fread(input_image, 3, WIDTH * HEIGHT, fp_in);
    fclose(fp_in);

    int i, j, k;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int sum = 0;
            for (k = 0; k < 3; k++) {
                sum += input_image[(i * WIDTH + j) * 3 + k];
            }

            if (sum > THRESHOLD) {
                output_image[(i * WIDTH + j) * 3] = MAX_VALUE;
                output_image[(i * WIDTH + j) * 3 + 1] = MAX_VALUE;
                output_image[(i * WIDTH + j) * 3 + 2] = MAX_VALUE;
            } else {
                output_image[(i * WIDTH + j) * 3] = input_image[(i * WIDTH + j) * 3];
                output_image[(i * WIDTH + j) * 3 + 1] = input_image[(i * WIDTH + j) * 3 + 1];
                output_image[(i * WIDTH + j) * 3 + 2] = input_image[(i * WIDTH + j) * 3 + 2];
            }
        }
    }

    FILE *fp_out = fopen(argv[2], "wb");
    if (fp_out == NULL) {
        printf("Error: Cannot open output file.\n");
        return 1;
    }

    fwrite(output_image, 3, WIDTH * HEIGHT, fp_out);
    fclose(fp_out);

    free(input_image);
    free(output_image);

    return 0;
}