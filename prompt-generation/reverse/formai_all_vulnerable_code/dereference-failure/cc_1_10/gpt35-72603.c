//FormAI DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 256
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

void load_image(char *filename, Image *img);
void save_image(char *filename, Image *img);
void invert_colors(Image *img);
void grayscale(Image *img);
void brighten(Image *img, int amount);
void darken(Image *img, int amount);
void blur(Image *img);
void sharpen(Image *img);
void apply_filter(Image *img, int filter[3][3]);

int main(int argc, char **argv) {
    char filename[MAX_FILENAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    Image img;

    if (argc != 2) {
        printf("Usage: image_editor <filename>\n");
        exit(1);
    }

    strncpy(filename, argv[1], MAX_FILENAME_LENGTH);
    load_image(filename, &img);

    while (1) {
        printf("Enter command (invert, grayscale, brighten, darken, blur, sharpen, save, exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strncmp(command, "invert", 6) == 0) {
            invert_colors(&img);
        } else if (strncmp(command, "grayscale", 9) == 0) {
            grayscale(&img);
        } else if (strncmp(command, "brighten", 8) == 0) {
            int amount;
            printf("Enter amount to brighten (0-255): ");
            scanf("%d", &amount);
            getchar();
            brighten(&img, amount);
        } else if (strncmp(command, "darken", 6) == 0) {
            int amount;
            printf("Enter amount to darken (0-255): ");
            scanf("%d", &amount);
            getchar();
            darken(&img, amount);
        } else if (strncmp(command, "blur", 4) == 0) {
            blur(&img);
        } else if (strncmp(command, "sharpen", 7) == 0) {
            sharpen(&img);
        } else if (strncmp(command, "save", 4) == 0) {
            save_image(filename, &img);
        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(img.data);

    return 0;
}

void load_image(char *filename, Image *img) {
    FILE *fp;
    char magic_number[3];
    int width, height, max_pixel_value;
    int i;

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    /* Read magic number */
    fgets(magic_number, 3, fp);
    if (strncmp(magic_number, "P6", 2) != 0) {
        printf("Error: Invalid file format\n");
        exit(1);
    }

    /* Read width, height, max pixel value */
    fscanf(fp, "%d\n%d\n%d\n", &width, &height, &max_pixel_value);

    /* Allocate memory for image data */
    img->data = (Pixel *) malloc(sizeof(Pixel) * width * height);

    /* Read pixel data */
    for (i = 0; i < width * height; i++) {
        fread(&img->data[i].red, 1, 1, fp);
        fread(&img->data[i].green, 1, 1, fp);
        fread(&img->data[i].blue, 1, 1, fp);
    }

    img->width = width;
    img->height = height;

    fclose(fp);
}

void save_image(char *filename, Image *img) {
    FILE *fp;
    int i;

    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    /* Write magic number, width, height, max pixel value */
    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, MAX_PIXEL_VALUE);

    /* Write pixel data */
    for (i = 0; i < img->width * img->height; i++) {
        fwrite(&img->data[i].red, 1, 1, fp);
        fwrite(&img->data[i].green, 1, 1, fp);
        fwrite(&img->data[i].blue, 1, 1, fp);
    }

    fclose(fp);
}

void invert_colors(Image *img) {
    int i;

    for (i = 0; i < img->width * img->height; i++) {
        img->data[i].red = MAX_PIXEL_VALUE - img->data[i].red;
        img->data[i].green = MAX_PIXEL_VALUE - img->data[i].green;
        img->data[i].blue = MAX_PIXEL_VALUE - img->data[i].blue;
    }
}

void grayscale(Image *img) {
    int i;
    unsigned char gray;

    for (i = 0; i < img->width * img->height; i++) {
        gray = (unsigned char) (0.2126 * img->data[i].red + 0.7152 * img->data[i].green + 0.0722 * img->data[i].blue);
        img->data[i].red = gray;
        img->data[i].green = gray;
        img->data[i].blue = gray;
    }
}

void brighten(Image *img, int amount) {
    int i;

    for (i = 0; i < img->width * img->height; i++) {
        img->data[i].red = img->data[i].red + amount > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : img->data[i].red + amount;
        img->data[i].green = img->data[i].green + amount > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : img->data[i].green + amount;
        img->data[i].blue = img->data[i].blue + amount > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : img->data[i].blue + amount;
    }
}

void darken(Image *img, int amount) {
    int i;

    for (i = 0; i < img->width * img->height; i++) {
        img->data[i].red = img->data[i].red - amount < 0 ? 0 : img->data[i].red - amount;
        img->data[i].green = img->data[i].green - amount < 0 ? 0 : img->data[i].green - amount;
        img->data[i].blue = img->data[i].blue - amount < 0 ? 0 : img->data[i].blue - amount;
    }
}

void blur(Image *img) {
    int i, j;
    int filter[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int sum;

    apply_filter(img, filter);

    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            sum = 0;

            if (i > 0 && j > 0) {
                sum += img->data[(j - 1) * img->width + (i - 1)].red;
                sum += img->data[(j - 1) * img->width + i].red;
                sum += img->data[(j - 1) * img->width + (i + 1)].red;
                sum += img->data[j * img->width + (i - 1)].red;
                sum += img->data[j * img->width + i].red;
                sum += img->data[j * img->width + (i + 1)].red;
                sum += img->data[(j + 1) * img->width + (i - 1)].red;
                sum += img->data[(j + 1) * img->width + i].red;
                sum += img->data[(j + 1) * img->width + (i + 1)].red;

                img->data[j * img->width + i].red = sum / 9;
                img->data[j * img->width + i].green = sum / 9;
                img->data[j * img->width + i].blue = sum / 9;
            }
        }
    }
}

void sharpen(Image *img) {
    int i, j;
    int filter[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

    apply_filter(img, filter);

    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            img->data[j * img->width + i].red = img->data[j * img->width + i].red > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : img->data[j * img->width + i].red;
            img->data[j * img->width + i].green = img->data[j * img->width + i].green > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : img->data[j * img->width + i].green;
            img->data[j * img->width + i].blue = img->data[j * img->width + i].blue > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : img->data[j * img->width + i].blue;
        }
    }
}

void apply_filter(Image *img, int filter[3][3]) {
    int i, j, x, y;
    int index;
    Image temp_img = *img;

    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            int r = 0, g = 0, b = 0;

            for (x = 0; x < 3; x++) {
                for (y = 0; y < 3; y++) {
                    int xi = i - 1 + x;
                    int yj = j - 1 + y;

                    if (xi >= 0 && xi < img->width && yj >= 0 && yj < img->height) {
                        index = yj * img->width + xi;

                        r += filter[y][x] * temp_img.data[index].red;
                        g += filter[y][x] * temp_img.data[index].green;
                        b += filter[y][x] * temp_img.data[index].blue;
                    }
                }
            }

            index = j * img->width + i;
            img->data[index].red = r;
            img->data[index].green = g;
            img->data[index].blue = b;
        }
    }
}