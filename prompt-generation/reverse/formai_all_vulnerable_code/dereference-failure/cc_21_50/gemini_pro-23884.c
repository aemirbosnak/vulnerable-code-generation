//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned char pixel;

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input file> <output file> <action> <optional argument>\n", argv[0]);
        printf("Actions:\n");
        printf("  flip-h: flip the image horizontally\n");
        printf("  flip-v: flip the image vertically\n");
        printf("  brightness <value>: change the brightness of the image\n");
        printf("  contrast <value>: change the contrast of the image\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *action = argv[3];
    int arg = 0;
    if (strcmp(action, "brightness") == 0 || strcmp(action, "contrast") == 0) {
        arg = atoi(argv[4]);
    }

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file '%s'\n", input_file);
        return 1;
    }

    // Read the header of the PGM file
    char header[100];
    fgets(header, sizeof(header), input);
    if (strcmp(header, "P5\n") != 0) {
        printf("Error: input file is not a PGM file\n");
        fclose(input);
        return 1;
    }

    int width, height, max_value;
    fscanf(input, "%d %d\n", &width, &height);
    fscanf(input, "%d\n", &max_value);

    // Read the image data
    pixel *image = malloc(width * height * sizeof(pixel));
    if (image == NULL) {
        printf("Error allocating memory for image\n");
        fclose(input);
        return 1;
    }

    fread(image, sizeof(pixel), width * height, input);
    fclose(input);

    // Perform the specified action
    if (strcmp(action, "flip-h") == 0) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width / 2; j++) {
                pixel temp = image[i * width + j];
                image[i * width + j] = image[i * width + width - j - 1];
                image[i * width + width - j - 1] = temp;
            }
        }
    } else if (strcmp(action, "flip-v") == 0) {
        for (int i = 0; i < height / 2; i++) {
            for (int j = 0; j < width; j++) {
                pixel temp = image[i * width + j];
                image[i * width + j] = image[(height - i - 1) * width + j];
                image[(height - i - 1) * width + j] = temp;
            }
        }
    } else if (strcmp(action, "brightness") == 0) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int new_value = image[i * width + j] + arg;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > max_value) {
                    new_value = max_value;
                }
                image[i * width + j] = new_value;
            }
        }
    } else if (strcmp(action, "contrast") == 0) {
        double factor = (double)arg / 100.0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int new_value = (image[i * width + j] - 128) * factor + 128;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > max_value) {
                    new_value = max_value;
                }
                image[i * width + j] = new_value;
            }
        }
    }

    // Write the modified image to the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file '%s'\n", output_file);
        free(image);
        return 1;
    }

    // Write the header of the PGM file
    fprintf(output, "P5\n%d %d\n%d\n", width, height, max_value);

    // Write the image data
    fwrite(image, sizeof(pixel), width * height, output);
    fclose(output);

    free(image);

    return 0;
}