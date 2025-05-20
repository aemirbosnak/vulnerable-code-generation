//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 4096

// Custom error codes
#define ERR_FILE_NOT_FOUND 1
#define ERR_FILE_OPEN_FAILED 2
#define ERR_FILE_READ_FAILED 3
#define ERR_FILE_WRITE_FAILED 4
#define ERR_STAT_FAILED 5
#define ERR_MALLOC_FAILED 6

// Function to print error message and exit the program
void error(const char *msg, int code) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(code);
}

// Function to check if a file exists
bool file_exists(const char *path) {
    struct stat buf;
    return stat(path, &buf) == 0;
}

// Function to read a file into a buffer
char *read_file(const char *path) {
    FILE *fp;
    char *buf;
    size_t size;

    // Open the file for reading
    fp = fopen(path, "rb");
    if (fp == NULL) {
        error("fopen() failed", ERR_FILE_OPEN_FAILED);
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    // Allocate a buffer to hold the file contents
    buf = malloc(size + 1);
    if (buf == NULL) {
        error("malloc() failed", ERR_MALLOC_FAILED);
    }

    // Read the file into the buffer
    if (fread(buf, size, 1, fp) != 1) {
        error("fread() failed", ERR_FILE_READ_FAILED);
    }

    // Close the file
    fclose(fp);

    // Null-terminate the buffer
    buf[size] = '\0';

    return buf;
}

// Function to write a buffer to a file
void write_file(const char *path, const char *buf, size_t size) {
    FILE *fp;

    // Open the file for writing
    fp = fopen(path, "wb");
    if (fp == NULL) {
        error("fopen() failed", ERR_FILE_OPEN_FAILED);
    }

    // Write the buffer to the file
    if (fwrite(buf, size, 1, fp) != 1) {
        error("fwrite() failed", ERR_FILE_WRITE_FAILED);
    }

    // Close the file
    fclose(fp);
}

// Function to compare two files
bool compare_files(const char *path1, const char *path2) {
    struct stat buf1, buf2;
    char *buf1_contents, *buf2_contents;
    int result;

    // Check if the files exist
    if (!file_exists(path1) || !file_exists(path2)) {
        return false;
    }

    // Get the file sizes
    if (stat(path1, &buf1) != 0 || stat(path2, &buf2) != 0) {
        error("stat() failed", ERR_STAT_FAILED);
    }

    // Check if the file sizes are different
    if (buf1.st_size != buf2.st_size) {
        return false;
    }

    // Read the files into buffers
    buf1_contents = read_file(path1);
    buf2_contents = read_file(path2);

    // Compare the buffers
    result = strcmp(buf1_contents, buf2_contents);

    // Free the buffers
    free(buf1_contents);
    free(buf2_contents);

    return result == 0;
}

// Function to synchronize two files
void sync_files(const char *path1, const char *path2) {
    struct stat buf1, buf2;
    char *buf1_contents, *buf2_contents;

    // Check if the files exist
    if (!file_exists(path1) || !file_exists(path2)) {
        error("File not found", ERR_FILE_NOT_FOUND);
    }

    // Get the file sizes
    if (stat(path1, &buf1) != 0 || stat(path2, &buf2) != 0) {
        error("stat() failed", ERR_STAT_FAILED);
    }

    // Check if the file sizes are different
    if (buf1.st_size != buf2.st_size) {
        // Copy the larger file to the smaller file
        if (buf1.st_size > buf2.st_size) {
            buf1_contents = read_file(path1);
            write_file(path2, buf1_contents, buf1.st_size);
            free(buf1_contents);
        } else {
            buf2_contents = read_file(path2);
            write_file(path1, buf2_contents, buf2.st_size);
            free(buf2_contents);
        }
    } else {
        // Compare the files
        if (!compare_files(path1, path2)) {
            // Copy the contents of the first file to the second file
            buf1_contents = read_file(path1);
            write_file(path2, buf1_contents, buf1.st_size);
            free(buf1_contents);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    // Synchronize the files
    sync_files(argv[1], argv[2]);

    // Exit successfully
    return 0;
}