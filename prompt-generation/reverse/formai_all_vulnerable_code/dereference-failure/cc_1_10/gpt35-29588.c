//FormAI DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_SIZE 100
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    int maxPixelValue;
    int** pixels;
} Image;

typedef struct {
    char command;
    int value;
} Instruction;

Image* readPPMImage(char* filename) {
    FILE* fp;
    Image* image;
    char line[MAX_LINE_SIZE];
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the P3 identifier
    if (fgets(line, MAX_LINE_SIZE, fp) == NULL || strcmp(line, "P3\n") != 0) {
        printf("Error: Invalid PPM file format\n");
        exit(EXIT_FAILURE);
    }

    // Skip the comment line (if any)
    if (fgets(line, MAX_LINE_SIZE, fp) != NULL && line[0] == '#') {
        while(fgets(line, MAX_LINE_SIZE, fp) != NULL && line[0] == '#');
    }

    // Read image width, height, and max pixel value
    if (sscanf(line, "%d %d", &i, &j) != 2 || i <= 0 || j <= 0) {
        printf("Error: Invalid PPM file format\n");
        exit(EXIT_FAILURE);
    }
    image = (Image*)malloc(sizeof(Image));
    image->width = i;
    image->height = j;
    if (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        sscanf(line, "%d", &i);
        image->maxPixelValue = i;
    }
    else {
        printf("Error: Invalid PPM file format\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for pixels
    image->pixels = (int**)malloc(sizeof(int*) * image->height);
    for (i = 0; i < image->height; i++) {
        image->pixels[i] = (int*)malloc(sizeof(int) * image->width);
    }

    // Read pixel values
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (fscanf(fp, "%d", &image->pixels[i][j]) != 1) {
                printf("Error: Invalid PPM file format\n");
                exit(EXIT_FAILURE);
            }
            if (image->pixels[i][j] > image->maxPixelValue) {
                printf("Error: Invalid PPM file format\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(fp);
    return image;
}

void writePPMImage(Image* image, char* filename) {
    FILE* fp;
    int i, j;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P3\n# Created by Image Editor\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VALUE);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(fp, "%d ", image->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void executeInstruction(Instruction* instruction, Image* image) {
    int i, j;

    switch (instruction->command) {
        case 'F':
            for (i = 0; i < image->height; i++) {
                for (j = 0; j < image->width; j++) {
                    image->pixels[i][j] = instruction->value;
                }
            }
            break;
        case 'H':
            for (i = 0; i < image->height / 2; i++) {
                for (j = 0; j < image->width; j++) {
                    int temp = image->pixels[i][j];
                    image->pixels[i][j] = image->pixels[image->height - i - 1][j];
                    image->pixels[image->height - i - 1][j] = temp;
                }
            }
            break;
        case 'R':
            for (i = 0; i < image->height; i++) {
                for (j = 0; j < image->width; j++) {
                    image->pixels[i][j] = MAX_PIXEL_VALUE - image->pixels[i][j];
                }
            }
            break;
        case 'C':
            for (i = 0; i < image->height; i++) {
                for (j = 0; j < image->width; j++) {
                    if (image->pixels[i][j] < instruction->value) {
                        image->pixels[i][j] = 0;
                    }
                    else {
                        image->pixels[i][j] = MAX_PIXEL_VALUE;
                    }
                }
            }
            break;
        case 'S':
            writePPMImage(image, "output.ppm");
            break;
        default:
            break;
    }
}

Instruction* parseInstruction(char* commandStr) {
    Instruction* instruction;
    char command;
    int value;

    instruction = (Instruction*)malloc(sizeof(Instruction));

    command = commandStr[0];
    instruction->command = toupper(command);

    if (command == 'F' || command == 'C') {
        if (sscanf(commandStr + 1, "%d", &value) == 1) {
            instruction->value = value;
        }
        else {
            instruction->value = MAX_PIXEL_VALUE;
        }
    }
    else {
        instruction->value = 0;
    }

    return instruction;
}

int main() {
    Image* image;
    char input[MAX_LINE_SIZE];
    bool done = false;

    // Read initial image
    image = readPPMImage("input.ppm");

    // Execute user commands
    while(!done) {
        printf("Enter a command (F/Flip H/Negative R/Threshold C/Save S/Quit Q): ");
        if (fgets(input, MAX_LINE_SIZE, stdin) == NULL) {
            printf("Error: Unable to read user input\n");
            exit(EXIT_FAILURE);
        }

        // Parse command and parameters
        Instruction* instruction = parseInstruction(input);

        switch (instruction->command) {
            case 'F':
            case 'H':
            case 'R':
            case 'C':
            case 'S':
                executeInstruction(instruction, image);
                break;
            case 'Q':
                done = true;
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        free(instruction);
    }

    // Free memory and exit program
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);

    return 0;
}