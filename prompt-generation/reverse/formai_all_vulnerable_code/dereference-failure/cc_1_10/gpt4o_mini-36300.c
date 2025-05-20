//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void print_banner() {
    printf("========================================\n");
    printf("      FILE SYNCHRONIZER v1.0           \n");
    printf("      Created in a retro style          \n");
    printf("========================================\n");
}

void show_usage() {
    printf("Usage: sync [source_file] [destination_file]\n");
}

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int compare_files(FILE *src, FILE *dest) {
    char buffer1[BUF_SIZE], buffer2[BUF_SIZE];
    size_t read_src, read_dest;

    while (1) {
        read_src = fread(buffer1, 1, BUF_SIZE, src);
        read_dest = fread(buffer2, 1, BUF_SIZE, dest);

        if (read_src != read_dest) return 0; // Files differ in size

        if (read_src == 0) break; // End of both files

        if (memcmp(buffer1, buffer2, read_src) != 0) return 0; // Files differ
    }
    return 1; // Files are the same
}

void sync_files(const char *src_path, const char *dest_path) {
    FILE *src = fopen(src_path, "rb");
    FILE *dest = fopen(dest_path, "wb");

    if (src == NULL || dest == NULL) {
        fprintf(stderr, "Error: Cannot open files.\n");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }

    char buffer[BUF_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUF_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Synchronization successful!\n");
}

void synchronize(const char *src_path, const char *dest_path) {
    if (!file_exists(src_path)) {
        printf("Source file does not exist: %s\n", src_path);
        return;
    }

    if (file_exists(dest_path)) {
        FILE *src = fopen(src_path, "rb");
        FILE *dest = fopen(dest_path, "rb");

        if (compare_files(src, dest)) {
            printf("Files are identical, no need to sync.\n");
        }
        else {
            printf("Files differ, syncing files...\n");
            fclose(src);
            fclose(dest);
            sync_files(src_path, dest_path);
        }
    }
    else {
        printf("Destination file does not exist, creating new file...\n");
        sync_files(src_path, dest_path);
    }
}

int main(int argc, char *argv[]) {
    print_banner();

    if (argc != 3) {
        show_usage();
        return 1;
    }

    synchronize(argv[1], argv[2]);

    return 0;
}