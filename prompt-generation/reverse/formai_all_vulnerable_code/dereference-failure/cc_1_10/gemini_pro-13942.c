//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom file header for storing metadata
typedef struct {
    char filename[256];
    int filesize;
    int num_clusters;
    int cluster_size;
    int first_cluster;
} FileHeader;

// Function to read the file header from the specified file
FileHeader read_file_header(FILE *fp) {
    FileHeader header;
    fread(&header, sizeof(FileHeader), 1, fp);
    return header;
}

// Function to read the specified number of bytes from the specified file cluster
void read_file_cluster(FILE *fp, int cluster, int cluster_size, char *buffer) {
    fseek(fp, cluster * cluster_size, SEEK_SET);
    fread(buffer, cluster_size, 1, fp);
}

// Function to recover a file from the specified disk image file
void recover_file(FILE *fp, char *filename) {
    FileHeader header = read_file_header(fp);
    if (strcmp(header.filename, filename) == 0) {
        // File found, allocate buffer and read file data
        char *buffer = malloc(header.filesize);
        for (int i = 0; i < header.num_clusters; i++) {
            read_file_cluster(fp, header.first_cluster + i, header.cluster_size, buffer + i * header.cluster_size);
        }

        // Write recovered file to disk
        FILE *out = fopen(filename, "wb");
        fwrite(buffer, header.filesize, 1, out);
        fclose(out);

        // Free allocated memory
        free(buffer);
    }
}

// Function to scan the specified disk image file for lost files
void scan_disk_image(FILE *fp) {
    // Initialize variables
    char *buffer = malloc(512);
    int cluster_size = 512;
    int num_clusters = 0;
    int first_cluster = 0;

    // Read first cluster and check for file header
    fread(buffer, cluster_size, 1, fp);
    if (buffer[0] == 'F' && buffer[1] == 'H') {
        // File header found, get metadata
        FileHeader header;
        memcpy(&header, buffer, sizeof(FileHeader));
        num_clusters = header.num_clusters;
        first_cluster = header.first_cluster;
    }

    // Iterate through remaining clusters, looking for lost files
    for (int i = 1; i < num_clusters; i++) {
        // Read cluster and check for file header
        fread(buffer, cluster_size, 1, fp);
        if (buffer[0] == 'F' && buffer[1] == 'H') {
            // File header found, recover file
            FileHeader header;
            memcpy(&header, buffer, sizeof(FileHeader));
            recover_file(fp, header.filename);
        }
    }

    // Free allocated memory
    free(buffer);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <disk_image_file>\n", argv[0]);
        return 1;
    }

    // Open disk image file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening disk image file\n");
        return 1;
    }

    // Scan disk image for lost files
    scan_disk_image(fp);

    // Close disk image file
    fclose(fp);

    return 0;
}