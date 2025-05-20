//FormAI DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_COMMAND_LENGTH 50
#define MAX_ARGS_LENGTH 20
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = (Image *) malloc(sizeof(Image));

    if (image == NULL) {
        printf("Failed to allocate memory for image.\n");
        return NULL;
    }

    image->width = width;
    image->height = height;

    image->pixels = (int **) malloc(sizeof(int *) * height);

    if (image->pixels == NULL) {
        printf("Failed to allocate memory for pixel array.\n");
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        image->pixels[i] = (int *) calloc(width, sizeof(int));

        if (image->pixels[i] == NULL) {
            printf("Failed to allocate memory for pixel row.\n");
            return NULL;
        }
    }

    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }

    free(image->pixels);
    free(image);
}

Image *load_image(char *filename) {
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Failed to open file \"%s\".\n", filename);
        return NULL;
    }

    char line[100];
    fgets(line, 100, f);

    if (strcmp(line, "P2\n") != 0) {
        printf("\"%s\" is not a valid PGM file.\n", filename);
        return NULL;
    }

    int width, height, max_value;
    fscanf(f, "%d %d %d\n", &width, &height, &max_value);

    Image *image = create_image(width, height);

    if (image == NULL) {
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value;
            fscanf(f, "%d", &pixel_value);

            if (pixel_value < 0 || pixel_value > max_value) {
                printf("Invalid pixel value %d.\n", pixel_value);
                return NULL;
            }

            image->pixels[i][j] = pixel_value;
        }
    }

    fclose(f);

    return image;
}

int save_image(Image *image, char *filename) {
    FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("Failed to create or overwrite file \"%s\".\n", filename);
        return 0;
    }

    fprintf(f, "P2\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VALUE);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(f, "%d ", image->pixels[i][j]);
        }

        fprintf(f, "\n");
    }

    fclose(f);

    return 1;
}

Image *apply_command(Image *image, char *command, char **args) {
    if (strcmp(command, "invert") == 0) {
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                image->pixels[i][j] = MAX_PIXEL_VALUE - image->pixels[i][j];
            }
        }
    } else if (strcmp(command, "grayscale") == 0) {
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                int gray = (int) ((0.3 * image->pixels[i][j]) + (0.59 * image->pixels[i][j]) + (0.11 * image->pixels[i][j]));
                image->pixels[i][j] = gray;
            }
        }
    } else if (strcmp(command, "brightness") == 0) {
        int amount = atoi(args[0]);

        if (amount < -MAX_PIXEL_VALUE || amount > MAX_PIXEL_VALUE) {
            printf("Invalid brightness amount: %s.\n", args[0]);
            return NULL;
        }

        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                int new_value = image->pixels[i][j] + amount;
                image->pixels[i][j] = (new_value < 0) ? 0 : (new_value > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : new_value;
            }
        }
    } else if (strcmp(command, "contrast") == 0) {
        float amount = atof(args[0]);

        if (amount < 0.0 || amount > 1.0) {
            printf("Invalid contrast amount: %s.\n", args[0]);
            return NULL;
        }

        float factor = (259 * (amount + 255)) / (255 * (259 - amount));

        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                int new_value = (int) (factor * (image->pixels[i][j] - 128) + 128);
                image->pixels[i][j] = (new_value < 0) ? 0 : (new_value > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : new_value;
            }
        }
    } else {
        printf("Invalid command: %s.\n", command);
        return NULL;
    }

    return image;
}

void print_image(Image *image) {
    printf("Image: %dx%d\n", image->width, image->height);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d ", image->pixels[i][j]);
        }

        printf("\n");
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    char args_list[MAX_ARGS_LENGTH][MAX_COMMAND_LENGTH];
    int num_args = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    Image *image = load_image(filename);

    if (image == NULL) {
        return 1;
    }

    printf("Enter command: ");
    scanf("%s", command);

    printf("Enter arguments (if any), separated by spaces: ");
    char ch = getchar();

    while (ch != '\n') {
        if (ch == ' ' && num_args < MAX_ARGS_LENGTH - 1) {
            args_list[num_args][0] = '\0';
            num_args++;
        } else {
            strncat(args_list[num_args], &ch, 1);
        }

        ch = getchar();
    }

    char **args = (char **) malloc(sizeof(char *) * num_args);

    if (args == NULL) {
        printf("Failed to allocate memory for argument array.\n");
        return 1;
    }

    for (int i = 0; i < num_args; i++) {
        args[i] = args_list[i];
    }

    Image *edited_image = apply_command(image, command, args);

    if (edited_image == NULL) {
        return 1;
    }

    char new_filename[MAX_FILENAME_LENGTH];
    printf("Enter new filename: ");
    scanf("%s", new_filename);

    if (!save_image(edited_image, new_filename)) {
        return 1;
    }

    printf("Saved edited image to %s.\n", new_filename);

    free_image(image);
    free_image(edited_image);

    return 0;
}