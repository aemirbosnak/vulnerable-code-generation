//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LEN 100

FILE *open_image(char *filename, char *mode)
{
    FILE *fp;
    char fullname[MAX_FILENAME_LEN];
    strncpy(fullname, filename, MAX_FILENAME_LEN);
    char *ext = strrchr(fullname, '.');
    if (ext == NULL) {
        strcat(fullname, ".pgm");
    }
    fp = fopen(fullname, mode);
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", fullname);
        exit(EXIT_FAILURE);
    }
    return fp;
}

void write_image_header(FILE *fp, int width, int height)
{
    fprintf(fp, "P2\n%d %d\n255\n", width, height);
}

void read_image_header(FILE *fp, int *width, int *height)
{
    char line[100];
    fgets(line, 100, fp);
    if (line[0] != 'P' || line[1] != '2') {
        fprintf(stderr, "Invalid file format.\n");
        exit(EXIT_FAILURE);
    }
    fgets(line, 100, fp);
    sscanf(line, "%d %d", width, height);
    fgets(line, 100, fp);
}

void read_image_data(FILE *fp, int *data, int width, int height)
{
    int x, y;
    char line[100];
    for (y = 0; y < height; y++) {
        fgets(line, 100, fp);
        for (x = 0; x < width; x++) {
            sscanf(line, "%d", &data[y*width+x]);
            strtok(line, " ");
        }
    }
}

void write_image_data(FILE *fp, int *data, int width, int height)
{
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fprintf(fp, "%d ", data[y*width+x]);
        }
        fprintf(fp, "\n");
    }
}

void flip_image(int *data, int width, int height)
{
    int x, y;
    int tmp;
    for (y = 0; y < height/2; y++) {
        for (x = 0; x < width; x++) {
            tmp = data[y*width+x];
            data[y*width+x] = data[(height-y-1)*width+x];
            data[(height-y-1)*width+x] = tmp;
        }
    }
}

void adjust_brightness(int *data, int width, int height, int adjust_value)
{
    int x, y;
    int max = 255;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            data[y*width+x] = data[y*width+x] + adjust_value;
            if (data[y*width+x] < 0) {
                data[y*width+x] = 0;
            } else if (data[y*width+x] > max) {
                data[y*width+x] = max;
            }
        }
    }
}

void adjust_contrast(int *data, int width, int height, int contrast_value)
{
    int x, y;
    int max = 255;
    double adjust_factor = 1 + contrast_value/100.0;
    int new_value;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            new_value = (int)((data[y*width+x] - 128) * adjust_factor + 128);
            if (new_value < 0) {
                data[y*width+x] = 0;
            } else if (new_value > max) {
                data[y*width+x] = max;
            } else {
                data[y*width+x] = new_value;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *input_filename = argv[1];
    char *output_filename = argv[2];

    FILE *input_fp = open_image(input_filename, "r");
    FILE *output_fp = open_image(output_filename, "w");

    int width, height;
    read_image_header(input_fp, &width, &height);

    int data[width*height];
    read_image_data(input_fp, data, width, height);

    printf("What do you want to do with the image?\n");
    printf("1. Flip the image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");

    char choice[10], value_str[10];
    int value;
    fgets(choice, 10, stdin);
    choice[strlen(choice)-1] = '\0';

    switch (atoi(choice)) {
        case 1:
            flip_image(data, width, height);
            printf("Image flipped.\n");
            break;
        case 2:
            printf("Enter the amount of brightness adjustment (-255 to 255): ");
            fgets(value_str, 10, stdin);
            value_str[strlen(value_str)-1] = '\0';
            value = atoi(value_str);
            adjust_brightness(data, width, height, value);
            printf("Brightness adjusted.\n");
            break;
        case 3:
            printf("Enter the amount of contrast adjustment (-100 to 100): ");
            fgets(value_str, 10, stdin);
            value_str[strlen(value_str)-1] = '\0';
            value = atoi(value_str);
            adjust_contrast(data, width, height, value);
            printf("Contrast adjusted.\n");
            break;
        default:
            fprintf(stderr, "Invalid choice.\n");
            exit(EXIT_FAILURE);
    }

    write_image_header(output_fp, width, height);
    write_image_data(output_fp, data, width, height);

    printf("Output file written: %s\n", output_filename);

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}