//FormAI DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// The maximum number of characters in the filename
#define MAX_FILENAME_LEN 50

// The maximum number of characters in a command
#define MAX_COMMAND_LEN 50

// The maximum number of arguments in a command
#define MAX_ARGS 10

// The image struct
struct Image {
    int width;
    int height;
    int data[MAX_HEIGHT][MAX_WIDTH];
};

// Function to read an image from a file
void read_image(struct Image *img, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file: %s\n", filename);
        exit(1);
    }

    // Read the dimensions
    fscanf(fp, "%d %d", &img->height, &img->width);

    // Read the data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(fp, "%d", &img->data[i][j]);
        }
    }

    fclose(fp);
}

// Function to write an image to a file
void write_image(struct Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file: %s\n", filename);
        exit(1);
    }

    // Write the dimensions
    fprintf(fp, "%d %d\n", img->height, img->width);

    // Write the data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d ", img->data[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Function to apply a grayscale filter to an image
void grayscale(struct Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int gray = (img->data[i][j] >> 16) & 0xff;
            gray += (img->data[i][j] >> 8) & 0xff;
            gray += img->data[i][j] & 0xff;
            gray /= 3;
            img->data[i][j] = (gray << 16) | (gray << 8) | gray;
        }
    }
}

// Function to apply a blur filter to an image
void blur(struct Image *img) {
    int kernel[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    for (int i = 1; i < img->height - 1; i++) {
        for (int j = 1; j < img->width - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;
                    sum += kernel[k + 1][l + 1] * img->data[x][y];
                }
            }

            img->data[i][j] = sum / 9;
        }
    }
}

// Function to apply a rotate filter to an image
void rotate(struct Image *img) {
    struct Image tmp;
    tmp.height = img->width;
    tmp.width = img->height;

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            tmp.data[j][i] = img->data[i][j];
        }
    }

    for (int i = 0; i < tmp.height; i++) {
        for (int j = 0; j < tmp.width/2; j++) {
            int tmp2 = tmp.data[i][j];
            tmp.data[i][j] = tmp.data[i][tmp.width - j - 1];
            tmp.data[i][tmp.width - j - 1] = tmp2;
        }
    }

    memcpy(img, &tmp, sizeof(struct Image));
}

int main() {
    char filename[MAX_FILENAME_LEN];
    char command_line[MAX_COMMAND_LEN];
    char *args[MAX_ARGS];
    struct Image img;

    while (1) {
        printf("Enter command: ");
        fgets(command_line, MAX_COMMAND_LEN, stdin);

        // Remove newline character
        command_line[strcspn(command_line, "\n")] = 0;

        // Split command line into individual words
        char *arg = strtok(command_line, " ");
        int i = 0;
        while (arg != NULL) {
            args[i++] = arg;
            arg = strtok(NULL, " ");
        }

        if (strcmp(args[0], "read") == 0) {
            if (i < 2) {
                printf("Error: read command requires filename\n");
                continue;
            }
            read_image(&img, args[1]);
        }
        else if (strcmp(args[0], "write") == 0) {
            if (i < 2) {
                printf("Error: write command requires filename\n");
                continue;
            }
            write_image(&img, args[1]);
        }
        else if (strcmp(args[0], "grayscale") == 0) {
            grayscale(&img);
        }
        else if (strcmp(args[0], "blur") == 0) {
            blur(&img);
        }
        else if (strcmp(args[0], "rotate") == 0) {
            rotate(&img);
        }
        else if (strcmp(args[0], "quit") == 0) {
            break;
        }
        else {
            printf("Error: Command not recognized\n");
        }
    }

    return 0;
}