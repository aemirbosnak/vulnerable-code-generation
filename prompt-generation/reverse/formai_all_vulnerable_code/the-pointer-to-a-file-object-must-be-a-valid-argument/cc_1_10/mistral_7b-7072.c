//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024
#define LINE_BUFFER_SIZE 256
#define FILENAME_SIZE 256

void extract_metadata(const char *filename) {
    struct stat file_stat;
    int fd;
    char line[LINE_BUFFER_SIZE];
    char filename_with_path[FILENAME_SIZE];
    char *token;

    // Get file metadata
    if (stat(filename, &file_stat) < 0) {
        perror("Error reading file metadata");
        return;
    }

    printf("File name: %s\n", filename);
    printf("File size: %llu bytes\n", (unsigned long long)file_stat.st_size);
    printf("Number of lines: %d\n", get_num_lines(filename));
    printf("Last modification time: %s\n", ctime(&file_stat.st_mtime));

    // Extract number of lines from file
    memset(filename_with_path, 0, FILENAME_SIZE);
    strcpy(filename_with_path, "./");
    strcat(filename_with_path, filename);

    fd = open(filename_with_path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    int num_lines = 0;
    while (fgets(line, LINE_BUFFER_SIZE, fd) != NULL) {
        num_lines++;
    }

    close(fd);
}

int get_num_lines(const char *filename) {
    int num_lines = 0;
    int fd;
    char line[LINE_BUFFER_SIZE];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, LINE_BUFFER_SIZE, fd) != NULL) {
        num_lines++;
    }

    close(fd);
    return num_lines;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <C source file>\n", argv[0]);
        return 1;
    }

    extract_metadata(argv[1]);
    return 0;
}