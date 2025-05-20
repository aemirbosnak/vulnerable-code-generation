//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: innovative
// Imagine, an Image Editor in C!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our pixel is just a humble RGB triplet
typedef struct {
    int r, g, b;
} Pixel;

// An image is a collection of pixels, with width and height
typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

// Create an image from scratch
Image *create_image(int width, int height) {
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(Pixel) * width * height);
    return img;
}

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    Image *img = malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
    img->pixels = malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    return img;
}

// Save an image to a file
void save_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return;

    fprintf(fp, "%d %d\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

// Invert the colors of an image
void invert_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = 255 - img->pixels[i].r;
        img->pixels[i].g = 255 - img->pixels[i].g;
        img->pixels[i].b = 255 - img->pixels[i].b;
    }
}

// Apply a grayscale filter to an image
void grayscale_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        int avg = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
        img->pixels[i].r = avg;
        img->pixels[i].g = avg;
        img->pixels[i].b = avg;
    }
}

// Apply a sepia filter to an image
void sepia_image(Image *img) {
    float sepia[3][3] = {
        { 0.393, 0.769, 0.189 },
        { 0.349, 0.686, 0.168 },
        { 0.272, 0.534, 0.131 }
    };

    for (int i = 0; i < img->width * img->height; i++) {
        int old_r = img->pixels[i].r;
        int old_g = img->pixels[i].g;
        int old_b = img->pixels[i].b;

        img->pixels[i].r = (int)(sepia[0][0] * old_r + sepia[0][1] * old_g + sepia[0][2] * old_b);
        img->pixels[i].g = (int)(sepia[1][0] * old_r + sepia[1][1] * old_g + sepia[1][2] * old_b);
        img->pixels[i].b = (int)(sepia[2][0] * old_r + sepia[2][1] * old_g + sepia[2][2] * old_b);
    }
}

// Free the memory allocated for an image
void destroy_image(Image *img) {
    free(img->pixels);
    free(img);
}

// Read a command from the user
int read_command(char *command) {
    printf("Enter a command (invert, grayscale, sepia, save, load, quit): ");
    scanf("%s", command);
    return strcmp(command, "quit") == 0;
}

// Perform the specified operation on an image
void process_image(Image *img, char *command) {
    if (strcmp(command, "invert") == 0) invert_image(img);
    else if (strcmp(command, "grayscale") == 0) grayscale_image(img);
    else if (strcmp(command, "sepia") == 0) sepia_image(img);
    else if (strcmp(command, "save") == 0) {
        char filename[100];
        printf("Enter a filename to save the image to: ");
        scanf("%s", filename);
        save_image(img, filename);
    } else if (strcmp(command, "load") == 0) {
        destroy_image(img);
        char filename[100];
        printf("Enter a filename to load the image from: ");
        scanf("%s", filename);
        img = load_image(filename);
    }
}

int main() {
    // Create an image from scratch
    Image *img = create_image(640, 480);

    // Read a command from the user
    char command[100];
    while (!read_command(command)) {
        // Perform the specified operation on the image
        process_image(img, command);
    }

    // Free the memory allocated for the image
    destroy_image(img);
    return 0;
}