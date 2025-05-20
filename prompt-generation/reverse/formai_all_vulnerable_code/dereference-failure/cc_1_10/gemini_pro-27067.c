//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SECTOR_SIZE 512
#define MAX_SECTORS 1024

typedef struct {
    unsigned char boot_sector[SECTOR_SIZE];
    unsigned char fat[MAX_SECTORS * sizeof(unsigned int)];
    unsigned char root_directory[MAX_SECTORS * SECTOR_SIZE];
    unsigned char data_area[MAX_SECTORS * SECTOR_SIZE];
} disk_image;

disk_image *disk;

void read_disk_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fread(disk, sizeof(disk_image), 1, fp);
    fclose(fp);
}

void write_disk_image(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fwrite(disk, sizeof(disk_image), 1, fp);
    fclose(fp);
}

unsigned int get_fat_entry(unsigned int cluster) {
    return *(unsigned int *)&disk->fat[cluster * sizeof(unsigned int)];
}

void set_fat_entry(unsigned int cluster, unsigned int value) {
    *(unsigned int *)&disk->fat[cluster * sizeof(unsigned int)] = value;
}

unsigned int get_root_directory_entry(unsigned int index) {
    return *(unsigned int *)&disk->root_directory[index * SECTOR_SIZE];
}

void set_root_directory_entry(unsigned int index, unsigned int value) {
    *(unsigned int *)&disk->root_directory[index * SECTOR_SIZE] = value;
}

unsigned int get_data_sector(unsigned int cluster) {
    return cluster * MAX_SECTORS + 2;
}

void read_data_sector(unsigned int sector, unsigned char *data) {
    memcpy(data, &disk->data_area[sector * SECTOR_SIZE], SECTOR_SIZE);
}

void write_data_sector(unsigned int sector, const unsigned char *data) {
    memcpy(&disk->data_area[sector * SECTOR_SIZE], data, SECTOR_SIZE);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <disk image> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    disk = malloc(sizeof(disk_image));
    if (disk == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    read_disk_image(argv[1]);

    // Scan the root directory for deleted files
    for (unsigned int i = 0; i < MAX_SECTORS; i++) {
        unsigned int entry = get_root_directory_entry(i);
        if (entry == 0x00000000) {
            continue;
        }

        // Check if the file is deleted
        if ((entry & 0xE5) == 0xE5) {
            // The file is deleted. Recover it!

            // Get the starting cluster of the file
            unsigned int cluster = entry >> 16;

            // Read the data sectors of the file
            unsigned char data[SECTOR_SIZE * MAX_SECTORS];
            unsigned int sector = get_data_sector(cluster);
            for (unsigned int j = 0; j < MAX_SECTORS; j++) {
                read_data_sector(sector, &data[j * SECTOR_SIZE]);
                sector = get_fat_entry(cluster);
                if (sector == 0x0FFFFFF8) {
                    break;
                }
            }

            // Write the data to the output file
            FILE *fp = fopen(argv[2], "wb");
            if (fp == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            fwrite(data, SECTOR_SIZE * MAX_SECTORS, 1, fp);
            fclose(fp);

            // Mark the file as undeleted
            set_root_directory_entry(i, entry & 0x1FFFFFFF);
        }
    }

    write_disk_image(argv[1]);

    free(disk);

    return 0;
}