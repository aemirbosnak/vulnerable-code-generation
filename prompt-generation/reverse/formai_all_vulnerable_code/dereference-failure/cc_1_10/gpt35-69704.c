//FormAI DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

void printUsage() {
    printf("Usage: ./binary_converter async <file_path>\n");
}

void onError(const char* message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

void onInterrupt(int signal) {
    printf("Interrupted!\n");
    exit(EXIT_SUCCESS);
}

bool isBinary(char character) {
    return character == '0' || character == '1';
}

void readFromFile(int fileDescriptor) {
    size_t bufferSize = 1024;
    char* buffer = (char*)malloc(bufferSize);
    ssize_t bytesRead;

    while ((bytesRead = read(fileDescriptor, buffer, bufferSize)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            char c = buffer[i];

            if (isBinary(c)) {
                printf("%c", c);
                fflush(stdout);
            }
        }
    }

    free(buffer);

    if (bytesRead == -1) {
        onError("Error reading file");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    char* mode = argv[1];
    char* filePath = argv[2];

    if (strcmp(mode, "async") != 0) {
        printf("Invalid mode. Only 'async' mode supported.\n");
        return EXIT_FAILURE;
    }

    if (access(filePath, F_OK) == -1) {
        fprintf(stderr, "File '%s' does not exist.\n", filePath);
        return EXIT_FAILURE;
    }

    int fileDescriptor = open(filePath, O_RDONLY);

    if (fileDescriptor == -1) {
        onError("Error opening file");
    }

    signal(SIGINT, onInterrupt);

    readFromFile(fileDescriptor);

    if (close(fileDescriptor) == -1) {
        onError("Error closing file");
    }

    return EXIT_SUCCESS;
}