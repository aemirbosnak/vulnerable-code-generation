//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// This function takes in the image data array and its dimensions, 
// and returns the corresponding ASCII art string
char *convert_image_to_ascii(char *data, int width, int height) {
    // Allocate memory for the ASCII art string
    char *ascii = (char *)malloc((width+1) * height * sizeof(char));
    if (ascii == NULL) {
        perror("Error allocating memory");
        exit(errno);
    }

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Convert pixel value to ASCII character based on brightness
            int val = (int)data[i*width+j];
            if (val < 30) {
                ascii[i*(width+1)+j] = '@';
            } else if (val < 60) {
                ascii[i*(width+1)+j] = '#';
            } else if (val < 90) {
                ascii[i*(width+1)+j] = 'X';
            } else if (val < 120) {
                ascii[i*(width+1)+j] = 'O';
            } else if (val < 150) {
                ascii[i*(width+1)+j] = '*';
            } else if (val < 180) {
                ascii[i*(width+1)+j] = '+';
            } else if (val < 210) {
                ascii[i*(width+1)+j] = '=';
            } else if (val < 240) {
                ascii[i*(width+1)+j] = '-';
            } else {
                ascii[i*(width+1)+j] = ' ';
            }
        }
        // Add newline character at end of each row
        ascii[i*(width+1)+j] = '\n';
    }

    // Add null character at end of string
    ascii[(width+1)*height] = '\0';

    return ascii;
}

int main(int argc, char *argv[]) {
    int fd;
    char *filename;
    struct stat st;
    char *data;
    char *ascii;
    int width, height;

    // Check if filename was provided as argument
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    filename = argv[1];

    // Open file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(errno);
    }

    // Get file size and allocate memory for data array
    if (fstat(fd, &st) == -1) {
        perror("Error getting file size");
        exit(errno);
    }
    data = (char *)malloc(st.st_size);
    if (data == NULL) {
        perror("Error allocating memory");
        exit(errno);
    }

    // Read file into data array
    if (read(fd, data, st.st_size) == -1) {
        perror("Error reading file");
        exit(errno);
    }

    // Close file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(errno);
    }

    // Get image dimensions
    width = (int)data[18]*256 + (int)data[19];
    height = (int)data[22]*256 + (int)data[23];

    // Convert image to ASCII art
    ascii = convert_image_to_ascii(data+54, width, height);

    // Print ASCII art to console
    printf("%s", ascii);

    // Free memory
    free(data);
    free(ascii);

    return 0;
}