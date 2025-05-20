//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_RECOVERED_FILES 100

typedef struct {
    char name[256];
    long size;
    long offset;
} RecoveredFile;

void print_error(const char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
}

void recover_data(const char *disk_image, RecoveredFile *files, int *count) {
    FILE *file = fopen(disk_image, "rb");
    if (!file) {
        print_error("Failed to open disk image");
        return;
    }

    unsigned char buffer[BLOCK_SIZE];
    long total_read = 0;
    *count = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE) {
        // Simple heuristic: looking for JPEG files based on magic number
        if (buffer[0] == 0xFF && buffer[1] == 0xD8) {
            if (*count < MAX_RECOVERED_FILES) {
                snprintf(files[*count].name, sizeof(files[*count].name), "recovered_%03d.jpg", *count);
                files[*count].offset = total_read;
                fseek(file, total_read, SEEK_SET);
                // Need to get size
                int next_block_size = 0;
                while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE && !(buffer[0] == 0xFF && buffer[1] == 0xD8)) {
                    next_block_size += BLOCK_SIZE;
                    total_read += BLOCK_SIZE;
                }
                files[*count].size = next_block_size + BLOCK_SIZE;  // Including first block
                total_read += BLOCK_SIZE;
                (*count)++;
            } else {
                printf("Max recovery limit reached\n");
                break;
            }
        }
        total_read += BLOCK_SIZE;
    }
    fclose(file);
}

void write_recovered_files(const char *output_dir, RecoveredFile *files, int count) {
    for (int i = 0; i < count; i++) {
        char output_file_path[512];
        snprintf(output_file_path, sizeof(output_file_path), "%s/%s", output_dir, files[i].name);
        
        FILE *output_file = fopen(output_file_path, "wb");
        if (!output_file) {
            print_error("Failed to open output file");
            continue;
        }

        unsigned char buffer[BLOCK_SIZE];
        long current_offset = files[i].offset;
        FILE *input_file = fopen("disk_image.img", "rb");
        
        if (!input_file) {
            print_error("Failed to open disk image");
            fclose(output_file);
            continue;
        }

        fseek(input_file, current_offset, SEEK_SET);
        long bytes_to_read = files[i].size;

        while (bytes_to_read > 0) {
            size_t read = fread(buffer, 1, (bytes_to_read < BLOCK_SIZE) ? bytes_to_read : BLOCK_SIZE, input_file);
            fwrite(buffer, 1, read, output_file);
            bytes_to_read -= read;
        }

        fclose(input_file);
        fclose(output_file);
        printf("Recovered file: %s (Size: %ld bytes)\n", output_file_path, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <disk_image> <output_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *disk_image = argv[1];
    const char *output_directory = argv[2];

    RecoveredFile recovered_files[MAX_RECOVERED_FILES];
    int recovered_count;

    recover_data(disk_image, recovered_files, &recovered_count);
    write_recovered_files(output_directory, recovered_files, recovered_count);

    return EXIT_SUCCESS;
}