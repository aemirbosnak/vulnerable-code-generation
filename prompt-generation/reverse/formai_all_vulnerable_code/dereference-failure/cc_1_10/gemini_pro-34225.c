//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file data
typedef struct {
    char *name;
    char *contents;
    size_t size;
} FileData;

// Function to recover files from a disk image
void recover_files(const char *disk_image) {
    // Open the disk image file
    FILE *disk = fopen(disk_image, "rb");
    if (!disk) {
        perror("Error opening disk image file");
        return;
    }

    // Read the FAT table
    const size_t FAT_SIZE = 512;
    unsigned char FAT[FAT_SIZE];
    fseek(disk, 0, SEEK_SET);
    fread(FAT, 1, FAT_SIZE, disk);

    // Iterate over the FAT table
    size_t cluster = 2;
    while (cluster != 0xFFF) {
        // Read the cluster
        const size_t CLUSTER_SIZE = 512;
        unsigned char cluster_data[CLUSTER_SIZE];
        fseek(disk, cluster * CLUSTER_SIZE, SEEK_SET);
        fread(cluster_data, 1, CLUSTER_SIZE, disk);

        // Check if the cluster is empty
        int empty = 1;
        for (size_t i = 0; i < CLUSTER_SIZE; i++) {
            if (cluster_data[i] != 0) {
                empty = 0;
                break;
            }
        }

        // If the cluster is not empty, parse the files
        if (!empty) {
            size_t offset = 0;
            while (offset < CLUSTER_SIZE) {
                // Read the file name
                char file_name[11];
                memcpy(file_name, cluster_data + offset, 11);
                file_name[10] = '\0';

                // Check if the file name is valid
                int valid = 1;
                for (size_t i = 0; i < 10; i++) {
                    if (file_name[i] == ' ' || file_name[i] == 0) {
                        valid = 0;
                        break;
                    }
                }

                // If the file name is valid, parse the file contents
                if (valid) {
                    // Read the file size
                    size_t file_size;
                    memcpy(&file_size, cluster_data + offset + 11, 4);

                    // Read the file contents
                    char *file_contents = malloc(file_size + 1);
                    memcpy(file_contents, cluster_data + offset + 15, file_size);
                    file_contents[file_size] = '\0';

                    // Store the file data
                    FileData file_data = {
                        .name = strdup(file_name),
                        .contents = file_contents,
                        .size = file_size
                    };

                    // Save the file to disk
                    FILE *file = fopen(file_data.name, "wb");
                    if (!file) {
                        perror("Error opening file");
                        return;
                    }
                    fwrite(file_data.contents, 1, file_data.size, file);
                    fclose(file);

                    // Free the file data
                    free(file_data.name);
                    free(file_data.contents);
                }

                // Advance to the next file
                offset += 32;
            }
        }

        // Advance to the next cluster
        cluster = FAT[cluster];
    }

    // Close the disk image file
    fclose(disk);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <disk_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Recover the files from the disk image
    recover_files(argv[1]);

    return EXIT_SUCCESS;
}