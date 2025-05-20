//FormAI DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 20
#define MAX_FILE_SIZE 100000

typedef unsigned char BYTE;

// Function to read input file
int read_file(char* name, BYTE* data) {
    FILE* file;
    file = fopen(name, "rb");

    if (file == NULL) {
        printf("Error: file not found.");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(data, 1, size, file);
    fclose(file);

    return size;
}

// Function to write output file
void write_file(char* name, BYTE* data, int size) {
    FILE* file;
    file = fopen(name, "wb");
    fwrite(data, 1, size, file);
    fclose(file);
}

// Function to convert image to greyscale
void to_greyscale(BYTE* img_data, int width, int height) {
    int i, j;
    BYTE r, g, b, y;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            r = img_data[(i * width + j) * 3];
            g = img_data[(i * width + j) * 3 + 1];
            b = img_data[(i * width + j) * 3 + 2];
            y = (BYTE)(0.299 * r + 0.587 * g + 0.114 * b);
            img_data[(i * width + j) * 3] = img_data[(i * width + j) * 3 + 1] = img_data[(i * width + j) * 3 + 2] = y;
        }
    }
}

int main(int argc, char *argv[]) {

    // Check if correct number of arguments are supplied
    if (argc != 4) {
        printf("Error: Insufficient arguments!\n");
        printf("Usage: cimgedit <input_filename> <output_filename> <operation_type>\n");
        return 1;
    }

    // Get input and output file names
    char* input_file_name = argv[1];
    char* output_file_name = argv[2];
    int operation_type = atoi(argv[3]);

    // Read image file
    BYTE* input_data = (BYTE*)malloc(sizeof(BYTE) * MAX_FILE_SIZE);
    int input_size = read_file(input_file_name, input_data);

    if (input_size == -1)
        return 1;

    int width, height;
    char magic_number[3];
    sscanf(input_data, "%s %d %d", magic_number, &width, &height);

    // Check if image is of type P6
    if (strcmp(magic_number, "P6") != 0) {
        printf("Error: Invalid image type!\n");
        return 1;
    }

    // Check if command is valid
    if (operation_type < 1 || operation_type > 2) {
        printf("Error: Invalid command!\n");
        return 1;
    }

    // Perform operation based on command
    if (operation_type == 1)
        to_greyscale(input_data + strlen(magic_number) + 4, width, height);

    // Write output file
    write_file(output_file_name, input_data, input_size);

    return 0;
}