//FormAI DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20
#define MAX_COMMAND_LEN 20

typedef struct Image {
    int width;
    int height;
    char **pixels;
} Image;

typedef struct Command {
    char type[MAX_COMMAND_LEN];
    int arg1;
    int arg2;
} Command;

void print_usage() {
    printf("Usage: image_editor <input_file> <output_file> <command_file>\n");
}

char **allocate_pixels(int width, int height) {
    char **pixels = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(char));
    }
    return pixels;
}

Image *load_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file '%s'\n", filename);
        return NULL;
    }

    // Read image dimensions
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    fgetc(file); // consume newline character

    // Allocate memory for pixels
    char **pixels = allocate_pixels(width, height);

    // Read in pixels
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixels[y][x] = fgetc(file);
        }
        fgetc(file); // consume newline character
    }

    // Initialize Image struct
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    fclose(file);
    return image;
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file '%s'\n", filename);
        return;
    }

    // Write image dimensions
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write pixels
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fputc(image->pixels[y][x], file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

void apply_command(Image *image, Command command) {
    if (strcmp(command.type, "crop") == 0) {
        int x = command.arg1;
        int y = command.arg2;

        // Create new image with cropped dimensions
        Image *cropped_image = malloc(sizeof(Image));
        cropped_image->width = image->width - x;
        cropped_image->height = image->height - y;
        cropped_image->pixels = allocate_pixels(cropped_image->width, cropped_image->height);

        // Copy pixels from image to cropped_image
        for (int j = y; j < image->height; j++) {
            for (int i = x; i < image->width; i++) {
                cropped_image->pixels[j-y][i-x] = image->pixels[j][i];
            }
        }

        // Free old image memory and set pointer to cropped_image
        for (int j = 0; j < image->height; j++) {
            free(image->pixels[j]);
        }
        free(image->pixels);
        image->width = cropped_image->width;
        image->height = cropped_image->height;
        image->pixels = cropped_image->pixels;

    } else if (strcmp(command.type, "flip") == 0) {
        // Flip image horizontally
        char **flipped_pixels = allocate_pixels(image->width, image->height);
        for (int y = 0; y < image->height; y++) {
            for (int x = 0; x < image->width; x++) {
                flipped_pixels[y][x] = image->pixels[y][image->width - x - 1];
            }
        }

        // Free old image memory and set pointer to flipped_image
        for (int j = 0; j < image->height; j++) {
            free(image->pixels[j]);
        }
        free(image->pixels);
        image->pixels = flipped_pixels;

    } else if (strcmp(command.type, "invert") == 0) {
        // Invert colors of image
        for (int y = 0; y < image->height; y++) {
            for (int x = 0; x < image->width; x++) {
                image->pixels[y][x] = '255' - image->pixels[y][x];
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    // Load input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Process commands from command file
    FILE *command_file = fopen(argv[3], "r");
    if (!command_file) {
        printf("Could not open file '%s'\n", argv[3]);
        return 1;
    }
    Command command;
    while (fscanf(command_file, "%s %d %d", command.type, &command.arg1, &command.arg2) != EOF) {
        apply_command(image, command);
    }
    fclose(command_file);

    // Save output image
    save_image(image, argv[2]);

    // Free memory
    for (int j = 0; j < image->height; j++) {
        free(image->pixels[j]);
    }
    free(image->pixels);
    free(image);

    return 0;
}