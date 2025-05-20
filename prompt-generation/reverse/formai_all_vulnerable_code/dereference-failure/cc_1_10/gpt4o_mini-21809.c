//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_FILES 50
#define MAGIC_NUMBER 0x12345678

typedef struct {
    int id;
    char name[100];
    size_t size;
    long offset;
} FileInfo;

typedef struct {
    int magic;
    int file_count;
    FileInfo files[MAX_FILES];
} RecoveryHeader;

void write_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

void recover_data(const char *inputPath, const char *outputPath) {
    int input_fd = open(inputPath, O_RDONLY);
    if (input_fd < 0) {
        write_error("Failed to open input file");
        return;
    }

    RecoveryHeader header;
    if (read(input_fd, &header, sizeof(header)) != sizeof(header)) {
        write_error("Failed to read the recovery header");
        close(input_fd);
        return;
    }

    if (header.magic != MAGIC_NUMBER) {
        write_error("Invalid recovery file");
        close(input_fd);
        return;
    }

    for (int i = 0; i < header.file_count; i++) {
        FileInfo fileInfo = header.files[i];
        char *buffer = malloc(fileInfo.size);
        if (!buffer) {
            write_error("Memory allocation failed");
            close(input_fd);
            return;
        }

        lseek(input_fd, fileInfo.offset, SEEK_SET);
        if (read(input_fd, buffer, fileInfo.size) != (ssize_t)fileInfo.size) {
            free(buffer);
            write_error("Failed to read file data");
            close(input_fd);
            return;
        }

        FILE *outputFile = fopen(fileInfo.name, "wb");
        if (!outputFile) {
            free(buffer);
            write_error("Failed to open output file for writing");
            close(input_fd);
            return;
        }

        fwrite(buffer, 1, fileInfo.size, outputFile);
        fclose(outputFile);
        free(buffer);
        printf("Recovered file: %s (size: %zu bytes)\n", fileInfo.name, fileInfo.size);
    }

    close(input_fd);
    printf("Data recovery completed successfully.\n");
}

void print_usage(const char *program_name) {
    printf("Usage: %s <input_recovery_file> <output_directory>\n", program_name);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *inputPath = argv[1];
    char *outputPath = argv[2];

    // Append a slash to the output path if not present
    if (outputPath[strlen(outputPath) - 1] != '/') {
        strcat(outputPath, "/");
    }

    // Set the current directory to the output directory
    if (chdir(outputPath) != 0) {
        write_error("Failed to change directory to output path");
        return EXIT_FAILURE;
    }

    recover_data(inputPath, outputPath);
    return EXIT_SUCCESS;
}