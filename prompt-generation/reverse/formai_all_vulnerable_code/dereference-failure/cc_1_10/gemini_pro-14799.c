//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct file_header {
    uint64_t size;
    char name[100];
};

struct disk {
    char *data;
    uint64_t size;
};

struct file_entry {
    uint64_t offset;
    uint64_t size;
    char name[100];
};

typedef struct {
    struct file_header header;
    char *data;
} file_t;

typedef struct {
    struct disk *disk;
    struct file_entry *files;
    int num_files;
} file_system_t;

file_system_t *fs;

void print_usage() {
    printf("Usage: recover <disk_image> <output_directory>\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    // Load the disk image
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open disk image '%s'\n", argv[1]);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    uint64_t file_size = ftell(fp);
    rewind(fp);

    fs = malloc(sizeof(file_system_t));
    if (fs == NULL) {
        fprintf(stderr, "Error: could not allocate memory for file system\n");
        return 1;
    }

    fs->disk = malloc(sizeof(struct disk));
    if (fs->disk == NULL) {
        fprintf(stderr, "Error: could not allocate memory for disk\n");
        return 1;
    }

    fs->disk->data = malloc(file_size);
    if (fs->disk->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for disk data\n");
        return 1;
    }

    fs->disk->size = file_size;
    fread(fs->disk->data, 1, file_size, fp);
    fclose(fp);

    // Parse the file system
    uint64_t offset = 0;
    while (offset < fs->disk->size) {
        struct file_header *header = (struct file_header *)(fs->disk->data + offset);

        if (header->size == 0) {
            break;
        }

        struct file_entry *entry = malloc(sizeof(struct file_entry));
        if (entry == NULL) {
            fprintf(stderr, "Error: could not allocate memory for file entry\n");
            return 1;
        }

        entry->offset = offset + sizeof(struct file_header);
        entry->size = header->size;
        strcpy(entry->name, header->name);

        fs->files = realloc(fs->files, (fs->num_files + 1) * sizeof(struct file_entry));
        if (fs->files == NULL) {
            fprintf(stderr, "Error: could not allocate memory for file entries\n");
            return 1;
        }

        fs->files[fs->num_files] = *entry;
        fs->num_files++;

        offset += sizeof(struct file_header) + header->size;
    }

    // Create the output directory
    int ret = mkdir(argv[2], 0755);
    if (ret != 0) {
        fprintf(stderr, "Error: could not create output directory '%s'\n", argv[2]);
        return 1;
    }

    // Extract the files
    for (int i = 0; i < fs->num_files; i++) {
        struct file_entry *entry = &fs->files[i];

        char *file_path = malloc(strlen(argv[2]) + strlen(entry->name) + 2);
        if (file_path == NULL) {
            fprintf(stderr, "Error: could not allocate memory for file path\n");
            return 1;
        }

        sprintf(file_path, "%s/%s", argv[2], entry->name);

        fp = fopen(file_path, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Error: could not open file '%s' for writing\n", file_path);
            return 1;
        }

        fwrite(fs->disk->data + entry->offset, 1, entry->size, fp);
        fclose(fp);

        free(file_path);
    }

    return 0;
}