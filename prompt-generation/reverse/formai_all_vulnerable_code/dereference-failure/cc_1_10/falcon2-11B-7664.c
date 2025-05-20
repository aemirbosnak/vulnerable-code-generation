//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

// Define constants
#define BUFFER_SIZE 1024
#define MAX_COLORS 256

// Define global variables
int image_fd;
int image_height;
int image_width;
int image_channels;
int image_size;
int* image_data;

// Define function prototypes
void* process_image(void* arg);
void read_image_from_file(const char* filename);
void write_image_to_file(const char* filename);
void* process_image_thread(void* arg);

// Main function
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    // Open the image file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Failed to open image file: %s\n", strerror(errno));
        exit(1);
    }

    // Read the image data from the file
    read_image_from_file(argv[1]);

    // Process the image in a separate thread
    pthread_t thread;
    pthread_create(&thread, NULL, process_image_thread, NULL);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Write the modified image data back to the file
    write_image_to_file(argv[1]);

    // Close the file descriptor
    close(fd);

    return 0;
}

// Function to process the image in a separate thread
void* process_image(void* arg) {
    // Get the argument from the parent process
    int* image_data = (int*)arg;

    // Process the image data
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            for (int c = 0; c < image_channels; c++) {
                int color = image_data[y * image_width * image_channels + x * image_channels + c];
                if (color > 128) {
                    color -= 256;
                }
                else if (color < 0) {
                    color += 256;
                }
                image_data[y * image_width * image_channels + x * image_channels + c] = color;
            }
        }
    }

    // Return the processed image data back to the parent process
    return image_data;
}

// Function to read the image data from a file
void read_image_from_file(const char* filename) {
    // Open the image file for reading
    image_fd = open(filename, O_RDONLY);
    if (image_fd < 0) {
        fprintf(stderr, "Failed to open image file: %s\n", strerror(errno));
        exit(1);
    }

    // Read the image dimensions from the file
    struct stat file_info;
    fstat(image_fd, &file_info);
    image_height = file_info.st_blksize;
    image_width = file_info.st_blksize;
    image_channels = 1;

    // Read the image data from the file
    image_size = image_height * image_width * image_channels;
    image_data = (int*)malloc(image_size * sizeof(int));
    if (image_data == NULL) {
        fprintf(stderr, "Failed to allocate memory for image data: %s\n", strerror(errno));
        exit(1);
    }
    int read_size = read(image_fd, image_data, image_size);
    if (read_size!= image_size) {
        fprintf(stderr, "Failed to read image data: %s\n", strerror(errno));
        exit(1);
    }

    // Close the file descriptor
    close(image_fd);
}

// Function to write the image data to a file
void write_image_to_file(const char* filename) {
    // Open the image file for writing
    image_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (image_fd < 0) {
        fprintf(stderr, "Failed to open image file: %s\n", strerror(errno));
        exit(1);
    }

    // Write the image dimensions to the file
    struct stat file_info;
    fstat(image_fd, &file_info);
    file_info.st_blksize = image_height;
    file_info.st_blksize = image_width;
    file_info.st_blksize = image_channels;
    if (write(image_fd, &file_info, sizeof(struct stat))!= sizeof(struct stat)) {
        fprintf(stderr, "Failed to write image dimensions to file: %s\n", strerror(errno));
        exit(1);
    }

    // Write the image data to the file
    write(image_fd, image_data, image_size);
    if (write(image_fd, image_data, image_size)!= image_size) {
        fprintf(stderr, "Failed to write image data to file: %s\n", strerror(errno));
        exit(1);
    }

    // Close the file descriptor
    close(image_fd);
}

// Function to process the image in a separate thread
void* process_image_thread(void* arg) {
    // Get the argument from the parent process
    int* image_data = (int*)arg;

    // Process the image data
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            for (int c = 0; c < image_channels; c++) {
                int color = image_data[y * image_width * image_channels + x * image_channels + c];
                if (color > 128) {
                    color -= 256;
                }
                else if (color < 0) {
                    color += 256;
                }
                image_data[y * image_width * image_channels + x * image_channels + c] = color;
            }
        }
    }

    // Return the processed image data back to the parent process
    return image_data;
}