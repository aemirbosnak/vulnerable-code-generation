//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#define MAX_SIZE 1024

#define MAX_PIXEL_VALUE 255

#define MAX_COLOR_VALUE 3 

unsigned char *image = NULL;

int height = 0, width = 0, max_val = 0;

unsigned char *pixel_at(int row, int col) {
    return image + (row * width + col) * MAX_COLOR_VALUE;
}

void load_ppm(const char *file_name) {
    FILE *infile = fopen(file_name, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", file_name);
        return;
    }
    char head[100];
    fscanf(infile, "%s", head);
    if (strcmp(head, "P6")) {
        fprintf(stderr, "Error: File not a P6 PPM file %s\n", file_name);
        return;
    }
    fscanf(infile, "%d %d %d", &width, &height, &max_val);
    if (max_val > MAX_PIXEL_VALUE) {
        fprintf(stderr, "Error: Maximum pixel value is too high %d > %d\n", max_val, MAX_PIXEL_VALUE);
        return;
    }
    int image_size = height * width * MAX_COLOR_VALUE;
    image = (unsigned char *) malloc(image_size * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), image_size, infile);
    fclose(infile);
}

void save_ppm(const char *file_name) {
    FILE *outfile = fopen(file_name, "wb");
    if (outfile == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", file_name);
        return;
    }
    fprintf(outfile, "P6\n%d %d\n%d\n", width, height, max_val);
    int image_size = height * width * MAX_COLOR_VALUE;
    fwrite(image, sizeof(unsigned char), image_size, outfile);
    fclose(outfile);
}

void invert_colors() {
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            unsigned char *p = pixel_at(r, c);
            for (int ch = 0; ch < MAX_COLOR_VALUE; ++ch) {
                p[ch] = MAX_PIXEL_VALUE - p[ch];
            }
        }
    }
}

void grayscale() {
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            unsigned char *p = pixel_at(r, c);
            unsigned char gray_value = 0;
            for (int ch = 0; ch < MAX_COLOR_VALUE; ++ch) {
                gray_value += p[ch];
            }
            gray_value /= MAX_COLOR_VALUE;
            for (int ch = 0; ch < MAX_COLOR_VALUE; ++ch) {
                p[ch] = gray_value;
            }
        }
    }
}

void sepia() {
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            unsigned char *p = pixel_at(r, c);
            unsigned char r_val = p[0];
            unsigned char g_val = p[1];
            unsigned char b_val = p[2];

            unsigned char new_r = (r_val * 0.393) + (g_val * 0.769) + (b_val * 0.189);
            unsigned char new_g = (r_val * 0.349) + (g_val * 0.686) + (b_val * 0.168);
            unsigned char new_b = (r_val * 0.272) + (g_val * 0.534) + (b_val * 0.131);

            p[0] = (new_r > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : new_r;
            p[1] = (new_g > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : new_g;
            p[2] = (new_b > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : new_b;
        }
    }
}

void validate_number_input(int min, int max, int *value) {
    char buf[MAX_SIZE];
    fgets(buf, MAX_SIZE, stdin);
    if (buf[0] == '\n') {
        fprintf(stderr, "Warning: Invalid input, defaulting to %d\n", *value);
        return;
    }
    int input_number = atoi(buf);
    if (input_number < min || input_number > max) {
        fprintf(stderr, "Warning: Input out of range, defaulting to %d\n", *value);
        return;
    }
    *value = input_number;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s ppm_filename\n", argv[0]);
        return 1;
    }
    load_ppm(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error: Failed to load image %s\n", argv[1]);
        return 2;
    }
    char next_op;
    do {
        printf("Enter operation (i=invert, g=grayscale, s=sepia, q=quit): ");
        next_op = getchar();
        switch(tolower(next_op)) {
            case 'i': 
                invert_colors(); 
                printf("Colors inverted.\n"); 
                break;
            case 'g': 
                grayscale(); 
                printf("Converted to grayscale.\n"); 
                break;
            case 's': 
                sepia(); 
                printf("Converted to sepia.\n"); 
                break;
            case 'q': 
                break;
            case '\n': 
                break;
            default: 
                fprintf(stderr, "Warning: Invalid input '%c'\n", next_op); 
        }
    } while (next_op != 'q');
    save_ppm("output.ppm");
    printf("Image saved to output.ppm.\n");
    free(image);
    image = NULL;
    return 0;
}