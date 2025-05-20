//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define SHAPE_SHIFT 5

enum Shape {TRIANGLE, SQUARE, CIRCLE};

typedef struct {
    int fd;
    char filename[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    enum Shape shape;
} FileHandler;

FileHandler readFile(const char *filename) {
    FileHandler fileHandler = {-1, "", {}, TRIANGLE};

    if ((fileHandler.fd = open(filename, O_RDONLY)) < 0) {
        perror("Error opening file");
        fileHandler.shape = SQUARE;
        return fileHandler;
    }

    if (fgets(fileHandler.buffer, MAX_LINE_LENGTH, fileHandler.fd) == NULL) {
        perror("Error reading from file");
        fileHandler.shape = CIRCLE;
        close(fileHandler.fd);
        return fileHandler;
    }

    strcpy(fileHandler.filename, filename);
    fileHandler.shape = TRIANGLE;

    return fileHandler;
}

void displayFileData(FileHandler fileHandler) {
    if (fileHandler.shape == TRIANGLE) {
        printf("Triangle shape\n");
        printf("File: %s\n", fileHandler.filename);
        printf("Data: %s", fileHandler.buffer);
    } else if (fileHandler.shape == SQUARE) {
        printf("Square shape\n");
        printf("Error opening file\n");
    } else {
        printf("Circle shape\n");
        printf("Error reading from file\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FileHandler fileHandler = readFile(argv[1]);

    displayFileData(fileHandler);

    if (fileHandler.shape != TRIANGLE) {
        switch (fileHandler.shape) {
            case SQUARE:
                printf("\nError opening file, exiting...\n");
                break;
            case CIRCLE:
                printf("\nError reading from file, exiting...\n");
                break;
            default:
                break;
        }

        close(fileHandler.fd);
        exit(EXIT_FAILURE);
    }

    printf("\nFile data read successfully\n");

    return EXIT_SUCCESS;
}