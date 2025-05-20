//FormAI DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_INPUT_COMMAND_LENGTH 20

// Function to invert the colors of an image
void invert_colors(int ***image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*image)[i][j] = 255 - (*image)[i][j];
        }
    }
}

// Function to blur an image
void blur_image(int ***image, int height, int width) {
    int new_image[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int count = 0;
            int sum = 0;

            for (int k = i - 2; k <= i + 2; k++) {
                for (int l = j - 2; l <= j + 2; l++) {
                    if (k >= 0 && k < height && l >= 0 && l < width) {
                        count++;
                        sum += (*image)[k][l];
                    }
                }
            }

            new_image[i][j] = sum / count;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*image)[i][j] = new_image[i][j];
        }
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    int height, width;
    int **image;

    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE *image_file = fopen(file_name, "r");

    if (image_file) {
        fscanf(image_file, "%d %d", &width, &height);

        image = (int **) malloc(sizeof(int *) * height);
        for (int i = 0; i < height; i++) {
            image[i] = (int *) malloc(sizeof(int) * width);
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fscanf(image_file, "%d", &image[i][j]);
            }
        }

        fclose(image_file);

        char input_command[MAX_INPUT_COMMAND_LENGTH];

        while (1) {
            printf("Enter command (invert, blur, quit): ");
            scanf("%s", input_command);

            for (int i = 0; i < strlen(input_command); i++) {
                input_command[i] = tolower(input_command[i]);
            }

            if (!strcmp(input_command, "invert")) {
                invert_colors(&image, height, width);
            } else if (!strcmp(input_command, "blur")) {
                blur_image(&image, height, width);
            } else if (!strcmp(input_command, "quit")) {
                break;
            } else {
                printf("Invalid command!\n");
            }
        }

        FILE *output_file = fopen(strcat(file_name, "_modified"), "w");

        fprintf(output_file, "%d %d\n", width, height);

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fprintf(output_file, "%d ", image[i][j]);
            }
            fprintf(output_file, "\n");
        }

        fclose(output_file);

        for (int i = 0; i < height; i++) {
            free(image[i]);
        }

        free(image);
    } else {
        printf("File not found!\n");
    }

    return 0;
}