//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

// Function to get the file size
long get_file_size(const char *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

// Function to copy a file
int copy_file(const char *src, const char *dest) {
    FILE *fsrc, *fdest;
    char buffer[BUFSIZ];
    size_t nread;

    fsrc = fopen(src, "rb");
    if (fsrc == NULL) {
        perror("fopen");
        return -1;
    }

    fdest = fopen(dest, "wb");
    if (fdest == NULL) {
        perror("fopen");
        return -1;
    }

    while ((nread = fread(buffer, 1, BUFSIZ, fsrc)) > 0) {
        fwrite(buffer, 1, nread, fdest);
    }

    fclose(fsrc);
    fclose(fdest);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    // Get the source file size
    long src_size = get_file_size(argv[1]);
    if (src_size == -1) {
        perror("get_file_size");
        return 1;
    }

    // Get the destination file size
    long dest_size = get_file_size(argv[2]);
    if (dest_size == -1) {
        perror("get_file_size");
        return 1;
    }

    // Check if the destination file is smaller than the source file
    if (dest_size < src_size) {
        fprintf(stderr, "Destination file is smaller than source file\n");
        return 1;
    }

    // Copy the file
    if (copy_file(argv[1], argv[2]) != 0) {
        perror("copy_file");
        return 1;
    }

    printf("File copied successfully\n");
    return 0;
}