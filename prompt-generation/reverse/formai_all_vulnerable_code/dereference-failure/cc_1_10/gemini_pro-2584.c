//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    unsigned int size;
    unsigned char *data;
} file_entry;

// Read a single file from a recovery file
int read_file(FILE *f, file_entry *file) {
    // Read the file name
    char name[256];
    if (fread(name, 1, 256, f) != 256) {
        return -1;
    }

    // Read the file size
    unsigned int size;
    if (fread(&size, sizeof(unsigned int), 1, f) != 1) {
        return -1;
    }

    // Read the file data
    unsigned char *data = malloc(size);
    if (fread(data, 1, size, f) != size) {
        free(data);
        return -1;
    }

    // Store the file information in the file_entry structure
    file->name = strdup(name);
    file->size = size;
    file->data = data;

    return 0;
}

// Write a single file to a recovery file
int write_file(FILE *f, file_entry *file) {
    // Write the file name
    if (fwrite(file->name, 1, 256, f) != 256) {
        return -1;
    }

    // Write the file size
    if (fwrite(&file->size, sizeof(unsigned int), 1, f) != 1) {
        return -1;
    }

    // Write the file data
    if (fwrite(file->data, 1, file->size, f) != file->size) {
        return -1;
    }

    return 0;
}

// Recover files from a recovery file
int recover_files(FILE *f) {
    // Read the number of files
    unsigned int num_files;
    if (fread(&num_files, sizeof(unsigned int), 1, f) != 1) {
        return -1;
    }

    // Create an array of file_entry structures
    file_entry *files = malloc(sizeof(file_entry) * num_files);

    // Read the files from the recovery file
    for (unsigned int i = 0; i < num_files; i++) {
        if (read_file(f, &files[i]) != 0) {
            return -1;
        }
    }

    // Write the files to the disk
    for (unsigned int i = 0; i < num_files; i++) {
        FILE *out = fopen(files[i].name, "wb");
        if (out == NULL) {
            return -1;
        }

        if (fwrite(files[i].data, 1, files[i].size, out) != files[i].size) {
            fclose(out);
            return -1;
        }

        fclose(out);
    }

    // Free the memory allocated for the files
    for (unsigned int i = 0; i < num_files; i++) {
        free(files[i].name);
        free(files[i].data);
    }
    free(files);

    return 0;
}

int main(int argc, char *argv[]) {
    // Check if the user specified a recovery file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s recovery_file\n", argv[0]);
        return 1;
    }

    // Open the recovery file
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    // Recover the files from the recovery file
    if (recover_files(f) != 0) {
        fprintf(stderr, "Error recovering files\n");
        return 1;
    }

    // Close the recovery file
    fclose(f);

    return 0;
}