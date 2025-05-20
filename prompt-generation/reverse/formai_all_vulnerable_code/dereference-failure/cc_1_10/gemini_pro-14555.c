//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SECTOR_SIZE 512
#define FAT_ENTRY_SIZE 32

typedef struct {
    char filename[8];
    char ext[3];
    uint8_t attributes;
    uint16_t first_cluster;
    uint32_t file_size;
} fat_direntry;

typedef struct {
    uint8_t jump_code;
    char oem_id[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t num_fats;
    uint16_t max_root_entries;
    uint16_t total_sectors;
    uint16_t fat_size;
    uint16_t root_dir_sector;
} fat_bootsector;

typedef struct {
    uint32_t start_cluster;
    uint32_t end_cluster;
    uint32_t file_size;
} fat_fileinfo;

FILE* disk_image;
fat_bootsector bootsector;
uint8_t* fat;
fat_direntry* root_dir;

void read_sector(uint32_t sector, void* buffer) {
    fseek(disk_image, sector * SECTOR_SIZE, SEEK_SET);
    fread(buffer, SECTOR_SIZE, 1, disk_image);
}

void write_sector(uint32_t sector, void* buffer) {
    fseek(disk_image, sector * SECTOR_SIZE, SEEK_SET);
    fwrite(buffer, SECTOR_SIZE, 1, disk_image);
}

void read_bootsector() {
    read_sector(0, &bootsector);
}

void read_fat() {
    fat = malloc(bootsector.fat_size * SECTOR_SIZE);
    for (int i = 0; i < bootsector.num_fats; i++) {
        read_sector(bootsector.reserved_sectors + i * bootsector.fat_size, fat + i * SECTOR_SIZE);
    }
}

void read_root_dir() {
    root_dir = malloc(bootsector.max_root_entries * sizeof(fat_direntry));
    read_sector(bootsector.root_dir_sector, root_dir);
}

fat_fileinfo* get_fileinfo(char* filename) {
    for (int i = 0; i < bootsector.max_root_entries; i++) {
        if (strcmp(root_dir[i].filename, filename) == 0) {
            fat_fileinfo* fileinfo = malloc(sizeof(fat_fileinfo));
            fileinfo->start_cluster = root_dir[i].first_cluster;
            fileinfo->end_cluster = 0;
            fileinfo->file_size = root_dir[i].file_size;
            return fileinfo;
        }
    }
    return NULL;
}

uint32_t get_cluster_sector(uint32_t cluster) {
    return bootsector.reserved_sectors + bootsector.num_fats * bootsector.fat_size + (cluster - 2) * bootsector.sectors_per_cluster;
}

void recover_file(char* filename, char* output_filename) {
    fat_fileinfo* fileinfo = get_fileinfo(filename);
    if (fileinfo == NULL) {
        printf("File not found.\n");
        return;
    }

    FILE* output_file = fopen(output_filename, "wb");

    uint32_t cluster = fileinfo->start_cluster;
    while (cluster != 0xFFFFFFFF) {
        uint32_t sector = get_cluster_sector(cluster);
        uint8_t buffer[SECTOR_SIZE];
        read_sector(sector, buffer);
        fwrite(buffer, SECTOR_SIZE, 1, output_file);
        cluster = fat[cluster * FAT_ENTRY_SIZE];
    }

    fclose(output_file);
    free(fileinfo);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <disk image> <filename> <output filename>\n", argv[0]);
        return 1;
    }

    disk_image = fopen(argv[1], "rb+");
    read_bootsector();
    read_fat();
    read_root_dir();

    recover_file(argv[2], argv[3]);

    fclose(disk_image);
    free(fat);
    free(root_dir);

    return 0;
}