//FormAI DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct image {
    int width;
    int height;
    int *pixels;
};

void print_menu() {
    printf("Welcome to Sherlock Holmes' Image Editor\n");
    printf("=======================================\n");
    printf("1. Load an image\n");
    printf("2. Save the current image\n");
    printf("3. Change image size\n");
    printf("4. Flip image horizontally\n");
    printf("5. Flip image vertically\n");
    printf("6. Change color tone\n");
    printf("0. Exit program\n");
}

int get_int_input(char *message) {
    int input;
    printf("%s", message);
    scanf("%d", &input);
    return input;
}

void load_image(struct image *im) {
    char filename[100];
    printf("Enter the filename of the image to load: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    int w, h;
    fread(&w, sizeof(int), 1, fp);
    fread(&h, sizeof(int), 1, fp);

    im->width = w;
    im->height = h;

    int num_pixels = w * h;
    im->pixels = (int *)malloc(sizeof(int) * num_pixels);
    fread(im->pixels, sizeof(int), num_pixels, fp);

    fclose(fp);
    printf("Image loaded successfully\n");
}

void save_image(struct image *im) {
    char filename[100];
    printf("Enter the filename to save the image: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not create file %s\n", filename);
        return;
    }

    fwrite(&(im->width), sizeof(int), 1, fp);
    fwrite(&(im->height), sizeof(int), 1, fp);
    fwrite(im->pixels, sizeof(int), im->width * im->height, fp);

    fclose(fp);
    printf("Image saved successfully\n");
}

void change_size(struct image *im) {
    int new_w = get_int_input("Enter the new width of the image: ");
    int new_h = get_int_input("Enter the new height of the image: ");

    int num_pixels = new_w * new_h;
    int *new_pixels = (int *)malloc(sizeof(int) * num_pixels);

    for (int i = 0; i < new_w; i++) {
        for (int j = 0; j < new_h; j++) {
            if (i >= im->width || j >= im->height) {
                new_pixels[i*new_h + j] = 0;
            } else {
                new_pixels[i*new_h + j] = im->pixels[i*im->height + j];
            }
        }
    }

    free(im->pixels);
    im->width = new_w;
    im->height = new_h;
    im->pixels = new_pixels;

    printf("Image size changed successfully\n");
}

void flip_horizontally(struct image *im) {
    int num_pixels = im->width * im->height;
    for (int i = 0; i < im->width/2; i++) {
        for (int j = 0; j < im->height; j++) {
            int temp = im->pixels[i*im->height + j];
            im->pixels[i*im->height + j] = im->pixels[(im->width-i-1)*im->height + j];
            im->pixels[(im->width-i-1)*im->height + j] = temp;
        }
    }
    printf("Image flipped horizontally successfully\n");
}

void flip_vertically(struct image *im) {
    int num_pixels = im->width * im->height;
    for (int i = 0; i < im->width; i++) {
        for (int j = 0; j < im->height/2; j++) {
            int temp = im->pixels[i*im->height + j];
            im->pixels[i*im->height + j] = im->pixels[i*im->height + (im->height-j-1)];
            im->pixels[i*im->height + (im->height-j-1)] = temp;
        }
    }
    printf("Image flipped vertically successfully\n");
}

void change_tone(struct image *im) {
    int r_offset = get_int_input("Enter the red offset: ");
    int g_offset = get_int_input("Enter the green offset: ");
    int b_offset = get_int_input("Enter the blue offset: ");

    int num_pixels = im->width * im->height;
    for (int i = 0; i < num_pixels; i++) {
        int r = (im->pixels[i] >> 16) & 0xFF;
        int g = (im->pixels[i] >> 8) & 0xFF;
        int b = im->pixels[i] & 0xFF;

        r = (r + r_offset > 0xFF) ? 0xFF : ((r + r_offset < 0) ? 0 : r + r_offset);
        g = (g + g_offset > 0xFF) ? 0xFF : ((g + g_offset < 0) ? 0 : g + g_offset);
        b = (b + b_offset > 0xFF) ? 0xFF : ((b + b_offset < 0) ? 0 : b + b_offset);

        im->pixels[i] = (r << 16) | (g << 8) | b;
    }

    printf("Image tone changed successfully\n");
}

void free_image(struct image *im) {
    free(im->pixels);
    im->width = 0;
    im->height = 0;
}

int main() {
    struct image current_image = {0};
    int choice;

    do {
        print_menu();
        choice = get_int_input("Enter your choice: ");
        switch (choice) {
            case 1:
                load_image(&current_image);
                break;
            case 2:
                save_image(&current_image);
                break;
            case 3:
                change_size(&current_image);
                break;
            case 4:
                flip_horizontally(&current_image);
                break;
            case 5:
                flip_vertically(&current_image);
                break;
            case 6:
                change_tone(&current_image);
                break;
            case 0:
                free_image(&current_image);
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}