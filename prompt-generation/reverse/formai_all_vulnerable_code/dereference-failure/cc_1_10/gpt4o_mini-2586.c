//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100
#define FILENAME_SIZE 255

typedef struct {
    char name[FILENAME_SIZE];
    long size;
    long start_block;
} File;

void display_files(File *files, int file_count);
void recover_file(FILE *disk_image, File file, const char *output_dir);
int parse_disk_image(const char *disk_image_path, File *files);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <disk_image_path> <output_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *disk_image_path = argv[1];
    const char *output_directory = argv[2];

    File files[MAX_FILES];
    int file_count = parse_disk_image(disk_image_path, files);

    if (file_count == -1) {
        fprintf(stderr, "Error reading disk image: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    display_files(files, file_count);

    for (int i = 0; i < file_count; i++) {
        recover_file(fopen(disk_image_path, "rb"), files[i], output_directory);
    }

    return EXIT_SUCCESS;
}

int parse_disk_image(const char *disk_image_path, File *files) {
    FILE *disk_image = fopen(disk_image_path, "rb");
    if (!disk_image) {
        return -1;
    }

    // Simulate reading files from disk (in a real scenario, you would read metadata)
    for (int i = 0; i < MAX_FILES; i++) {
        snprintf(files[i].name, FILENAME_SIZE, "file%d.txt", i);
        files[i].size = BLOCK_SIZE * (i + 1); // Size increases with file number
        files[i].start_block = i * (BLOCK_SIZE / 2);
    }

    fclose(disk_image);
    return MAX_FILES; // Return the number of files recovered
}

void display_files(File *files, int file_count) {
    printf("Found the following files in the disk image:\n");
    for (int i = 0; i < file_count; i++) {
        printf("%d: %s (Size: %ld bytes, Start Block: %ld)\n", 
               i + 1, files[i].name, files[i].size, files[i].start_block);
    }
}

void recover_file(FILE *disk_image, File file, const char *output_dir) {
    char output_path[FILENAME_SIZE];
    snprintf(output_path, FILENAME_SIZE, "%s/%s", output_dir, file.name);

    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        fprintf(stderr, "Error creating file %s: %s\n", output_path, strerror(errno));
        return;
    }

    fseek(disk_image, file.start_block * BLOCK_SIZE, SEEK_SET);

    char *buffer = malloc(file.size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        fclose(output_file);
        return;
    }

    size_t read_bytes = fread(buffer, 1, file.size, disk_image);
    if (read_bytes != file.size) {
        fprintf(stderr, "Error reading file data for %s: %s\n", file.name, strerror(errno));
    }
    
    fwrite(buffer, 1, read_bytes, output_file);

    free(buffer);
    fclose(output_file);

    printf("Recovered file: %s\n", output_path);
}